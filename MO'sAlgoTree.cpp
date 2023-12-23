#include "bits/stdc++.h" 
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
// #include<ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define removeDuplicate(v) v.erase(unique(all(v)),v.end())
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define fr(i,n) for(int i=0;i<n;i++)
#define Mod 1000000007
#define PI 3.1415926535897932384626
#define random() ((ll)rand() << 32 | rand())

using namespace std;
// using namespace __gnu_pbds;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef unsigned long long ull;
typedef long double ld;
#define ordered_setp tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_set1 tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_setR tree<int, null_type,greater<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_setR1 tree<int, null_type,greater_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
//  S.order_of_key -> element smaller than  || *S.find_by_order -> value at index   

/*----------------------------------------------------------------------------------------------------------------------------*/
#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" ";_print(x); cerr<<endl;
#else
#define debug(x)
#endif

void _print(ll t){cerr<<t;}
void _print(int t){cerr<<t;}
void _print(char t){cerr<<t;}
void _print(string t){cerr<<t;}
void _print(double t){cerr<<t;}
void _print(ull t){cerr<<t;}
void _print(ld t){cerr<<t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T v1 : v) {_print(v1); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> s) {cerr << "[ "; for (T s1 : s) {_print(s1); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> s) {cerr << "[ "; for (T s1 : s) {_print(s1); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> m) {cerr << "[ "; for (auto m1 : m) {_print(m1); cerr << " ";} cerr << "]";}

/*----------------------------------------------------------------------------------------------------------------------------*/
int X[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int Y[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};

int binExpItr(ll a,ll b,ll M){ a %=M; int res =1; while (b){ if(b&1) res = (res *1ll *a)%M; a = (a* 1ll* a)%M;b >>=1;}  return res;}
ll ModInvr(ll x){return (binExpItr(x,Mod-2,Mod));}
vector<ll> fact; void factorial(int n){fact.resize(n+1); fact[0]=1; for(int i=1; i<=n ;i++) fact[i] = (fact[i-1]*i)%Mod;}
ll Ncr(ll n, ll r) {return fact[n] * ModInvr(fact[r] * fact[n - r] % Mod) % Mod;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, ModInvr(b), m) + m) % m;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} 
/*----------------------------------------------------------------------------------------------------------------------------*/

static void run_with_stack_size(void (*func)(void), size_t stsize) {
    char *stack, *send;
    stack = (char *)malloc(stsize);
    send = stack + stsize - 16;
    send = (char *)((uintptr_t)send / 16 * 16);
    asm volatile(
        "mov %%esp, (%0)\n"
        "mov %0, %%esp\n"
        :
        : "r"(send));
    func();
    asm volatile("mov (%0), %%esp\n" : : "r"(send));
    free(stack);
}
/*----------------------------------------------------------------------------------------------------------------------------*/


const int N = 1e5+10,L = 21;
vector<vector<int>>adj;
vector<int>in, out,c,et,h;
ll timer = 0;
int dp[N][L];


void dfs(int node, int par){
    in[node] = timer++;
    et.push_back(node);
    dp[node][0] = par;

    for (int i = 1; i < L; i++){
        dp[node][i] = dp[dp[node][i - 1]][i - 1];
    }

    for (auto it : adj[node]){
      if (it == par) continue;
        h[it]+= h[node];
        dfs(it, node);
    }

    out[node] = timer++;
    et.push_back(node);
}

bool is_ancestor(int u, int v){
    return in[u] <= in[v] && out[u] >= out[v];
}

int lca(int u, int v){
  if (is_ancestor(u,v)) return u;  
  if(is_ancestor(v,u))  return v;
    
  for(int i = L - 1; i >= 0; i--){
    if(!is_ancestor(dp[u][i],v)){
      u = dp[u][i];
    }
  }
  
return dp[u][0];
}
/*
dfs(1,1)
*/


/*-------------------- MO's Algo -------------------*/
int len;
vector<ll> fq1,fq2; // for time index , for actual values
ll curr;

struct Node{
    int l, r, lca,idx;
};

bool cmp(Node a, Node b){
  if (a.l/len != b.l/len){
      return a.l < b.l;
  }
return a.r < b.r;
}

void initialise(int n){
  adj.clear();
  adj.resize(n+1);
  in.clear();
  in.resize(n+1);
  c.clear();
  c.resize(n+1);
  out.clear();
  out.resize(n+1);
  h.clear();
  h.resize(n+1);
  h.assign(n+1,1);
  et.clear();
  timer=0;

  fq1.clear();
  fq1.resize(n+1);
  fq2.clear();
  fq2.resize(n+1);
  // len = (int) sqrt (n + .0) + 1;
  len = 450;
  curr=0;
}


void add(int ind){
    fq1[et[ind]]++;
    int x= c[et[ind]];
    
  curr -= (fq2[x]*(fq2[x]-1))/2;
    if(fq1[et[ind]]==1) fq2[x]++;
    else{
      fq2[x]--;
    }
  curr += (fq2[x]*(fq2[x]-1))/2;
}

void remove(int ind){
    fq1[et[ind]]--;
    int x= c[et[ind]];
    
  curr -= (fq2[x]*(fq2[x]-1))/2;
    if(fq1[et[ind]]==1){
       fq2[x]++;
    }
    else fq2[x]--;
  curr += (fq2[x]*(fq2[x]-1))/2;
}

/*------------------------------------------------*/




void solve(){
  ll n,m,k,q;

vector<Node> qr;
  fr(i,q){
    int u,v;
    cin>>u>>v;
    if(in[u]>in[v]) swap(u,v);
    int l = lca(u,v);

    // case 1
    int x,y;
    if(l==u){ // direct path
       l=-1;
       x = in[u];
       y = in[v]; 
    }

    else{  // curved path -- need to consider the contribution of lca
       x = out[u];
       y = in[v]; 
    }

    Node nd ={.l =x, .r=y ,.lca = l,.idx =i};
    qr.push_back(nd);
  }

  sort(all(qr),cmp);
  vector<int> ans(q,0);
  int l=0,r=-1;

  for(auto it: qr){
     while(l>it.l){
        l--;
        add(l);
     } 

     while(r<it.r){
       r++;
       add(r);
     }

     while(l<it.l){
        remove(l);
        l++;
     }
     
     while(r>it.r){
        remove(r);
        r--;
    }


    ll d = curr,d1;

    if(it.lca!=-1){ // add the contribution
    int x= c[it.lca];
      d-= (fq2[x]*(fq2[x]-1))/2;
      fq2[x]++;
      d += (fq2[x]*(fq2[x]-1))/2;
      fq2[x]--;

      d1 = h[et[it.l]] + h[et[it.r]]- 2*h[it.lca]+1;
    }
    else
    d1 = h[et[it.r]] - h[et[it.l]]+1;


    ans[it.idx] -= d;  
    ans[it.idx] += (d1*(d1-1))/2;
  }













}




/*----------------------------------------------------------------------------------------------------------------------------*/
int32_t main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(0); 
  cout.tie(0);
  int t1=1,t=1;
  cin>>t1;

  while (t1--){
    // cout<<"Case #"<<t++<<": ";
    // run_with_stack_size(solve, 1024 * 1024 * 1024);
    solve();
  }

  return 0;
}


