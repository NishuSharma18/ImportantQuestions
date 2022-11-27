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
#define travrs(m,it) for(auto it =m.begin();it!=m.end();it++)
#define mx(v) *max_element(all(v))
#define mn(v) *min_element(all(v))
#define Mod 1000000007
#define pb push_back
#define mp make_pair
#define PI 3.1415926535897932384626
using namespace std;
using namespace __gnu_pbds;

int binExpItr(ll a,ll b){ a %=Mod;    
int res =1;
while (b){
if(b&1) res = (res *1ll *a)%Mod;
a = (a* 1ll* a)%Mod;
b >>=1;  }
return res;}

ll ModInvr(ll x,ll m){return (binExpItr(x,m-2));}
ll fact[1000007];
void factorial(){ fact[0]=1;
 Fr(i,1,1000007) fact[i] = (fact[i-1]*i)%Mod;}
ll Ncr(ll n, ll r) {
return fact[n] * ModInvr(fact[r] * fact[n - r] % Mod,Mod) % Mod;}


ll CRT(vector<pair<ll,ll> > &v){ // {(2,1), (3,2), (5,3)}  -> (p,k) 
// p1,p2...pn are relatively prime
ll ans =0;
ll n = v.size();
ll m =1;
fr(i,n) m*= v[i].first; 
// m = p1*p2*p3......*pn  

fr(i,n){
ll t=1;
for (ll j = 0; j<i; j++){
t *= v[j].first;
t *= ModInvr(v[j].first,v[i].first);
t%=m; }

ans += (t*(v[i].second+m-ans))%m;
ans %=m;
}
return ans;
}


int main(){
int n;
cin>>n;
vector<pair<ll,ll> > v(n);
fr(i,n){
cin>>v[i].first>>v[i].second;
}    
cout<<CRT(v);

    
return 0;
}