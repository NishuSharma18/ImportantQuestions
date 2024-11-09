#include "bits/stdc++.h"
#define ll long long
#define int long long
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define all(v) v.begin(),v.end()
#define Mod 1000000007
using namespace std;
/* Fear says "WHAT IF", Faith says "EVEN IF" */

ll cost[3001][3001];
int m,n;
vector<long long> dp_before, dp_cur;

void compute(int l, int r, int optl, int optr) {
   if (l > r) return;
   int mid = (l + r) >> 1;
   pair<long long, int> best = {LLONG_MAX, -1};
   for (int k = optl; k <= min(mid, optr); k++) {
      best = min(best, {(k ? dp_before[k - 1] : 0) + cost[k][mid], k});
   }
   dp_cur[mid] = best.first;
   int opt = best.second;
   compute(l, mid - 1, optl, opt);
   compute(mid + 1, r, opt, optr);
}

void solve(){
   cin>>n>>m;
   vector<int> a(n);
   for(int i=0; i<n; i++) cin>>a[i];
   dp_before.assign(n,0);
   dp_cur.assign(n,0);
   
   for(int i=0; i<n; i++){
      ll tot=0;
      for(int j=i; j<n; j++){
         tot+= a[j];
         cost[i][j] = (tot*tot);
      }
   }

   for(int i = 0; i < n; i++)
      dp_before[i] = cost[0][i];

   for(int i = 1; i <m; i++) {
      compute(0, n - 1, 0, n - 1);
      dp_before = dp_cur;
   }

   cout<<dp_before[n - 1]<<'\n';   
}

int32_t main(){
   ios_base::sync_with_stdio(false); 
   cin.tie(0); 
   cout.tie(0);
   solve();
   return 0;
}
/*
   https://cp-algorithms.com/dynamic_programming/divide-and-conquer-dp.html
   https://usaco.guide/plat/DC-DP?lang=cpp
   https://cses.fi/problemset/task/2086/
*/
