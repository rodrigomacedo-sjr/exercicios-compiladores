%option noyywrap


%{
  char* removerUltimoCaracter(char *s) {
    size_t len = strlen(s);
    s[len - 1] = '\0';
    return s;
  }
%}


%%

// conta  n espaços
" "+ { printf("whitespace\n"); }

// dá prioridade para buscar a string IF especificamente
"if" { printf("IF\n"); }

// letra + qualquer combinação de letras e números
[a-z]+([a-z]|[0-9])+ { printf("%s ID\n", yytext); }

// 0 ou mais números seguidos de um ponto seguidos de um ou mais números
[0-9]*"."[0-9]+ { printf("%s REAL\n", yytext); }

// n números
[0-9]+ { printf("%s NUM\n", yytext); }

// dois traços + qualquer combinação de letras
// importante remover o \n do final do comentário por razões estéticas (acredito eu)
"--"[a-z]+"\n" { yytext = removerUltimoCaracter(yytext); printf("%s comment\n", yytext); }

// todo o resto é um erro
. { printf("%s error\n", yytext); }



%%

#include <string.h>

int main(int argc, char** argv) {
    return yylex();
}
