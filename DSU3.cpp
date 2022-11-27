// Roads are not in berlin -- Codeforces

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
cin>>n;
for (int i = 1; i<=n; i++){
make(i);
}
k= n-1;

vector<pair<int,int> > vp1,vp2;
while (k--){
int u,v;
cin>>u>>v;
if(find(u)== find(v)){ // extra edge
vp1.push_back({u,v});
}
else Union(u,v);
}


for (int i = 1; i <=n; i++){   
for (int j = i+1; j <= n; j++){
if(find(i)!= find(j)){
Union(i,j) ; // This will create an edge between next connected component    
vp2.push_back({i,j});
} 
}
}

for(auto m1: vp2){
cout<<m1.first<<" "<<m1.second<<endl;    
}


cout<<vp1.size()<<endl;
for (int i = 0; i <vp1.size(); i++){
cout<<vp1[i].first<<" "<<vp1[i].second<<" ";
cout<<vp2[i].first<<" "<<vp2[i].second<<endl;
}



// map<int,int > mp;


// int Ct =0;
// for (int i = 1; i <=n; i++){
// if(find(i)==i) Ct++;
// else{
// if(mp.find(find(i))== mp.end())    
// mp[find(i)] = i;
// }
// }


// cout<<--Ct<<endl;
// int x=1;
// for(auto m1:mp){
// if(x!=1) cout<<m1.second<<endl;
// if(x!=Ct+1)
// cout<<m1.first<<" "<<m1.second<<" "<<m1.second<<" ";
// x++;
// }


    return 0;
}