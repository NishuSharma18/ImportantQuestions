#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> res;

void generate(vector<int> &subset,int i,vector<int> &nums ){   //Note: Vector pass by reference to avoid copies
    if(i==nums.size()){
        res.push_back(subset);
        return;
    }
    // ith element not in subset;
    generate(subset,i+1,nums);

    // ith element is in the subset;
    subset.push_back(nums[i]);
     generate(subset,i+1,nums);
     subset.pop_back();
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int i = 0; i <n; i++){
        cin>>nums[i];
    }
    vector<int> v;

    generate(v,0,nums);
    for(auto ele:res){
        for(auto e1 :ele){
            cout<<e1<<" ";
        }
        cout<<endl;
    }
/*
int n;
cin>>n;
for (int i = 1; i <= n; i++){
    for(int j=1;j<=i;j++){
        cout<<j<<" ";
    }
    for (int j = 1; j<=2*n-1-2*i; j++){
        cout<<"  ";
    }
    
    for (int j = i ; j >=1; j--){
        if(j==n){
            j--;
        }
        cout<<j<<" ";
    } 
    cout<<endl; 
}
*/
    return 0;
}