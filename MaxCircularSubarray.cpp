#include<bits/stdc++.h>
using namespace std;

int kadane(int a[],int n){
int sum =0,maxsum=a[0];
for (int i = 0; i <n; i++){
sum+= a[i];
if(sum>maxsum) maxsum =sum;
if(sum<0) sum=0;
}
return maxsum;   
}

int main(){
int n;
cin>>n;
int a[n];
int arrSum=0;
for (int i = 0; i <n; i++){
cin>>a[i];
arrSum+= a[i];
}

int res1 = kadane(a,n);

// for non contributing terms
for (int i = 0; i <n; i++){
a[i]*= -1;
}
int res2 = arrSum + kadane(a,n);

cout<<max(res1,res2);

return 0;
}