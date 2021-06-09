#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void print(Node *root)
{
    Node *temp = root;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// } Driver Code Ends

class Solution
{
public:
    void reverse(Node **head)
    {
        Node *prev = NULL;
        Node *curr = NULL;
        Node *upcoming = NULL;
        curr = *head;
        while (curr != NULL)
        {
            upcoming = curr->next;
            curr->next = prev;
            prev = curr;
            curr = upcoming;
        }
        *head = prev;
    }
    Node *compute(Node *head)
    {
        // your code goes here
        Node *temp = NULL;
        Node *hd = NULL;
        reverse(&head);
        int max = head->data;
        while (head != NULL)
        {
            if (head->data >= max)
            {
                max = head->data;
                if (hd == NULL)
                {
                    temp = new Node(head->data);
                    hd = temp;
                }
                else
                {
                    temp->next = new Node(head->data);
                    temp = temp->next;
                }
            }
            head = head->next;
        }

        reverse(&hd);
        return hd;
    }
};

// { Driver Code Starts.

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int K;
        cin >> K;
        struct Node *head = NULL;
        struct Node *temp = head;

        for (int i = 0; i < K; i++)
        {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else
            {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout << endl;
    }
}