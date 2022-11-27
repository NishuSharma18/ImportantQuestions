#include<bits/stdc++.h>
using namespace std;

// function<void(int,int)> dfs = [&](int s, int p) {
//     vis[s] = 1;
//     bool ok = 1; // used for articulation points
//     if (p != -1) lvl[s] = lvl[p] + 1;
//     for (auto x: g[s]) {
//       if (x == p) continue;
//       if (vis[x]) dp[s] = min(dp[s], lvl[x]);
//       else {
//         dfs(x, s);
//         dp[s] = min(dp[s], dp[x]);
//         ok &= (dp[x] < lvl[s]);
//         if (dp[x] > lvl[s]) {
//           // edge s -> u is a bridge
//           cout << s << " -> " << x << '\n';
//         }
//       }
//     }
//     // if ok is false then s is a articulation point
//     // if (!ok) cout << s << '\n'; 
//   };
//   lvl[0] = 0;
//   dp[0] = 0;
//   dfs(0, -1);


int main(){
    
    return 0;
}