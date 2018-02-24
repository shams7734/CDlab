%%
[\t]+
is |
am |
are |
was |
were {printf("%s : is a valid helping verb",yytext);}
[a-z A-Z]+ {printf("%s : is not a valid helping verb",yytext);}
.	
%%
int main()
{
	yylex();
	return 0;
}
