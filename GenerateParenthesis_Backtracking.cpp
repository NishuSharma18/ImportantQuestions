#include<bits/stdc++.h>
using namespace std;

vector<string> valid;

void generate(string&s ,int open,int close){  //Note: string pass by reference to avoid copies  
if(open==0 && close==0){
    valid.push_back(s);
    return;
}
if (open>0){
s.push_back('(');
generate(s,open-1,close);
s.pop_back();    // Backtracking step
}

if (close>0){
if(open<close){  // we want more open brackets in strings so remaining open < remaing close <--
s.push_back(')');
generate(s,open,close-1);
s.pop_back();   // Backtracking step
}
}
}


int main(){
    string s;
    int n;
    cin>>n;
    generate(s,n,n);
    for(auto e1:valid){
        cout<<e1<<endl;
    }

    return 0;
}