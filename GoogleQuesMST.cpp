/*
Codeforces Round #597 (Div. 2)
D:: Shichikuji and Power Grid
*/

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
#define Fr(i,a,b) for(int i=a; (a<b)?i<b:i>=b ; (a<b)? i++:i--)
#define travrs(m) for(auto it =m.begin();it!=m.end();it++)
#define mx(v) *max_element(all(v))
#define mn(v) *min_element(all(v))
// #define Mod 1000000007
#define pb push_back
#define PI 3.1415926535897932384626
using namespace std;
using namespace __gnu_pbds;
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

bool PowerofTwo(int n){
if(n&(n-1)) return false;
return true;  
}
ll Mod =998244353;

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

vector<int > graph[N]; 
bool visited[N];

void dfs(int v){
visited[v] = true;  
for(int child : graph[v]){
if(child == v) continue;
if(visited[child] == false){
dfs(child);
}}  
}

ll fact[1000007];
void factorial(int Mod){ fact[0]=1;
 Fr(i,1,1000007) fact[i] = (fact[i-1]*i)%Mod;}

ll Ncr(ll n, ll r,ll Mod) {
return fact[n] * ModInvr(fact[r] * fact[n - r] % Mod) % Mod;}

*/


// vector<ll > graph[N]; 
// bool visited[N];
// ll depth[N];


  
// void dfs(int v){
// visited[v] = true;  

// for(int child : graph[v]){
// if(child == v) continue;
// if(visited[child] == false){
// depth[child] = depth[v] +1;  
// dfs(child);
// }
// }  
// }
const int N = 2e3+10;
// vector<int > graph[N]; 
int parent[N];
int sz[N];

// DSU:
void make(int v){
parent[v] = v;
sz[v]= 1;
}
  
int find(int v){
if(parent[v]==v) return v;
// return find(parent[v]); 
//Path compression optimization
return parent[v] =find(parent[v]); 
}  

void Union(int a,int b){
a = find(a);    
b = find(b);
if(a!=b){
if(sz[a]<sz[b]) swap(a,b);
parent[b] = a;
sz[a] += sz[b];    
}    
}



int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
int t=1,t_case=1;
// cin>>t;
while (t--){
ll n,k;
cin>>n;

Fr(i,1,n+1) make(i);
vector<pair<ll,pair<ll,ll> > > vp;
vector<pair<ll,ll> > dis;

for (int i = 1; i <=n; i++){
ll x,y;
cin>>x>>y;  
dis.push_back({x,y});
}

vl costCon(n) ,costSource(n);
iv(costSource);
iv(costCon);

debug(costSource)
int Node=0;
for (int i = 1; i <=n; i++){
vp.push_back({costSource[i-1],{Node,i}});
}

for (int i = 1; i <=n; i++){
for (int j = i+1; j <=n; j++){
ll wt=(costCon[i-1]+costCon[j-1])*(abs(dis[i-1].first - dis[j-1].first) +abs(dis[i-1].second - dis[j-1].second) );  
vp.push_back({wt,{i,j}});
}
}

sort(all(vp));


//-->> MST

ll total_amt =0;
vector<pair<ll,ll> > connections;
vector<ll> powerStations;

for(auto v1: vp){
ll wt = v1.first;
ll u = v1.second.first;
ll v = v1.second.second;
if(find(u)== find(v)) continue;
Union(u,v);
total_amt += wt;
// cout<<u<<" "<<v<<endl;
if(u==0) powerStations.push_back(v);
else if(v==0) powerStations.push_back(u);
else{
connections.push_back({u,v});  
}
}

cout<<total_amt<<endl;
cout<<powerStations.size()<<endl;
for(auto p: powerStations){
cout<<p<<" ";  
}
cout<<endl;

cout<<connections.size()<<endl;
for(auto c: connections){
cout<<c.first<<" "<<c.second<<endl;  
}


// cout<<"Case #"<<t_case<<": ";
// t_case++;
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
abcdefghijklmnopqrstuvwxzy
bcdefghijklmnopqrstuvwxyaz
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

