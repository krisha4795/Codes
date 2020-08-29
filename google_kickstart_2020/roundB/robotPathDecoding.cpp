#include<bits/stdc++.h>

using namespace std;


void solve()
{
	string path;
	cin>>path;
	int n=path.size();
	long long int m=pow(10,9);
	stack<string>stk;
	for(int i=0;i<n;i++)
	{
		string temp="";
		temp+=path[i];
		if(temp==")")
		{

			long long int l=0,r=0,u=0,d=0;
			while(!stk.empty() && stk.top()!="(")
			{
				string c=stk.top();
				// cout<<c<<endl;
				if(c=="E")
				{
					r++;
				}
				else if(c=="W")
				{
					r--;
				}
				else if(c=="N")
				{
					u--;
				}
				else if(c=="S")
				{
					u++;
				}
				else
				{
					u=(u+stoll(stk.top()))%m;
					stk.pop();
					r=(r+stoll(stk.top()))%m;
					// stk.pop();

				}
				stk.pop();
			}
			stk.pop();
			long long int repeat=1;
			if(!stk.empty())
			{
				repeat=stoll(stk.top());
				stk.pop();
			}
			r*=repeat;
			u*=repeat;
			// cout<<r<<" repeat"<<u<<endl;
			stk.push(to_string(r));
			stk.push(to_string(u));

		}
		else 
			{
				
				stk.push(temp);
			}
	}
	// cout<<"yes1"<<endl;
	long long int u=0,r=0;
	while(!stk.empty())
	{
		string c=stk.top();
		if(c=="W")
		{
			r--;
		}
		else if(c=="E")
		{
			r++;
		}
		else if(c=="N")
		{
			u--;
		}
		else if(c=="S")
		{
			u++;
		}
		else
		{
			u=(u+stoll(stk.top()))%m;
			stk.pop();
			r=(r+stoll(stk.top()))%m;
			// stk.pop();
		}
		stk.pop();	
		// cout<<r<<" "<<u<<endl;

	}

	int x=1,y=1;
		// cout<<"yes2"<<endl;

	// int u=stoi(stk.top());
	// stk.pop();
	// int r=stoi(stk.top());
		// cout<<u<<" "<<r<<endl;
	if(r>0)x+=r;
	else if(r<0)
	{
		x=pow(10,9);
		x+=r+1;
	}
	if(u>0)y+=u;
	else if(u<0)
	{
		y=pow(10,9);
		y+=u+1;
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