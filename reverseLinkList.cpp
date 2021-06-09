#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
typedef struct node node;
void reverse(node **head)
{
    node *prev = NULL;
    node *curr = NULL;
    node *upcoming = NULL;
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
void printlist(node *head)
{
    if (head == NULL)
    {
        cout << "Empty List" << endl;
        return;
    }
    while (head != NULL)
    {
        cout << head->data << "--->";
        head = head->next;
    }
    return;
}
void push(node **head, int n)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = n;
    temp->next = NULL;
    if (*head == NULL)
    {
        *head = temp;
        return;
    }
    node *last = *head;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = temp;
    return;
}

int main()
{
    node *l = NULL;
    int n;
    cout << "give inputs to link list. input -1 to stop" << endl;
    while (true)
    {
        cin >> n;
        if (n == -1)
        {
            break;
        }
        push(&l, n);
    }
    printlist(l);
    cout << "Reversing:" << endl;
    reverse(&l);
    printlist(l);
    return 0;
}