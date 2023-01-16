#include<bits/stdc++.h>
using namespace std;

const int N=21;
vector<vector<int> > adj(N,vector<int>(N));

long long func(int n,vector<int> arr){
  vector<vector<int> > dp(n,vector<int> (1<<n,0));

  for (int i = 0; i <n; i++){
  dp[i][1<<i] =1;
  }

  for (int mask = 1; mask <(1<<n); mask++){
    for (int i = 0; i <n; i++){
    // checking current element is present in the subset or not(to add the conections)
    if((1&(mask>>i))){
      for(int j=0;j<n;j++){
        if(j!=i && arr[i]!= arr[j] &&(1&(mask>>j)) &&
        adj[arr[i]-1][arr[j]-1] ){
          //:::::::::::::::::::::::
          dp[i][mask] += dp[j][mask^(1<<i)]; // turn off the ith bit because now we have to check connections of jth bit
        }
      }
    }
    }
  }

  long long ans =0;
  for (int i = 0; i <n; i++)
  ans += dp[i][(1<<n)-1]; // connecting all elements(111111...)
return ans;  
}





int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
int t1=1,t_case=1;
//  cin>>t1;

while (t1--){
long long n,m,k;
cin>>n>>m;
vector<int> v ={1,2,3};
// vl a(n);
// fr(i,n) cin>>a[i];
adj.resize(n+1);
while (m--){
  int u,v;
  cin>>u>>v;
  u--;v--;
  adj[u][v]=1;
  adj[v][u]=1;
}


cout<<func(n,v);


}
  return 0;
}

/*
 " I AM VENGEANCE , I AM THE NIGHT , I AM THE BATMAN ! "
____ __ __ __ __ __ ___                             ___ __ __ __ __ __ ____
 `-._:  .:'   `:::  .:\           |\__/|           /::  .:'   `:::  .:.-'
     \      :          \          |:   |          /         :       /
      \     ::    .     `-_______/ ::   \_______-'   .      ::   . /
       |  :   :: ::'  :   :: ::'  :   :: ::'      :: ::'  :   :: :|
       |     ;::         ;::         ;::         ;::         ;::  |
       |  .:'   `:::  .:'   `:::  .:'   `:::  .:'   `:::  .:'   `:|
       /     :           :           :           :           :    \
      /______::_____     ::    .     ::    .     ::   _____._::____\
                    `----._:: ::'  :   :: ::'  _.----'
                           `--.       ;::  .--'
                               `-. .:'  .-'
                                  \    /
                                   \  /
                                    \/
*/


/*
srand(time(NULL));
int cnt =1;
while (cnt<=10){ 
cnt++;  
int n = rand()%10+1;
vector<int> a(n);
fr(i,n){
a[i] = rand()%7 +1;
if(opt(a,n) != brute(a,n)){
cout<<n<<endl;
fr(i,n) cout<<a[i]<<" ";
cout<<endl;
break;  
} }}
*/

