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

// ******** Sparse Table **************
const int MAXN = (1 << 20);
const int MAXLOG = 20;

  ll dp[MAXN][MAXLOG];
    ll prec_lg2[MAXN], n;

    void reBulid(){
     memset(dp, 0, sizeof(dp)); 
     memset(prec_lg2, 0, sizeof(prec_lg2)); 
     n = 0; 
  }

    void precompute(vector<ll> &a){
        n = a.size();
        for(int i = 2; i < 2 * n; i++) 
      prec_lg2[i] = prec_lg2[i >> 1] + 1;

        for(int i = 0; i < n; i++) 
      dp[i][0] = a[i];

        for(int j = 1; (1 << j) <= n; j++)    
            for(int i = 0; i < n; i++)
                // dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
                dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
    }


  // 0(1) per  query
    ll query(int l, int r) {
        ll k = prec_lg2[r - l + 1];
        
    // return min(dp[l][k], dp[r - (1 << k) + 1][k]);
    return max(dp[l][k], dp[r - (1 << k) + 1][k]);
    }


void solve(){
  ll n,m,k;
  cin>>n;
  vl a(n);
  fr(i,n) cin>>a[i];












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


