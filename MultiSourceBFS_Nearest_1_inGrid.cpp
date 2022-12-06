#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
 
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
 

// MUltiSourceBFS
// Distance of nearest cell having 1


vector<int> dx = {-1,0,0,1};
vector<int> dy = {0,-1,1,0};

bool isValid(int i,int j,int n,int m){
  if(i>=0 && i<n && j>=0 && j<m)
  return true;
return false;  
}

vector<vector<int>>nearest(vector<vector<int>>grid){
int n = grid.size();
int m = grid[0].size();

queue<vector<int> > q;  // {row,col,distance};
vector<vector<bool> > vis(n,vector<bool>(m,false));

for (int i = 0; i <n; i++){
  for (int j = 0; j <m; j++){
   if(grid[i][j]==1){
   q.push({i,j,0}); 
   vis[i][j]= true;
   }
  }
}

vector<vector<int> > res(n,vector<int>(m,0));

while (!q.empty()){
  vector<int> v = q.front();
  q.pop();
  int curr_x = v[0];
  int curr_y = v[1];
  int dis = v[2];
  res[curr_x][curr_y] = dis;

for (int i = 0; i <4; i++){
  int x = curr_x + dx[i];
  int y = curr_y + dy[i];
  
  if(isValid(x,y,n,m)){
    if(!vis[x][y]){
      vis[x][y] =1;
     q.push({x,y,dis+1});
    }
  }
}


}

return res;
}


 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
 


 
 
 
	    
	    
	
}