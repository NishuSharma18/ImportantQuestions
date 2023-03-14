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
#define Fr(i,a,b) for(int i=a; (a<b)?i<b:i>=b ; (a<b)? i++:i--)
#define Mod 1000000007
#define pb push_back
#define PI 3.1415926535897932384626
using namespace std;
using namespace __gnu_pbds;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<pair<ll,ll> > vpll;
typedef vector<pair<int,int> > vp;
typedef unsigned long long ull;
typedef long double ld;
// #define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update>
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// #define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_set tree<int, null_type,greater<int>, rb_tree_tag,tree_order_statistics_node_update>
// #define ordered_set tree<int, null_type,greater_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
//  S.order_of_key -> element smaller than  || *S.find_by_order -> value at index   


// ***************************************** Debugging *****************************************
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
// ******************************************************************************************************************************


int X[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int Y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int binExpItr(ll a,ll b,ll M){ 
  a %=M;    
  int res =1;
  while (b){
  if(b&1) res = (res *1ll *a)%M;
    a = (a* 1ll* a)%M;
    b >>=1;  }
  return res;
}
ll ModInvr(ll x){return (binExpItr(x,Mod-2,Mod));}

/*
ll fact[1000007];
  void factorial(){ fact[0]=1;
    Fr(i,1,1000007) fact[i] = (fact[i-1]*i)%Mod;}

ll Ncr(ll n, ll r) {
  return fact[n] * ModInvr(fact[r] * fact[n - r] % Mod) % Mod;}


bool PowerofTwo(int n){
if(n&(n-1)) return false;
return true;  
}

const int N= 300007;
bool isprime[N];
vector<int> LowPrime(N,0) ,HighPrime(N,0);

void Sieve(){
  memset(isprime,true,sizeof(isprime));
  isprime[0] = isprime[1] = false;    
  for (int i = 2; i <N; i++){
    if(isprime[i]==true){
    LowPrime[i] = HighPrime[i] =i;    
    for (int j = 2*i; j <N; j+=i) {
        isprime[j] = false;
        HighPrime[j] = i;
    if(LowPrime[j] == 0) LowPrime[j] = i;
}        
}}
}

// Prime Factors in O(log(N)) time per query
vector<int> PrimeFacs(int num){
  vector<int> m;
  while(num>1){
  int prmfct = HighPrime[num];
    bool fg = false;
    while(num%prmfct ==0){
      num /= prmfct;
        fg =1;
    }    
  if(fg) m.push_back(prmfct);
}
return m;
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

ll floorX(ll a,ll b) return a/b;
ll ceilX(ll a,ll b) return (a+b-1)/b ;

// Prime Factorization [time - O(sqrt(n)) ]
map<ll,ll> PrimeFactors(ll n){ 
map<ll,ll> PrimeFac;
for (ll i =2; i*i <=n; i++){
while (n%i==0){
PrimeFac[i]++;
n/=i;
}
}
if(n>1){  // Edge case for prime no
PrimeFac[n]++;
}
return PrimeFac; 
}

*/

// ************* Sqrt Decomposition ******************
const int N = 1e3+10;
vector<ll> b(N);
int len;
// 0- based indexing

void preprocessing(vector<ll> &a,int n){
  len = (int) sqrt (n + .0) + 1;
  b.clear();
  b.resize(len);
  // b.assign(len,INT_MIN);     // for max queries
for (int i=0; i<n; ++i){
    b[i / len] += a[i];
    // b[i / len] = max(a[i],b[i / len]);   // for max queries
}
}


ll query(ll l,ll r,vector<ll>&a){
    ll sum = 0;
ll c_l = l / len;
ll c_r = r / len;
  if (c_l == c_r){ // if Both are in same segment
    for (int i=l; i<=r; ++i)
        sum += a[i];
  }
  else{
    for (int i=l, end=(c_l+1)*len-1; i<=end; ++i)
        sum += a[i];
    for (int i=c_l+1; i<=c_r-1; ++i)
        sum += b[i];
    for (int i=c_r*len; i<=r; ++i)
        sum += a[i];
}

return sum;
}

void update(ll ind,ll val,vector<ll> &a){
  b[ind/len] += (val-a[ind]);
  a[ind] = val;
}




int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
int t1=1,t_case=1;
//  cin>>t1;

while (t1--){
  ll n,m,k,q;
  cin>>n>>q;
  vl a(n);
  fr(i,n) cin>>a[i];

preprocessing(a,n);


// answering the queries
while(q--){
    ll l, r,ty;
    cin>>ty;
    if(ty==1){
    cin>>l>>r;
    l--,r--;
    cout<<query(l,r,a)<<'\n';
    }
    else{
      ll ind,val;
      cin>>ind>>val;
      ind--;
      update(ind,val,a);
    }
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

