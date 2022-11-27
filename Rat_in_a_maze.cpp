#include<bits/stdc++.h>
using namespace std;

void solve(int i,int j,vector<vector<int>> &a,int n,vector<string>&ans ,string res,vector<vector<int>> &vis){
if(i==n-1 && j==n-1){
    ans.push_back(res);
    return;
}
// Downward ::
// (position is not crossed the matrix) &&
// (position is not visited) && (position not contain 0)
if(i+1<n && !vis[i+1][j] && a[i+1][j]==1){
 vis[i][j] =1;   // previous position marked to be visited
 solve(i+1,j,a,n,ans,res +'D',vis);
 vis[i][j] = 0;   // <-- BACKTRACKING STEP
}

// Left
if(j-1>=0 && !vis[i][j-1] && a[i][j-1]==1){
 vis[i][j] =1;   // previous position marked to be visited
 solve(i,j-1,a,n,ans,res +'L',vis);
 vis[i][j] = 0;   // <-- BACKTRACKING STEP
}

// Right
if(j+1<n && !vis[i][j+1] && a[i][j+1]==1){
 vis[i][j] =1;   // previous position marked to be visited
 solve(i,j+1,a,n,ans,res +'R',vis);
 vis[i][j] = 0;   // <-- BACKTRACKING STEP
}

// Upward
if(i-1>=0 && !vis[i-1][j] && a[i-1][j]==1){
 vis[i][j] =1;   // previous position marked to be visited
 solve(i-1,j,a,n,ans,res +'U',vis);
 vis[i][j] = 0;   // <-- BACKTRACKING STEP
}

}

int main(){   
vector<vector<int>> maze{
    //  {1,0,0,0},   
    //  {1,1,0,1},   
    //  {1,1,0,0},   
    //  {0,1,1,1},    
     {1,0,0,0,1,1,1,1},   
     {1,1,0,1,1,0,0,1},   
     {1,1,0,0,1,1,0,1},   
     {0,1,1,1,1,1,1,1},    
    };
vector<vector<int>> vis{
    //  {0,0,0,0},   
    //  {0,0,0,0},   
    //  {0,0,0,0},   
    //  {0,0,0,0},    
     {0,0,0,0,0,0,0,0},   
     {0,0,0,0,0,0,0,0},   
     {0,0,0,0,0,0,0,0},   
     {0,0,0,0,0,0,0,0},    
    };
vector<string> ansr;
solve(0,0,maze,4,ansr,"",vis);

sort(ansr.begin(),ansr.end());

// Printing the output
for(auto it: ansr){
    cout<<it<<endl;
}    
    return 0;
}