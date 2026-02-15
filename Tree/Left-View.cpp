#include<bits/stdc++.h>
using namespace std;

// left view of a binary tree
//            1
//          /   \
//         2     3
//        / \     \
//       4   5     6
// left view is 1 2 4

// Approach:
// 1. hum 1 map banayege or usme lvl or us lvl pr node 1st node hoga usse store karege
// 2. queue me pair store karege node and uska level
// 3. jab tak q->empty na ho jaaye tab tak loop chalayenge
// 4. q se pair nikal ke uska level check karege ki map me us level pr node store hai ya nahi
// 5. agar nahi hai to us level pr node store karege
// 6. uske baad us node ke left and right child ko q me push

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

vector<int> leftView(Node* root) {
    vector<int> ans;
    if(root==NULL) return ans;

    map<int,int> mp; // level and node data
    queue<pair<Node*,int>> q; // node and level

    q.push({root,0});

    while(!q.empty()){
        auto it=q.front();
        q.pop();
        Node* node=it.first;
        int lvl=it.second;
        // check if level is already present in map or not
        if(mp.find(lvl)==mp.end()){
            mp[lvl]=node->data;
        }

        if(node->left){
            q.push({node->left,lvl+1});
        }

        if(node->right){
            q.push({node->right,lvl+1});
        }
    }

    for(auto it:mp){
        ans.push_back(it.second);
    }
    
    return ans;
}