#include <bits/stdc++.h>

using namespace std;

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

int getCountOfNode(Node *root, int l, int h)
{

    if (!root)
        return 0;

    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
        return 1 + getCountOfNode(root->left, l, h) +
               getCountOfNode(root->right, l, h);

    else if (root->data < l)
        return getCountOfNode(root->right, l, h);

    else
        return getCountOfNode(root->left, l, h);
}

bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        Node *root;
        Node *tmp;
        //int i;

        root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            int k;
            cin >> k;
            insert(&root, k);
        }

        cout << isDeadEnd(root);
        cout << endl;
    }
}

// } Driver Code Ends

void inorder(Node *root, unordered_set<int> &h)
{
    if (root == NULL)
        return;
    inorder(root->left, h);
    h.insert(root->data);
    inorder(root->right, h);
}
bool isDeadEnd(Node *root)
{
    //Your code here
    unordered_set<int> h;
    inorder(root, h);
    unordered_set<int>::iterator i;
    int flag = 0;
    vector<int> leaf;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *t = q.front();
        q.pop();
        if (t->left == NULL && t->right == NULL)
        {
            leaf.push_back(t->data + 1);
            leaf.push_back(t->data - 1);
        }
        if (t->left)
            q.push(t->left);
        if (t->right)
            q.push(t->right);
    }
    for (int i = 0; i < leaf.size(); i = i + 2)
    {
        if (leaf[i + 1] == 0)
        {
            if (h.find(leaf[i]) != h.end())
            {
                flag = 1;
                break;
            }
        }
        else
        {
            if (h.find(leaf[i]) != h.end() && h.find(leaf[i + 1]) != h.end())
            {
                flag = 1;
                break;
            }
        }
    }
    return flag;
}