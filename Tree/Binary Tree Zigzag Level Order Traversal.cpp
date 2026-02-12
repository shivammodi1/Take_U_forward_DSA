#include> bits / stdc++.h>
using namespace std;

// zig zag level order traversal of a binary tree
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
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

// Approach:
//1. What I Observe is that 
//       -> If level is even then element are in left to right order
//       -> If level is odd then element are in right to left order
//2. So we can use queue to store the element of each level and then reverse the order of element if level is odd
// 3. We can use a variable to keep track of the level and increment it after processing each level
// Time Complexity: O(n) where n is the number of nodes in the tree
// Space Complexity: O(n) where n is the number of nodes in the tree

vector<vector<int>> zigzagLevelOrder(Node *root)
{
    vector<vector<int>> ans;
    queue<Node *> q;
    q.push(root);
    int level = 0;
    while (!q.empty())
    {
        int n = q.size();
        vector<int> tmp;
        while (n--)
        {
            Node temp = q.front();
            q.pop();
            tmp.push_back(temp->data);

            if (root->left)
            {
                q.push(root->left);
            }
            if (root->right)
            {
                q.push(root->right);
            }
        }

        if (level % 2 != 0)
        {
            // odd level means we have to move
            // right to left
            reverse(tmp.begin(), tmp.end());
        }
        // other evel level
        // left to right
        ans.push_back(tmp);
        level++;
    }
    return ans;
}

int main()
{
    return 0;
}