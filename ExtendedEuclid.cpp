#include<bits/stdc++.h>
using namespace std;
// ax+ by = gcd(a,b);
// gcd(a,0) = a

class Triplet{
public:    
int x,y,gcd;
};

Triplet extendedEuclid(int a,int b){
if(b==0){
Triplet ans;
ans.x =1;
ans.gcd = a;
ans.y =0;
return ans;}

Triplet smallAns = extendedEuclid(b,a%b);
Triplet ans;
ans.gcd = smallAns.gcd;
ans.x = smallAns.y;
ans.y =  smallAns.x -(a/b)*smallAns.y ;
return ans;
}

int main(){
// int a,b;
// cin>>a>>b;
// Triplet ans = extendedEuclid(a,b);
// cout<<ans.gcd<<" "<<ans.x<<" "<<ans.y;

//for Multiplicative Inverse of a wrt M
// put b= M
// and obviously gcd(a,m) =1 , otherwise MMI does not exist;
int A,M;
cin>>A>>M;
Triplet ans1 = extendedEuclid(A,M);
if(ans1.x <0){  // to avoid negative values;    equals to (ans.x)%M
while (ans1.x<0){
ans1.x += M;
}}

if(ans1.gcd ==1) cout<<"MMI is : "<<(ans1.x)%M<<endl;
else cout<<"MMI does not exist\n";

return 0;
}