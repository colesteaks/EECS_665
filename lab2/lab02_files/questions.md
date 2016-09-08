### EECS 665 Lab 2
#### Nicholas Jurden 2415098

1. How and why does `-DCORRECT` remove errors and warnings?
- from what I am able to glean, this defines CORRECT initially so that the preprocessor includes the libraries in the `ifdef CORRECT` block in `pre-proc1.c`. It accomplishes the same for the conditional in `defs2.h`. Because all of the files within these conditionals and the functions from them used in pre-proc1.c are now included, we can compile pre-proc1.c. `ifdef` checks to see if a macro is defined before executing the contents in its conditional block.

2. What does `-lm` do to resolve the error?
- 

3. What has the linker done in `a.out` compared to `linker3.o`
