#include "bits/stdc++.h" 
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
// #include<ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
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
/* ever tried, ever failed, no matter try again, fail again, fail better */
/*----------------------------------------------------------------------------------------------------------------------------*/

int M = 1e9+7; 
struct Node{
    int l1,l2,r1,r2;

    Node(){
        l1= 0; // l,r
        l2= 0;  // l,r-1
        r1= 0;  // l+1, r
        r2= 0;  // l+1,r-1
    }

    Node(int l1,int l2,int r1,int r2){
        this->l1= l1;
        this->l2= l2;
        this->r1= r1;
        this->r2= r2;
    }
};

class SegementTree{
    public:
    vector<Node> tree;

    SegementTree(ll n){
        tree.resize(4*n+4);
    }

    Node Combine(Node &a, Node &b){
        Node ans(0,0,0,0);
         ans.l2 = max({a.l2+ b.l2, a.l2+ b.r2 , a.l1+ b.r2}); 
         ans.r1 = max({a.r1+ b.r1, a.r2+ b.r1 , a.r2+ b.l1}); 
         ans.r2 = max({a.r2+ b.r2, a.r2+ b.l2 , a.r1+ b.r2}); 
         ans.l1 = max({a.l1+ b.r1, a.l2+ b.l1}); 
         ans.l1%=M;
         ans.l2%=M;
         ans.r1%=M;
         ans.r2%=M;
       return ans; 
    }
    
    void Build(int node,int st,int end,vector<int> &a){
        if(st== end){
        tree[node].l1 = a[st];
        tree[node].l2 = 0;
        tree[node].r1 = 0;
        tree[node].r2 = 0;
        return;
        }

        ll mid = (st+ end)>>1;
        Build(2*node,st,mid,a);
        Build(2*node+1,mid+1,end,a);

        tree[node] = Combine(tree[2*node],tree[2*node+1]);
    } 

    Node Query(int node,int st,int end,int l,int r){
        if(st>r || end<l) 
        return Node(0,0,0,0);    
        if(l<=st && r>=end) 
        return tree[node];

        ll mid = (st+end)>>1;
        Node q1 = Query(2*node,st,mid,l,r);    
        Node q2 = Query(2*node+1,mid+1,end,l,r);    

        return Combine(q1,q1);
    }

    void PointUpdate(int node,int st,int end,int ind,int val,vector<int> &a){
        if(st==end){
            a[st]= val;
            tree[node].l1= val;
            tree[node].l2 = 0;
            tree[node].r1 = 0;
            tree[node].r2 = 0;
            return;
        }  
        ll mid = (st+end)>>1;
        if(mid>=ind)
            PointUpdate(2*node,st,mid,ind,val,a);
        else
            PointUpdate(2*node+1,mid+1,end,ind,val,a);
        tree[node] = Combine(tree[2*node],tree[2*node+1]);
    }
};


int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {   
    int n = nums.size();
    SegementTree st(n+1);
    st.Build(1,0,n-1,nums);

    int ans=0;
    for(auto it: queries){
       st.PointUpdate(1,0,n-1,it[0],it[1],nums);
       Node t = st.Query(1,0,n-1,0,n-1);
       int tot=max({t.l1,t.l2,t.r1,t.r2});
       ans = (ans+ tot+ 0LL)%M;     
    }
    return ans;
}

void solve(){
  ll n,m,k;
  cin>>n;
  vi a(n);
  fr(i,n) cin>>a[i];

   vector<vector<int>> q = {{1,-2},{0,-3}};
   cout<<maximumSumSubsequence(a,q)<<'\n'; 
}

/*----------------------------------------------------------------------------------------------------------------------------*/
int32_t main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(0); 
  cout.tie(0);
    solve();
  return 0;
}


