#include<bits/stdc++.h>
using namespace std;

int MCM(vector<int> &v,int n){
    vector<vector<int> > dp(n-1,vector<int>(n-1));

    for (int gap = 0; gap <dp.size(); gap++){
      for(int i=0,j=gap;j<dp.size() ;i++,j++){
        
        if(gap==0){// diagonal
            dp[i][j]=0;
        }
        else if(gap==1){
           dp[i][j] = (v[i] *v[j]* v[j+1]); 
        }
        else{
            int mn = INT_MAX;
           for(int k=i;k<j;k++){
            // (i,k)--> left half and (k+1,j)--> right half 
            int lcost = dp[i][k];
            int rcost = dp[k+1][j];
            int multicost = (v[i]*v[k+1]*v[j+1]);
            mn = min(mn,lcost+rcost+multicost);
           } 
           dp[i][j] = mn;
        }

      }  
    }

 // top right corner
 return dp[0][n-1];   
}



int main(){
    int n;
    cin>>n;
    vector<int> v(n);
 
    return 0;
}