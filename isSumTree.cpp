#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, 
   left child and right child */
struct node
{
    int data;
    node *left;
    node *right;
};

/* Utillity function to check if 
the given node is leaf or not */
int isLeaf(node *node)
{
    if (node == NULL)
        return 0;
    if (node->left == NULL && node->right == NULL)
        return 1;
    return 0;
}

/* returns 1 if SumTree property holds for the given
    tree */
int isSumTree(node *node)
{
    int ls; // for sum of nodes in left subtree
    int rs; // for sum of nodes in right subtree

    /* If node is NULL or it's a leaf node then
       return true */
    if (node == NULL || isLeaf(node))
        return 1;

    if (isSumTree(node->left) && isSumTree(node->right))
    {

        // Get the sum of nodes in left subtree
        if (node->left == NULL)
            ls = 0;
        else if (isLeaf(node->left))
            ls = node->left->data;
        else
            ls = 2 * (node->left->data);

        // Get the sum of nodes in right subtree
        if (node->right == NULL)
            rs = 0;
        else if (isLeaf(node->right))
            rs = node->right->data;
        else
            rs = 2 * (node->right->data);

        /* If root's data is equal to sum of nodes in left
           and right subtrees then return 1 else return 0*/
        return (node->data == ls + rs);
    }
    return 0;
}

/* Helper function that allocates a new node
 with the given data and NULL left and right
 pointers.
*/
node *newNode(int data)
{
    node *node1 = new node();
    node1->data = data;
    node1->left = NULL;
    node1->right = NULL;
    return (node1);
}

/* Driver code */
int main()
{
    node *root = newNode(26);
    root->left = newNode(10);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(6);
    root->right->right = newNode(3);
    if (isSumTree(root))
        cout << "The given tree is a SumTree ";
    else
        cout << "The given tree is not a SumTree ";
    return 0;
}