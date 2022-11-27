// Two Pointers Approach
#include<bits/stdc++.h>
using namespace std;

int TrappedWater(vector<int> v){
    int water =0;
    int n= v.size();
    int leftmax = 0,rightmax =0;
    int left =0,right=n-1;   // Two Poiners declared
while (left<=right){
    if (v[left]<= v[right]){
        if (v[left]>leftmax){
            leftmax = v[left];
        }
        else{
        water += leftmax-v[left];
         }
         left++;
    }

    else{
    if (v[right]>=rightmax){
        rightmax = v[right];
    }
    else{
        water += rightmax-v[right];
    }
    right--;
    }
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