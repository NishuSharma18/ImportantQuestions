/* Microsoft::
Given an array of size N and we have to find the count of 
distinct element in every window of size K.
in O(N) time
*/ 

#include<bits/stdc++.h>
using namespace std;

int main(){
int n,k;
cin>>n>>k;
vector<int> v(n);
for(auto & v1:v){
    cin>>v1;
}

// -->>
unordered_map<int ,int> m;
for (int i = 0; i <k; i++){
m[v[i]]++;
}
cout<<m.size()<<endl;

for (int i =k; i <n; i++){
if(m[v[i-k]] ==1){
m.erase(v[i-k]);
}else{
m[v[i-k]]--;   
}

m[v[i]]++;
cout<<m.size()<<endl;
}

    return 0;
}