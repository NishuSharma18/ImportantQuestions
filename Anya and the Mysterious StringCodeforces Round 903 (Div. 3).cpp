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

/*
https://codeforces.com/contest/1881/problem/G
*/

struct Node{
 int l1,l2,r1,r2; // l1l2... r2r1......
 bool flag;

 Node(){
  l1= -1;
  l2= -1;
  r1= -1;
  r2= -1;
  flag = false;
 }

 Node(int l1,int l2,int r1,int r2,bool flag){
  this->l1= l1;
  this->l2= l2;
  this->r1= r1;
  this->r2= r2;
  this->flag = flag;
 }

};


class SegTree{
 vector<Node> Stree;
 vector<ll> lazy;

 public:
 SegTree(int n){
    Stree.resize(4*(n+1));
    lazy.resize(4*(n+1));
 } 

 Node Combine(Node &a, Node &b){
  Node ans(-1,-1,-1,-1,false);
  if(a.l1==-1) return b;
  if(b.l1==-1) return a;

  ans.l1 = a.l1;
  if(a.l2!= -1) ans.l2 = a.l2;
  else ans.l2 = b.l1;

  ans.r1 = b.r1;
  if(b.r2!= -1) ans.r2 = b.r2;
  else ans.r2= a.r1;

  // for flag
  if(a.flag || b.flag) ans.flag = 1;
  else{
    if(a.r1== b.l1) ans.flag = 1;
    if(a.r2 !=-1 && a.r2== b.l1) ans.flag =1;
    if(b.l2 !=-1 && a.r1 == b.l2) ans.flag =1;
  }
  return ans;
 }

  void Build(ll node,ll st,ll end, string &s){
    if(st== end){
      Stree[node].flag = false;
      Stree[node].l1 = s[st]-'a';
      Stree[node].r1 = s[st]-'a';
      Stree[node].l2 = -1;
      Stree[node].r2 = -1;
      return;
    }

    ll mid = (st+ end)>>1;
    Build(2*node,st,mid,s);
    Build(2*node+1,mid+1,end,s);
    Stree[node] = Combine(Stree[2*node] ,Stree[2*node+1]);
  }  

  void push(int v) {
      Stree[v*2].l1 = (Stree[v*2].l1 + lazy[v])%26;
    if(Stree[2*v].l2 != -1) 
      Stree[v*2].l2 = (Stree[v*2].l2 + lazy[v])%26;
    
      Stree[v*2].r1 = (Stree[v*2].r1 + lazy[v])%26;
    if(Stree[2*v].r2 != -1) 
      Stree[v*2].r2 = (Stree[v*2].r2 + lazy[v])%26;
  
      Stree[v*2+1].l1 = (Stree[v*2+1].l1 + lazy[v])%26;
    if(Stree[2*v+1].l2 != -1) 
      Stree[v*2+1].l2 = (Stree[v*2+1].l2 + lazy[v])%26;
    
      Stree[v*2+1].r1 = (Stree[v*2+1].r1 + lazy[v])%26;
    if(Stree[2*v+1].r2 != -1) 
      Stree[v*2+1].r2 = (Stree[v*2+1].r2 + lazy[v])%26;

      lazy[v*2] += lazy[v];
      lazy[v*2+1] += lazy[v];
      lazy[v] = 0;
  }


  void Update(int v, int st, int end, int l, int r, ll addend) {
    if(st>r || end<l) return;

    if(l<=st && r>=end){
        Stree[v].l1 = (Stree[v].l1 + addend)%26;
      if(Stree[v].l2 != -1) 
        Stree[v].l2 = (Stree[v].l2 + addend)%26;
      
        Stree[v].r1 = (Stree[v].r1 + addend)%26;
      if(Stree[v].r2 != -1) 
        Stree[v].r2 = (Stree[v].r2 + addend)%26;

      lazy[v] = (lazy[v] +addend)%26;
    return;  
    }

       push(v);
      ll mid = (st+end)>>1;
      Update(2*v,st,mid,l,r,addend);    
      Update(2*v+1,mid+1,end,l,r,addend);  
      Stree[v] = Combine(Stree[v*2],Stree[v*2+1]);
  }
  
  Node query(int v, int st, int end, int l, int r) {
    if(st>r || end<l)
      return Node(-1,-1,-1,-1,false);
    
    if(l<=st && r>=end) 
       return Stree[v];

      push(v);
     ll mid = (st+end)>>1;
     Node q1 = query(2*v,st,mid,l,r);    
     Node q2 = query(2*v+1,mid+1,end,l,r);  

    return Combine(q1,q2);
  } 

};



void solve(){
  ll n,m,k;
  cin>>n>>k;
  string s;
  cin>>s;

  SegTree st(n);
  st.Build(1,0,n-1,s);

  while(k--){
    int t,l,r;
    cin>>t>>l>>r;
    l--;r--;

    if(t==1){
      ll x;
      cin>>x;
      x%=26;
      st.Update(1,0,n-1,l,r,x);
    }

    else{
      if(st.query(1,0,n-1,l,r).flag) no
      else yes
    }
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


