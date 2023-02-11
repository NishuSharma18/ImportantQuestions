/*
    maximum sum increasing subsequence 
*/

#include<bits/stdc++.h>
using namespace std;

// Memoization (sometimes gives TLE)
const int N = 1e5+7;
int dp[N];
int MSIS(vector<int> &v,int i){
    if(dp[i]!=-1) return dp[i];
    int ans = v[i];

    for (int j =0; j<i; j++){
        if(v[i] >= v[j]){
            ans = max(ans, MSIS(v,j)+v[i]);
        }
    }
 return dp[i] = ans;   
}

// Tabulation
int MSIStb(vector<int> &v,int n){
    int dp[n];
    for (int i = 0; i <n; i++) dp[i] = v[i];

    for (int i = 1; i <n; i++){
       for(int j =0;j<i;j++){
        if(v[i]>= v[j] && dp[i] <dp[j]+v[i]){
          dp[i] =dp[j]+v[i];  
        }
       } 
    }

    int res =-1;
    for (int i = 0; i <n; i++){
        res = max(res,dp[i]);
    }
    
    return res;
}

/*
LIS -- Tabulation
*/

int LIS(vector<int> &v,int n){
    int dp[n];
    for (int i = 0; i <n; i++) dp[i] =1;

    for (int i = 1; i <n; i++){
       for(int j =0;j<i;j++){
        if(v[i]> v[j] && dp[i] <dp[j]+1){
          dp[i] =dp[j]+1;  
        }
    } 
}

    int res =-1;
    for (int i = 0; i <n; i++){
        res = max(res,dp[i]);
    }
    return res;
}




int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i <n; i++){
        cin>>v[i];
    }

    int res = -1;
    for (int i = 1; i <n; i++){
        memset(dp,-1,sizeof(dp));
        res = max(res,MSIS(v,i));
    }
    
    cout<<res<<'\n';
    cout<<LIS(v,n)<<'\n';

    return 0;
}