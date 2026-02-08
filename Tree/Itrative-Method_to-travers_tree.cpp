#include<bits/stdc++.h>
using namespace std;


// iterative method to traverse tree

// Node structure -> ek tree node me data, left child, right child hota hai
struct Node{
    int data;
    Node* left;
    Node* right;

    // constructor -> jab new node banega tab value assign hogi
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};



// ================= PREORDER TRAVERSAL =================
// Order hota hai -> Root Left Right

vector<int> preOrder(Node* root){
    vector<int> ans;   // traversal ka output store karega

    // agar tree empty hai to empty vector return
    if(!root){
        return ans;
    }

    stack<Node*> st;  // stack use karenge recursion ki jagah
    st.push(root);    // root ko stack me daal diya

    // jab tak stack empty nahi hota
    while(!st.empty()){
        Node* node = st.top(); // top node nikala
        st.pop();              // stack se remove kiya

        ans.push_back(node->data); // uska data output me daala (ROOT)

        // IMPORTANT:
        // right pehle push karte hain
        if(node->right){
            st.push(node->right);
        }

        // phir left push karte hain
        // taki left child pehle pop ho (stack LIFO hota hai)
        if(node->left){
            st.push(node->left);
        }
    }
    return ans;
}




// ================= INORDER TRAVERSAL =================
// Order hota hai -> Left Root Right

vector<int> inOrder(Node* root){
    vector<int> ans;
    stack<Node*> st;
    Node* node = root;   // current node root se start

    while(true){

        // jab tak node exist karta hai
        if(node){
            // left side jaate jao aur stack me push karte jao
            st.push(node);
            node = node->left;
        }

        else{
            // agar stack empty ho gaya -> traversal khatam
            if(st.empty()){
                break;
            }

            // stack se node nikalo
            node = st.top();
            st.pop();

            // ab root print karo
            ans.push_back(node->data);

            // ab right subtree pe move karo
            node = node->right;
        }
    }
    return ans;
}




// ================= POSTORDER TRAVERSAL =================
// Order hota hai -> Left Right Root

// Trick use ki hai:
// pehle modified preorder karenge -> Root Right Left
// phir reverse kar denge -> Left Right Root (postorder mil jayega)

vector<int> postOrder(Node* root){
    vector<int> ans;

    // agar tree empty hai
    if(!root){
        return ans;
    }

    stack<Node*> st;
    st.push(root);

    while(!st.empty()){
        Node* temp = st.top();
        st.pop();

        // root store kar rahe hain
        ans.push_back(temp->data);

        // left push
        if(temp->left){
            st.push(temp->left);
        }

        // right push
        if(temp->right){
            st.push(temp->right);
        }
    }

    // ab array reverse karenge
    // kyuki abhi order hai -> Root Right Left
    // reverse ke baad ho jayega -> Left Right Root
    reverse(ans.begin(), ans.end());

    return ans;
}
