/*	Shams Ali
	2015KUCP1034
	Program to check whether a grammer is LL1 or Not .
*/
#include<bits/stdc++.h>
using namespace std;

pair<char,string> x;
map<char, vector<string> > m;
map<char, vector<char> > first;
map<char, vector<char> > follow;
map<pair<char,char>, string> p;

vector<string> v;
vector<char> ve;
vector<char> v1;
char startsymbol;

int count1=0;
template < typename F, typename S >
    ostream& operator << ( ostream& os, const pair< F, S > & p )
    {
        return os << "(" << p.first << ", " << p.second << ")";
}
template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v )
{
    typename vector< T > :: const_iterator it;
    for( it = v.begin(); it != v.end(); it++ )
    {
        os << *it;
    }
    return os;
}
template < typename F, typename S >
    ostream &operator << ( ostream & os, const map< F, S > &v )
    {
        os << "[";
        typename map< F , S >::const_iterator it;
        for( it = v.begin(); it != v.end(); it++ )
        {
            if( it != v.begin() ) os << ", ";
            os << it -> first << " = " << it -> second ;
        }
        return os << "]";
}
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
		count1++;
	}
}

void storefirst(map<char, vector<char> > &ma)
{
	vector<string> f1(count1,"");
	int j=0;
	for(auto it=ma.begin();it!=ma.end();it++)
	{
		
		ve = it->second;
		for(int i=0;i<(int)ve.size();i++)
		{
			f1[j]=f1[j]+ve[i];
			
		}
		
		j++;
	}
	
	
}

void storefollow(map<char, vector<char> > ma)
{
	string f2[count1];
	int j=0;
	for(auto it=ma.begin();it!=ma.end();it++)
	{
		
		ve = it->second;
		for(int i=0;i<(int)ve.size();i++)
		{
			f2[j]=f2[j]+ve[i];
			
		}
		
		j++;
	}
}

vector<char> findfirst(char ch)
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
  
  	return first[ch];
}

vector<char> &findfollow(char ch)
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
     
	return follow[ch];    
}

int main()
{
 
  int num;
  string prod[100];
  
  FILE *fp;
  fp=freopen("ll1.txt","r",stdin);
  
  cin >> num;
  for(int i=0;i<num;i++)
  {
     cin >> prod[i];
  }
  
  cout<< "Here, # is considered as NULL\n"<<endl;
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
 
  vector<char> temp1;
  vector<char> temp2;
  for(auto it=m.begin();it!=m.end();it++)
  {
        temp1=findfirst(it->first);
       	
  }
  
  cout << endl;
  cout << "first of the following productions are : "<<endl;
  show(first);
  
  storefirst(first);
  follow[startsymbol].push_back('$');
  for(auto it=m.begin();it!=m.end();it++)
  {
       	findfollow(it->first);     
  }
  //cout<<findfollow('A');
  cout << endl; 
  cout << "follow of the following productions are : "<<endl;
  show(follow);

  storefollow(follow);
  
  int status1=0;
  string temp3;
  	for(auto it=m.begin();it!=m.end();it++)
	{
		ve=findfirst(it->first);
		v1=findfollow(it->first);
		v=it->second;
		
		for(int i=0;i<(int)v.size();i++)
		{
			for(int j=0;j<num;j++)
			{
				if( v[i]==prod[j].substr(3) && prod[j][0]==it->first && prod[j].substr(3)!="#")
				{
					for(int k=0;k<(int)ve.size();k++)
					{
						if(ve[k]!='#')
						{
							if(p.find(make_pair(it->first,ve[k]))!=p.end())
							{
								status1=1;
								
								p[make_pair(it->first,ve[k])] = prod[j];
								cout<<"Grammer is not LL1"<<endl;
								fclose(fp);
								return 1;
							
							}
							else
							{
								p[make_pair(it->first,ve[k])] = prod[j];
								
							}
						}
						
						else
						{
							for(int b=0;b<(int)v1.size();b++)
							{
								temp3=prod[j+1];
								p[make_pair(it->first,v1[b])] = temp3;
								
							}
							break;
						}
						
					}
				}
				
			}
		}
		
	}
	cout<<"\nParsing Table is : "<<endl;
	cout<<p<<endl;
  if(status1==0)
			cout<<"\nGrammer is LL1"<<endl;
  fclose(fp);
}	
