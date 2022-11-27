#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int > graph[N];
int value[N]; 
int depth[N];
int parent[N];

void dfs( int vertex,int par=0){
// Storing the parent of every node
parent[vertex] = par;

for(auto child : graph[vertex]){    
if(child == par) continue;
depth[child] = depth[vertex]+1;
dfs(child,vertex);}
}
// Storing the Path
vector<int> Path(int vertex){
vector<int> res;
while (parent[vertex] != 0){
res.push_back(vertex);    
vertex = parent[vertex];    
}
reverse(res.begin(),res.end());
return res;  }

int main(){
int n;
cin>>n;
for (int i = 0; i <n-1; i++){
int v1,v2;
cin>>v1>>v2;
// Adjacency List (less space complexity)
graph[v1].push_back(v2);
graph[v2].push_back(v1);
}
 
dfs(1); 
int x,y;
cin>>x>>y;
vector<int> a = Path(x),b = Path(y);

int ans=-1 ;
int mnLen = min(a.size(),b.size());
for (int i = 0; i <mnLen; i++){
if(a[i] == b[i]) ans = a[i];
else break;
}
 
cout<<ans<<endl;




    return 0;
}