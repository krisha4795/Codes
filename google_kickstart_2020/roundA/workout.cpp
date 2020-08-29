#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n,k;	
	cin>>n>>k;
	vector<int>time(n);
	for(int i=0;i<n;i++)
	{
		cin>>time[i];
	}
	vector<int>interval;
	int diff=1;
	for(int i=1;i<n;i++)
	{
		interval.push_back(time[i]-time[i-1]-1);
		diff=max(diff,interval[i-1]+1);
	}
	int start=1,end=diff;
	// int k=0;
	int max_diff=diff;
	while(start<=end)
	{
		int mid=(start+end)/2,count=0;
		// cout<<mid<<endl;
		for(int i=0;i<interval.size();i++)
		{
			count+=interval[i]/mid;
		}
		if(start==end || start==end+1)
		{
			if(count<=k ) max_diff=mid;
			break;	
		}
		if(count>k)
		{
			start=mid+1;
		}
		else

		{
			max_diff=mid;
			end=mid;
			
		}
		// cout<<start<<" "<<end<<" "<<k<<endl;
	}
	cout<<max_diff<<endl;
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
