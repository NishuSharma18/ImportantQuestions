#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// MORRIS Traversal
vector<int> preorder(TreeNode* root){
  vector<int> preorder;
  TreeNode* tmp = root;
  while(tmp!=NULL){
    if(tmp->left==NULL){// left side is not present
      preorder.push_back(tmp->val);
      // inorder.push_back(tmp->val);
      tmp = tmp->right;
    }
    else{ // left side is present
      TreeNode* prev= tmp->left;
      while(prev->right && prev->right!= tmp){
        prev = prev->right; // go to rightmost  
      }

      if(prev==NULL){// currently no thread is there
        prev->right = tmp;// adding the thread
        preorder.push_back(tmp->val);
        tmp = tmp->left;// go to left subtree
      }
      else{
        prev->right=NULL; // remove the thread
        // inorder.push_back(tmp->val);
        tmp = tmp->right;// and go to right
      }
    }
  }
return preorder;
}





int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
int t1=1,t_case=1;
 cin>>t1;

while (t1--){










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

