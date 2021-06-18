#include <bits/stdc++.h>
using namespace std;
typedef struct Node
{
    int l;
    int h;
    Node *left;
    Node *right;
} Node;
Node *newNode(int n1, int n2)
{
    Node *t = (Node *)malloc(sizeof(Node));
    t->l = n1;
    t->h = n2;
    t->left = t->right = NULL;
    return t;
}
Node *insert(Node *node, int n1, int n2)
{
    if (node == NULL)
    {
        node = newNode(n1, n2);
        return node;
    }
    if (node->l > n2)
    {
        node->left = insert(node->left, n1, n2);
    }
    else if (node->h < n1)
    {
        node->right = insert(node->right, n1, n2);
    }
    return node;
}
void inorder(Node *root, int &l)
{
    if (root == NULL)
        return;
    inorder(root->left, l);
    l++;
    cout << endl;
    cout << root->l << " " << root->h;
    inorder(root->right, l);
}
int main()
{
    int arr[][2] = {{1, 5}, {3, 7}, {2, 6}, {10, 15}, {5, 6}, {4, 100}};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        root = insert(root, arr[i][0], arr[i][1]);
    }
    int l = 0;
    inorder(root, l);
    cout << endl
         << "Non-Conflicting Appointments=" << l;
    return 0;
}