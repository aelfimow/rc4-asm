# rc4-asm
This is a 64-bit RC4 stream cipher implementation in x86 assembly language.

RC4 was developed by Ronald L. Rivest in the 80s. This is an attempt to implement
the algorithm in 64-bit assembly language.

## Tests
See my [rc4-asm-test](https://github.com/aelfimow/rc4-asm-test) repository.

## Tools
I am using [mingw-w64](https://mingw-w64.org) to compile the tests.

The [assembly source file](src/rc4func.S) has been originally generated using my [cppasm](https://github.com/aelfimow/cppasm)
generator.
