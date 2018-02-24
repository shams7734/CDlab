/*	Shams Ali
	2015kucp1034
	Lex code to identify keyword and identifiers
*/
%%
[\t]+
break |
case |
char |
const |
continue |
default |
do |
else |
enum |
extern |
float |
for |
goto |
if |
while |
long |
register |
return |
short |
signed |
sizeof |
static |
switch |
typedef |
union |
unsigned |
void |
volatile |
int |
double |
auto |
struct {printf("%s : is a keyword\n",yytext);}
[_a-zA-Z][_a-zA-Z0-9]* {printf("%s : is an identifier\n",yytext);}
.* {printf("%s : is not a valid identifier\n",yytext);}	
%%
int main()
{
	printf("Enter any string\n");
	yylex();
	return 0;
}
