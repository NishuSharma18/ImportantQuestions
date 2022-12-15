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

#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update>  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// #define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
// #define ordered_set tree<int, null_type,greater<int>, rb_tree_tag,tree_order_statistics_node_update>
// #define ordered_set tree<int, null_type,greater_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

ll gcd(ll a, ll b) {
if (b==0) return a;
return gcd(b, a % b);
}

bool isprime[100000];
vector<int> LowPrime(100000,0) ,HighPrime(100000,0);

void Sieve(){
memset(isprime,true,sizeof(isprime));
isprime[0] = isprime[1] = false;    
for (int i = 2; i <=100000; i++){
if(isprime[i]==true){
// LowPrime[i] = HighPrime[i] =i;    
for (int j = 2*i; j <100000; j+=i) {
isprime[j] = false;
// HighPrime[j] = i;
// if(LowPrime[j] == 0) LowPrime[j] = i;
}        
}}
}

// Prime Factors in O(log(N)) time per query
unordered_map<int ,int> PrimeFacs(int num){
unordered_map<int,int> m;
while(num>1){
int prmfct = HighPrime[num];
while(num%prmfct ==0){
num /= prmfct;
m[prmfct]++;}    
}
return m;
}

// All Divisers using sieve
vector<int> divisers[100000];
void diviser(){
Fr(i,1,100000){
for(int j =i; j <100000; j+=i){
divisers[j].push_back(i);    
}}}

// int binExpRecr(int a,int b){
// // base case
// if(b==0) return 1;    
// int res =binExpRecr(a,b/2);
// if(b&1) return (a*(res *1ll*res)%Mod)%Mod ;   
// else return (res*1ll*res)%Mod;
// }


int binExpItr(ll a,ll b){ a %=Mod;    
int res =1;
while (b){
if(b&1) res = (res *1ll *a)%Mod;
a = (a* 1ll* a)%Mod;
b >>=1;  }
return res;}

// Binary Multiplication
ll binMultiply(ll a,ll b){ ll res =0;
while(b){
if(b&1) res = (res+a)%Mod;    
a =(a+a)%Mod;
b >>=1;}
return res;}

// Prime Factorization [time - O(sqrt(n)) ]
vector<int> PrimeFactors(int n){ vector<int> PrimeFac;
for (int i =2; i*i <=n; i++){
while (n%i==0){
PrimeFac.push_back(i);
n/=i;}}
if(n>1){  // Edge case for prime no
PrimeFac.push_back(n);}
return PrimeFac; }

ll ModInvr(ll x){return (binExpItr(x,Mod-2));}
ll fact[1000007];
void factorial(){ fact[0]=1;
 Fr(i,1,1000007) fact[i] = (fact[i-1]*i)%Mod;}
ll Ncr(ll n, ll r) {
return fact[n] * ModInvr(fact[r] * fact[n - r] % Mod) % Mod;}

//*********************************************************//


int main(){
int a= 36,b=24;
// cout<<fixed<<pow(4,5)<<endl;
// cout<<binExpItr(a,b)<<endl;
// cout<<binMultiply(344575487342574545,534643743753476843);   

// set<int> s;
// vector<int> v = PrimeFactors(180);

// removeDuplicate(v);

// for (int i = 0; i <v.size(); i++){
// s.insert(v[i]);
// }
 
// for(auto s1:v){
// cout<<s1<<endl;    
// } 

// int num;
// cin>>num;
// Sieve();
// unordered_map<int,int> m =PrimeFacs(num);
// for(auto m1:m){
// cout<<m1.first<<" "<<m1.second<<endl;    
// }

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


/*
╣╢╣╣╫▓▓▓▓▓▓▓▓▀,░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░╡░░░▓▓g▒╕       ╠╢╢▒
╢╣╣╣╫▓▓▓▓▓▓▓"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\░░╙╣╢▓@░      ╟╢╢▒
╣╢╣╢╫▓▓▓▓▓▓ ░        ░,░░░░░░░░░░ ░░░░░░░░░░░░░░░░░░░░░░\░░░░\░░╙╣╢╣▓░╖,,,,╟╢╢▒,
╢╢╣▒╢▓▓▓▓▓ ░         )  /                         ¿      \    ╕  ╟╣╣╣▓@╚'`╙╟╢╢╜`
╣╣╢▒╢▓▓▓▓   ╛       ,' ╛                          ]    \ ]W       ▓╣▓▓╣▓%  ╟╢╢░
▒▒▒▒╢▓▓▓   ╛        ▌ ╛            ╡               N    ) ▓    ├  ░▓▓▓▓▓▓K ╫╢╢
▒▒▒▒╢▓▓   ƒ        ╫ r             ▓               Ü▒╖   )╢L       ]▓▓▓▓▓╢µ╫╢╢
▒▒▒▒▒▓M           ]▌ƒ         ┌    ▓            ▐  [  Ñ,  ▓▓    ╟░t░▓▓▓▓▓▓▓╫╣╣
▒▒▒▒▒╫   ƒ       ░╫╒    ▐     ┤   ▐▓            ▐. [   'ô,▓▓░▐  ▐▓░░▐▓▓▓▓▓▓▓╣╣
▒▒▒▒▒▌            ▌╛    Γ     Γ   ▓█       ]    ▐L░[     \╟╢▌j░  ╣▓ï░▓▓▓▓▓▓▓╣╣
▒▒▒▒▒C░ ├        ]▓      ╒       j▓▓ j     ▐    ║▌░Γ       ▓▓░░░░▓╣Ü░▓▓▓▓▓▓╣╣╣
▒▒▒▒▒ ░░Γ ░░░ ░░░▓M░░░Å▐░▌╓⌐╤▓╥╖,▓▓▒░├░j░░░▓░░░░▒▌╓H╤╤¬.    ]░░░░▓▓▓L▐▓▓▓▓▓▓▓▓╜╙
▒▒▒▒╢░░░░░░░░░░░░▓░░░ƒy▌▐░░░ƒ▒░░░╢▌▒░Γ░▐░░░▓░░░░░▌░▒     '"  ░░░░▐▓▓▓░▓▓▓▓▓▓▓[
▒▒▒▒ ░░j░░░░░░░░░▓░░ƒ░▒░░░░ƒ░░░░▓▓▒j░░░▓░░▐▓░░░├▒M▐          ░░░░▐▓▓▓░▓▓▓▓▓▓▓[
▒▒▒▒ ░░▐░░░░░░░░]▓▒Æ░░▐Å░░Æ▒Å░░╟▓▒`▐Å░Å▌░░▓▌░░░░ ░▌          Ü░▒░▓▓╣▓▌▓▓▓▓▓▌▓▒
▒▒▒▒;░░├░░░░░░░▒▐▓▒#░░▓▒░▒▒]░▒░▀▒  ▐░ƒ▒░▒▒▓░░▒Å┘ƒ░           ▒░▒▒▒▓▓▓█▓▓▓▓▓▓▓▌
▒▒▒╣▒░░┤░░░░░░┤▒╟▓▒▒Ç▒▒▓▒░▐▀▒▓▒▒  ,░▒▒ƒ▒░▓░▒Åƒ` ░▓═"  ,▄▄▒▒▒▒▓▒░▒▌░▓▓▓▓▓▌▓▓▓▓▌
▒▒▒▒░░░┤░░░░░░┤░▓█▓███▀▀██▓▒██▄, ╒▒▒`)░░╝▒░▓▒  Å▒⌐▄███████████▄m░▌▒▓▓▓▓▓▓▓▓▓▓▌
▒▒╢╫░░░╡░░░▐░░▓▓██▀▒╜▐█▀▀▀███░▀█▓   ╒▒" ▒┘╒`  Æ▒æ█▀▒█▀▀▓███▄▒▐░░▓██▓▓▓▌▓▌▓▓▓▓▓,,
▒▒Ñ▐░░░[░░░▐▒▒▐░▓▌   █╣  ▄▌]▒█ ╙ "              ╝` █╣ ╓▄▓]▒█ ▐▒▒▒░▒▐▓▓▓▓▓▓▓▓▌▓╙╙
▒▒║▓░░░▒Γ░░▐░░▐░▓▌   ▀▌╜░╙╜╙╫█                     █▌╜░░▒╨▓█ ║░╨┼▒▒▓▓▀▒▓▓▓▓▓▓▓
▒╢╢╢░░░P▌░░▐░░▐▒╟▌Å╕  '▀ÑÑ╩ⁿ"                       ▀▀▓▓▓M▀  ▓▀▒▒▒▐▓░▓▓▒▓▓▓▓▓▓▌
╣Ñ▒▌░░░Ü▒░░▐▒░░░▐▌░░░ÖªMMMT░                       'ΓMMAMMM▒░F░▒░▒▓▒▒▒Å▓▓▓▓▓▓▓▓
╣Ü╣▌░░░▌░░░▐▒░▒░▐▌░░░,░░░░░            ,▒            ░░░░░▒▒░▌░▐▒▒░▀▒▒▒▒▓▓▓▓▓▓▓\
╣╢╣░░░░▓░░▒▐▒░▒░▒▓░░░░░░░░             `░             ░░░░░░░▌▒╢▒▒▌▒▒▓▒▓▓▓▓▓▓▓▓U
╣║╢░░░▒▓▒░░░▒▒▒░▒▓░                     ╙                 ░░░▒▌▒▒▒▒▒▀▒▓▓▓▓▓▓▓▓▓▌
╢║▒▐░░░▓▒▒░░▒▒▒▌▒▓                                          ┌▒║▓▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓█
╢╫▐║▒░▒▓▒░░░▒▒▒▓▒▓▓                                       ╖╓▒▒▒▓▓▄▓▓▓▓▓▓▓▓▓▓▓▓▓█
╣╫▓É▒▒▒▓▒▒▒▒░▐▒╢░▒▓▓                                      ▒▒▒▒▒█▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓
╢╟▓▌▒▒▒▌▒▒▒▒▒▐▒▓▌▒▓▓▓▄                                   ╓▒▄▓▌▒▐▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓
╢╟╫░▒▒▒▌▒▒▒▒▒▒▒▓▓▒▐▓▓▓▓▄             ╙▒▒▒▒▒╜`          ,▒▄▓▓▓▓▓▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓
╢Ñ▐░▒▒▒▌░▒▒▒║▒▒▒▓▓▒▓▓▓▓▓▓▄,                          ╓▒▓▓▓▓▓▓▌▓▓▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓
╢▌▓▒▒▒▒░▌▒▒▒░▒░▒▓▓▌▓▓▓▓▓▓▓▓▓▄,                    ,g▓▓▓▓▓▓▓▓▓▒▓▓▓▓▓▓▓▓▓▒▓▓▓▓█▓▓▓
╢Ü▓▒░░░▒▌▒▒░▒▌▌▒▓▓▓▒▓▓▓▓▓▓▓▓▓▒▒▒w              ,æ▒▒█▓▓▌▓▓▓▓▓▓▒▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓
╣Ñ▓░░░▓░▓░░░░▐┼▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓░▒▒▒▒W,░░░ ░  ╓m▒▒▒▒▐▓▓▓▌▓▓▓▓▓▌▐▓▓▓▒▓▓▌▒▒▓▓▓▓▓█▓▓▓
▓▓▓░░░▓░▓░L░░░▒░▒▓▓▓▓▓█▓▓▓▓▓▓▓▌░░╙▒▒▒▒▒mmm▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▒▓▓▓▌▓▓▀▒▒▒▓▓▓▓▓█▓▓▓
▓▓▓░░▐▓░▓▌▐░░░░▌▒░▓▓▓▓▓▓▓▓▓▌▓▓██▄▄░╙▒▒▒▒▒▒▒▒▒▒▄▄██▓▓▓▓▓▓▓▓▓▓▒▓▓▓▒▓▓▒▒▒▒▓▓▓▓▓██▓▓
▓╣▓░░▓░░▓▓░░░░░▓░░░▓▓▓▓▓▓▓▓▓▓▓████████████████████▓▓▓▓▓▓▓▓▓▓▒▓▓░▓▓▒▒▒▒▓▓▓▓▓▓▓█▓▓
╣╣▓░░▓░▌▓▓WL░░░░▌░░▐▓▓▓▓▓▓▓▀▒▒▓░░▀█████████████▀▒▒▒▒▓▓▓▓▓▓▓▌▐▓▌▓▓░▒▒▒▒▓▓▓▓▓▓▓█▓▓
▓▓▓▒▓▌░▓▐▓▓▐░░░░▓▄░▒▓▌▒▒▒▒▒▒▒▒▌░░░░░░░░░░░╙▒▒▒▒▒▒▒▒▒▒▒▒▒▀▀▓▌▐▓▒▓░▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓
▓▐▓▒▓▌░▓▌██▌░░░░░▓▓░░█▒▒▒▒▒▒▒▒░░░░░░░░░░░░░░░░╨▒▒▒▒▒▒▒▒▒▒▒▒▌▐░▓▌▒▒▒▒▐▓▓▓▓▓▓▓▓█▓▓
▒▄██████████▌▒░░░▓▓▒░░▒▒▒▒▒╜░░░░░░░░░░░░░░░░░░░░░╙╢▒▒▒▒▒▒▒▒▌▒▒▓▒▒▒▒▒▓▓▓▓▓▓██████
█████████████░▒░░░▓▒▓▓▒▒╢░░░░░░░░░░░░░░░░░░░░░░░░░░░╙║▒▒▒▒▒▓▒▐░▒▒▒▒▓▓█▓▓▓▓██████
*/
