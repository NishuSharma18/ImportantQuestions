#include<bits/stdc++.h>
#define ll long long
using namespace std;

//:::::: Bitwise AND of Number Range:::::::::::
ll rangeAnd(ll n,ll m){
  ll res =0;
  for (int bit = 62; bit>=0; bit--){
    if( (n&(1LL<<bit)) != (m &(1LL<<bit))){
      break; // not matched
    }
    else{
      res |=(n&(1LL<<bit));
    }
  }
  return res;
}


int main(){
  
  return 0;
}