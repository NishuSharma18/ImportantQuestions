#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 2e5 + 5, MX = 20;

// HLD
ll value[ N] = {0}, heavyChild[ N] = {0}, weight[ N] = {0};
ll treepos[N] = {0}, treeIndex[N] = {0};
vector< ll> adj[N];
ll global_treepos;
ll parents[ N][ MX];
ll In[ N], Out[ N];
ll global_time;

class segmentTree{
public:
    ll n, k;
    vector< ll> tree;
    
    ll query( ll l, ll r){
        ll res = 0;
        
        for( l += n, r += n; l <= r; l >>= 1, r >>= 1){
            if( l & 1) res += tree[ l++];
            if( !(r & 1)) res += tree[ r--];       
        }
        
        return res;
    }
    
    void update( ll p, ll val){
        tree[ p + n] = val;
        for( ll i = (p + n) >> 1; i > 0; i >>= 1){
            tree[ i] = tree[ i << 1] + tree[ i << 1 | 1];
        }
    }
    
    segmentTree( vector< ll> v){
        n = v.size();
        k = 1;
        while( k < n){
            k = k << 1;
        }
        while( n < k){ n++; v.push_back( 0);}
        tree.resize( k * 2, 0);
        
        for( ll i = n; i <= 2 * k - 1; i++){
            tree[ i] = v[ i - n];
        }
        
        for( ll i = n - 1; i > 0; i--){
            tree[ i] = tree[ i << 1] + tree[ i << 1 | 1];
        }
    }

    segmentTree(){
    }
};
segmentTree *st;

void HLdfs( ll node, ll par){
    // dfs for finding the weight and heavy child of nodes.
    weight[ node] = 1;
    heavyChild[ node] = -1;

    for( auto next : adj[ node]){
        if( next != par){
            HLdfs( next, node);
            weight[ node] += weight[ next];

            if( weight[ next] > weight[ heavyChild[ node]]){
                heavyChild[ node] = next;
            }
        }
    }
}
void BinaryLift( ll node, ll parent){
    if( parent <= 0) global_time = 0;

    parents[ node][ 0] = parent;
    In[ node] = ++global_time;
    
    ll i = 1;
    for( ; i < MX; i++){
        ll mid = parents[ node][ i - 1];
        if( mid == -1){
            parents[ node][ i] = -1;
            break;
        }
        parents[ node][ i] = parents[ mid][ i - 1];
    }
    
    for( ; i < MX; i++){
        parents[ node][ i] = -1;
    }
    
    for( auto next : adj[ node]){
        if( next != parent)
            BinaryLift( next, node);
    }
    
    Out[ node] = ++global_time;
}

bool isParent( ll x, ll y){
    return In[ x] <= In[ y] && Out[ x] >= Out[ y];
}
ll lca( ll x, ll y){
    if( isParent( x, y) || !( x - y))
        return x;
    if( isParent( y, x))
        return y;
    
    for( ll i = MX - 1; i >= 0; i--){
        ll mid = parents[ x][ i];
        if( mid != -1 &&  !isParent( mid, y)){
            x = mid;
        }
    }
    return parents[ x][ 0];
}

void decompose( ll node, ll parent, ll index){
    // decompose the heavy and light edges and build the segment tree
    if( index == -1){
        treeIndex[ node] = node;
    }else{
        treeIndex[ node] = index;
    }

    treepos[ node] = global_treepos++;

    if( heavyChild[ node] != -1){
        decompose( heavyChild[ node], node, treeIndex[ node]);
    }

    for( ll next : adj[ node]){
        if( next != parent && next != heavyChild[ node]){
            decompose( next, node, -1);
        }
    }
}

void HLD( ll n){
    // Peform all the pre-computation work for HLD and build segment tree
    HLdfs( 1, 0);
    BinaryLift( 1, 0);
    global_treepos = 0;
    decompose( 1, 0, -1);

    vector< ll> v( n);
    for( ll i = 1; i <= n; i++){
        v[ treepos[ i]] = value[ i];
    }
    
    st = new segmentTree( v);
}
void update( ll node, ll x){
    value[ node] = x;
    st -> update( treepos[ node], x);
}
ll query( ll u, ll v){
    ll a = lca( u, v), utop = treeIndex[ u], vtop = treeIndex[ v];

    ll sum = 0;

    while( isParent( a, u)){
        ll par;
        if( isParent( a, utop)){
            par = utop;
        }else{
            par = a;
        }
        sum += st-> query( treepos[ par], treepos[ u]);
        u = parents[ par][ 0];
        utop = treeIndex[ u];
    }
    while( isParent( a, v)){
        ll par;
        if( isParent( a, vtop)){
            par = vtop;
        }else{
            par = a;
        }
        sum += st-> query( treepos[ par], treepos[ v]);
        v = parents[ par][ 0];
        vtop = treeIndex[ v];
    }
    sum -= value[ a];
    return sum;
}

// first call HLD(n) { here n is the number of nodes in the tree}
// call update(x, s) update function to update the value of xth node to s
// call query( u, v) to get the query for the path from u to v

bool testcase = false;
void solve(){
    // taking tree as input.
    ll n, q; cin>> n>> q;
    for( ll i = 1; i <= n; i++){
        cin>> value[ i];
    }
    for( ll i = 0; i < n - 1; i++){
        ll u, v; cin>> u>> v;

        adj[ u].push_back( v);
        adj[ v].push_back( u);
    }

    HLD( n);

    while( q--){
        ll type; cin>> type;
        if( type == 1){
            ll s, x; cin>> s>> x;
            update( s, x);
        }else{
            ll s; cin>> s;
            cout<< query( 1, s)<< '\n';
        }
    }
}



int main(){
    ll t = 1;
    if( testcase) cin>> t;
    while( t--){
        solve();
    }
    return 0;
}