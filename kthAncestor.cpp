#include <bits/stdc++.h>
using namespace std;

// A Binary Tree Node
struct Node
{
    int data;
    struct Node *left, *right;
};
Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
Node *t;
Node *kthAncestor(Node *root, int node, int &k)
{
    // Base case
    if (!root)
        return NULL;

    if (root->data == node ||
        (t = kthAncestor(root->left, node, k)) ||
        (t = kthAncestor(root->right, node, k)))
    {
        if (k > 0)
            k--;

        else if (k == 0)
        {
            // print the kth ancestor
            cout << "Kth ancestor is: " << root->data;

            // return NULL to stop further backtracking
            return NULL;
        }

        // return current node to previous call
        return root;
    }
}
int main()
{
    // Let us create binary tree shown in above diagram
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    int k = 2;
    int node = 5;

    // print kth ancestor of given node
    Node *parent = kthAncestor(root, node, k);

    // check if parent is not NULL, it means
    // there is no Kth ancestor of the node
    if (parent)
        cout << "-1";

    return 0;
}