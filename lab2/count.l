%{
	int count=0;
%}
%%
[\n] {return count;}
[a-z A-Z] count++;
%%

int main()
{
	printf("Enter a string\n");
	yylex();
	printf("count=%d\n",count);
}

