%option noyywrap

%{
%}

%%

// + e - individualmente
"+"|"-" { printf("%s\n", yytext); }

// uma letra seguida de uma combinação de 0 ou mais letras ou números
[a-z]([a-z]|[0-9])* { printf("%s\n", yytext); }

// número inteiro ou notação científica
[0-9]+("e"[0-9]+|"e"[0-9]+("+"|"-")[0-9]+) { printf("%s\n", yytext); }

// ignore quebra de linha
\n {}

// qualquer outra coisa
. { printf("ERRO\n"); }


%%


int main(int argc, char** argv) {
    return yylex();
}
