#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Utility function to create a new Tree Node
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

vector<int> bottomView(Node *root);

// Function to Build Tree
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
    Node *root = newNode(stoi(ip[0]));

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

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

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
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int main()
{
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s, ch;
        getline(cin, s);
        Node *root = buildTree(s);

        vector<int> res = bottomView(root);
        for (int i : res)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

//Function to return a list containing the bottom view of the given tree.
vector<int> bottomView(Node *root)
{
    //Your code here
    unordered_map<int, int> m;
    queue<pair<Node *, int>> q;
    Node *temp;
    vector<pair<int, int>> vec;
    vector<int> v;
    if (root == NULL)
    {
        v.clear();
        return v;
    }
    q.push(make_pair(root, 0));
    int val;
    while (!q.empty())
    {
        pair<Node *, int> p = q.front();
        q.pop();
        temp = p.first;
        val = p.second;
        if (temp->left != NULL)
        {
            q.push(make_pair(temp->left, val - 1));
        }
        if (m.find(val) == m.end())
        {
            m[val] = temp->data;
            // vec.push_back(make_pair(temp->data, val));
        }
        else if (m.find(val) != m.end())
        {
            m[val] = temp->data;
        }
        if (temp->right != NULL)
        {
            q.push(make_pair(temp->right, val + 1));
        }
    }

    for (int i = -10000; i < 10000; i++)
    {
        if (m.find(i) != m.end())
        {
            cout << m[i] << " ";
        }
    }
    return v;
}
