%option noyywrap

%{
%}


%%

("aba")+ { printf("action 1\n"); }
("a"("b")*"a") { printf("action 2\n"); }
"a"|"b" { printf("action 3\n"); }

%%


int main(int argc, char** argv) {
    return yylex();
}
