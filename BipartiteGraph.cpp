#include<bits/stdc++.h>
using namespace std;
 
const int N = 200010;
// vector<vector<int> > graph;  // array of vectors
// bool visited[N];
bool bipart;
// vector<int> color;

void colorBipart(vector<vector<int> >&graph,int vertex, int curr,vector<int> &color,vector<bool>& visited){
if(color[vertex] != -1 && color[vertex] != curr) {
bipart = false;
return;}

color[vertex] = curr;
if(visited[vertex]) return;
visited[vertex] = true;

for(auto child: graph[vertex]){    
colorBipart(graph,child, curr xor 1,color,visited);  // because toggle the colour
}
}

 
 
int main(){
int t;
cin>>t;
while(t--){
bipart = true;    
int n;
cin>>n;
vector<vector<int> > graph(n);
vector<int > color(n,-1); 
vector<bool > visited(n,false); 

for (int i = 0; i <n; i++){
int v1,v2;
cin>>v1>>v2;
v1--;v2--;
graph[v1].push_back(v2);
graph[v2].push_back(v1);
}

for (int i = 0; i <n; i++){
if(!visited[i]) colorBipart(graph,i,0,color,visited);
}
// colorBipart(graph,0,0,color);

if(bipart) cout<<"Grpah is Bipartite \n";
else cout<<"Grpah is not Bipartite \n";

}
return 0;
}


