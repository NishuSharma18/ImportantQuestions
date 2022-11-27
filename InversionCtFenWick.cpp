#include<bits/stdc++.h>
#define ll long long
using namespace std;

// Fenwick Tree
const int N = 2e5+10;
vector<ll> Bit(N);

void UpdateFW(ll i,ll x){
for (; i <=Bit.size(); i+=(i&(-i))){
  Bit[i] += x;
}
}

ll valueFw(ll i){
 ll ans =0;
 for(; i>0;i-=(i&(-i)))
 ans +=Bit[i];
return ans;
}

void CreateFW(vector<ll> a){
  for (int i = 0; i <a.size(); i++)  
  UpdateFW(i+1,a[i]);
}


int main(){
vector<int> v ={8,2 ,9,2,8};
ll n = *max_element(v.begin(),v.end());
 Bit.clear();
 Bit.resize(n+1);

/*
// array compression ::
map<ll,int> mp;
for (int i = 0; i <v.size(); i++){
mp[v[i]];
}

int ct=1;
for(auto &m1: mp){
   m1.second = ct;
   ct++; 
}
for (int i = 0; i <v.size(); i++){
    v[i] = mp[v[i]];
}
*/



ll res =0;
for (int i = 0; i <5; i++){
    res+= (valueFw(n+1) - valueFw(v[i])); 
    UpdateFW(v[i],1);
}

cout<<res<<endl;
    
    return 0;
}