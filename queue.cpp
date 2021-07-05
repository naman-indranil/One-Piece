// #include <bits/stdc++.h>
// using namespace std;
// typedef struct Queue
// {
//     int d;
//     Queue *next;
// } Queue;
// Queue *front = NULL;
// Queue *back = NULL;
// void push(int data, Queue **q)
// {
//     Queue *t = (Queue *)malloc(sizeof(Queue));
//     t->d = data;
//     t->next = NULL;
//     if (*q == NULL)
//     {
//         *q = t;
//         front = *q;
//         back = *q;
//         free(t);
//         return;
//     }
//     back->next = t;
//     *q = front;
//     free(t);
// }
// int pop(Queue **q)
// {
//     Queue *t = front;
//     if (front->next == NULL)
//         return -1;
//     front = front->next;
//     int n = t->d;
//     free(t);
//     *q = front;
//     return n;
// }
// bool empty(Queue *q)
// {
//     if (q->next == NULL)
//     {
//         return true;
//     }
//     return false;
// }
// int main()
// {
//     Queue *q = NULL;
//     for (int i = 0; i < 10; i++)
//     {
//         push(i, &q);
//     }
//     cout << endl;
//     for (int i = 0; i < 5; i++)
//     {
//         cout << pop(&q) << " ";
//     }
//     cout << endl
//          << empty(q);
//     return 0;
// }