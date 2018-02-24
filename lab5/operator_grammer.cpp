/*	Shams Ali
	2015KUCP1034
	Program to check operator grammer and acceptability of any input string.
*/
#include<bits/stdc++.h>
using namespace std;

pair<char,string> x;
map<char, vector<string> > m;
map<pair<char,char>, string> p;

char startsymbol;

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
            os << it -> first << " = \"" << it -> second<<"\"" ;
        }
        return os << "]";
}

int precedence(char c)
{
	switch(c)
	{
		case '$':
			return 0;
		case 'i':
			return 11;
		case '-':
			return 2;
		case '+':
			return 3;
		case '*':
			return 4;
		case '/':
			return 5;
		case '^':
			return 6;
		default:
			return 7;
	}
	
}

int isoperator(char c)
{
	if(c=='+'|| c=='-' ||c=='*'||c=='/'||c=='%'||c=='^'||c=='.')
		return 1;
	else 
		return 0;
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
  
  cout<< "Here, # is considered as NULL\n"<<endl;
  cout << "Input file : "<<endl;
  for(int i=0;i<num;i++)
  {
     cout << prod[i] << endl;
  }
  
  fclose(fp);
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
  
  string temp;
  char cha;
  int status1=0;
  int status2=0;
  
  for(int i=0;i<num;i++)
  {
  		temp=prod[i].substr(3);
  		
  		for(int j=1;j<(int)temp.length();j++)
  		{
  			cha=temp[j];
  			status1=isoperator(cha);
  			j++;
  			if(status1==0)
  			{
  				status2=1;
  				cout<<"\nThis grammer is not an Operator Grammer."<<endl;
	  			fclose(fp);
	  			return 1;
  			}
  		}
  		
  		if( (isupper(temp[i]) && isupper(temp[i+1]) ) || ( (int)temp.length()%2==0 ) )
  		{
  			status2=1;
  			cout<<"\nThis grammer is not an Operator Grammer."<<endl;
  			fclose(fp);
  			return 1;
  		}
  		
  }
  
        if(status2==0)
  		{ 
  			cout<<"\nThis grammer is an Operator Grammer."<<endl;
   		}
  
  string s1;
  int k=0;
  char c1;
  for(int i=0;i<num;i++)
  {
  		temp=prod[i].substr(3);
  		for(int j=0;j<(int)temp.length();j++)
  		{
  			c1=temp[j];
  			if( (c1<=65 || c1>=90) && (find(s1.begin(),s1.end(),temp[j])==s1.end() ) )
  			{
  				s1=s1+temp[j];
  				k++;
  			}
  		}
  }
  s1=s1+"$";
  
  int p1,p2;
  string input;
  fp=freopen("input1.txt","r",stdin);
  cin>>input;
  
  cout<<"\nInput string is : \t"<<input<<"\n"<<endl;
  stack<char> st;
  st.push('$');
  
  char ch1;
  int status=0;
  
  for(int i=0;i<(int)input.length();)
  {
  		if( find(s1.begin(),s1.end(),input[i]) != s1.end() )
  		{
	  		p1=precedence(input[i]);
	  		ch1=st.top();
	  		if(input[i]==ch1 && ch1=='$')
	  		{
	  			cout<<"[ "<<ch1<<", "<<input[i]<<" ] :\t";
	  			cout<<"\n\nInput string accepted\n"<<endl;
	  			status=1;
	  			fclose(fp);
	  			return 1;
	  		}
	  		for(int j=0;j<(int)s1.length();j++)
	  		{
	  			p2=precedence(ch1);
	  			cout<<"[ "<<ch1<<", "<<input[i]<<" ] :\t";
	  			if(p2<=p1)
	  			{
	  				st.push(input[i]);
	  				cout<<"Pushed in stack "<<input[i]<<endl;
	  				i++;
	  				break;
	  			}
	  			else 
	  			{
	  				st.pop();
	  				cout<<"Poped from stack "<<ch1<<endl;
	  				break;
	  			}
	  		}
  		}
  		else
  		{
  			cout<<"\nInvalid input string\n";
  			fclose(fp);
	  		return 1;
  		}
  }
  
  if(status==0)
  {
  		cout<<"\nInput String not accepted\n"<<endl;
  }
    
  fclose(fp);
  
}
