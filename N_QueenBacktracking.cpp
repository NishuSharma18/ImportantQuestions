#include<bits/stdc++.h>
using namespace std;

bool isSafe(int** arr,int x,int y,int n){
// row attack     
for (int row = 0; row < x; row++){
    if(arr[row][y]==1){
        return false;
    }
}
// for diagonal attack
int row= x,col=y; // left diagonal;
while (row>=0 && col>=0){
    if(arr[row][col]==1){
        return false;
    }
    row--;
    col--;
}

row= x,col=y; // right diagonal;  // again intialising row and col
while (row>=0 && col<n){
    if(arr[row][col]==1){
        return false;
    }
    row--;
    col++;
}

return true;
}

// Execution function
bool NQueen(int **board,int row,int N){
if(row>=N){
    return true;
}

for(int col=0;col<N;col++){
    if(isSafe(board,row,col,N)){
        board[row][col]=1;
if(NQueen(board,row+1,N)){
    return true;
}
board[row][col] =0;  //If Not true(BACKTRACKING)

    }
}
return false;
}



int main(){
int N;
cin>>N;
int** arr = new int*[N];
for(int i=0;i<N;i++){
   arr[i] = new int[N];
for(int j=0;j<N;j++){
 arr[i][j] =0; 
}    
}

if(NQueen(arr,0,N)){
for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
        cout<<arr[i][j]<<" ";
    }
    cout<<endl;
    
}

}
else{
    cout<<"We can't Place\n";
}



}