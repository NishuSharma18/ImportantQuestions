#include "bits/stdc++.h"
#define ll long long
using namespace std;

#ifndef ONLINE_JUDGE
#include "C:/algo/debug.h"
#else
#define debug(x)
#endif

class XOR_BASIS{
    vector<int> basis;
    public:

    void Build(vector<int> a, int n){        
        vector<int> vis(n,0);
        for(int bit= 21 ;bit>=0 ;bit--){
            int ind=-1;
            for(int i=0 ;i<n ;i++){
                if(vis[i]) continue;
                if((a[i]&(1<<bit))){
                    vis[i] = 1;
                    ind = i;
                    break;
                }
            }
            
            if(ind!=-1){
               for(int i=0 ;i<n ;i++){
                    if(vis[i]) continue;
                    if((a[i]&(1<<bit))){
                        a[i] ^=a[ind];
                    }
               }
            }
        }    
        
        // here the remaining array will be the basis
        for(auto it:a){
            if(it!=0) basis.push_back(it);
        }
        sort(basis.rbegin(), basis.rend());
    }    
        
    int MaxSubsetXOR(){    
        int ans=0;
        int n = basis.size();
        int ind =0;
        for(int bit =21 ;bit>=0; bit--){
            if(ind>=n) break;
            if((ans &(1<<bit))) continue;
            if((1<<bit)> basis[ind]) continue;
            
            while(ind<n){
                if(1<<(bit+1)> basis[ind]) break;
                ind++;
            }
            if(ind>=n) break;
            
            if((basis[ind] &(1<<bit)) && !(ans &(1<<bit))){
                ans ^= basis[ind];
                ind++;
            } 
        }
       return ans;
    }
};

void solve(){
   int n;
   cin>>n;
   vector<int> a(n);
   for(int i=0; i<n; i++) cin>>a[i];
   XOR_BASIS b;
   b.Build(a,n);
   cout<<b.MaxSubsetXOR()<<'\n';
}

int32_t main(){
   ios_base::sync_with_stdio(false); 
   cin.tie(0); 
   cout.tie(0);
   int t=1;
   cin>>t;
   while(t--){
    solve();
   }
    
   return 0;
}
