#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define iv(v) for(auto & v1:v) cin>>v1
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define removeDuplicate(v) v.erase(unique(all(v)),v.end())
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define fr(i,n) for(int i=0;i<n;i++)
#define stBit(n,i) (n|(1<<i))
#define unstBit(n,i) ((~(1<<i)) &n)
#define bs(v,x) binary_search(all(v),x)
#define sumv(v) accumulate(all(v),0)
#define Fr(i,a,b) for(int i=a; (a<b)?i<b:i>=b ; (a<b)? i++:i--)
#define travrs(m) for(auto it =m.begin();it!=m.end();it++)
#define mx(v) *max_element(all(v))
#define mn(v) *min_element(all(v))
#define Mod 1000000007
#define pb push_back
#define PI 3.1415926535897932384626
using namespace std;
// using namespace __gnu_pbds;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<pair<ll,ll> > vpll;
typedef vector<pair<int,int> > vp;
typedef unordered_map<ll,ll> um;
typedef unsigned long long ull;
typedef long double ld;
// #define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update>
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// #define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_set tree<int, null_type,greater<int>, rb_tree_tag,tree_order_statistics_node_update>
// #define ordered_set tree<int, null_type,greater_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
//  S.order_of_key -> element smaller than  || *S.find_by_order -> value at index   


// --------->>> Debugging <<<-------
#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" ";_print(x); cerr<<endl;
#else
#define debug(x)
#endif

void _print(ll t){cerr<<t;}
void _print(int t){cerr<<t;}
void _print(char t){cerr<<t;}
void _print(string t){cerr<<t;}
void _print(double t){cerr<<t;}
void _print(ull t){cerr<<t;}
void _print(ld t){cerr<<t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T v1 : v) {_print(v1); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> s) {cerr << "[ "; for (T s1 : s) {_print(s1); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> s) {cerr << "[ "; for (T s1 : s) {_print(s1); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> m) {cerr << "[ "; for (auto m1 : m) {_print(m1); cerr << " ";} cerr << "]";}
// ---------->>>  ###########  <<<---------- // 


// --> LAZY SEGMENT TREE CONSTRUCTION(node =1) <--
const int N = 1e5+7;
const int infmn = INT_MIN;
vector<int> tree(4*N),lazy(4*N);


void Build(int node,int start,int end,vector<int> &v){
   if(start== end){
   tree[node] = v[start];
    return;
   }

  int mid = (start+end)>>1;
   Build(2*node,start,mid,v); 
   Build(2*node+1,mid+1,end,v); 

    // tree[node] = max(tree[2*node],tree[2*node+1]);
    tree[node] = (tree[2*node]+tree[2*node+1]);
return;
}

// for queries
int query(int node,int st,int end,int l,int r){
    if(lazy[node]!=0){
      tree[node] +=((end-st+1)*(lazy[node]));
      if(st!= end){
        lazy[2*node] +=lazy[node];
        lazy[2*node+1] +=lazy[node];
      }
      lazy[node] =0;
    }

    if(st>r || end<l){
        return 0;
    }
    if(st>=l && end <=r){
        return tree[node];
    }
    int mid = (st+end)>>1;
    int q1= query(2*node ,st ,mid ,l, r);
    int q2= query(2*node +1 ,mid+1 , end,l, r);
    return (q1+q2);
}

void Update(int node,int st,int end,vector<int> &a,int l,int r,int val){
    if(lazy[node]!=0){
      tree[node] +=((end-st+1)*(lazy[node]));
      if(st!= end){
        lazy[2*node] +=lazy[node];
        lazy[2*node+1] +=lazy[node];
      }
      lazy[node] =0;
    }
    
    if(st>r || end<l){
        return ;
    }

    if(st>=l && end <=r){
      ll tmp = (end-st+1)*val ;
      tree[node]+= tmp;
      if(st!= end){
        lazy[2*node] +=val;
        lazy[2*node+1] +=val;
      }      
        return ;
    }

    int mid = (st+end)>>1;
    Update(2*node,st,mid,a,l,r,val);        
    Update(2*node +1,mid+1,end,a,l,r,val);

tree[node] = (tree[2*node]+tree[2*node +1]);
return;
}


/*
// --> SEGMENT TREE CONSTRUCTION <--
const int N = 1e5+7;
const int infmn = INT_MIN;
vector<int> tree(4*N);


void Build(int node,int start,int end,vector<int> &v){
   if(start== end){
   tree[node] = v[start];
    return;
   }

  int mid = (start+end)>>1;
   Build(2*node,start,mid,v); 
   Build(2*node+1,mid+1,end,v); 

    tree[node] = max(tree[2*node],tree[2*node+1]);
}

// for queries
int query(int node,int st,int end,int l,int r){
    if(st>r || end<l){
        return infmn;
    }
    if(st>=l && end <=r){
        return tree[node];
    }
    int mid = (st+end)>>1;
    int q1= query(2*node ,st ,mid ,l, r);
    int q2= query(2*node +1 ,mid+1 , end,l, r);

    return max(q1,q2);
}

void Update(int node,int st,int end,vector<int> &a,int ind,int val){
    if(st==end){
        a[st]= val;
        tree[node]= val;
        return;
    }
    int mid = (st+end)>>1;
    if(ind<=mid){
        Update(2*node,st,mid,a,ind,val);        
    }
    else{
        Update(2*node +1,mid+1,end,a,ind,val);
    }
// backtracking
tree[node] = max(tree[2*node],tree[2*node +1]);

}


*/




int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
int t1=1,t_case=1;
//  cin>>t1;

while (t1--){
ll n,m,k;
cin>>n>>k;
vi a(n);
fr(i,n) cin>>a[i];

tree.resize(4*(n+3));
lazy.resize(4*(n+3));
Build(0,0,n-1,a);


while (k--){
  int type;
  cin>>type;
  if(type==1){
    int l,r,val;
    cin>>l>>r>>val;
  l--;
  r--;

    Update(1,0,n-1,a,l,r,val);
    debug(tree)
  }


  else{
    int l,r;
    cin>>l>>r;
    l--;
    r--;
    cout<<query(1,0,n-1,l,r)<<'\n';

  }
}



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

