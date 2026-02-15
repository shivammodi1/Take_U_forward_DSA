#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};

// Bottom view if binary tree
//                         1
//                       /   \
//                     2      3
//                    /  \   /  \
//                    4   5  6   7
// bottom view:- [{4},{2},{6},{3},{7}]

// Approach:-
// approach same h top view ke jaisa bss isme map me hd ko update kr denge jab bhi hd ka key milega toh usme node data store karenge
// 1. toh hum 1 map<int,int> lenge jisme hd and node data store karenge
// 2. queue me pair<Node*,int> store karenge jisme node and uska hd store karenge
// 3. queue me root node and hd=0 store karenge
// 4. jab tak queue empty nahi hoti tab tak loop chalayenge
//          a. queue se front element nikalenge
//          b. map me hd -> node data store karenge 
//          c. agar left child hai toh usse queue me hd-1 ke sath store karenge
//          d. agar right child hai toh usse queue me hd+1 ke sath store karenge
// 5. loop ke baad map me jo bhi values hongi unhe print kar

vector<int> bottomView(Node* root){
    vector<int> ans;
    if(!root){
        return ans;
    }

    map<int,int>mp;
    queue<pair<Node*,int>>q;
    q.push({root,0});

    while(!q.empty()){
        auto it = q.front();
        q.pop();
        Node* node = it.first;
        int hd = it.second;

       // store node data in map for hd
        mp[hd] = node->data;

        if(node->left){
            q.push({node->left,hd-1});
        }
        if(node->right){
            q.push({node->right,hd+1});
        }
    }

    for(auto i:mp){
        ans.push_back(i.second);
    }
    return ans;
}

int main(){
    return 0;
}