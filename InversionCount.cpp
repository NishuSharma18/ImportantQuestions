#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll Merge(int arr[],int l,int mid,int r){
 ll invCt =0;
 int n1 = mid-l+1;
 int n2 = r - mid;
 int a[n1];
 int b[n2];
 for(int i=0;i<n1;i++) a[i] = arr[l+i];
 for(int i=0;i<n2;i++) b[i] = arr[mid+i+1];

int i=0,j=0,k=l;
while(i<n1 && j<n2){
if(a[i]<=b[j]){ 
arr[k] =a[i];    
k++;i++;
}
else{
arr[k] = b[j];  
invCt += n1-i;   
k++;j++;
}
}
// Remaining element::
while (i<n1){
arr[k] = a[i];
k++;i++;
}
while (j<n2){
arr[k] = b[j];
k++;j++;
}
return invCt;
}
// -->>
ll mergeSort(int arr[],int l,int r){
ll invCt =0;
if(l<r){
int mid = l+(r-l)/2;
invCt += mergeSort(arr,l,mid);
invCt += mergeSort(arr,mid+1,r);
invCt += Merge(arr,l,mid,r);
}
return invCt;
}

int main(){
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++){
cin>>a[i];
}
cout<<mergeSort(a,0,n-1)<<endl;

return 0;
}