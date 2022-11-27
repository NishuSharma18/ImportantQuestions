#include<bits/stdc++.h>
using namespace std;

bool matching(char a,char b){
      return (a=='('&&b==')'||a=='{'&&b=='}'||a=='['&&b==']');  
}

bool Parenthesis(string s){
 stack<char> st;
for (int i = 0; i < s.size(); i++){
   if (s[i]=='('|| s[i]=='{'||s[i]=='['){
       st.push(s[i]);
   } 
   else{
     if(st.empty()){
         return false;
     }
     else  if(!matching(st.top(),s[i])){
        return false;
     }
     else{
       st.pop();
     }  
   }
}
return st.empty();
}

// Using Unordered Map
bool Parenthesis_Maps(string s){
    stack<char> st1;
unordered_map<char,int> m ={{'(',-1},{'{',-2},{'[',-3},{')',1},{'}',2},{']',3}};
// for (char ele:s){
    for (int ele = 0; ele < s.size(); ele++){
    if (m[s[ele]]<0){
        st1.push(s[ele]);
    }
    else{
        if (st1.empty()){
        return false;
        }
        char top = st1.top();
        st1.pop();
        if(m[s[ele]]+m[top]!=0){
            return false;
        } 
    }
     
}
if (st1.empty())return true;
else{return false;}
}



int main(){
    string s;
    cin>>s;
    if(Parenthesis_Maps(s)){
        cout<<"Parenthesis is Balenced \n";
    }
    else{
        cout<<"Unbalenced Parenthesis\n";
    }
    return 0;

}


// /*
// bool isPrime(int n){
//     for(int i=2;i<=sqrt(n);i++){
//         if(n%i == 0 ){
//             return false;
//         }
//     }
//         return true;
// }

// int main(){
// int n;
// cin>>n;

// while (true){
//   if(n == 2){
//       cout<<"Number is Prime\n";
//       break;
//   }

//   else if(n%2==0){
//   n++;  
//   continue;
// }

// else if(!isPrime(n)){
//     cout<<n<<" is Odd and Non prime\n";
//     n++;
// }

// else if(isPrime(n)){
//     cout<<n<<" is prime\n";
//     break;
// }
// }
// return 0;
// }
// /*