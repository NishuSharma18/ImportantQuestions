#include<bits/stdc++.h>
using namespace std;

// const int n=1e4,m=1e4;
const int n=5,m=4;
int grid[n][m];
int dp[n][m];

int func(int i,int j){
if(i>=n || j>=m) return 1e7;
// if(i==0 && j==0) return grid[0][0];    
if(i==n-1 && j==m-1) return grid[0][0];    
if(dp[i][j]!= -1) return dp[i][j]; 
int ans = min(grid[i][j] + func(i+1,j),grid[i][j] + func(i,j+1));
// int ans = min(grid[i][j] + func(i-1,j),grid[i][j] + func(i,j-1));
return dp[i][j] = ans;
}


int main(){
memset(dp,-1,sizeof(dp));



int n,m;
cin>>n>>m;
for (int i = 0; i <n; i++){
for (int j = 0; j <m; j++){
cin>>grid[i][j];
}
}


// cout<<func(n-1,m-1)<<endl;
cout<<func(0,0)<<endl;

    return 0;
}