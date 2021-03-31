#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i = 1;
    // int c3 = 0;
    // int c5 = 0;
    for (; i <= 100; i++)
    {
        // c3++;
        // c5++;
        // if (c3 == 3 && c5 == 5)
        // {
        //     cout << " PING PONG" << endl;
        //     c3 = 0;
        //     c5 = 0;
        // }
        // else if (c3 == 3)
        // {
        //     cout << "PING" << endl;
        //     c3 = 0;
        // }
        // else if (c5 == 5)
        // {
        //     cout << "PONG" << endl;
        //     c5 = 0;
        // }
        if (i % 3 == 0)
        {
            if (i % 5 == 0)
            {
                cout << "PING PONG" << endl;
            }
            else
            {
                cout << "PING" << endl;
            }
        }
        else if (i % 5 == 0)
        {
            cout << "PONG" << endl;
        }
        else
        {
            cout << i << endl;
        }
    }
    return 0;
}