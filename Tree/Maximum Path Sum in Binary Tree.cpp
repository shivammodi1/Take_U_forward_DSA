#include <bits/stdc++.h>
using namespace std;

// Maximum Path Sum in Binary Tree
// hame each node se max path sum calculate krna hain
// jiska path max hoga wahi ans return kr dena hain

class Solution {
public:
    int solve(Node* root, int &maxSum){
        if(root == NULL) return 0;

        // Correct negative values handling
        int leftSum = max(0, solve(root->left, maxSum));
        int rightSum = max(0, solve(root->right, maxSum));

        // path passing through this node
        maxSum = max(maxSum, leftSum + rightSum + root->data);

        // return best single path upward
        return root->data + max(leftSum, rightSum);
    }

    int findMaxSum(Node *root) {
        int maxSum = INT_MIN;
        solve(root, maxSum);
        return maxSum;
    }
};
