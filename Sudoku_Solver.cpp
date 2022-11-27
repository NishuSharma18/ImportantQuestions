#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<char>> &board,int row,int col,char c){
    for (int i = 0; i < 9; i++){
    if(board[i][col]==c) return false;
    if(board[row][i]==c) return false;
    // for 3*3 box
    if(board[3*(row/3) +i/3][3*(col/3) + i%3]==c)  return false;   
}
return true;
}

bool solve(vector<vector<char>> &board){
for (int i = 0; i < board.size(); i++){
for (int j = 0; j < board[0].size(); j++){
    if(board[i][j]==' '){
        for (char c = '1'; c <= '9'; c++){
            if(isValid(board,i,j,c)){
                board[i][j]= c;
             if (solve(board)){            // Recursion
                 return true;
             } 
                 board[i][j]=' ';         // BACKTRACKING
            }
        }   
            return false;
}
}
}
return true;
}

int main(){
    vector<vector<char>> v{
     {'5','3',' ','6','7','8','9',' ','2'},   
     {'6','7','2','1','9','5','3','4','8'},   
     {' ','9','8','3','4','2','5','6','7'},   
     {'8','5','9','7','6','1','4','2','3'},   
     {'4','2','6','8','5','3','7','9','1'},   
     {'7','1','3','9',' ','4','8','5','6'},   
     {'9','6',' ','5','3','7','2','8','4'},   
     {'2','8','7','4','1','9',' ',' ','5'},   
     {'3','4','5','2','8','6','1','7','9'},   
    };
   
    
if(solve(v)){
   for (int i = 0; i < 9; i++){
   for (int j = 0; j < 9; j++){
    cout<<v[i][j]<<" ";
   }
       cout<<endl;
   }   
}

else{
    cout<<"NOT VALID\n";
}

    return 0;
}