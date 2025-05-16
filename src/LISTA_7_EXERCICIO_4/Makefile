FLEX=flex
CC=gcc

EXECUTAVEL = cstats
FONTE = l7e4.l

$(EXECUTAVEL): $(FONTE)
	$(FLEX) $(FONTE)
	$(CC) lex.yy.c -o $(EXECUTAVEL)

clear:
	rm -f lex.yy.c
	rm -f $(EXECUTAVEL)
