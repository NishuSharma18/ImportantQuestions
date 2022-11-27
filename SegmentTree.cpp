#include<bits/stdc++.h>
using namespace std;

// --> SEGMENT TREE CONSTRUCTION <--
const int N = 1e6+7;
const int infmn = INT_MIN;
vector<vector<int>> tree(4*N,vector<int>(3));


void Build(int node,int start,int end,string &s){
   if(start== end){
   tree[node][0] = s[start] =='('; //open brackets
   tree[node][1] = s[start] ==')'; // close brackets
   tree[node][2] = 0; // full brackets
    return;
   }

  int mid = (start+end)>>1;
  Build(2*node,start,mid,s);  
  Build(2*node+1,mid+1,end,s); 

    tree[node][0] = tree[2*node][0] + tree[2*node+1][0]- min(tree[2*node][0],tree[2*node+1][1]); 
    tree[node][1] = tree[2*node][1] + tree[2*node+1][1]- min(tree[2*node][0],tree[2*node+1][1]); 
    tree[node][2] = tree[2*node][2] + tree[2*node+1][2]- min(tree[2*node][0],tree[2*node+1][1]); 
}


// for queries
vector<int> query(int node,int st,int end,int l,int r){
    vector<int> res(3,0);
    if(st>r || end<l){
        return res;
    }
    if(st>=l && end <=r){
        return tree[node];
    }

    int mid = (st+end)>>1;
    vector<int> q1= query(2*node ,st ,mid ,l, r);
    vector<int> q2= query(2*node +1 ,mid+1 , end,l, r);

    res[0] = q1[0] + q2[0]- min(q1[0],q2[1]); 
    res[1] = q1[1] + q2[1]- min(q1[0],q2[1]); 
    res[2] = q1[2] + q2[2]- min(q1[0],q2[1]); 
    return res;
}



int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);    
string s;
cin>>s;
int n,m,k;
cin>>m;
// vector<int> a(n);
// for (int i = 0; i <n; i++)
//  cin>>a[i];  

n = s.size();
Build(1,0,n-1,s);

while(m--){
int l,r;
cin>>l>>r;
cout<<(query(1,0,n-1,l-1,r-1)[2] *(-2))<<"\n";
}
    return 0;
}