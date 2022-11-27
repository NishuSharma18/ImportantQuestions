#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int > graph[N];
int value[N]; 
int depth[N];

void dfs( int vertex,int par=0){

for(auto child : graph[vertex]){    
if(child == par) continue;
depth[child] = depth[vertex]+1;
dfs(child,vertex);

}
}

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
// Finding max depth and mac depth node:
int maxDepth =-1, maxNode;
for (int i = 1; i <=n; i++){
if(depth[i] > maxDepth){
maxDepth = depth[i];
maxNode = i;}
// reset the  depth array 
depth[i] =0;
}
 
dfs(maxNode);
maxDepth = -1;
// finding diameter
for (int i = 1; i <=n; i++){
if(depth[i] > maxDepth) maxDepth = depth[i];
}

cout<<"Diameter of the Tree is "<<maxDepth<<" units.\n";


    return 0;
}