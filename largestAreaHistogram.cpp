#include<bits/stdc++.h>
using namespace std;


int largestRectangleArea(vector < int > & histo) {
  stack < int > st;
  int maxA = 0;
  int n = histo.size();
  for (int i = 0; i <= n; i++) {
    while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
      int height = histo[st.top()];
      st.pop();
      int width;
      if (st.empty())
        width = i;
      else
        width = i - st.top() - 1;
      maxA = max(maxA, width * height);
    }
    st.push(i);
  }
  return maxA;
}



int maximalRectangle(vector<vector<char>>& matrix) {
    int n = matrix[0].size();
    vector<int> tmp(n);
    for (int i = 0; i <n; i++){
        tmp[i] = matrix[0][i]-'0';
    }

    int maxArea = largestRectangleArea(tmp);

    for (int i = 1; i <matrix.size(); i++){
        for (int j = 0; j <n; j++){
            if(matrix[i][j]=='0') tmp[j]=0;
            else tmp[j]+= (matrix[i][j]-'0');
        }
        maxArea = max(maxArea,largestRectangleArea(tmp));
    }
            
    return maxArea;
}

int main(){
    
    return 0;
}