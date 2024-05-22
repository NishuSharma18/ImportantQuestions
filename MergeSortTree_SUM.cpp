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
class MergeSortTree{
   vector<int> a,p;
   int ret;
   vector<vector<pair<int,ll> > > tree;

   public:
   MergeSortTree(int n, vector<int> &a1,vector<int> &p1){
      a = a1;
      p = p1;
      tree.assign(8* n +n, vector<pair<int,ll>>());
      ret = 0;
   }

   void build(int si, int ss, int se) {
      if(ss == se) {
         tree[si].push_back({p[ss], a[ss]});
         return;
      }
      int mid = ss + (se - ss) / 2;
      build(2 * si, ss, mid);
      build(2 * si + 1, mid + 1, se);
      merge(tree[2 * si].begin(),  tree[2 * si].end(),
      tree[2 * si + 1].begin(), tree[2 * si + 1].end(), 
      back_inserter(tree[si]));

      for(int i=1; i<tree[si].size(); i++){
        tree[si][i].second +=tree[si][i-1].second; // prefix sum
      }
   }

   int query(int si, int ss, int se, int qs, int qe, pair<int,int> x) {
      if(ss > qe || se < qs) return ret;
      if(ss >= qs && se <= qe){
        auto ptr = lower_bound(tree[si].begin(), tree[si].end(), x)- tree[si].begin();
        if(!ptr) return ret;
        ptr--;
        return tree[si][ptr].second;
      }
      int mid = ss + (se - ss) / 2;
      int left = query(2 * si, ss, mid, qs, qe, x);
      int right = query(2 * si + 1, mid + 1, se, qs, qe, x);
      return (left+right);
   }
};

void solve(){
  ll n,m,k;
  cin>>n>>m;
  vi a(n);
  fr(i,n) cin>>a[i];
  vi b(n);
  fr(i,n) cin>>b[i];

  MergeSortTree st(n,a,b);
  st.build(1,0,2*n-1);
  while(k--){
    ll p,q,r; cin>>p>>q>>r;
    pair<int,int> x = {r,-1};
    int ans= st.query(1,0,2*n-1,p,q,x);
    cout<<ans<<'\n';
  }
}

/*----------------------------------------------------------------------------------------------------------------------------*/
int32_t main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(0); 
  cout.tie(0);
    solve();
  return 0;
}


