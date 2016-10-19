### EECS 665 Lab 5 Report
###### Nicholas Jurden, 2415098

#### Objective of Lab5
The objective of this lab was to create a calculator that produces the evaluated result of expressions passed in through the command line. Expressions are parsed using a grammar as defined with the tool ANTLRworks. The lab evaluates basic arithmetic expressions, adheres to mathematical precedence, and also evaluates logarithmic and trigonometric functions.

#### How My Parser Works
According to wikipedia, an LL parser is a top down parser for a subset of context free languages. It performs leftmost derivation on a sentence. In this case, the subset of context free languages we used was a part of numerical language. The parser chooses which rule to use based on an input, and then produces a derivation of the input based on that rule until it reaches a terminal symbol. In this case, terminal symbols are numerical, and rules represent various operations which are implemented using java libraries.

#### Implementation Discussion
This lab was implemented using ANTLR 3. I had no previous understanding of ANTLR and very rusty java knowledge, so initially beginning this lab was a bit difficult. After I started to conceptualize how ANTLR represents grammars, the lab became more intuitive. To maintain mathematical precedence, I used different grammar rules according to PE(MD)(AS). This guarantees that the parser cannot get to an operator out of order until it evaluates expressions with higher precedence. I faced a few errors: first, where to define variables that would be modified by java logic (mostly, as in the example we were given, I used 'l'). Another error I got was `The following alternatives can never be matched: `, which in one example was related to the order that I listed fragments.

#### ANTLRworks Features
By far the most valuable feature of ANTLRworks is the syntax diagram feature. It was very useful to be able to visualize the general derivation possibilities for my grammar rules. I was able to eliminate many errors down the road during implementation by checking my code against these diagrams.

#### Sources
https://en.wikipedia.org/wiki/LL_parser
