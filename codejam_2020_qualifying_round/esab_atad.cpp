#include<bits/stdc++.h>

using namespace std;

int B;
int query(int i)
{
	cout<<i<<endl;
	int c;
	cin>>c;
	// scanf("%d",&c);
	return c;
}

// string printR(std::vector<int> &v,int b)
// {
// 	for(int i=1;i<v.size();i++)
// 	{
// 		cout<<v[i];
// 	}
// 	cout<<endl;
// 	string s;
// 	cin>>s;
// 	return s;
// }
// void reverseR(vector<int>&A,int B,int L)
// {
// 	for(int i=1
// 	return;
// }

void flip(vector<int>&A,int B,int L,int R)
{
	for(int i=1;i<=L;i++)
	{
		A[i]^=1;
	}
	for(int i=B;i>=R;i--)
	{
		A[i]^=1;
	}
	return;
}
void t_solve()
{
	vector<int>ans(B+1);
	int L=1,R=B;
	for(int r=1	;true;r+=2)
	{
		int same=-1;
		int diff=-1;
		if (r!=1 && r%10==1)
		{
			for(int l=1;l<L;l++)
			{
				if(ans[l]==ans[B+1-l])
				{
					same=l;
				}
				else
				{
					diff=l;
				}
			}

			int a,b;
			if(same!=-1)
				a=query(same);
			else query(1);
			if(diff!=-1)
				b=query(diff);
			else query(1);
			if(same!=-1 )
			{
				if ( a!=ans[same])
				{
					flip(ans,B,L,R);
					// reverseR(ans,B,L);
				}

				if( b!= ans[diff])
				{
					reverse(ans.begin()+1,ans.end());
					// reverseR(ans,B,L);
					// flip(ans,B,L);
				}
			}
			else 
			{
				if(b!=ans[diff])
				flip(ans,B,L,R);
			}	
			r+=2;
		}
		ans[L]=query(L);
		ans[R]=query(R);
		L++;
		R--;
		if(L>R)
		{
			// string response;
			// response=printR(ans,B);
			for(int i=1;i<=B;i++)
			{
				cout<<ans[i];
			}
			cout<<endl;
			string response;
			cin>>response;
			assert(response=="Y");
			 return;
		}
		

	}
	return;
}
int main()
{
	int T;
	cin>>T>>B;
	// scanf("%d%d",&T,&B);
	for(int t=0;t<T;t++)
	{
		// cout<<t<<endl;
		t_solve();
	}
	return 0;
}