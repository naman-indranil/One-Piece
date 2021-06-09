#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;

} * start;

void insert();

// } Driver Code Ends
//User function Template for C

//Function to find the data of nth node from the end of a linked list.
int getNthFromLast(struct Node *head, int n)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        n--;
    }
    temp = head;
    if (n > 0)
    {
        return -1;
    }
    while (n < 0)
    {
        n++;
        temp = temp->next;
    }
    return temp->data;
}

// { Driver Code Starts.

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        start = NULL;
        int n, k;
        scanf("%d", &n);
        scanf("%d", &k);
        insert(n);
        int res = getNthFromLast(start, k);
        printf("%d\n", res);
    }
    return 0;
}

void insert(int n)
{
    int value, i;
    struct Node *temp;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);
        if (i == 0)
        {
            start = (struct Node *)malloc(sizeof(struct Node));
            start->data = value;
            start->next = NULL;
            temp = start;
            continue;
        }
        else
        {
            temp->next = (struct Node *)malloc(sizeof(struct Node));
            temp = temp->next;
            temp->data = value;
            temp->next = NULL;
        }
    }
}