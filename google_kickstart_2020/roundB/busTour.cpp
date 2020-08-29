#include<bits/stdc++.h>

using namespace std;
 
void solve()
{
	int n,D;
	cin>>n>>D;
	vector<int>dates(n);
	for(int i=0;i<n;i++)
	{
		cin>>dates[i];
	}
	for(int i=n-1;i>=0;i--)
	{
		int c=D/dates[i];
		int mod=D%dates[i];
		if(c<1) 
		{
			D=-1;
			cout<<D<<endl;
			return;	
		}
		D-=mod;
	}
	cout<<D<<endl;
	return;
}

int main()
{
	int T;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		cout<<"Case #"<<i+1<<": ";
		solve();
	}
	return 0;
}