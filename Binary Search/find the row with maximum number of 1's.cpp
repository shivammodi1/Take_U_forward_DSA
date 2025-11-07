#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        
        int n=mat.size();
        int m=mat[0].size();

    
        int maxSum=0;
        int row=0;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=0;j<m;j++){
                sum+=mat[i][j];
            }
            if(sum>maxSum){
                maxSum=sum;
                row=i;
            }
        }

        return {row,maxSum};

    }
};