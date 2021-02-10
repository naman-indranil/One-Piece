// #include <iostream>
// #include <iomanip>

// using namespace std;

// int main()
// {
//     // YOUR CODE GOES HERE
//     // Please take input and print output to standard input/output (stdin/stdout)
//     // E.g. 'cin' for input & 'cout' for output
//     int n1;
//     long int n2;
//     char n3;
//     float n4;
//     double n5;
//     cin >> n1;
//     cin >> n2;
//     cin >> n3;
//     cin >> n4;
//     cin >> n5;
//     cout << n1 << endl;
//     cout << n2 << endl;
//     cout << n3 << endl;
//     cout << fixed << setprecision(3) << n4 << endl;
//     cout << fixed << setprecision(9) << n5 << endl;
//     return 0;
// }
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// Your Code goes here
int compute(int, int);
int main()
{
    int A, B;
    cin >> A;
    cin >> B;
    cout << compute(A, B) << endl;
    return 0;
}
int compute(int a, int b)
{
    int s = 0;
    s = (int)(pow(a, 2) + pow(b, 2));
    return s;
}
