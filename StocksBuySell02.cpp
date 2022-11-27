// Multiple times Buy and sell
#include<bits/stdc++.h>
using namespace std;

int MaxProfit(vector<int> v){
 int profit =0;
 for(int i=1;i<v.size();i++){
     if(v[i-1]<v[i]){
         profit += (v[i]-v[i-1]);
     }
 }   
 return profit;
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
cout<<"MaxProfit is: "<<MaxProfit(nums);
    return 0;
}