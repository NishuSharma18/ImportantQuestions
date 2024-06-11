#include "bits/stdc++.h" 
#define ll long long
using namespace std;

class FunctionalGraph{
  vector<int> successor;
  vector<int> pref;
  vector<int> NumberOfReachableNodes;
  int number_of_cycles,Cycle_Sz,n;
  
  public:
  FunctionalGraph(int n1){
    n = n1+1;
    successor.resize(n);
    pref.resize(n);
    NumberOfReachableNodes.resize(n);
    number_of_cycles =0;
  }

  void add(int u,int v){
    successor[u]= v;
  }

  int dfs(int v,int len=1){
    if(NumberOfReachableNodes[v]) 
      return len;

    if(pref[v]){
      NumberOfReachableNodes[v] = len-pref[v];
      Cycle_Sz = len-pref[v];
		  number_of_cycles++;
      return pref[v];
    }

    pref[v] = len;
	  int u = successor[v];
    int curr = dfs(u,len+1);
    NumberOfReachableNodes[v] = NumberOfReachableNodes[u];
    if(curr>len) NumberOfReachableNodes[v]++; // not in the cycle
    return curr;
  }

  vector<int> CountCycles(){
    vector<int> cycles;
    for(int i = 1; i <=n; i++){
        Cycle_Sz= -1;
        dfs(i);
        if(Cycle_Sz!= -1)
          cycles.push_back(Cycle_Sz);
    }
    // return number_of_cycles;
    return cycles;
  }

  vector<int> ReachableNodes(){
    CountCycles();
    return NumberOfReachableNodes;
  }

};

void solve(){
  int n;
  cin>>n;
  FunctionalGraph f(n+1);
  for(int i=1; i<=n; i++){
    int v; cin>>v;
    f.add(i,v);
  }

  vector<int> res = f.ReachableNodes();
  ll ans=0;
  for(int i=1; i<=n; i++){
    ans+= res[i];
  }
  cout<<ans<<'\n';
}
 
/*----------------------------------------------------------------------------------------------------------------------------*/
int32_t main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(0); 
  cout.tie(0);
	solve(); 
  return 0;
}
 