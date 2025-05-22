
EXECUTAVEL = l7e2
FONTE = l7e2.l

$(EXECUTAVEL): $(FONTE)
	$flex $(FONTE)
	$gcc lex.yy.c -o $(EXECUTAVEL)

clear:
	rm -f lex.yy.c
	rm -f $(EXECUTAVEL)
