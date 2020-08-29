#include<bits/stdc++.h>

using namespace std;
void solve()
{
	int budget,n;
	cin>>n>>budget;
	vector<int>price(n);
	for(int i=0;i<n;i++)
	{
		cin>>price[i];
	}
	int ans=0,local=0,cost=0;
	sort(price.begin(),price.end());
	for(int i=0;i<n;i++)
	{
		if(budget<price[i])
		{
			break;
		} 
		budget-=price[i];
		ans++;
	}
	cout<<ans<<endl;
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
	