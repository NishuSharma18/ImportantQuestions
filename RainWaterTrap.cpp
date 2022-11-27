#include<bits/stdc++.h>
using namespace std;

int TrappedWater(vector<int> v){
    int water =0;
    int n = v.size();
    vector<int> left,right;    //Creating two arrays
    left.assign(n,0);
    right.assign(n,0);    // Because of Runtime error
    left[0] =v[0];
    for (int i = 1; i < n; i++){
        left[i] = max(v[i],left[i-1]);
    }
    
    right[n-1] = v[n-1]; 
    for (int i = n-2; i >=0; i--){
        right[i] = max(right[i+1],v[i]);
    }

for (int i = 0; i <n; i++){
    water += min(right[i],left[i]) - v[i];
}
    return water;
}

int main(){
 vector<int> nums;
int n; 
cin>>n;
for (int i = 0; i < n; i++){
    int ele;
    cin>>ele;
    nums.push_back(ele);
}
cout<<"The Trapped Water is: "<<TrappedWater(nums)<<" Units\n";
    return 0;
}