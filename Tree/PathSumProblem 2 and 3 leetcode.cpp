#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};



/* ============================================================
   ===================== PATH SUM II ==========================
   ============================================================

   PROBLEM:
   Return all root-to-leaf paths where sum = target.

   APPROACH:
   1. Use DFS.
   2. Maintain a vector 'path' from root to current node.
   3. When leaf node reached:
        - Calculate sum of path.
        - If equal to target → store path.
   4. Backtrack (pop element).

   Time Complexity: O(N²) worst case
   ============================================================ */

void helperPath2(TreeNode* root, int k, 
                 vector<int>& path, 
                 vector<vector<int>>& ans) {

    if(!root) return;

    path.push_back(root->val);

    // If leaf node
    if(!root->left && !root->right) {
        int sum = 0;
        for(int i = 0; i < path.size(); i++) {
            sum += path[i];
        }

        if(sum == k) {
            ans.push_back(path);
        }

        path.pop_back();   // backtrack
        return;
    }

    helperPath2(root->left, k, path, ans);
    helperPath2(root->right, k, path, ans);

    path.pop_back();   // backtrack
}

vector<vector<int>> pathSumII(TreeNode* root, int k) {
    vector<vector<int>> ans;
    vector<int> path;
    helperPath2(root, k, path, ans);
    return ans;
}



/* ============================================================
   ===================== PATH SUM III =========================
   ============================================================

   PROBLEM:
   Count all downward paths where sum = target.
   Path can start and end at ANY node.

   APPROACH (Your Vector Method):
   1. Maintain path from root to current node.
   2. At every node:
        - Traverse path backward.
        - Calculate subpath sums.
        - If sum == k → increment count.
   3. Backtrack.

   Time Complexity: O(N²) worst case
   ============================================================ */

void helperPath3(TreeNode* root, int k, 
                 vector<long long>& path, 
                 int& count) {

    if(!root) return;

    path.push_back(root->val);

    helperPath3(root->left, k, path, count);
    helperPath3(root->right, k, path, count);

    long long sum = 0;

    // Check all subpaths ending at current node
    for(int i = path.size() - 1; i >= 0; i--) {
        sum += path[i];
        if(sum == k) {
            count++;
        }
    }

    path.pop_back();   // backtrack
}

int pathSumIII(TreeNode* root, int k) {
    vector<long long> path;
    int count = 0;
    helperPath3(root, k, path, count);
    return count;
}