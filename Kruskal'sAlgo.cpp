// Kruskal's Algorithm

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
vector<int > graph[N]; 
int parent[N];
int size[N];

void make(int v){
parent[v] = v;
size[v]= 1;
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
if(size[a]<size[b]) swap(a,b);
parent[b] = a;
size[a] += size[b];    
}    
}


int main(){
int n,k;
cin>>n>>k;
for (int i = 1; i<=n; i++){
make(i);
}


vector<pair<int,pair<int,int> > > vp;
while (k--){
int u,v,wt;
cin>>u>>v>>wt;
vp.push_back({wt,{u,v}});
}

sort(vp.begin(),vp.end());

int total_wt =0;
for (int i = 0; i <k; i++){
int wt = vp[i].first;
int u = vp[i].second.first;
int v = vp[i].second.second;
if(find(u)== find(v)) continue;
Union(u,v);
total_wt += wt;
cout<<u<<" "<<v<<endl;
}

cout<<total_wt<<endl;

    return 0;
}