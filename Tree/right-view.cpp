#include<bits/stdc++.h>
using namespace std;

//  right view of a binary tree
//            1
//          /   \
//         2     3
//        / \     \
//       4   5     6
// right view is 1 3 6

// Approach:
// 1. hum 1 map banayege or usme lvl or us lvl pr node ko store orr update karege jiise ki hume right view milega
// 2. queue me pair store karege node and uska level
// 3. jab tak q->empty na ho jaaye tab tak loop chalayenge
// 4. q se lvl or node nikaal kr mp me us lvl pr node store or update karege
// 5. uske baad us node ke left and right child ko q me push


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

vector<int> rightView(Node* root) {
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
        
        mp[lvl]=node->data; // always update the value for the level

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