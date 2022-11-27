// Minimum Spanning Tree -->>
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

void minEdge(){


}





int main(){
int n,k;
cin>>n>>k;
vector<pair<int,int> > adj[n];

int u,v,wt;
while (k--){
  cin>>u>>v>>wt;
  adj[u].push_back({v,wt});  
  adj[v].push_back({u,wt});  
}

// Three Vectors -->>
vector<bool> tree(n,false);
vector<int > parent(n),key(n,INT_MAX);

key[0] =0;
parent[0] = -1;

for (int i = 0; i <n-1; i++){
int mini = INT_MAX,u;

for(int v =0;v<n;v++){
   if(!tree[v] && key[v]< mini)
   mini = key[v],u=v;
}
  tree[u] = true;    


}



    return 0;
}