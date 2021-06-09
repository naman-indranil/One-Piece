#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
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

struct Node *start = NULL;

// } Driver Code Ends

class Solution
{
public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node *segregate(Node *head)
    {

        // Add code here
        Node *temp = NULL;
        Node *hd = NULL;
        int c0 = 0, c1 = 0, c2 = 0;
        while (head != NULL)
        {
            if (head->data == 0)
            {
                c0++;
            }
            else if (head->data == 1)
            {
                c1++;
            }
            else
            {
                c2++;
            }
            head = head->next;
        }
        while (c0 > 0)
        {
            c0--;
            if (temp == NULL)
            {
                temp = new Node(0);
                hd = temp;
            }
            else
            {
                temp->next = new Node(0);
                temp = temp->next;
            }
        }
        while (c1 > 0)
        {
            c1--;
            if (hd == NULL)
            {
                temp = new Node(1);
                hd = temp;
            }
            else
            {
                temp->next = new Node(1);
                temp = temp->next;
            }
        }
        while (c2 > 0)
        {
            c2--;
            if (hd == NULL)
            {
                temp = new Node(2);
                hd = temp;
            }
            else
            {
                temp->next = new Node(2);
                temp = temp->next;
            }
        }
        return hd;
    }
};

// { Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1)
{
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);

        if (i == 0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main()
{

    int n;

    int t;
    scanf("%d", &t);

    while (t--)
    {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}