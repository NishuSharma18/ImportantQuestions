#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int test_cnt;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int x, int y){return x > y ? x : uniform_int_distribution<int>(x, y)(rng);}


int solve (vector<int> A) {
    int ans;
    return ans;
}


void output(long long N, long long M, string tag = ""){
    ostringstream in_oss, out_oss;
    if(test_cnt < 10) {
        in_oss << "test/in0" << test_cnt;
        out_oss << "test/out0" << test_cnt;
    } else {
        in_oss << "in" << test_cnt;
        out_oss << "out" << test_cnt;
    }

    if(tag.size() > 0) {
        in_oss << "_" << tag << "_test";
        out_oss << "_" << tag << "_test";
    }
    in_oss << ".txt";
    out_oss << ".txt";        
    ofstream test_in(in_oss.str());
    ofstream test_out(out_oss.str());

    int t=10;
    test_in <<t<< endl;
    while(t--){
        int n = rand(N/2,N);
        int k = rand(M/2,M);
        test_in << n <<" "<<k << endl;    

        vector<int> a(n);
        for (int i = 0; i < n; i++) test_in << (a[i] = rand(1, M)) << " \n"[i == n - 1];
        test_out << solve(a) << endl;
    }
    test_in.close();
    test_out.close();
    ++test_cnt; 
}
 
const long NN = 1e5, MM = 1e3,KK=1e2;
const long N1 = 1e6, M1 = 1e4,K1=1e2;

signed main(){
   int count=4; 
   output(KK,K1);
   output(KK,K1);
   output(MM,M1);
   output(MM,M1);
    while(count--){
        output(NN,N1);
    }
    return 0;
}
    // test_in << 10 << endl;
    // for (int _ = 0; _ < 10; _++){
    //     int n = rand(1, N - 9 + _), k = rand(1, K);
    //     test_in << n << " " << k << endl;
    //     N -= n;
    // }
    // int m = rand(M / rand(1, 5), M);
    // vector<int> a(n);
    // string A = "", B = "";
    // int na = rand(max(1LL, N / rand(1, 100)), N);
    // int nb = rand(max(1LL, N / rand(1, 100)), N);
    // for (int i = 0; i < na; i++) A += char('a' + rand(0, 25));
    // for (int i = 0; i < nb; i++) B += char('a' + rand(0, 25));
    // string S = A;
    // N -= na;
    // int n = na + rand(max(1LL, N / rand(1, 2)), N);
    // while(S.size() < n){
    //     int p = rand(0, 2);
    //     if (p == 1){
    //         if (S.size() + A.size() > n) goto bad;
    //         S += A;
    //     }
    //     if (p == 2){
    //         if (S.size() + B.size() > n) goto bad;
    //         S += B;
    //     }
    //     bad: S += char('a' + rand(0, 25));
    // }
// long long x = rand(5e17, 1e18);
    // vector<int> a(n), b(n);
    // for (int i = 0; i < n; i++) test_in << (b[i] = rand(0, 1)) << " \n"[i == n - 1];
    // int k = rand(5e8, 1e9);
    // test_in << k << endl;
    // test_in << x << endl;
    // test_in << S << endl;
    // string S = "", fight = "FIGHT", war = "WAR";
    // stack<string> rems;
    // int len = 0;
    // while(len < n - 5){
    //     if (rand(0, 1)){
    //         len += 5;
    //         int k = rand(1, 5);
    //         S += fight.substr(0, k);
    //         rems.push(fight.substr(k));
    //     }else{
    //         len += 3;
    //         int k = rand(1, 3);
    //         S += war.substr(0, k);
    //         rems.push(war.substr(k));
    //     }
    //     while(!rems.empty() and rand(0, 1)){
    //         S += rems.top();
    //         rems.pop();
    //     }
    // }
    // while(!rems.empty()){
    //     S += rems.top();
    //     rems.pop();
    // }
    // int rem = N - len;
    // S += fight.substr(0, rem);
    // test_in << S << endl;
    // auto ans = solve(n, S);
    // // for (int i = 0; i < n; i++) test_out << ans[i] << " \n"[i == n - 1];
    // Bidirectional GRAPH
    // vector<vector<int>> friends, extra;
    // int last = 0;
    // for (int i = 1; i < N; i++){
    //     if (rand(0, 1)){
    //         last = i;
    //         continue;
    //     }else{
    //         int p = rand(last, i - 1);
    //         friends.push_back({p + 1, i + 1});
    //         for (int j = 0, k = last; j < 100 and k != i; j++, k++){
    //             if (k != p) extra.push_back({k + 1, i + 1});
    //         }
    //     }
    // }
    // while(!extra.empty() and friends.size() < (int)3e5){
    //     friends.push_back(extra.back());
    //     extra.pop_back();
    // }
    // test_in << friends.size() << endl;
 
    // for (auto &e : friends) test_in << e[0] << ' ' << e[1] << endl;
    // test_out << solve(N, friends) << endl;
    // test_in << A << endl;
    // test_in << B << endl;
    // {
        // if (rand(0, 1) and i) a[i] = a[rand(0, i - 1)];
        // else a[i] = rand(1, 1e9);
        // a[i] = rand(-1e9, 1e9);
        // test_in << a[i] << " \n"[i == n - 1];
    // }
    // int k = rand(1, n);
    // k = min<int>(k, 5000);
    // test_in << k << endl;
    // for (int i = 0; i < m; i++){
    //     queries[i][0] = rand(1, 2);
    //     queries[i][1] = rand(1, n);
    //     queries[i][2] = rand(0, 1e9);
    //     if (rand(0, 1)) queries[i][2] *= -1;
    //     test_in << queries[i][0] << " " << queries[i][1] << " " << queries[i][2] << endl;
    // }
    // test_out << solve(a, m) << endl;
    // int out = solve(n, S, a, A, B);
    // test_out << out << endl;
    // for (int i = 0; i < n; i++) test_out << out[i] << " \n"[i == n - 1];
    // output(NM, NM, MM);
    // output(NM, NM, MM);
    // output(NM, NM, MM);
    // output(NM, NM, MM);
    // output(NM, NM, NN);
    // output(NM, NM, NN);
    // output(NM, NM, NN);
    // output(NM, NM, NN);
    // output(NM, NM, NN);
    // output(NM, NM, NN);
    // output(NM, NM, NN);