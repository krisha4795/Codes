#include<bits/stdc++.h>

using namespace std;


void solve()
{
	int W,H,L,U,R,D;
			// cout<<"yes1"<<endl;

	cin>>W>>H>>L>>U>>R>>D;

	// vector<vector<double>>dp(W,vector<double>(H,0));
	float	 dp[W][H];
	for(int i=0;i<W;i++)
	{
		for(int j=0;j<H;j++) dp[i][j]=(double)0;
	}
	// // memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	float ans=0;
	if(W==L && H==U)
	{
		cout<<ans<<endl;
		return;
	}
	if(R==W && H==D)
	{
		cout<<ans<<endl;
	 return ;
	}
	for(int i=1;i<W;i++)
	{
		if(i+1>=L && i+1<=R && 0>=U-1  && 0<=D-1)continue;
		dp[i][0]=dp[i-1][0]/2;
								// cout<<dp[i][1]<<" "<<i<<" "<<1<<endl;
	}
	// cout<<endl;
	for(int i=1;i<H;i++)
	{
		if(1>=L && 1<=R && i+1>=U  &&i+1<=D)continue;
		dp[0][i]=dp[0][i-1]/2;
								// cout<<dp[1][i]<<" "<<1<<" "<<i<<endl;
	}
	// cout<<endl;
	// cout<<"yes2"<<endl;
	for(int i=1;i<W;i++)
	{
		for(int j=1;j<H;j++)
		{
			if(i+1>=L && i+1<=R && j+1>=U  &&j+1<=D)
				{
								// cout<<dp[i][j]<<" "<<i<<" "<<j<<endl;

					continue;
				}
			float p1=j<H-1?0.5:1;
			float p2=i<W-1?0.5:1;
			dp[i][j]+=(dp[i-1][j]*p1)+(dp[i][j-1]*p2);
			// cout<<p2<<" "<<p1<<endl;
			// cout<<dp[i][j]<<" "<<i<<" "<<j<<endl;
		}
		// cout<<" dsddf "<<dp[i][H]<<endl;

	}
	// cout<<"yes3"<<endl;
	 ans=dp[W-1][H-1];
	// ans= ans-dp[R][D];
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