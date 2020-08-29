#include<bits/stdc++.h>

using namespace std;
void findPossibleDiagonals(std::vector<vector<int>>&diagonals,vector<int>&row,int n,int trace,int index,int sum )
{
	if(sum>trace) return;
	if(index==n)
	{
		if(sum==trace)
		{
			diagonals.push_back(row);
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		row[index]=i;
		findPossibleDiagonals(diagonals,row,n,trace,index+1,sum+i);
	}
	return;
}
// bool find(vector<vector<int>>&matrix,int&row,int & col)
// {
// 	int n=matrix.size();
// 	for(int i=0;i<n;i++)
// 	{
// 		for(int j=0;j<n;j++)
// 		{
// 			if(matrix[i][j]==0) 
// 			{
// 				row=i;
// 				col=j;
// 				return false;
// 			}
// 		}
// 	}
// }
bool isRow(vector<vector<int>>&matrix,int row,int val)
{
	for(int i=0;i<matrix.size();i++)
	{
		if(matrix[row][i]==val) return false;
	}
	return true;
}
bool isCol(vector<vector<int>>&matrix,int col,int val)
{
	for(int i=0;i<matrix.size();i++)
	{
		if(matrix[i][col]==val) return false;
	}
	return true;
}
bool isPossible(vector<vector<int>>&matrix,int row,int col)
{
	// int row,col;
		// cout<<row<<" "<<col<<endl;

	if(row>=matrix.size()) return true;
	if(col>=matrix.size()) return isPossible(matrix,row+1,0);
	if(matrix[row][col]==0)
	{
		for(int v=1;v<=matrix.size();v++)
		{
			if(isRow(matrix,row,v) && isCol(matrix,col,v))
			{
				matrix[row][col]=v;
				if(isPossible(matrix,row,col+1)) return true;
				matrix[row][col]=0;
			}
		}
	}
	else
	{
		if(isPossible(matrix,row,col+1)) return true;
	}
	return false;

}
void printR(vector<vector<int>>&v)
{
	for(int i=0;i<v.size();i++)
	{
		for(int j=0;j<v.size();j++)
		{
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
}
void solve()
{
	int trace,n;
	cin>>n>>trace;
	// cout<<n<<" "<<trace<<endl;
	vector<vector<int>>diagonals;
	vector<int>row(n);
	vector<vector<int>>matrix(n,vector<int>(n,0));
	findPossibleDiagonals(diagonals,row,n,trace,0,0);
	for(int i=0;i<diagonals.size();i++)
	{
		for(int j=0;j<n;j++)
		{
			// cout<<"yes"<<endl;
			matrix[j][j]=diagonals[i][j];
			// cout<<matrix[j][j]<<" ";
		}
		// cout<<endl;
			if(isPossible(matrix,0,0))
			{
				cout<<"POSSIBLE"<<endl;
				printR(matrix);
				return;
			}
		
	}
	cout<<"IMPOSSIBLE"<<endl;
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