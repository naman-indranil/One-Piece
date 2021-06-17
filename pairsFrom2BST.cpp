#include <bits/stdc++.h>
using namespace std;

// structure of a node of BST
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void insert(Node **tree, int val)
{
    Node *temp = NULL;
    if (!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if (val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if (val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }
}

int countPairs(Node *root1, Node *root2, int x);

// Driver code
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        Node *root1 = NULL;
        Node *root2 = NULL;
        int n1, n2, k;
        cin >> n1;
        for (int i = 0; i < n1; i++)
        {
            cin >> k;
            insert(&root1, k);
        }
        cin >> n2;
        for (int i = 0; i < n2; i++)
        {
            cin >> k;
            insert(&root2, k);
        }
        int s;
        cin >> s;
        cout << countPairs(root1, root2, s) << "\n";
    }
    return 0;
}

// } Driver Code Ends

void inorder(Node *root, vector<int> &v)
{
    if (root == NULL)
        return;
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}
int countPairs(Node *root1, Node *root2, int x)
{
    // Code here
    vector<int> v1;
    unordered_set<int> h;
    inorder(root1, v1);
    queue<Node *> q;
    q.push(root2);
    while (!q.empty())
    {
        Node *t = q.front();
        q.pop();
        h.insert(t->data);
        if (t->left)
        {
            q.push(t->left);
        }
        if (t->right)
        {
            q.push(t->right);
        }
    }
    int pairs = 0;
    int c;
    for (int i = 0; i < v1.size(); i++)
    {
        c = x - v1[i];
        if (h.find(c) != h.end())
        {
            pairs++;
        }
    }
    return pairs;
}