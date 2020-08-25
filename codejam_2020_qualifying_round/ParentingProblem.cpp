#include<bits/stdc++.h>

using namespace std;

// struct compare{
//   bool operator()(const pair<int,int>&p1,const pair<int,int>&p2)
//   {
//       return p1.first<p2.fist;
//   }
// };

int main()
{
    int T;
    cin>>T;
    for(int t=0;t<T;t++)
    {
        int n;
        cin>>n;
        // vector<int>start(n);
        vector<pair<int,int>>end(n),start(n);
        
        // vector<vector<int>>interval(n,vector<int>(2));
        for(int i=0;i<n;i++)
        {
            cin>>start[i].first>>end[i].first;
        }
        string sol(n,' ');
        int k=2;
        char c='C';
        for(int i=0;i<n;i++)
        {
            start[i].second=i;
            end[i].second=i;
        }
        sort(end.begin(),end.end());
        sort(start.begin(),start.end());
        int i=0,j=0,flag=0;
        while(i<n && j<n )
        {
            if(start[i].first<end[j].first)
            {
                if(k<=0)
            {
                sol="IMPOSSIBLE";
                break;
            }
                k--;
                int p=start[i].second;
                if(k==1) sol[p]='C';
                else 
                {
                    if(flag==0)
                    {
                        sol[p]='J';
                        flag=1;
                        
                    }
                    else sol[p]=c;
                }
                i++;
            }
            else
            {
                int p=end[j].second;
                c=sol[p];
                k++;
                j++;
            }
        }
        cout<<"Case #"<<t+1<<": "<<sol<<endl;
        
        
        
    }
    return 0;
}