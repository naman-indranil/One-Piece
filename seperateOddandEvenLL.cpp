#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

// } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
public:
    Node *divide(int N, Node *head)
    {
        // code here
        Node *temp = NULL;
        Node *hd = NULL;
        Node *t = head;
        while (t != NULL)
        {
            if (t->data % 2 == 0)
            {
                if (hd == NULL)
                {
                    temp = new Node(t->data);
                    hd = temp;
                }
                else
                {
                    temp->next = new Node(t->data);
                    temp = temp->next;
                }
            }
            t = t->next;
        }
        t = head;
        while (t != NULL)
        {
            if (t->data % 2 == 1)
            {
                if (hd == NULL)
                {
                    temp = new Node(t->data);
                    hd = temp;
                }
                else
                {
                    temp->next = new Node(t->data);
                    temp = temp->next;
                }
            }
            t = t->next;
        }
        return hd;
    }
};

// { Driver Code Starts.

int main()
{
    //code
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int data;
        cin >> data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N - 1; ++i)
        {
            cin >> data;
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans);
    }
    return 0;
}