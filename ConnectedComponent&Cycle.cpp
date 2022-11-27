#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
vector<int > graph[N];  // array of vectors
bool visited[N];
vector<vector<int> > res;
vector<int> current_cc;

void Dfs(int vertex){
// modification
current_cc.push_back(vertex);
// done
visited[vertex] = true;
for(int child : graph[vertex]){   
if(visited[child]) continue;
Dfs(child);   
}
} 

// CycleDetection
bool CycleDfs(int vertex,int parent){
bool ans = false;
visited[vertex] = true;
for(int child: graph[vertex]){
if(visited[child] && child == parent) continue;
if(visited[child]) return true;    
ans |= CycleDfs(child,vertex);
}
return ans;
}
 

int main(){
int n,m;
cin>>n>>m;
for (int i = 0; i <m; i++){
int v1,v2;
cin>>v1>>v2;
graph[v1].push_back(v2);
graph[v2].push_back(v1);
}

int ct =0;
for (int i = 1; i <=n; i++){
current_cc.clear();    
if(visited[i]) continue;
Dfs(i);
res.push_back(current_cc); // store all components 
ct++;
}


// cout<<"No of Connected components: "<<ct<<endl; 
// for(auto c1: res){
// for(auto c2:c1)
// cout<<c2<<" ";
// cout<<endl;     
// }


// for(auto c1:  graph){
// for (auto c2:c1){
// cout<<c2<<" ";    
// }
// cout<<endl;    
// }

// bool isLoopExist = false;
// for (int i = 0; i <=n; i++) visited[i] = 0;

// for (int i = 1; i <=n; i++){
// if(visited[i]) continue;
// if(CycleDfs(i,0)) {
// isLoopExist = true;
// break;}
// }
// cout<<isLoopExist<<endl;
    
return 0;
}