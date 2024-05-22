#include<bits/stdc++.h>
using namespace std;

// It will return the number of elements lesser than K
class MergeSortTree{
   vector<int> a;
   int ret;
   vector<vector<int> > tree;

   public:

   MergeSortTree(int n, vector<int> &a1){
      a = a1;
      tree.assign(4 * n +n, vector<int>());
      ret = 0;
   }

   void build(int si, int ss, int se) {
      if(ss == se) {
         tree[si].push_back(a[ss]);
         return;
      }
      int mid = ss + (se - ss) / 2;
      build(2 * si, ss, mid);
      build(2 * si + 1, mid + 1, se);
      merge(tree[2 * si].begin(), tree[2 * si].end(), 
      tree[2 * si + 1].begin(), tree[2 * si + 1].end(), back_inserter(tree[si]));
   }

   int query(int si, int ss, int se, int qs, int qe, int x) {
      if(ss > qe || se < qs) return ret;
      if(ss >= qs && se <= qe){
         auto ptr = lower_bound(tree[si].begin(), tree[si].end(), x);
         return ptr-tree[si].begin();
      }

      int mid = ss + (se - ss) / 2;
      int left = query(2 * si, ss, mid, qs, qe, x);
      int right = query(2 * si + 1, mid + 1, se, qs, qe, x);
      return (left+right);
   }

};


int main(){
   int n,q;
   cin>>n>>q;
   vector<int> a(n);
   for(int i=0; i<n; i++){
       cin>>a[i];
   }
   MergeSortTree ms(n,a);
   ms.build(1,0,n-1);

   while(q--){
      int x;
      int l,r;
      cin>>l>>r>>x;
      cout<<ms.query(1,0,n-1,l,r,x)<<'\n';
   }

   return 0;
}