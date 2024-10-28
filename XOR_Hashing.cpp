#include "bits/stdc++.h"
#define ll long long
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define all(v) v.begin(),v.end()
#define Mod 1000000007
using namespace std;
/* Fear says "WHAT IF", Faith says "EVEN IF" */

#ifndef ONLINE_JUDGE
#include "C:/algo/debug.h"
#else
#define debug(x)
#endif

ll getRandomNumber(ll l, ll r) {
   static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
   return uniform_int_distribution<ll>(l, r)(rng);
} 
// getRandomNumber(0,INT64_MAX)

void solve(){
   ll n,m,k;
   cin>>n;
   vector<int> a(n),b(n);
   for(int i=0; i<n; i++) cin>>a[i];
   for(int i=0; i<n; i++) cin>>b[i];

   map<int, long long> hash_vals;
	for(int i=0; i<n; i++){
		if(!hash_vals.count(a[i])) hash_vals[a[i]] = getRandomNumber(0,INT64_MAX);
	}
	for(int i=0; i<n; i++){
		if(!hash_vals.count(b[i])) hash_vals[b[i]] = getRandomNumber(0,INT64_MAX);
	}

   set<int> vis;
	vector<long long> a_xor(n);
	for (int i = 0; i <n; i++) {
		if (!vis.count(a[i])) {
			a_xor[i] = hash_vals[a[i]];
			vis.insert(a[i]);
		}
		if(i > 0) { a_xor[i] ^= a_xor[i - 1]; }
	}

   vis.clear();
	vector<long long> b_xor(n);
	for (int i = 0; i <n; i++) {
		if (!vis.count(b[i])) {
			b_xor[i] = hash_vals[b[i]];
			vis.insert(b[i]);
		}
		if(i > 0) { b_xor[i] ^= b_xor[i - 1]; }
	}

   int q;
   cin>>q;
   while(q--){
      int x,y;
      cin>>x>>y;
      x--;y--;
      if(a_xor[x]==b_xor[y]){
         cout<<"Yes\n";
      }
      else{
         cout<<"No\n";
      }
   }
}

int32_t main(){
   ios_base::sync_with_stdio(false); 
   cin.tie(0); 
   cout.tie(0);
   solve();
   return 0;
}
/*
   XOR HASHING 
   comparing two sets- but here we can't query to specific (L,R)
   as we're just taking the element as unique
   https://atcoder.jp/contests/abc250/tasks/abc250_e

   for comparing multiset instead of XOR sum, just take simple summation
   https://atcoder.jp/contests/abc367/tasks/abc367_f 
*/