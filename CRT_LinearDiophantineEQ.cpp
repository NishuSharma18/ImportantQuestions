#include<bits/stdc++.h>
using namespace std;

class triplet {
  public:
  long long x,y,gcd;

triplet(){} // default constructor

 triplet(long long x1,long long y1,long long gcd1){
    x = x1;
    y = y1;
    gcd = gcd1;
  }
};


// :::::: Solution of linear Diophantine Equation ::::::
triplet ExtendedEuclid(long long a ,long long b){
  if(b==0){
    triplet t(1,0,a);
    return t;
  }

  triplet t1 = ExtendedEuclid(b,a%b);
  triplet ans;
  ans.gcd = t1.gcd;
  ans.x = t1.y;
  ans.y = t1.x-(a/b)*(t1.y);

  return ans;
}



/*
:::::: CRT::::
a == a1(mod n1);
a == a2(mod n2);
*/

int CRT(long long a1,long long n1,long long a2,long long n2){
  triplet t = ExtendedEuclid(n1,n2); // x' , y' , gcd(n1,n2)

  long long x = t.x;
  long long gcd = t.gcd;
  /*
  a1-a2 = k* gcd(n1,n2) /// then only solution exist
  (a1-a2)% gcd===0 
  */

 if((a1-a2)%gcd !=0){
  return -1;
 }
  
  else{
    long long k = (a1-a2)/gcd;
  long ans = a1- n1*((k*x )%(n2/gcd)) ;
long long lcm = (n1*n2)/gcd;

if(ans<0) ans+= lcm;
  return ans;
  }
}


int main(){
  int t;
  cin>>t;
  while(t--){
  long long a1,n1,a2,n2;
  cin>>a1>>n1>>a2>>n2;
  cout<<CRT(a1,n1,a2,n2)<<"\n";
  }

/*
3
10000 23000 9000 23000
10000 23000 10000 23000
1234 2000 746 2002

output:
-1
10000
489234

*/


  return 0;
}