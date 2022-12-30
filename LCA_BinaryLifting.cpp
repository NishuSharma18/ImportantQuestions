#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
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
#define Fr(i,a,b) for(int i=a; (a<b)?i<b:i>=b ; (a<b)? i++:i--)
#define travrs(m) for(auto it =m.begin();it!=m.end();it++)
#define mx(v) *max_element(all(v))
#define mn(v) *min_element(all(v))
#define Mod 1000000007
#define pb push_back
#define PI 3.1415926535897932384626
using namespace std;
// using namespace __gnu_pbds;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<pair<ll,ll> > vpll;
typedef vector<pair<int,int> > vp;
typedef unordered_map<ll,ll> um;
typedef unsigned long long ull;
typedef long double ld;
// #define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update>
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// #define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_set tree<int, null_type,greater<int>, rb_tree_tag,tree_order_statistics_node_update>
// #define ordered_set tree<int, null_type,greater_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
//  S.order_of_key -> element smaller than  || *S.find_by_order -> value at index   


#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" ";_print(x); cerr<<endl;
#else
#define debug(x)
#endif

// --------->>> Debugging <<<-------
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
// ---------->>>  ###########  <<<---------- // 

int X[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int Y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int binExpItr(ll a,ll b,ll M){ a %=M;    
int res =1;
while (b){
if(b&1) res = (res *1ll *a)%M;
a = (a* 1ll* a)%M;
b >>=1;  }
return res;}

ll ModInvr(ll x){return (binExpItr(x,Mod-2,Mod));}


/*

/* // permutations of array ::
sort(all(a));
do{
for(auto a1:a){
  cout<<a1<<" ";
}
cout<<endl;
}while(next_permutation(all(a)));
cout<<endl;


ll fact[1000007];
void factorial(){ fact[0]=1;
 Fr(i,1,1000007) fact[i] = (fact[i-1]*i)%Mod;}
ll Ncr(ll n, ll r) {
return fact[n] * ModInvr(fact[r] * fact[n - r] % Mod) % Mod;}


int longestSubarray(int arr[], int n, int k) {
int start = 0, end =0, sum = 0, maxLength = 0;
while (start < n) {
while ((end < n) && (sum + arr[end] <= k)){
sum += arr[end];
end++;}
if (sum == k) maxLength = max(maxLength, (end - start ));
// here -->> (sum > k)
sum -= arr[start];
start++;}
return maxLength;}

bool isPalindrome(string s){
string s1 = s;
reverse(s.begin(),s.end());
if(s == s1) return true;
return false; }

bool matching(char a, char b){
return (a=='(' && b==')');  
}

ll minm(ll a,ll b){
return (a<b)? a:b;  
}

vector<vector<int> > graph(N); 
vector<bool> vis(N);
vector<int> depth(N);
 
void dfs(int v){
visited[v] = true;  
for(int child : graph[v]){
if(child == v) continue;
if(visited[child] == false){
depth[child] = depth[v]+1;
dfs(child);
}}  
}

int floorX(int a,int b) return a/b;
int ceilX(int a,int b) return (a+b-1)/b ;

ll fact[1000007];
void factorial(){ fact[0]=1;
 Fr(i,1,1000007) fact[i] = (fact[i-1]*i)%Mod;}

ll Ncr(ll n, ll r) {
return fact[n] * ModInvr(fact[r] * fact[n - r] % Mod) % Mod;}
*/

// ::::::: BINARY LIFTING ::::::::
const int N = 2e5+10;

vector<vector<int> > graph(N);
vector<int> lvl(N);
vector<vector<int> > up(N,vector<int>(21));


// constructing the up Table 
void BinaryLifting(int src,int par){
  up[src][0] = par;
  for(int i =1;i<21;i++){
    if(up[src][i-1]!=-1)
    up[src][i] = up[up[src][i-1]][i-1];// 2^x = 2^(x-1) + 2^(x-1)
    else 
    up[src][i] = -1;
  }

  for(auto child: graph[src]){
    if(child != par)
    BinaryLifting(child,src);
  }

}

// ::::: ans to queries in log(n) ::::::
int liftNode(int node,int jumps){
  if(node==-1 || jumps==0)
  return node;

// traverse from most significant bit to lsb
for (int i = 20; i>=0; i--){
    if(jumps >= (1<<i)){
      return liftNode(up[node][i],jumps- (1<<i));
    }
} 
}


void dfs(int v,int par){
  for(auto c: graph[v]){
    if(c== par) continue;
    lvl[c] = lvl[v]+1;
    dfs(c,v);
  }
}

// :::::::: LCA in (log(n))^2 --> Binary Search :::::::::::::
int LCA1(int u ,int v){
  if(lvl[u]<lvl[v]){
    swap(u,v);
  }
 
  u = liftNode(u,lvl[u]-lvl[v]); // now both are at same level
// now we can apply Binary search to find the LCA in log(n)
// so overall complexity will be [log(n)*log(n)]

  int l =0,r= lvl[u];
  while (l<r){
    int mid = (l+r)/2;
    int x1 = liftNode(u,mid);
    int x2 = liftNode(v,mid);
    if(x1==x2) r = mid;
    else l= mid+1;
}

return liftNode(u,l);
}

// :::::::::: LCA in Log(n) ::::::::
int LCA(int u,int v){
    if(lvl[u]<lvl[v]){
    swap(u,v);
  }
 
  u = liftNode(u,lvl[u]-lvl[v]);

  if(u==v) return u;
  for(int i = 20;i>=0;i--){
    if(up[u][i]!= up[v][i]){ // make max possible jump(upto x-1) (just below the lca)
      u = up[u][i];
      v = up[v][i];
    }
  }
return up[u][0];
}

/*
in main() function
BinaryLifting(1,-1);
dfs(1,-1);
*/

int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
int t1=1,t_case=1;
//  cin>>t1;

while (t1--){
ll n,k,q;
cin>>n>>q;

// vi a(n);
// fr(i,n) {
// cin>>a[i];
// }
graph.resize(n+2);
lvl.resize(n+2);


fr(i,n-1){
  int ele;
  cin>>ele;
  graph[ele].push_back(i+2);
}

BinaryLifting(1,-1);
dfs(1,-1);

while(q--){
  int u,v;
  cin>>u>>v;
  cout<<LCA(u,v)<<'\n';
}



}
  return 0;
}

/*
 " I AM VENGEANCE , I AM THE NIGHT , I AM THE BATMAN ! "
____ __ __ __ __ __ ___                             ___ __ __ __ __ __ ____
 `-._:  .:'   `:::  .:\           |\__/|           /::  .:'   `:::  .:.-'
     \      :          \          |:   |          /         :       /
      \     ::    .     `-_______/ ::   \_______-'   .      ::   . /
       |  :   :: ::'  :   :: ::'  :   :: ::'      :: ::'  :   :: :|
       |     ;::         ;::         ;::         ;::         ;::  |
       |  .:'   `:::  .:'   `:::  .:'   `:::  .:'   `:::  .:'   `:|
       /     :           :           :           :           :    \
      /______::_____     ::    .     ::    .     ::   _____._::____\
                    `----._:: ::'  :   :: ::'  _.----'
                           `--.       ;::  .--'
                               `-. .:'  .-'
                                  \    /
                                   \  /
                                    \/
*/


/*
srand(time(NULL));
int cnt =1;
while (cnt<=10){ 
cnt++;  
int n = rand()%10+1;
vector<int> a(n);
fr(i,n){
a[i] = rand()%7 +1;
if(opt(a,n) != brute(a,n)){
cout<<n<<endl;
fr(i,n) cout<<a[i]<<" ";
cout<<endl;
break;  
} }}
*/


