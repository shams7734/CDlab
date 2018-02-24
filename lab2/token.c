/*	Shams Ali
 	2015kucp1034
 	Implementation of tokenization of c program according to their category.
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>


int isSymbol(char c)
{
	if(c=='(' || c==')' || c=='[' || c==']' || c=='{' || c=='}' || c=='"' || c==',' || c==';' || c=='+' || c=='-' || c=='/' || c== '*'
		|| c=='=' || c=='<' || c=='>'){
		return 1;
	}
	else{
		return 0;
	}
}


char *symbol(char c)
{
	switch(c)
	{
		case '+' :
		case '-' : 
		case '*' :
		case '/' :
			return "Arithmatic Operator";
		case '&' :
		case '|' : 
		case '!' :
		case '^' :
			return "Logical Operator";
		case '(' : 
			return "opening parenthesis";
		case ')' :
			return "closing parenthesis";
		case '=' :
   			return "assignment operator";
		case ',' :
			return "coma";
		case '[' :
			return "opening bracket";
		case ']' :
			return "closing bracket";
		case '{' :
			return "opening curly brace";
		case '}' :
			return "closing curly brace";
		case ';' :
			return "end of line";
		case '<' :
			return "less than";
		case '>' :
 			return "greater than";
		default :
			return "none";
	}
}


int isReserved(char input[])
{
	int i,k;
	FILE* fp1;
	//reading known keywords from file
	fp1 = fopen("keywords.txt","r");
	int noOfKeys;
 	fscanf(fp1,"%d",&noOfKeys);
	char table[noOfKeys][100];
	for(i=0;i<noOfKeys;i++)
	{
		fscanf(fp1,"%s",table[i]);			
	}
	fclose(fp1);

	for(i=0;i<noOfKeys;i++)
	{
		int flag = 0;
		for(k=0;k<strlen(input) && (int)strlen(table[i]);k++)
		{
			//character by character matching if input matches a keyword or not
			if(table[i][k]!=input[k])
			{
				flag = 1;
				break;
			}
		}
		if(flag==0 && strlen(input)==(int)strlen(table[i]))
		{
			printf("%s : Keyword\n",input);
			return 1;
		}
	}
	if(i==noOfKeys)
	{
		return 0;
	}		
}


int isConstant(char input[])
{
	int i;
	for(i=0;i<strlen(input);i++)
	{
		if(!isdigit(input[i]))
			return 0;
	}
	return 1;
}


int isIdentifier(char input[])
{
	int i;
	if( input[0]!='_' && !isalpha(input[0]) )
	{
		printf("%s : Not a valid identifier\n",input);
		return 0;
	}
	for(i=1;i<strlen(input);i++)
	{
		if(!isalpha(input[i]) && !isdigit(input[i]) && input[i]!='_')
		{
			printf("%s : Not a valid identifier\n",input);
			return 0;
		}
	}

	printf("%s : Valid identifier\n",input);
	return 1;
}



void main()
{
	int i;
	FILE *fp;
	fp = fopen("input1.txt","r");
	char c;
	int count=0;
	int flag=0,flag2=0;
	char temp[100];
	printf("Tokens Found :\n\n");
	while(!feof(fp))
	{
		fscanf(fp,"%c",&c);		
		if(c==' ' || c=='\n' || c=='\t')
		{
			//skipping spaces and new lines
		}
		else{	
			if(isSymbol(c))
			{
				if(c=='/')
				{
					flag++;
				}
				//flag to check for single line comment
				if(flag==2)
				{
					while(c!='\n')
					{
						fscanf(fp,"%c",&c);
					}
					count = count -2;
					flag=0;	
				}
				if(c=='"')
				{
					printf("%c",c);
					fscanf(fp,"%c",&c);
					while(c!='"')
					{
						printf("%c",c);
						fscanf(fp,"%c",&c);
					}
					printf("\" : String Constant\n");
					continue;
				}
				if(c!='/' && c!='\n')
				printf("%c : %s\n",c,symbol(c));
				count++;
				
			}
			else{
				i=0;
				flag = 0;
				temp[i++] = c;
				while(c!=' ' && c!='\t' && c!='\n' && !isSymbol(c) && !feof(fp) )
				{
					fscanf(fp,"%c",&c);
					if(isSymbol(c))
					{
						printf("%c : %s\n",c,symbol(c));
						count++;
					}
					else
					{	
						if(c!=' ')
						temp[i++] =c;
					}
				}
				temp[i] = '\0';
				i=0;
				if(!isReserved(temp)){
					int f = isConstant(temp);
					if(f==1)
					{
						printf("%s : Constant\n",temp);
					}
					else					
					isIdentifier(temp);				
				}
				count++;
			}	
		}
		
	}
	printf("\nTotal Number Of Tokens : %d\n",count);
}
