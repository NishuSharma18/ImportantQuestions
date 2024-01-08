#include<bits/stdc++.h>
#define ll long long
using namespace std;


struct update{
    // Two types of updates 
    ll setval;
    ll increment;
    /*
        first set the value to 'setval' and then increase it by 'increment'
    */ 
    update(){
        setval = -1;
        increment = 0;
    }

    update(ll setval, ll increment){
        this->setval = setval;
        this->increment = increment;
    }

    // overload the equals operator
    bool operator==(const update & other)const {
        return (setval== other.setval && increment== other.increment);
    }
};


template<class T, class U>
// T -> node, U->update.
struct Lsegtree{
    vector<T>st;
    vector<U>lazy;
    ll n;
    T identity_element;
    U identity_update;

    Lsegtree(ll n, T identity_element, U identity_update){
        this->n = n;
        this->identity_element = identity_element;
        this->identity_update = identity_update;
        st.assign(4*n,identity_element);
        lazy.assign(4*n, identity_update);
    }

    T combine(T l, T r){
        // change this function as required.
        T ans = (l + r);
        // T ans = __gcd(l,r);
        // T ans = max(l,r);
        return ans;
    }

    void buildUtil(ll v, ll tl, ll tr, vector<T>&a){
        if(tl == tr){
           st[v] = a[tl];
           return;
        }
        ll tm = (tl + tr)>>1;
        buildUtil(2*v + 1, tl, tm,a);
        buildUtil(2*v + 2,tm+1,tr,a);
        st[v] = combine(st[2*v + 1], st[2*v + 2]);
    }

    // change the following 2 functions, and you're more or less done.
    T apply1(T curr, U upd, ll tl, ll tr){
        // for replacing the value as upd    
        // T ans = (tr-tl+1)*upd;
        
        //for incrementing range by upd
        T ans = curr + (tr-tl+1)*upd;

        // for max query and assign value update
        // T ans = upd;
        // for max query and increment range by upd update
        // T ans = curr+upd;
      return ans;
    }

    T apply(T curr, U upd, ll tl, ll tr){
       T ans = curr;

       if(upd.setval != -1){
           ans = ((tr-tl+1)*upd.setval); 
       }
        
        ans += ((tr-tl+1)*upd.increment); 
      return ans;
    }

    U combineUpdate1(U old_upd, U new_upd, ll tl, ll tr){
        // total update in the children 
        // U ans = old_upd;
        // we are replacing the value in the range
        // ans=new_upd;

        // if we are adding in the range
        U ans = old_upd + new_upd;
        return ans;
    }  

    U combineUpdate(U old_upd, U new_upd, ll tl, ll tr){
        U ans;
        if(new_upd.setval == -1){
            ans = old_upd;
            ans.increment += new_upd.increment;
        }
        else{
            ans = new_upd;
        }
     return ans;
    }  

    void push_down(ll v, ll tl, ll tr){
        if(lazy[v] == identity_update)return;
        st[v] = apply(st[v], lazy[v], tl, tr);
        
        if(2*v + 2 < 4*n){
            ll tm = (tl + tr)>>1;
            lazy[2*v + 1] = combineUpdate(lazy[2*v+1], lazy[v], tl, tm);
            lazy[2*v + 2] = combineUpdate(lazy[2*v+2], lazy[v], tm+1,tr);            
        }
        lazy[v] = identity_update;
    }

    T queryUtil(ll v, ll tl, ll tr, ll l, ll r){
        push_down(v,tl,tr);
        if(l > r)return identity_element;
        
        if(tr < l or tl > r){
            return identity_element;
        }

        if(l <= tl and r >= tr){
            return st[v];
        }
        ll tm = (tl + tr)>>1;
        return combine(queryUtil(2*v+1,tl,tm,l,r), queryUtil(2*v+2,tm+1,tr,l,r));
    }
 
    void updateUtil(ll v, ll tl, ll tr, ll l, ll r, U upd){
        push_down(v,tl,tr); 
        if(tr < l or tl > r)return;
        
        if(tl >=l and tr <=r){
            lazy[v] = combineUpdate(lazy[v],upd,tl,tr);
            push_down(v,tl,tr);
        }
        else{
            ll tm = (tl + tr)>>1;
            updateUtil(2*v+1,tl,tm,l,r,upd);
            updateUtil(2*v+2,tm+1,tr,l,r,upd);
            st[v] = combine(st[2*v + 1], st[2*v+2]);
        }
    }



    void build(vector<T>a){
        buildUtil(0,0,n-1,a);
    }

    T query(ll l, ll r){
        return queryUtil(0,0,n-1,l,r);
    }

    void update(ll l,ll r, U upd){
        updateUtil(0,0,n-1,l,r,upd);
    }
};

/*
1-based Indexing --
  Lsegtree<ll,ll> st(n+1,0,-1);  // for assignment update (-1) 
  Lsegtree<ll,ll> st(n+1,0,0);  // for increment update  (0)
  Lsegtree<ll,ll> st(n+1,INT_MIN,0);  // for max Query & range update 
  st.build(a);
  update upd(-1,0);
  Lsegtree<ll,update> st(n+1,0,upd);
*/

int main(){
    
    return 0;
}