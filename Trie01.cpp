#include<bits/stdc++.h>
using namespace std;

struct Node{
  Node* links[26];
  bool flag = false;

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
    }
    // here last reference trie will be present
    tmp->flag = true;
  }

  // O(length)
  bool Search(string word){
    Node *tmp = root;
     for (int i = 0; i <word.length(); i++){
        if(!tmp->containsKey(word[i])){
          return false;
        }
        tmp = tmp->get(word[i]);
     }

   if(tmp->flag) return true;
   return false;   
  }

  // O(length)
  bool StartsWith(string word){
    Node *tmp = root;
     for (int i = 0; i <word.length(); i++){
        if(!tmp->containsKey(word[i])){
          return false;
        }
        tmp = tmp->get(word[i]);
     }
    return true;
  }

};


int main(){
    Trie t;
    t.Insert("Nishu");
    t.Insert("Nishchay");
    t.Search("Nish");
    t.StartsWith("Nish");
    
    return 0;
}