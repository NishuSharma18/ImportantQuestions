#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
const long long vl = 1e14;
vector<pair<int,int>> graph[N];  // weighted graph

vector<int> parent(N,-1);



//-->>
vector<long long> Dijkstra(int source){
vector<long long> dis(N,vl);  
vector<int> visited(N,0);  
set<pair<int,int> > st;

st.insert({0,source});
dis[source] =0;


while (st.size()>0){
auto it = st.begin();
int node = it->second;
int d = it->first;
st.erase(it);

// if(visited[node]==1) continue;  //-- this also works fine
// visited[node] =1;                  
if(d> dis[node]) continue; 

for(auto c : graph[node]){
int child = c.first;
long long wt = c.second;
if(wt+ dis[node] < dis[child]){
dis[child] = wt + dis[node];
parent[child] = node;
st.insert({dis[child],child});    
}
}

}

return dis;
}
  


int main(){
int n,k;
cin>>n>>k;

for (int i = 0; i <k; i++){
int u,v,wt;
cin>>u>>v>>wt;
graph[u].push_back({v,wt});
graph[v].push_back({u,wt}); 
}
 
// vector<int> shortestpath = Dijkstra(1);
// for (int i = 1; i <=n; i++){
// cout<<i<<"-->> "<<shortestpath[i]<<endl;    
// }


vector<long long> shortestpath = Dijkstra(1);

if(shortestpath[n]== vl) cout<<-1<<endl; // No path exist

else{
vector<long long> res;
res.push_back(n);
long long x=n;
while(x>1){
x = parent[x];
res.push_back(x);
}
reverse(res.begin(),res.end());


for(auto s: res){
cout<<s<<" ";    
}
cout<<endl;
}

    return 0;
}