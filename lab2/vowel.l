/*	Shams Ali
	2015kucp1034
	Lex code to count vowels and consonants in a string
*/
%{
	int vowel=0;
	int consonant=0;
%}
%%
[\n] {return 0;}
[aeiou AEIOU] vowel++;
[bcdfghjklmnpqrstvwxyz BCDFGHJKLMNPQRSTVWXYZ] consonant++;
.
%%

int main()
{
	printf("Enter a string\n");
	yylex();
	printf("consonant=%d\t vowel=%d\n",consonant,vowel);
}

