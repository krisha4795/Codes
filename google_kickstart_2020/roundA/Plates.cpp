#include<bits/stdc++.h>

using namespace std;
void solve()
{
	int n,k,p;
	cin>>n>>k>>p;
	vector<vector<int>>stacks(n,vector<int>(k+1));
	// vector<vector<int>>
	for(int i=0;i<n;i++)
	{
		int x=0;
		stacks[i][0]=0;
		for(int j=1;j<=k;j++)
		{
			int y;
			cin>>y;
			stacks[i][j]=x+y;
			x=stacks[i][j];
		}
	}	

	// int dp[n+1][p+1];
	std::vector<vector<int>> dp(n+1,vector<int>(p+1,0));
	// memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=p;j++)
		{
			for(int v=0;v<=k && v<=j;v++)
			{
				dp[i][j]=max(dp[i][j],dp[i-1][j-v]+stacks[i-1][v]);
			}
			// cout<<dp[i][j]<<endl;
		}
	}
	cout<<dp[n][p]<<endl;
	return ;

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
	