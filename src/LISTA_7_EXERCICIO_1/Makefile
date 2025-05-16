FLEX=flex
CC=gcc

EXECUTAVEL = l7e1
FONTE = l7e1.l

$(EXECUTAVEL): $(FONTE)
	$(FLEX) $(FONTE)
	$(CC) lex.yy.c -o $(EXECUTAVEL)

clear:
	rm -f lex.yy.c
	rm -f $(EXECUTAVEL)
