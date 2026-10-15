%{
#include <stdio.h>
%}

%%
(if)|(then)|(print)|(end) {
    printf("KEYWORD: %s\n", yytext);
}
[0-9]+ {
    printf("INTEGER: %s\n", yytext);
}
[a-zA-Z][^ \n]* {
    printf("IDENTIFIER: %s\n", yytext);
}
. { }
%%