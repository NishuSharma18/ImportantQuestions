#include<bits/stdc++.h>
using namespace std;

int main(){
int n,sum;
cin>>n>>sum;
int a[n];
unordered_map<int,int> m;
vector<pair<int,int>> v;
for (int i = 0; i <n; i++){
cin>>a[i];
}

int curSum =0;
// int a1[n];
// a1[0] =a[0];
// for (int i = 1; i <n; i++){
// a1[i] = a1[i-1] + a[i];
// }

for (int i = 0; i < n; i++){
curSum += a[i];
if(curSum == sum) v.push_back(make_pair(0,i));

if(m.find(curSum-sum) != m.end()){
// auto it = m.find(curSum-sum);     
v.push_back(make_pair(m[curSum-sum]+1,i));
// v.push_back(make_pair(it->second+1,i));
}


m[curSum] = i;    
       
}

int n1 = v.size();
if(n1==0) cout<<"NO such Subarray Exist!\n";
else{
for(auto v1:v){
cout<<v1.first<<" "<<v1.second<<endl;    
}    
}

return 0;
}