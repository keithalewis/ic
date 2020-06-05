# Notes

## Things

_Signature_ - return type and argument types

_Function_ - pointer to C symbol

_Call stack_ - array of `void*` pointers to argument values.
Push (left to right) pointer on stack (including null), pop pointer from stack.

_Bind_ call stack and signature - makes copies of values.

_Call_  function on bound stack and signature. Free's bound values after call (`cdecl`)

_Proc_ - user defined function.

_Exec_ - call proc to get a value.

## Types and Values

A _(value) type_ describes the layout of bits in memory.

A _value_ is the bytes of a type.

Known types - `int`, ..., `pointer`

Every type has `make(type, size=0)`, `copy(value)`, and `free()` to manage memory.

Every type has `gets(is)` to scan and allocate values from streams.
Every type has `puts(os)` to print values to streams.

Every value has a `size`.

## New types

`struct tm { int tm_sec; ... }`


## Values

`int 123`

`tm { 1, ... }` - use default constructor

Can we read header files verbatim to load types and functions?

```
include <stdio.h> using LIBC_SO


Configure `isspace` to allow for parentheses and commas. (?)

```
// include lib-names.h
open libc; // set libc dlopen(LIBC_SO, RTLD_LAZY)
int fputc(int c, FILE *stream); // let puts dlsym(libc, "puts")
```

## Computations

Dictionary stack. `{` pushes new dict on stack, `}` pops it.
Only top level dict is writable???

Closures stores pointer to top of dict stack(s).

Bind used current dictionary values for args. 

`func(type arg, ...)` apply scope to arg based on func???
