#include<bits/stdc++.h>

using namespace std;
struct  trie
{	int count=0;
	trie* children[26]={NULL};
	bool EOW=false;
};
void insert(string s,trie* root)
{
	trie* node=root;
	for(int i=0;i<s.size();i++)
	{
		int c=s[i]-'A';
		if(!node->children[c])
		{
			trie* child=new trie();
			node->children[c]=child;
		}
		node=node->children[c];
		node->count++;
		// cout<<s[i]<<" "<<node->count<<endl;

	}
	node->EOW=true;
	return;
}
int findMaxCount(trie* root,int k,int rank)
{
	int p1=0,p2=0;
	int flag=0;
	int total_children=root->count,child=0;
	for(int i=0;i<26;i++)
	{
		trie *node=root->children[i];
		if(!node)continue;
		flag=1;
		char alpha='A'+i;
		int c=node->count;
		child+=node->count;
		// cout<<c<<" fdfd "<<alpha<<endl;
		int c1=(c/k)*(rank+1);
		if(c>=k)	
		{
			p1+=findMaxCount(node,k,rank+1);
		}
		else
		{
			p1+=c1;
		}
		p2+=c%k;
		// cout<<p1<<" "<<p2<<endl;
	}	
	
	// cout<<"flag=="<<flag<<endl;
	int noOfWordsEndAtRoot=total_children-child;
	p2=(p2+noOfWordsEndAtRoot)/k;
	if(flag==0) 
	{
		int sol=rank*((root->count)/k);
		// cout<<root->count<<" "<<k<<" "<<sol<<" "<<rank<<endl;
		return sol;
	}

	// cout<<p1<<" "<<p2*rank<<endl;
	return p1+(p2*rank);
	
}

void solve()
{
	int n,k;
	cin>>n>>k;
	vector<string>strings(n);
		trie* root=new trie();
	for(int i=0;i<n;i++)
	{
		cin>>strings[i];
		insert(strings[i],root);
	}
	root->count=n;
	int answer=0;
	// cout<<"dfss"<<endl;
	answer=findMaxCount(root,k,0);
	cout<<answer<<endl;
	return;


}

int main()
{
	int T;
	cin>>T;
	for(int t=0;t<T;t++)
	{
		cout<<"Case #"<<t+1<<": ";
		solve();
	}
	return 0;
}