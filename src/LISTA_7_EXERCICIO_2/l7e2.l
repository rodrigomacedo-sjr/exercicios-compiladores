%option noyywrap


%{
int jaExibiu = 0;

void verificarNovaLinha() {
    jaExibiu ? printf("\n") : (jaExibiu = 1);
}

void exibirComentario(char* c) {
    c[strlen(c) - 1] = '\0';
    printf("%s comment", c);
}
%}


%%


"i""f" { verificarNovaLinha(); printf("%s IF", yytext); }                  // IF
[a-hj-z]([0-9]|[a-z])* { verificarNovaLinha(); printf("%s ID", yytext); }  // ID
"."[0-9]+ { verificarNovaLinha(); printf("%s REAL", yytext); }             // REAL
[0-9]+"."[0-9]* { verificarNovaLinha(); printf("%s REAL", yytext); }       // REAL
[0-9]+ { verificarNovaLinha(); printf("%s NUM", yytext); }                 // NUM
"-""-"[a-z]+"\n" { verificarNovaLinha(); exibirComentario(yytext); }       // comment
" "+ { verificarNovaLinha(); printf("white space"); }                      // white space
. { verificarNovaLinha(); printf("%s error", yytext); }                    // error


%%


int main(int argc, char** argv) {
    return yylex();
}
