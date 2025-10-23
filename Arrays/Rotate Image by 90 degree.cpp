#include<bits/stdc++.h>
using namespace std;
/* matrix : given input matrix, you are require
 to change it in place without using extra space */
void rotate(vector<vector<int> >& mat) {
    // Your code goes here
   // Initialize the result matrix with zeros
    int n=mat.size();
    vector<vector<int>> res(n, vector<int>(n));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            res[j][n-1-i] = mat[i][j];
        }
    }
    mat=res;
}

// method 2
// transpose -> reverse row wise
void rotate(vector<vector<int>>& m) {
    int n = m.size();

    // transpose
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){ // fix here
            swap(m[i][j], m[j][i]);
        }
    }

    // reverse each row
    for(int i=0;i<n;i++){
        int st=0, end=n-1;
        while(st<end){
            swap(m[i][st], m[i][end]);
            st++;
            end--;
        }
    }
}


