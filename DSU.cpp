#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
vector<int > graph[N]; 
int parent[N];
int sz[N];

void make(int v){
parent[v] = v;
sz[v]= 1;
}
  
int find(int v){
if(parent[v]==v) return v;
// return find(parent[v]); 
//Path compression optimization
return parent[v] =find(parent[v]); 
}  

void Union(int a,int b){
a = find(a);    
b = find(b);
if(a!=b){
if(sz[a]<sz[b]) swap(a,b);
parent[b] = a;
sz[a] += sz[b];    
}    
}


int main(){
int n,k;
cin>>n>>k;
for (int i = 1; i<=n; i++){
make(i);
}
 
while (k--){
int u,v;
cin>>u>>v;
Union(u,v);
}

int ConnectedComponents =0;
for (int i = 1; i <=n; i++){
if(find(i)==i) ConnectedComponents++;
}
 
cout<<ConnectedComponents<<endl;

    return 0;
}