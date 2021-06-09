#include <stdio.h>
#include <stdlib.h>

/* structure for a Node */
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

void splitList(struct Node *head, struct Node **head1_ref, struct Node **head2_ref);
struct Node *newNode(int key)
{
    struct Node *temp = new Node(key);

    return temp;
}
/* Function to split a list (starting with head) into two lists.
   head1_ref and head2_ref are references to head Nodes of 
    the two resultant linked lists */

void printList(struct Node *head)
{
    struct Node *temp = head;
    if (head != NULL)
    {
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    }
}

/* Driver program to test above functions */
int main()
{

    int t, n, i, x;
    scanf("%d", &t);
    while (t--)
    {
        struct Node *temp, *head = NULL;
        struct Node *head1 = NULL;
        struct Node *head2 = NULL;
        scanf("%d", &n);
        scanf("%d", &x);
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++)
        {
            scanf("%d", &x);

            temp->next = new Node(x);

            temp = temp->next;
        }

        temp->next = head;

        splitList(head, &head1, &head2);

        // printf("\nFirst Circular Linked List");
        printList(head1);

        // printf("\nSecond Circular Linked List");
        printList(head2);
    }
    return 0;
}
// } Driver Code Ends

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    // your code goes here
    Node *node = head;
    int l = 1;
    int h1 = 0, h2 = 0;
    while (node != NULL && node->next != head)
    {
        l++;
        // printf("the countis: %d",l);
        node = node->next;
    }
    h1 = 0;
    h2 = (l + 1) / 2;
    Node *temp1 = NULL;
    Node *head1 = NULL;
    node = head;
    while (h1 < h2)
    {
        if (temp1 == NULL)
        {
            temp1 = new Node(node->data);
            head1 = temp1;
        }
        else
        {
            temp1->next = new Node(node->data);
            temp1 = temp1->next;
        }
        node = node->next;
        h1++;
        // printf("%d ",temp1->data);
    }
    temp1->next = head1;
    *head1_ref = head1;
    Node *temp2 = NULL;
    Node *head2 = NULL;
    while (h2 < l)
    {
        if (temp2 == NULL)
        {
            temp2 = new Node(node->data);
            head2 = temp2;
        }
        else
        {
            temp2->next = new Node(node->data);
            temp2 = temp2->next;
        }
        node = node->next;
        h2++;
        // printf("%d ",temp2->data);
    }
    temp2->next = head2;
    *head2_ref = head2;
}