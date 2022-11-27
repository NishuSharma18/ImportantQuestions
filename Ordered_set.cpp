#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define all(v) v.begin(),v.end()
#define removeDuplicate(v) v.erase(unique(all(v)),v.end())
#define Fr(i,a,b) for(int i=a; (a<b)?i<b:i>=b ; (a<b)? i++:i--)
#define fr(i,n) for(int i=0;i<n;i++)
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
using namespace std;
using namespace __gnu_pbds;
const int Mod = 1e9+7;
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// #define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
// #define ordered_set tree<int, null_type,greater<int>, rb_tree_tag,tree_order_statistics_node_update>
// #define ordered_set tree<int, null_type,greater_equal<int>, rb_tree_tag,tree_order_statistics_node_update>


int main(){
ordered_set s;
s.insert(2);
s.insert(2);
s.insert(10);
s.insert(4);
s.insert(19);
s.insert(19);
s.insert(7);
for(auto s1:s) cout<<s1<<" ";
cout<<endl;

cout<<"1st element: "<<*s.find_by_order(1)<<endl;
cout<<"No of element smaller then 9: "<<s.order_of_key(19)<<endl;
cout<<endl;
cout<<"Lower bound of 7: "<<*s.lower_bound(7)<<endl;
cout<<"Lower bound of 8: "<<*s.lower_bound(8)<<endl;
cout<<"Upper bound of 7: "<<*s.upper_bound(7)<<endl;

s.erase(2);

return 0;
}