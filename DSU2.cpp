#include<bits/stdc++.h>
using namespace std;
int mod = 1000000007;
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
// Path compression optimization
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
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
int t=1,t_case=1;
cin>>t;
while (t--){
int n;
cin>>n;

for (int i = 1; i<=n; i++){
make(i);
}

set<int> comp_maxes;
for (int i = 1; i < n+1; ++i) {
    int p;
    cin >> p;  
auto it = comp_maxes.lower_bound(p);
int val = *it;
if (it == comp_maxes.end()) {
comp_maxes.insert(p);
}

else {
int mx;
while (it != comp_maxes.end()) {            
mx = *it;
Union(p, mx);
comp_maxes.erase(it);
it = comp_maxes.lower_bound(p);
}
comp_maxes.insert(mx);
}

}



int ConnectedComponents =0;
for (int i = 1; i <=n; i++){
if(find(i)==i) ConnectedComponents++;
}
 
cout<<ConnectedComponents<<endl;



}
return 0;
}

