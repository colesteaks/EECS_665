LEX=lex
YACC=yacc
CC=gcc

LFLAGS=
CFLAGS=-Wall -Wno-unused-label -Wno-unused -g

all: lexer

lexer: lexer.lex.o
	$(CC) -o $@ $+

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.lex.c: %.l
	$(LEX) $(LFLAGS) -o $@ $<

%.out: %.c lexer
	./lexer < $< > $@

test: test.out
		diff test.out result.out

clean:
	$(RM) *.o
	$(RM) *.lex.c
	$(RM) *.out
	$(RM) *.log *.aux
	$(RM) lexer

.PHONY: clean all test
