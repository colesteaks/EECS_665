### EECS 665 Lab 2
#### Nicholas Jurden 2415098

1. How and why does `-DCORRECT` remove errors and warnings?
- from what I am able to glean, this defines CORRECT initially so that the preprocessor includes the libraries in the `ifdef CORRECT` block in `pre-proc1.c`. It accomplishes the same for the conditional in `defs2.h`. Because all of the files within these conditionals and the functions from them used in pre-proc1.c are now included, we can compile pre-proc1.c. `ifdef` checks to see if a macro is defined before executing the contents in its conditional block.

2. What does `-lm` do to resolve the error?
- the `l` flag indicates a library is being selected. the `m` flag imports teh standard math library, which includes functions like `pow`. This corrects the error by defining `pow`, which was previously undefined.

3. What has the linker done in `a.out` compared to `linker3.o`
- the difference between `gcc -c linker3.c` and `gcc -L./lib linker3.c foo.c -lmul` is that, in the latter, the functions `foo`, `my_mul` and `printf` are defined. This is because gcc is told to look in an additional library folder (where `my_mul` is defined), to include `foo.c` which contains the definition of `foo`, and resulting in `a.out` which, upon observation in the objdump, contains all of these functions.
