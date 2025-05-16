%option noyywrap


%{
int jaExibiu = 0;

void exibir(char* c) {
    jaExibiu ? printf("\n") : (jaExibiu = 1);
    printf("%s", c);
}
%}


%%


"aba"+ { exibir(yytext); printf(" (action 1)"); }
"a""b"*"a" { exibir(yytext); printf(" (action 2)"); }
"a"|"b" { exibir(yytext); printf(" (action 3)"); }


%%


int main(int argc, char** argv) {
    return yylex();
}
