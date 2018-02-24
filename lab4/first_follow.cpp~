/*	Shams Ali
	2015KUCP1034
	Implementing first and follow .
*/
#include<bits/stdc++.h>
using namespace std;

pair<char,string> x;
map<char, vector<string> > m;
map<char, vector<char> > first;
map<char, vector<char> > follow;

vector<string> v;
vector<char> ve;
char startsymbol;

void show(map<char, vector<char> > ma)
{
	for(auto it=ma.begin();it!=ma.end();it++)
	{
		char c = it->first;
		cout<<c<<" : { ";
		ve = it->second;
		for(int i=0;i<(int)ve.size();i++)
		{
			if(i!=0)
			{
				cout<<" , ";
			}
			cout<<ve[i];
		}
		cout<<" }"<<endl;
	}
}

void findfirst(char ch)
{
	 vector<string> v;
	 vector<char> ve;
       v = m[ch] ;
       int flag=0;
       
       for(int i=0;i<(int)v.size();i++)
       {
         
         int count=0;
         for(int j=0;j<(int)v[i].length();j++)
         {
               flag=0;
               
		   if(v[i][j]>90 || v[i][j]<65)
		   {
		      
		      if(find(first[ch].begin(),first[ch].end(),v[i][j])==first[ch].end())
		      {
		         first[ch].push_back(v[i][j]);
		      }
		      break;
		   }
		   else
		   {
		      findfirst(v[i][j]);
		     
		      ve = first[v[i][j]];
		      
		      for(int l=0;l<(int)ve.size();l++)
		      {
		         
		           if(ve[l]=='#')
		           {
		              flag=1;
		              count++;
		           }
		           else if(find(first[ch].begin(),first[ch].end(),ve[l])==first[ch].end())
				   {
				   		first[ch].push_back(ve[l]);
				   }
		        
		      }
		      if(flag==0)
		      {
		        break;
		      }
		   
		       
		   }
		  
	   }
	   if(count==(int)v[i].length())
	   {
	     first[ch].push_back('#');
	   }
	    
       }
  
}

void findfollow(char ch)
{
	 vector<string> v;
	 vector<char> ve;
       v = m[ch] ;
             
       for(int i=0;i<(int)v.size();i++)
       {
         
         for(int j=0;j<(int)v[i].length();j++)
         {
               int flag = 0;
               int count;
               if(v[i][j]>90 || v[i][j]<65)
               {
                 
               }
               else
               {   
                   count = 0;
                   for(int k=j+1;k<(int)v[i].length();k++)
                   {
		                 flag = 0;
		                 
		                 if(v[i][k]>90 || v[i][k]<65)
				     	 {
				       		 follow[v[i][j]].push_back(v[i][k]);
				     	 }
		                 else
		                 {
						       ve = first[v[i][k]];
						       for(int l=0;l<(int)ve.size();l++)
						       {
								     if(ve[l]=='#')
								     {
								       flag=1;
								       count++;
								     }
								     else if(find(follow[v[i][j]].begin(),follow[v[i][j]].end(),ve[l])==follow[v[i][j]].end())
									 {
								   	 	follow[v[i][j]].push_back(ve[l]);
									 }
							 
							   }
								if(flag==0)
								{
								  break;
								}
		        		 }
		       	   }
				   if(count==(int)v[i].length()-(j+1))
				   {
						ve = follow[ch];
						for(int s=0;s<(int)ve.size();s++)
						{
							if(find(follow[v[i][j]].begin(),follow[v[i][j]].end(),ve[s])==follow[v[i][j]].end())
							{
							   follow[v[i][j]].push_back(ve[s]);
							}
						}
			   		}
               }
                   
       	}
     }   
	    
}

int main()
{
 
  int num;
  string prod[100];
  
  FILE *fp;
  fp=freopen("input.txt","r",stdin);
  
  cin >> num;
  for(int i=0;i<num;i++)
  {
     cin >> prod[i];
  }
  
  cout<< "Here, $ is considered as NULL\n"<<endl;
  cout << "Input file : "<<endl;
  for(int i=0;i<num;i++)
  {
     cout << prod[i] << endl;
  }
  
  int count =0;
  for(int i=0;i<num;i++)
  {
		if(count==0)
		{
			  startsymbol=prod[i][0];
			  count++;
		}
		x.first = prod[i][0];
		x.second = prod[i].substr(3);
		m[x.first].push_back(x.second);
  }
 
  
  for(auto it=m.begin();it!=m.end();it++)
  {
        findfirst(it->first);
  }
  
  cout << endl;
  cout << "first of the following productions are : "<<endl;
  show(first);
  
  follow[startsymbol].push_back('$');
  
  for(auto it=m.begin();it!=m.end();it++)
  {
        findfollow(it->first);
  }
  
  cout << endl; 
  cout << "follow of the following productions are : "<<endl;
  show(follow);
  
  fclose(fp);
}
