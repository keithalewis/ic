# Notes

## Things

Use `FILE*` for input/output. Use `fdopen` to convert from file descriptor
and `fmemopen` for strings of known length. Use `open_memstream` to write to a dynamic string buffer.

_Value types_ - a type having contiguous bits

_Signature_ - return type and argument types

_Function_ - pointer to C symbol

_Call stack_ - array of `void*` pointers to argument values.
Push (left to right) pointer on stack (including null), pop (right to left) pointer from stack.

_Bind_ call stack and signature - makes copies of values.

_Call_  function on bound stack and signature. Free's bound values after call (`cdecl`)

_Proc_ - user defined function. Every proc has a closure/environment pointer to look up variables.
The pointer is just the current environment. A new dict is pushed for variables local to
the function.

_Exec_ - call proc to get a value.

_Dict_ - key/value pairs
Every dict is fixed size. May have special last entry to point to another dictionary.
(Fat list of dicts.)

Push dict in front of dict. Dict becomes back.
Back dict makes special last entry.

Push marker/pop marker.

Dicts are immutable. Can pass pointers into dicts for closure/environment.

_Stack_ - dictionary stack

## Types and Values

A _(value) type_ describes the layout of bits in memory.

A _value_ is the bytes of a type.

Known types - `int`, ..., `pointer`

Every type has `make(type, size=0)`, `copy(value)`, and `free()` to manage memory.

Every type has `gets(is)` to scan and allocate values from streams.
Every type has `puts(os)` to print values to streams.

Every value has a `size`.
Every value has a `addr`. // copy(value) same as memcpy(addr(dest), addr(src), size(src))

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

## Examples

```
	void* x = ic_type_make(IC_TYPE_DOUBLE);
	ic_type_encode(stdin, IC_TYPE_DOUBLE, x);
	ic_type_decode(stdout, IC_TYPE_DOUBLE, x);

	void* y = ic_type_make(IC_TYPE_DOUBLE);
	void* s = ic_call_make(1); // call stack
	ic_call_push(s, IC_TYPE_DOUBLE, x);
	ic_call_func(s, cos, y);
	ic_call_free(s);
	ic_type_decode(stdout, IC_TYPE_DOUBLE, y);
	lc_type_free(y);

	lc_type_free(x);
```
