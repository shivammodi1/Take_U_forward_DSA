// Given a binary tree root[], you need to find the sum of the nodes on the longest path from the root to any leaf node.If two or more paths have the same length, the path with the maximum sum of node values should be considered.
// Example 1:                  1
//                            /  \
//                           2    5
//                         /  \  /  \
//                        7    1 2   3
//                            /
//                           6
// so iss question jo maxLen hoga jis path ka uska sum bhi maximum hoga wo answer hoga
// toh iss example me
// root->leaf tak ke path hote hai
// 1->2->7  (length=3, sum=10)
// 1->2->1->6 (length=4, sum=10)
// 1->5->2 (length=3, sum=8)
// 1->5->3 (length=3, sum=9)
// toh iss example me answer 10 hoga kyunki 1->2->1->6 ka length 4 hai aur sum bhi 10 hai

#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void helper(Node* root,int len,int &maxLen,int sum,int &maxSum){

    //jab root null ho tabhi check karo
    // kya path ka len hain woh maxLen se bada hain ya nahi
    if(!root){
        if(len>maxLen){
            maxLen = len;
            maxSum = sum;
        }else if(len==maxLen){
            maxSum = max(maxSum,sum);
        }
        return;
    }
    // sum me root ka data add karo
    sum = sum + root->data;
    // left aur right dono ko call karo
    helper(root->left,len+1,maxLen,sum,maxSum);
    helper(root->right,len+1,maxLen,sum,maxSum);
}

int sumOfLongRootToLeafPath(Node *root)
{
    int len = 0, sum = 0;
    int maxLen=0, maxSum=INT_MIN;

    helper(root, len, sum, maxLen, maxSum);
    return maxSum;
}

int main()
{
    return 0;
}