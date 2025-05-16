%option noyywrap


%{
int jaExibiu = 0;

void exibir(char* c) {
    if (jaExibiu) {
      printf("\n");
    } else {
      (jaExibiu = 1);
    }
    printf("%s", c);
}
%}


%%

"\n" { } // ignora nl
"+" { exibir("+"); }
"-" { exibir("-"); }
[a-z]([0-9]|[a-z])* { exibir(yytext); }
[0-9]+"e"(([0-9]+)|(("+"|"-")[0-9]+)) { exibir(yytext); }
[0-9]+ { exibir(yytext); }
. { exibir("ERRO"); }


%%


int main(int argc, char** argv) {
    return yylex();
}
