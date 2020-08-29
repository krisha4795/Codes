#include<bits/stdc++.h>
using namespace std;
int getCount(int arr[],int n)
{
    int count=0;
    // cout<<n<<endl;
    for(int i=1;i<n-1;i++)
    {
        if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
        {
            count++;
            i++;
        }
    }
    // cout<<count<<endl;
    return count;
}
int main()
{
    int T;
    cin>>T;
    for(int t=0;t<T;t++)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        cout<<"Case #"<<t+1<<": "<<getCount(arr,n)<<endl;
        
    }
    // cout<<endl;
    return 0;
}