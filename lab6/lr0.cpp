/*	Shams Ali 
	2015KUCP1034
	Program to find lr0 items.
*/
#include<bits/stdc++.h>
using namespace std;
#include "utilities.h"

pair<string,string> x;
map<string, vector<string> > m;
set< set<string> > s,s4;
set<string > s2;
set<string> s1,s3;
string startsymbol;

int num;
string prod[100];
string prod1[100];
string temp;

set<string > closure(char c,int a)
{
	string temp1;
	size_t index;
	
	for(int i=0;i<num+1;i++)
	{
		if(c==prod1[i][0])
		{
			temp1=prod1[i];
			s1.insert(prod1[i]);
			temp=prod1[i].substr(3);
			index=temp.find(".");
			
			if(isupper(temp[index+1]))
			{
				for(int j=0;j<num+1;j++)
				{
					if( (temp[index+1]==prod1[j][0]) && (prod1[j]!=temp1) )
					{
						s3=closure(temp[index+1],num+1);
						s1.insert(s3.begin(),s3.end());
					}
				}
			}
			
		}
	}
	return s1;
}

set<set<string> >item(set<string> se,int a)
{
	
	string temp1;
	size_t index;
	char ch,ch1;
	for(auto i=se.begin();i!=se.end();i++)
	{
		set<string> ss,ss1;
		temp1=(*i);
		index=temp1.find(".");
		ch=temp1[index+1];
		for(auto j=se.begin();j!=se.end();j++)
		{
			temp=(*j);
			index=temp.find(".");
			if(ch==temp[index+1])
			{
				ch1=temp[index];
				temp[index]=temp[index+1];
				temp[index+1]=ch1;
				ss.insert(temp);
				index=temp.find(".");
				if((int)index < (int)temp.length()-1)
				{
					ch=temp[index+1];
					if(isupper(ch))
					{
						
						ss1=closure(temp[index+1],num+1);
						ss.insert(ss1.begin(),ss1.end());
					}
				}
				
			}
			
		}
		
		s4.insert(ss);
		/*set<string> ss2;
		ss2.insert(ss.begin(),ss.end());
		for(auto k=ss2.begin();k!=ss2.end();k++)
		{
			set< set<string> > s5;
			s5=item(ss2,num+1);
			s4.insert(s5.begin(),s5.end());
		}*/	
	
	}
	return s4;
}

int main()
{
	  
	  FILE *fp;
	  fp=freopen("input.txt","r",stdin);
	  
	  cin >> num;
	  for(int i=0;i<num;i++)
	  {
		 cin >> prod[i];
	  }
	  
	  fclose(fp);
	 
	  temp="Z->";
	  prod1[0].append(temp);
	  temp=prod[0][0];
	  prod1[0].append(temp); 
	  for(int i=0;i<num;i++)
	  {
	  		prod1[i+1]=prod[i];
	  }
	  
	  cout<< "Here, # is considered as NULL\n"<<endl;
	  cout << "Input file : "<<endl;
	  for(int i=0;i<num+1;i++)
	  {
		 cout << prod[i] << endl;
	  }
	  
	  cout<<"The new start symbol is : Z"<<endl;
	  
	  cout<<"\nNew productions :"<<endl;
	  
	  for(int i=0;i<num+1;i++)
	  {
		 cout << prod1[i] << endl;
	  }
	  
	  
	  int count =0;
	  size_t index;
	  for(int i=0;i<num+1;i++)
	  {
	  		index=prod1[i].find("->");
			if(count==0)
			{
				  startsymbol=prod1[i].substr(0,index-2);
				  count++;
			}
		
			x.first = prod1[i].substr(0,index-2);
			x.second = prod1[i].substr(index);
			m[x.first].push_back(x.second);
	  }
	  
	  cout<<"\nAugmented grammer is :"<<endl;
	  for(int i=0;i<num+1;i++)
	  {
	  		prod1[i].insert(3,1,'.');
	  		cout<<prod1[i]<<endl;
	  }
	  
	  cout<<"\nItem 0 is : \t";
	  s2=closure(prod1[0][0],num+1);
	  cout<<s2<<endl;
	  
	  cout<<"\nOther items are :\n"<<endl;
	  s4=item(s2,num+1);
	  cout<<s4<<endl;
	  
}
