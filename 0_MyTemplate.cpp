#include "bits/stdc++.h"
#define ll long long
#define Mod 1000000007
using namespace std;

#ifndef ONLINE_JUDGE
#include "C:/algo/debug.h"
#else
#define debug(x)
#endif

/*-----------------------------------------------------------------*/
int binExpItr(ll a, ll b, ll M){
   a %= M;
   int res = 1;
   while(b > 0){
      if(b & 1)
         res = (res * 1ll * a) % M;
      a = (a * 1ll * a) % M;
      b >>= 1;
   }
   return res;
}

ll ModInvr(ll x){ 
   return (binExpItr(x, Mod - 2, Mod)); 
}

vector<ll> fact, invfact;
void factorial(int n){
   fact.resize(n + 1);
   invfact.resize(n + 1);
   fact[0] = 1;
   for (int i = 1; i <= n; i++)
      fact[i] = (fact[i - 1] * i) % Mod;
   invfact[n] = ModInvr(fact[n]);
   for (int i = n - 1; i >= 0; i--)
      invfact[i] = (invfact[i + 1] * (i + 1)) % Mod;
}

ll Ncr(ll n, ll r){
   if(r > n) return 0;
   return (fact[n] * (invfact[r] * invfact[n - r] % Mod)) % Mod;
}

/*-----------------------------------------------------------------*/
vector<bool> isPrime;
vector<int> spf;

void Sieve(int n){
  isPrime = vector<bool>(n,true);
  spf =vector<int>(n,0);
  isPrime[0] = isPrime[1] = false; 

  for (int i = 2; i <n; i++){
    if(isPrime[i]==true){
      spf[i]  =i;    
      for(int j = 2*i; j <n; j+=i) {
        isPrime[j] = false;
        if(!spf[j]) spf[j] = i;
      }        
    }
  }
}

vector<int> PrimeFacs(int num){
  vector<int> m;
  while(num>1){
    int prmfct = spf[num];
    bool fg = false;
    while(num%prmfct ==0){
      num /= prmfct;
      fg =1;
    }

  if(fg) m.push_back(prmfct);
  }
  return m;
}

/*-----------------------------------------------------------------*/
int dp[100][180][2];
int digitDp(string &num,int n,int sum,bool tight){
  if(sum<0) return 0;
  if(n==1){
    if(sum>=0 && sum<=9) return 1;
    return 0;
  }
  if(dp[n][sum][tight] != -1) return dp[n][sum][tight];

  int ans=0;
  int ub= (tight ? (num[num.length()-n]-'0' ):9);
  for (int digit = 0; digit <=ub; digit++){
    ans += digitDp(num,n-1,sum-digit,(tight&(digit==ub)));
  }

return dp[n][sum][tight] = ans;  
}
// digitDp(s,s.length(),sum,1)

/*-----------------------------------------------------------------*/

vector<int> Lps(string s){
  int n = s.length();
  vector<int> lps(n,0);
  for(int i=1; i<n ;i++){
    int prev = lps[i-1];

     while(prev>0 && s[i]!= s[prev]){
        prev = lps[prev-1];  // previous matches
     }    

    if(s[i]==s[prev]) prev++;
     lps[i] = prev;
  }
return lps;  
}

/*-----------------------------------------------------------------*/
class FunctionalGraph{
  vector<int> successor;
  vector<int> pref;
  vector<int> NumberOfReachableNodes;
  int number_of_cycles,Cycle_Sz,n;
  
  public:
  FunctionalGraph(int n1){
    n = n1+1;
    successor.resize(n);
    pref.resize(n);
    NumberOfReachableNodes.resize(n);
    number_of_cycles =0;
  }

  void add(int u,int v){
    successor[u]= v;
  }

  int dfs(int v,int len=1){
    if(NumberOfReachableNodes[v]) 
      return len;

    if(pref[v]){
      NumberOfReachableNodes[v] = len-pref[v];
      Cycle_Sz = len-pref[v];
        number_of_cycles++;
      return pref[v];
    }

    pref[v] = len;
     int u = successor[v];
    int curr = dfs(u,len+1);
    NumberOfReachableNodes[v] = NumberOfReachableNodes[u];
    if(curr>len) NumberOfReachableNodes[v]++; // not in the cycle
    return curr;
  }

  vector<int> CountCycles(){
    vector<int> cycles;
    for(int i = 1; i <=n; i++){
        Cycle_Sz= -1;
        dfs(i);
        if(Cycle_Sz!= -1)
          cycles.push_back(Cycle_Sz);
    }
    // return number_of_cycles;
    return cycles;
  }

  vector<int> ReachableNodes(){
    CountCycles();
    return NumberOfReachableNodes;
  }

};

void solve(){
   ll n,m,k;
   cin>>n;
   vector<int> a(n);
   for(int i=0; i<n; i++) cin>>a[i];

}

int32_t main(){
   ios_base::sync_with_stdio(false); 
   cin.tie(0); 
   cout.tie(0);
   int t=1;
   cin>>t;
   while(t--) solve();
   return 0;
}
