#include<bits/stdc++.h>

using namespace std;

bool isRow(vector<vector<int>>array,int row)
{
    unordered_map<int,bool>umap;
    for(int i=0;i<array.size();i++)
    {
        if(umap.find(array[row][i])!=umap.end()) return 1;
        umap[array[row][i]]=true;
    }
    return 0;
}
bool isCol(vector<vector<int>>array,int col)
{
    unordered_map<int,bool>umap;
    for(int i=0;i<array.size();i++)
    {
        if(umap.find(array[i][col])!=umap.end()) return 1;
        umap[array[i][col]]=true;
    }
    return false;
}
int main()
{
    int T;
    cin>>T;
    for(int t=0;t<T;t++)
    {
        int n;
        cin>>n;
        vector<vector<int>>array(n,vector<int>(n));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>array[i][j];
            }
        }
        int trace=0,row=0,col=0;
        for(int i=0;i<n;i++)trace+=array[i][i];
        for(int i=0;i<n;i++)
        {
            if(isRow(array,i)) row++;
            if(isCol(array,i)) col++;
        }
        cout<< "Case #"<<t+1<<": "<<trace<<" "<<row<<" "<<col<<endl;
    }
    return 0;
}