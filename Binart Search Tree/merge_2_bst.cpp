// You are given the root of two BSTs, you have to merge this two BST and return the in-order traversal of the new BST.

// Examples:

// Input: root1 = [3, 1, 5], root2 = [4, 2, 6]

// Output: [1, 2, 3, 4, 5, 6]
// Explanation: After merging and sorting the two BST we get [1, 2, 3, 4, 5, 6].
// Input: root1 = [8, 2, 10, 1, N], root2 = [5, 3, N, 0, N]

// Approach:
// 1. We take two vector to store the in-order traversal of both BSTs.
// 2. We will traverse both bst and store the in-order traversal in the vector.
// 3. We will merge the two vector in sorted order and return the merged vector.

#include <bits/stdc++.h>
using namespace std;

// merge array in sorted manner
vector<int> mergeArray(vector<int> &A, vector<int> &B)
{
    vector<int> merged;
    int i = 0, j = 0;
    while (i < A.size() && j < B.size())
    {
        if (A[i] <= B[j])
        {
            merged.push_back(A[i]);
            i++;
        }
        else
        {
            merged.push_back(B[j]);
            j++;
        }
    }
    while (i < A.size())
    {
        merged.push_back(A[i]);
        i++;
    }
    while (j < B.size())
    {
        merged.push_back(B[j]);
        j++;
    }
    return merged;
}
// inorder traversal 
void Inorder(Node *root, vector<int> &inorder)
{
    if (root == NULL)
    {
        return;
    }
    Inorder(root->left, inorder);
    inorder.push_back(root->data);
    Inorder(root->right, inorder);
}
// function sorted array to bst
Node* arrayToBST(vector<int> &arr,int st,int end){
    if(st>end){
        return NULL;
    }

    int mid = st+(end-st)/2;
    Node* root = new Node(arr[mid]);
    root->left = arrayToBST(arr,st,mid-1);
    root->right = arrayToBST(arr,mid+1,end);
    return root;
}


Node *mergeBST(Node *root1, Node *root2)
{
    vector<int> inorder1, inorder2;
    // get the in-order traversal of both BSTs
    Inorder(root1, inorder1);
    Inorder(root2, inorder2);
    // merge the two vector in sorted order
    vector<int> merged = mergeArray(inorder1, inorder2);
    // Construct a new BST from the merged vector
    return arrayToBST(merged, 0, merged.size() - 1);
}

int main()
{
    return 0;
}