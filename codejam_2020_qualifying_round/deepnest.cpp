#include<bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin>>T;
    for(int t=0;t<T;t++)
    {
        string s;
        cin>>s;
        int n=s.size();
        string ans="";
        int count=0;
        for(int i=0;i<n;i++)
        {
            int c=s[i]-'0';
            while(count<c)
            {
                ans+='(';
                count++;
            }
            while(count>c)
            {
                ans+=')';
                count--;
            }
            ans+=s[i];
        }
        while(count>0)
        {
            ans+=')';
            count--;
        }
        cout<<"Case #"<<t+1<<": "<<ans<<endl;
    }
    return 0;
    
}