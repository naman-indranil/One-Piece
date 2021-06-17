#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

void printInorder(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

Node *Inorder(Node *root)
{
    if (root->left == NULL)
        return root;
    Inorder(root->left);
}

// } Driver Code Ends

class Solution
{
public:
    void inorder(Node *root, vector<int> &inord)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left, inord);
        inord.push_back(root->data);
        inorder(root->right, inord);
    }
    void putNext(Node *root, int t, Node *head)
    {
        if (t == -1)
        {
            // Node* temp=new Node(-1);
            // root->next=temp;
            return;
        }
        while (head != NULL)
        {
            if (t == head->data)
            {
                break;
            }
            if (t < head->data)
            {
                head = head->left;
            }
            else if (t > head->data)
            {
                head = head->right;
            }
        }
        root->next = head;
        return;
    }
    void nextVal(Node *root, vector<int> v, Node *head)
    {
        if (root == NULL)
        {
            return;
        }
        int l = 0;
        int h = v.size() - 1;
        int mid;
        while (l <= h)
        {
            mid = l + (h - l) / 2;
            if (v[mid] == root->data)
                break;
            if (v[mid] > root->data)
                h = mid - 1;
            else
                l = mid + 1;
        }
        if (v[mid + 1] > root->data)
            putNext(root, v[mid + 1], head);
        else
            putNext(root, -1, head);
        nextVal(root->left, v, head);
        nextVal(root->right, v, head);
    }
    void populateNext(Node *root)
    {
        //code here
        vector<int> inord;
        inorder(root, inord);
        for (int i = 0; i < inord.size(); i++)
        {
            // cout<<inord[i]<<" ";
        }
        Node *head = root;
        nextVal(root, inord, head);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    scanf("%d", &t);
    cin.ignore();
    while (t--)
    {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution obj;
        obj.populateNext(root);
        Node *ptr = Inorder(root);
        while (ptr)
        {
            printf("%d->%d ", ptr->data, ptr->next ? ptr->next->data : -1);
            ptr = ptr->next;
        }
        cout << endl;
    }
    return 0;
}