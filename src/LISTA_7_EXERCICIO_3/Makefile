EXECUTAVEL = l7e3
FONTE = l7e3.l

$(EXECUTAVEL): $(FONTE)
	flex $(FONTE)
	gcc lex.yy.c -o $(EXECUTAVEL)

clear:
	rm -f lex.yy.c
	rm -f $(EXECUTAVEL)
