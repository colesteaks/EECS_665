LEX=lex
YACC=yacc
CC=gcc

LFLAGS=
YFLAGS=
CFLAGS=-Wall -Wno-unused-label -Wno-unused -I. -DNDEBUG

all: fcg

fcg: fcg.yacc.o fcg.lex.o
	$(CC) -o $@ $+

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.lex.c: %.l
	$(LEX) $(LFLAGS) -o $@ $<

%.yacc.c: %.y
	$(YACC) $(YFLAGS) -d -o $@ $<

%.png: %.dot
	dot -Tpng -o $@ $<

test: all
	./fcg < test.c > test.dot

clean:
	$(RM) *.o
	$(RM) *.lex.c
	$(RM) *.yacc.c
	$(RM) *.yacc.h
	$(RM) *.yacc.output
	$(RM) *.dot
	$(RM) *.png
	$(RM) fcg

.PHONY: clean all test
