#include <bits/stdc++.h>
using namespace std;

vector<int> spirallyTraverse(vector<vector<int>> &mat)
{
    int r=mat.size();
    int c=mat[0].size();
    int top=0;
    int bottom = r-1;
    int left =0;
    int right = c-1;
    vector<int>ans;

    while(top<=bottom && left<=right){
        //top element push
        for(int j=left;j<=right;j++){
            ans.push_back(mat[top][j]);
        }
        top++;
        //right
        for(int i=top;i<=bottom;i++){
            ans.push_back(mat[i][right]);
        }
        right--;

        //bottom
        if(top<=bottom){
            for(int j=right;j>=left;j--){
                ans.push_back(mat[bottom][j]);
            }
            bottom--;
        }
        //left
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                ans.push_back(mat[i][left]);
            }
            left++;
        }
    }
    return ans;
}

int main()
{
}