// Given the root of a Binary Search Tree and a node value key, find if the node with value key is present in the BST or not.

// methos 1: recursive
bool search(Node *root, int key)
{
    if (!root)
    {
        return false;
    }

    if (root->data == key)
    {
        return true;
    }

    if (key < root->data)
    {
        return search(root->left, key);
    }
    if (key > root->data)
    {
        return search(root->right, key);
    }

    return false;
}

// method 2: iterative
// in this just traverse inorder than find the key in the vector 

void inorder(Node *root, vector<int> &v)
{
    if (!root)
    {
        return;
    }

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

bool search(Node *root, int key)
{
    vector<int> v;
    inorder(root, v);

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == key)
        {
            return true;
        }
    }

    return false;
}