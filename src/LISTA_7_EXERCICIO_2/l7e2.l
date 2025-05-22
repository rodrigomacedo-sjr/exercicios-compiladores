%option noyywrap


%{
  char* removerUltimoCaracter(char *s) {
    size_t len = strlen(s);
    s[len - 1] = '\0';
    return s;
  }
%}


%%

" "+ { printf("whitespace\n"); }

"if" { printf("IF\n"); }

[a-z]+([a-z]|[0-9])+ { printf("%s ID\n", yytext); }

[0-9]*"."[0-9]+ { printf("%s REAL\n", yytext); }

[0-9]+ { printf("%s NUM\n", yytext); }

"--"[a-z]+"\n" { yytext = removerUltimoCaracter(yytext); printf("%s comment\n", yytext); }

. { printf("%s error\n", yytext); }



%%

#include <string.h>

int main(int argc, char** argv) {
    return yylex();
}
