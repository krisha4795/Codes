#include<bits/stdc++.h>

using namespace std;


void solve()
{
	string path;
	cin>>path;
	int n=path.size();
	stack<char>stk;
	for(int i=0;i<n;i++)
	{
		if(path[i]==')')
		{

			int l=0,r=0,u=0,d=0;
			while(!stk.empty() && stk.top()!='(')
			{
				char c=stk.top();
				if(c=='E')
				{
					r++;
				}
				else if(c=='W')
				{
					l++;
				}
				else if(c=='N')
				{
					d++;
				}
				else if(c=='S')
				{
					u++;
				}
				stk.pop();
			}
			stk.pop();
			if(!stk.empty())
			{
				int repeat=stk.top()-'0';
				r*=repeat;
				l*=repeat;
				stk.pop();
			}
			while(l--)
			{
				stk.push('W');
			}
			while(r--)
			{
				stk.push('E');
			}
			while(u--)
			{
				stk.push('S');
			}
			while(d--)
			{
				stk.push('N');
			}

		}
		else stk.push(path[i]);
	}

	int x=1,y=1;
	while(!stk.empty())
	{
			cout<<x<<""<<y<<endl;
		char c=stk.top();
		if(c=='W')
		{
			if(x==1) x=pow(10,9);
			else x--;
		}
		else if(c=='E')
		{
			if(x==pow(10,9)) x=1;
			else x++;
		}
		else if(c=='S')
		{
			if(y==pow(10,9)) y=1;
			else y++;
		}
		else if(c=='N')
		{
			if(y==1) y=pow(10,9);
			else y--;
		}
		stk.pop();
	}
	cout<<x<<" "<<y<<endl;
	return ;
}

int main()
{
	int T,t;
	cin>>T;
	for(t=0;t<T;t++)
	{
		cout<<"Case #"<<t+1<<": ";
		solve();
	}
	return 0;
}