#include <bits/stdc++.h>
using namespace std;

// A Linked List node
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

/* Function to print nodes in a given linked list */
void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}

// } Driver Code Ends

class Solution
{
public:
    //Function to merge K sorted linked list.
    Node *mergeKLists(Node *arr[], int k)
    {
        // Your code here
        Node *fin = NULL;
        Node *head = NULL;
        int empty = 0;
        int minn = INT_MAX;
        int ind = -1;
        while (empty < k)
        {
            empty = 0;
            minn = INT_MAX;
            ind = -1;
            for (int i = 0; i < k; i++)
            {
                if (arr[i] == NULL)
                {
                    empty++;
                }
                else
                {
                    if (minn > arr[i]->data)
                    {
                        minn = arr[i]->data;
                        ind = i;
                    }
                }
            }
            if (ind != -1)
            {
                if (head == NULL)
                {
                    fin = new Node(minn);
                    head = fin;
                }
                else
                {
                    fin->next = new Node(minn);
                    fin = fin->next;
                }
                arr[ind] = arr[ind]->next;
            }
        }
        return head;
    }
};
