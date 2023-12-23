#include<bits/stdc++.h>
using namespace std;

struct Node{
  Node* links[26];
  int cntEndWith=0;  
  int cntPrefix=0;  

  bool containsKey(char ch){
    return (links[ch-'a'] != NULL);
  }

  void put(char ch, Node* referenceNode){
    links[ch-'a'] = referenceNode;
  }

  Node* get(char ch){
    return links[ch-'a'];
  }

};

//*************************************************

class Trie{
  Node* root;
  public:
  Trie(){
    root= new Node();
  }

// TC - O(Length of word)
  void Insert(string word){
    Node* tmp = root;
    for (int i = 0; i <word.length(); i++){
      if(!tmp->containsKey(word[i])){
          tmp->put(word[i],new Node());
      }
      tmp = tmp->get(word[i]);
      tmp->cntPrefix++;  // increase the prefix
    }
    // here last reference trie will be present
    tmp->cntEndWith++;
  }

  // O(length)
  bool CountWordsEqualTo(string word){
    Node *tmp = root;
     for (int i = 0; i <word.length(); i++){
        if(!tmp->containsKey(word[i])){
          return 0;
        }
        tmp = tmp->get(word[i]);
     }

   return tmp->cntEndWith;   
  }

  // O(length)
  bool CountWordsStartingWith(string word){
    Node *tmp = root;
     for (int i = 0; i <word.length(); i++){
        if(!tmp->containsKey(word[i])){
          return 0;
        }
        tmp = tmp->get(word[i]);
     }
    return tmp->cntPrefix;
  }

  void Erase(string word){
    Node *tmp = root;
     for (int i = 0; i <word.length(); i++){
        if(!tmp->containsKey(word[i])){
          return ;
        }
        tmp = tmp->get(word[i]);
        tmp->cntPrefix--;
     }  

    tmp->cntEndWith--; 
  }

};


int main(){
    
    return 0;
}