#include <bits/stdc++.h>
using namespace std;

// Question : 
// 1975. Maximum Matrix Sum
// You are given an n x n integer matrix. You can do the following operation any number of times:
// Choose any two adjacent elements of matrix and multiply each of them by -1.
// Two elements are considered adjacent if and only if they share a border.
// Your goal is to maximize the summation of the matrix's elements. Return the maximum sum of the matrix's elements using the operation mentioned above.
// Example 1:
// Input: matrix = [[1,-1],[-1,1]]
// Output: 4
// Explanation: We can follow the following steps to reach sum equals 4:
// - Multiply the 2 elements in the first row by -1.
// - Multiply the 2 elements in the first column by -1.


// Method to find maximum matrix sum
// 1. First, we will calculate the sum of absolute values of all elements in the matrix.
// 2. We will also count the number of negative elements in the matrix and find the minimum absolute value among all elements.
// 3. If the count of negative elements is even, we can convert all negative elements to positive, and the maximum sum will be the sum of absolute values.
// 4. If the count of negative elements is odd, we have to leave one negative element. To maximize the sum, we should leave the element with the smallest absolute value. 
// Therefore, we subtract twice the minimum absolute value from the total sum of absolute values to get the maximum sum.

long long maxMatrixSum(vector<vector<int>> &mat)
{
    int n - mat.size();
    int sum=0;
    int negCount=0;
    int minAbs=INT_MAX; // yeh minimum absolute value store karega
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            sum = sum + abs(mat[i][j]);
            if(mat[i][j]<0){
                negCount++;
            }
            // minimum absolute value find karna 
            minAbs = min(minAbs,abs(mat[i][j]));
        }
    }
    // if negCount is even then we can convert all negative to positive
    if(negCount%2==0){
        return sum;
    }
    else{
        // if negCount is odd then we have to leave one negative
        // like why 2*minAbs because we have already added minAbs in sum as positive
        // from +abs(mat[i][j]) to -abs(mat[i][j]) difference is 2*abs(mat[i][j]) 
        return sum - 2*minAbs; 
    }
}


int main()
{
    int n;
    cin>>n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>matrix[i][j];
        }
    }
    cout<<maxMatrixSum(matrix)<<endl;
    return 0;
}