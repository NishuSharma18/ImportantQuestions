#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define all(v) v.begin(),v.end()
#define removeDuplicate(v) v.erase(unique(all(v)),v.end())
#define Fr(i,a,b) for(int i=a; (a<b)?i<b:i>=b ; (a<b)? i++:i--)
#define fr(i,n) for(int i=0;i<n;i++)
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
using namespace std;
using namespace __gnu_pbds;
const int Mod = 1e9+7;

// #define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update>  
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// #define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
// #define ordered_set tree<int, null_type,greater<int>, rb_tree_tag,tree_order_statistics_node_update>
// #define ordered_set tree<int, null_type,greater_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

bool isprime[1000000];
vector<int> LowPrime(1000000,0) ,HighPrime(1000000,0);

void Sieve(){
memset(isprime,true,sizeof(isprime));
isprime[0] = isprime[1] = false;    
for (int i = 2; i <=1000000; i++){
if(isprime[i]==true){
// LowPrime[i] = HighPrime[i] =i;    
for (int j = 2*i; j <1000000; j+=i) {
isprime[j] = false;
// HighPrime[j] = i;
// if(LowPrime[j] == 0) LowPrime[j] = i;
}        
}}
}

// Prime Factors in O(log(N)) time per query
unordered_map<int ,int> PrimeFacs(int num){
unordered_map<int,int> m;
while(num>1){
int prmfct = HighPrime[num];
while(num%prmfct ==0){
num /= prmfct;
m[prmfct]++;}    
}
return m;
}

// All Divisers using sieve
vector<int> divisers[100000];
void diviser(){
Fr(i,1,100000){
for(int j =i; j <100000; j+=i){
divisers[j].push_back(i);    
}}}

// int binExpRecr(int a,int b){
// // base case
// if(b==0) return 1;    
// int res =binExpRecr(a,b/2);
// if(b&1) return (a*(res *1ll*res)%Mod)%Mod ;   
// else return (res*1ll*res)%Mod;
// }


int binExpItr(ll a,ll b){ a %=Mod;    
int res =1;
while (b){
if(b&1) res = (res *1ll *a)%Mod;
a = (a* 1ll* a)%Mod;
b >>=1;  }
return res;}

// Binary Multiplication
ll binMultiply(ll a,ll b){ ll res =0;
while(b){
if(b&1) res = (res+a)%Mod;    
a =(a+a)%Mod;
b >>=1;}
return res;}

// Prime Factorization [time - O(sqrt(n)) ]
vector<int> PrimeFactors(int n){ vector<int> PrimeFac;
for (int i =2; i*i <=n; i++){
while (n%i==0){
PrimeFac.push_back(i);
n/=i;}}
if(n>1){  // Edge case for prime no
PrimeFac.push_back(n);}
return PrimeFac; }

ll ModInvr(ll x){return (binExpItr(x,Mod-2));}
ll fact[1000007];
void factorial(){ fact[0]=1;
 Fr(i,1,1000007) fact[i] = (fact[i-1]*i)%Mod;}
ll Ncr(ll n, ll r) {
return fact[n] * ModInvr(fact[r] * fact[n - r] % Mod) % Mod;}

//*********************************************************//



vector<int> primesrequired(ll n){
vector<int> ans;
fr(i,n+1){
if(isprime[i]== true) ans.push_back(i);    }
return ans;
}

int main(){
clock_t stime = clock();    
Sieve();    
int t;
cin>>t;
while(t--){ 
ll l,r;
cin>>l>>r;
// step 1
vector<int> primes = primesrequired(sqrt(r));
// step 2
vector<int> res(r-l+1,1);
// step 3
for(auto pr: primes){
int firstMultiple = (((l/pr)*pr) < l )?  ((l/pr)*pr)+ pr :((l/pr)*pr);  
for(int j = max(firstMultiple,pr*pr); j<= r; j+= pr) res[j-l] = false;  // (j-l)
}

// step 4 (print)
for (int i =l; i <=r; i++){
if(res[i-l] == 1) cout<<i<<" ";
}
cout<<endl;

}
cout<<"time taken for above oper : "<< (double)(clock()-stime)/CLOCKS_PER_SEC<<" sec"; 
return 0;
}


/*
 " I AM VENGEANCE , I AM THE NIGHT , I AM THE BATMAN ! "
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