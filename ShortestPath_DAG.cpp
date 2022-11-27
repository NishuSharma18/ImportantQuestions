#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define iv(v) for(auto & v1:v) cin>>v1
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define removeDuplicate(v) v.erase(unique(all(v)),v.end())
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define fr(i,n) for(int i=0;i<n;i++)
#define stBit(n,i) (n|(1<<i))
#define unstBit(n,i) ((~(1<<i)) &n)
#define bs(v,x) binary_search(all(v),x)
#define sumv(v) accumulate(all(v),0)
#define f first
#define s second
#define Fr(i,a,b) for(int i=a; (a<b)?i<b:i>=b ; (a<b)? i++:i--)
#define travrs(m,it) for(auto it =m.begin();it!=m.end();it++)
#define mx(v) *max_element(all(v))
#define mn(v) *min_element(all(v))
#define Mod 1000000007
#define pb push_back
#define mp make_pair
#define PI 3.1415926535897932384626
using namespace std;
using namespace __gnu_pbds;

// SHORTEST PATH IN DIRECTED ACYCLIC GRAPH


const int Inf = 1e9;

// gives a stack of toposorted nodes
void findTopoSort(int node,vector<int>&vis,stack<int>& st,vector<vector<pair<int,int> > >&adj){
    vis[node]= 1;
    for(auto c: adj[node]){
        if(!vis[c.first]){
            findTopoSort(c.first,vis,st,adj);
        }
    }
st.push(node);    
}

void ShortestPath(int source,int n,vector<vector<pair<int,int> > >&adj){
    vector<int>vis(n,0);
    stack<int> st;

    // for all nodes that are not visited
    for (int i = 0; i <n; i++){
        if(!vis[i])
        findTopoSort(i,vis,st,adj);
    }

vector<int> dis(n,Inf);
dis[source]=0;

// a Bfs traversal 
while (!st.empty()){
    int node = st.top();
    st.pop();

// if the node has been reached previously 
    if(dis[node]!=Inf){
        // go to it's  children
        for(auto it : adj[node]){
            if(dis[node] + it.second <dis[it.first])
               // update the distance
               dis[it.first] = dis[node] + it.second;  
        }
    }
}

for (int i = 0; i <n; i++){
    if(dis[i]==Inf) cout<<"No such Path Exist\n";
    else cout<<"shortest dis :"<<dis[i]<<'\n';
}

}



int main(){

vector<vector<pair<int,int> > > adj(6);
adj[0].push_back({1,5});
adj[0].push_back({2,3});
adj[1].push_back({3,6});
adj[1].push_back({2,2});
adj[2].push_back({4,4});
adj[2].push_back({5,2});
adj[2].push_back({3,7});
adj[3].push_back({4,-1});
adj[4].push_back({5,-1});

int source =1;
ShortestPath(source,6,adj);

    
return 0;
}