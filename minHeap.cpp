#include <bits/stdc++.h>
using namespace std;
class heap
{
    int *arr;
    int size;
    int capacity;

public:
    heap(int c)
    {
        size = 0;
        capacity = c;
        arr = new int[c];
    }
    int parent(int i)
    {
        return (i - 1) / 2;
    }
    void swap(int &a, int &b)
    {
        int c = a;
        a = b;
        b = c;
    }
    int left(int i)
    {
        return 2 * i + 1;
    }
    int right(int i)
    {
        return 2 * i + 2;
    }
    void Insert(int k)
    {
        if (size == capacity)
        {
            cout << "Overflox\n";
            return;
        }
        size++;
        int i = size - 1;
        arr[i] = k;
        while (i != 0 && arr[i] < arr[parent(i)])
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }
    void decreasekey(int i, int newval)
    {
        arr[i] = newval;
        while (i != 0 && arr[i] < arr[parent(i)])
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }
    void heapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int sm = i;
        if (l < size && arr[sm] > arr[l])
        {
            sm = l;
        }
        if (r < size && arr[sm] > arr[r])
        {
            sm = r;
        }
        if (sm != i)
        {
            swap(arr[sm], arr[i]);
            heapify(sm);
        }
    }
    int extractMin()
    {
        if (size == 0)
            return -1;
        if (size == 1)
        {
            size--;
            return arr[0];
        }
        int r = arr[0];
        arr[0] = arr[size - 1];
        size--;
        heapify(0);
        return r;
    }
    void deleteKey(int i)
    {
        decreasekey(i, INT_MIN);
        extractMin();
    }
};
int main()
{
    heap a(10);
    a.Insert(5);
    a.Insert(2);
    a.Insert(6);
    cout << a.extractMin() << endl;
    cout << a.extractMin() << endl;
    a.Insert(20);
    a.Insert(12);
    a.deleteKey(2);
    cout << a.extractMin() << endl;
    cout << a.extractMin() << endl;
    return 0;
}