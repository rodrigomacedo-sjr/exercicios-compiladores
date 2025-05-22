CC=gcc

EXECUTAVEL = l7e1
FONTE = l7e1.l

$(EXECUTAVEL): $(FONTE)
	$flex $(FONTE)
	$gcc lex.yy.c -o $(EXECUTAVEL)

clear:
	rm -f lex.yy.c
	rm -f $(EXECUTAVEL)
