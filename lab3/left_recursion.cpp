/*	Shams Ali
	2015KUCP1034
	Program to remove left recursion
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int i,j,num;
	
	FILE *fp;
	fp=freopen("file.txt","r",stdin);
	cin>>num;
	string s[num];
	string temp;
	for(i=0;i<num;i++)
	{
		cin>>s[i];	
	}
	
	for(i=0;i<num;i++)
	{
		if(s[i][0]==s[i][3])
		{
			for(j=0;j<num;j++)
			{
				if(s[i][0]==s[j][0])
				{
					temp=s[j].substr(3);
					if(temp[0]==s[i][0])
					{
						cout<<"Z"<<i<<"->";
						cout<<temp.substr(1)<<"Z"<<i<<"|$"<<endl;
					}
					else
					{
						
						cout<<s[i][0]<<"->";
						cout<<temp<<"Z"<<i<<endl;
					}
				}
				
			}
	
		}
		else 
			cout<<s[i]<<endl;
	}
	
	fclose(fp);
	
	return 0;
}
