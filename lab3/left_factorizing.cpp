/*	Shams Ali
	2015KUCP1034
	Converting non deterministic to deterministic using left factorising method.
*/
#include<bits/stdc++.h>
using namespace std;

int newVariables = 1;

struct trie
{
  bool isLeaf;
  struct trie* Children[256];
};

struct trie* newNode()
{
    struct trie *t = (struct trie *)malloc(sizeof(struct trie));
    t->isLeaf = false;
    for(int i=0;i<256;i++) t->Children[i] = NULL;
    return t;
}

void insertIntoTrie(struct trie* root,string s)
{
    if(s == "") return;
    int length = s.length();
    int index = 0;
    struct trie *t = root;
    for(int i=0;i<length;i++)
    {
        index = s[i];
        if(t->Children[index] == NULL)
        {
            t->Children[index] = newNode();
        }
        t = t->Children[index];
    }
    t->isLeaf = true;
}

string getString(int a)
{
    string temp = "";
    temp = temp + (char)(a);
    return temp;
}

string integerToString(int a)
{
    string temp = "";
    while(a)
    {
        temp = temp + (char)(a%10 + 48);
        a/=10;
    }
    if(temp == "") temp = "0";
    return temp;
}

string applyLeftFactoring(struct trie *root,vector<string> &productions,string value)
{
    vector<string> branchProductions;
    for(int i=0;i<256;i++)
    {
        if(root->Children[i] != NULL)
        {
            string temp = applyLeftFactoring(root->Children[i],productions,getString(i));
            if(temp != "") branchProductions.push_back(temp);
        }
    }
    if(branchProductions.size() == 0)return value;
    else if(branchProductions.size() == 1 && !root->isLeaf) return value + branchProductions[0];
    else
    {
        string LHS = "[A" + integerToString(newVariables) + "]\t:\t",RHS = "";
        int i=0;
        for(i=0;i<(int)branchProductions.size()-1;i++) RHS += branchProductions[i]+" | ";
        RHS += branchProductions[i] + (root->isLeaf ? " | \356" : "");
        if(value == "") return RHS;
        else
        {
            string newProduction = LHS + RHS;
            productions.push_back(newProduction);
            return value + "[A" + integerToString(newVariables++) + "]";
        }
    }
}

int main()
{
    ifstream in;
    in.open("input.txt");
    int numberofproductions = 0;
    in>>numberofproductions;
   
    while(numberofproductions--)
    {
     
        string inputproduction;
        in>>inputproduction;
        cout<<"Production Rules before Left Factoring : \n"<<inputproduction<<"\n";
        struct trie *root = newNode();
        string left,right;
        int position = 0;
        position = inputproduction.find(":");
        left = inputproduction.substr(0, position);
        right = inputproduction.substr(position+1);
        position = right.find("|");
        string temp;
        while(position != -1)
        {
            temp = right.substr(0,position);
            right = right.substr(position+1);
            insertIntoTrie(root,temp);
            position = right.find("|");
        }
        insertIntoTrie(root,right);

        newVariables = 1;
        vector<string> productions;
        productions.push_back(left + "\t:\t" + applyLeftFactoring(root,productions,""));

        cout<<"Production Rules after Left Factoring :"<<endl;
        int size = productions.size();
        for(int i=size-1;i >= 0;i--) cout<<productions[i]<<endl;
        
    }
    in.close();
    return 0;
}
