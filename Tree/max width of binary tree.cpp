/*
# Width of Binary Tree

## 🧠 Problem Understanding

We need to find the **maximum width** of a binary tree.

The width of one level is defined as:

width = (index of last node - index of first node + 1)

We count the width including the null positions between nodes.

---

# 🌳 Approach (BFS + Indexing)

We use **Level Order Traversal (BFS)**.

Each node is assigned an index similar to a Complete Binary Tree.

If a node has index `i`:

Left child → `2*i + 1`  
Right child → `2*i + 2`

For every level:

1. Store the index of the first node
2. Store the index of the last node
3. Calculate width:
   
   width = last - first + 1

4. Keep updating the maximum width

---

## ⚠ Important Optimization

To prevent overflow:

At each level we normalize indexes:

currIndex = originalIndex - minIndex

This prevents very large numbers.

We use `long long` instead of `int` for indexes.
*/

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

class Solution {
public:

    /*
        Function: widthOfBinaryTree
        ---------------------------------
        Returns the maximum width of the binary tree.

        Logic:
        - Perform BFS (level order traversal)
        - Maintain index of each node
        - Normalize index at every level to prevent overflow
        - Compute width for each level
    */
    int widthOfBinaryTree(TreeNode* root) {

        // If tree is empty, width is 0
        if (!root) return 0;

        long long ans = 0;  // Stores maximum width found

        // Queue stores pair of (node, index)
        // Index represents its position in a complete binary tree
        queue<pair<TreeNode*, long long>> q;

        // Push root with index 0
        q.push({root, 0});

        // Perform level order traversal
        while (!q.empty()) {

            int levelSize = q.size();

            // Minimum index of current level
            // Used for normalization to prevent overflow
            long long minIndex = q.front().second;

            long long first = 0, last = 0;

            // Traverse all nodes at current level
            for (int i = 0; i < levelSize; i++) {

                // Normalize index to keep numbers small
                long long currIndex = q.front().second - minIndex;

                TreeNode* node = q.front().first;
                q.pop();

                // First node of level
                if (i == 0) first = currIndex;

                // Last node of level
                if (i == levelSize - 1) last = currIndex;

                // Push left child with calculated index
                if (node->left) {
                    q.push({node->left, 2 * currIndex + 1});
                }

                // Push right child with calculated index
                if (node->right) {
                    q.push({node->right, 2 * currIndex + 2});
                }
            }

            // Calculate width of current level
            long long width = last - first + 1;

            // Update maximum width
            ans = max(ans, width);
        }

        return (int)ans;
    }
};


// Example usage
int main() {

    /*
            1
          /   \
         3     2
        / \     \
       5   3     9

    Expected Maximum Width = 4
    */

    // Creating the tree manually
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);

    Solution sol;

    cout << "Maximum Width of Binary Tree: "
         << sol.widthOfBinaryTree(root) << endl;

    return 0;
}