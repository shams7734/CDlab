/*	Shams Ali
	2015kucp1034
	finding number of tokens
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,j,k;
	int tokens=0,status=0,status1=0;
	char search[13]={'{','}',',',';','(',')','+','/','-','%','*','=','^'};
	char alph[36]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
				  '0','1','2','3','4','5','6','7','8','9'};
	char ch;
	FILE *fp;
	fp=fopen("token.txt","r");
	ch=fgetc(fp);
	cout<<ch<<endl;
	while(ch!=EOF)
	{
		status=0;
		status1=0;
		
		for(i=0;i<13;i++)
		{
			if(ch==search[i])
			{
				tokens++;
				ch=fgetc(fp);
				status=1;
				break;
			}
		}
			
		if(ch=='\"')
		{
			while(ch!='\"')
				ch=fgetc(fp);
			tokens++;
			ch=fgetc(fp);
		}
		
		
		
		for(j=0;j<36;j++)
		{
			if(ch==alph[j])
			{
				status1=1;
				ch=fgetc(fp);
				tokens++;
				break;
			}
				
		}
		
		if(status1==1)
		{
			
			while(ch!='{'&&ch!='}'&&ch!=','&&ch!=';'&&ch!='('&&ch!=')'&&ch!='+'&&ch!='/'&&ch!='-'&&ch!='%'&&ch!='*'&&ch!='='&&ch!='^'&&ch!=' ')
			{	
				
				ch=fgetc(fp);
			}
			tokens++;	
			ch=fgetc(fp);
				
		}
		
		if(status==1)
			ch=fgetc(fp);
		
	}
	
	cout<<"Total number of tokens are "<<tokens<<endl;
	fclose(fp);
}
