#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
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

// left node traversal
void Left_Subtree(Node *root, vector<int> &ans)
{
    if (!root || (!root->left && !root->right))
    {
        return;
    }
    ans.push_back(root->data);
    if (root->left)
    {
        Left_Subtree(root->left, ans);
    }
    else
    {
        Left_Subtree(root->right, ans);
    }
}

// Right node traversal
void Right_Subtree(Node *root, vector<int> &ans)
{
    if (!root || (!root->left && !root->right))
    {
        return;
    }

    if (root->right)
    {
        Right_Subtree(root->right, ans);
    }
    else
    {
        Right_Subtree(root->left, ans);
    }
    ans.push_back(root->data);
}

// leaf node traversal
void Leaf_Node(Node *root, vector<int> &ans)
{
    if (!root)
    {
        return;
    }

    if (!root->left && !root->right)
    {
        ans.push_back(root->data);
        return;
    }

    Leaf_Node(root->left, ans);

    Leaf_Node(root->right, ans);
}

vector<int> boundaryTraversal(Node *root)
{
    vector<int> ans;

    if (!root)
    {
        return ans;
    }

    // Add the root node to the answer vector
    ans.push_back(root->data);
    // left boundary traversal
    Left_Subtree(root->left, ans);
    // leaf node traversal
    if (root->left || root->right)
    {
        Leaf_Node(root, ans);
    }
    // right boundary traversal
    Right_Subtree(root->right, ans);

    return ans;
}

int main()
{
    return 0;
}