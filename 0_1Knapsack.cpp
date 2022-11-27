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
#define f first
#define s second
#define Fr(i,a,b) for(int i=a; (a<b)?i<b:i>=b ; (a<b)? i++:i--)
#define travrs(m) for(auto it =m.begin();it!=m.end();it++)
#define mx(v) *max_element(all(v))
#define mn(v) *min_element(all(v))
#define Mod 1000000007
#define pb push_back
#define mp make_pair
#define PI 3.1415926535897932384626
using namespace std;
using namespace __gnu_pbds;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<pair<ll,ll> > vpll;
typedef unordered_map<ll,ll> um;
typedef unsigned long long ull;
typedef long double ld;
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update>
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// #define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
// #define ordered_set tree<int, null_type,greater<int>, rb_tree_tag,tree_order_statistics_node_update>
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

bool PowerofTwo(int n){
if(n&(n-1)) return false;
return true;  
}
/* // permutations of array ::
sort(all(a));
do{
for(auto a1:a){
  cout<<a1<<" ";
}
cout<<endl;
}while(next_permutation(all(a)));
cout<<endl;
-->>
void Pairsort(int a[],int b[],int n){
vector<pair<int,int> > v(n);
fr(i,n){
  v[i] = make_pair(a[i],b[i]);
}
sort(all(v),cmp);
fr(i,n){
  a[i] = v[i].f;
  b[i] = v[i].s;
}}
*/
int binExpItr(ll a,ll b,ll M){ a %=M;    
int res =1;
while (b){
if(b&1) res = (res *1ll *a)%M;
a = (a* 1ll* a)%M;
b >>=1;  }
return res;}

ll ModInvr(ll x){return (binExpItr(x,Mod-2,Mod));}
ll fact[1000007];
void factorial(){ fact[0]=1;
 Fr(i,1,1000007) fact[i] = (fact[i-1]*i)%Mod;}
ll Ncr(ll n, ll r) {
return fact[n] * ModInvr(fact[r] * fact[n - r] % Mod) % Mod;}

const int N = 1e5+10;
vector<int > graph[N];  // array of vectors
bool visited[N];

void Dfs(int vertex ){
visited[vertex] = true;
for(int child : graph[vertex]){   
if(visited[child]) continue;
Dfs(child);   
}}

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

// Knapsack problem::
long long dp[101][100001];
int w[N],s[N];

long long func(int i, int amt){
long long ans =0;
if(amt==0) return 0;  
if(i<0) return 0;
if(dp[i][amt] != -1) return dp[i][amt];

ans = func(i-1, amt);
if(amt -w[i] >=0)
ans = max(ans,func(i-1, amt -w[i]) +s[i]);

return dp[i][amt] = ans;
}


int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);

int t=1;
// cin>>t;
while (t--){
int n,amt;
cin>>n>>amt;
fr(i,n) cin>>w[i]>>s[i];

// int n,k;
// cin>>n>>k;
// vi v(n);
// fr(i,n) cin>>v[i]; 
memset(dp,-1,sizeof(dp));
cout<<func(n-1,amt)<<endl;





}
  return 0;
}

/*
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
  