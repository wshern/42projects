*This project has been created as part of the 42 curriculum by werlim.*

# get_next_line

## Description

`get_next_line` returns one line at a time from a file descriptor.

```c
char *get_next_line(int fd);
```

Each call returns the next line, including the trailing `\n`. The last line of
a file that does not end with `\n` is returned without one. When there is
nothing left to read, or on error, the function returns `NULL`.

The returned string is heap-allocated — the caller frees it.

Reading state is kept between calls in a `static` variable, so the function
never re-reads what it has already consumed. It works on regular files and on
standard input.

**Bonus**: multiple file descriptors can be read in an interleaved order
without losing track of each one's position.

## Instructions

No Makefile — the files are compiled directly with the program using them.

Mandatory:

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
   get_next_line.c get_next_line_utils.c main.c -o gnl
```

Bonus:

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
   get_next_line_bonus.c get_next_line_utils_bonus.c main.c -o gnl_bonus
```

`-D BUFFER_SIZE=n` is optional. Without it the header falls back to `42`. Any
positive `n` works: `1`, `9999`, `10000000`. A value of `0` or less makes
`get_next_line` return `NULL` immediately.

Usage:

```c
#include "get_next_line.h"

int  fd = open("file.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
```

## Files

| File | Contents |
| --- | --- |
| `get_next_line.c` | `get_next_line`, `update_storage`, `gnl_strbefore`, `gnl_strafter` |
| `get_next_line_utils.c` | `find_newline`, `gnl_strjoin`, `gnl_strlen`, `gnl_strcpy`, `gnl_free` |
| `get_next_line.h` | prototypes, includes, `BUFFER_SIZE` fallback |
| `*_bonus.[ch]` | same code, one static array indexed by `fd` |

## Algorithm

### The state

A single `static char *storage` holds everything that was read from the
descriptor but not yet returned. It survives between calls, which is the whole
point of the project — without it the second call would have no idea where the
first one stopped.

```
file:      "abc\ndef\nghi"      BUFFER_SIZE = 4

call 1 ->  storage "abc\ndef\n"  returns "abc\n"  storage left "def\n"
call 2 ->  storage "def\n"       returns "def\n"  storage left NULL
call 3 ->  storage "ghi"         returns "ghi"    storage left NULL
call 4 ->  read returns 0, storage NULL           returns NULL
```

### The three steps

Every call does the same three things, in order:

1. **`update_storage`** — loop `read()` in `BUFFER_SIZE` chunks, appending each
   chunk to `storage`, and stop as soon as `storage` contains a `\n` or `read`
   returns `0`. This is what keeps the function from swallowing the whole file:
   it reads the minimum needed to produce one line, no more.
2. **`gnl_strbefore`** — allocate and copy the part of `storage` up to and
   including the newline. That becomes the return value. If there is no newline
   (end of file without one), it copies the entire remainder instead.
3. **`gnl_strafter`** — allocate and copy the part after the newline, free the
   old `storage`, and make that leftover the new `storage`. If nothing remains,
   it frees and returns `NULL`, so the next call starts from a clean state.

`find_newline` drives steps 2 and 3. It returns the index of the first `\n`, or
`-1` when there is none — an `int` sentinel rather than a boolean, because both
callers need the position, not just the fact.

### Why this shape

The alternative is one function that scans, splits and reallocates in place.
That is shorter to describe but harder to reason about, and it does not fit the
Norm's 25-line limit without contortion. Splitting the work into *"give me what
comes before the newline"* and *"give me what comes after"* makes each function
one allocation, one copy, one return — small enough to be obviously correct,
and each one independently testable.

Ownership is deliberately simple. `gnl_strbefore` reads its argument and never
frees it; `gnl_strafter` always frees the string it is handed. So the caller
never has to ask who owns `storage` at a given moment, because the answer only
changes at one line in `get_next_line`. `gnl_free` exists so that error paths
can free two pointers and return `NULL` in a single expression.

**Trade-off:** joining each chunk onto `storage` means a line of length *L* is
copied roughly *L / BUFFER_SIZE* times, so a very long line costs
O(L² / BUFFER_SIZE). An index-into-a-fixed-buffer design would avoid this. It
was not chosen — correctness and defensibility matter more here than
throughput, and at a realistic `BUFFER_SIZE` the cost is not observable.

### Bonus

The mandatory version's `static char *storage` becomes:

```c
static char *storage[FD_MAX];
```

Still **one** static variable, as the bonus requires — it is an array, not a
set of variables. `fd` is used as a direct index, so switching between
descriptors is O(1) with no lookup or search:

```
storage[0]  -> NULL
storage[3]  -> "def\n"      <- fd 3 mid-file
storage[4]  -> NULL         <- fd 4 at a line boundary
storage[5]  -> "xy"         <- fd 5 mid-file
```

`FD_MAX` is a plain `#define 1024`, matching the default `RLIMIT_NOFILE` on
Linux. `OPEN_MAX` from `<limits.h>` is not reliable across platforms and
`sysconf` is not an allowed function. The array lives in `.bss`, so it is
zero-initialised at startup with no allocation and no failure path to handle.
Because an overrun in `.bss` is often invisible to Valgrind, `fd >= FD_MAX` is
rejected explicitly alongside `fd < 0`.

## Resources

- `man 2 read`, `man 3 malloc`, `man 2 open` — return values and error cases
- `valgrind --leak-check=full` and `-fsanitize=address` — leak and overrun checks

### Use of AI

AI was used as an explanatory tool, not as a source of code. Specifically:

- Explaining static storage duration, `.bss` initialisation, and why a static
  array still satisfies the "one static variable" bonus rule.
- Clarifying `read()` semantics: the difference between a `0` and a `-1`
  return, and why the buffer needs its own null terminator.
- Providing relevant knowledge that is related to this project.
- Reviewing my design for ownership and leak paths, and pointing out unresolved
  bugs found.
- Drafting this README.

All function bodies were written by me. No generated code was copied into the
project.