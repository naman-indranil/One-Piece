// C++ program to Count
// Inversions in an array
// using Merge Sort
#include <bits/stdc++.h>
using namespace std;

void _mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);

/* This function sorts the
input array and returns the
number of inversions in the array */
void mergeSort(int arr[], int array_size)
{
    // int temp[array_size];
    _mergeSort(arr, 0, array_size - 1);
}

/* An auxiliary recursive function
that sorts the input array and
returns the number of inversions in the array. */
void _mergeSort(int arr[], int left, int right)
{
    int mid, inv_count = 0;
    if (right > left)
    {
        /* Divide the array into two parts and
		call _mergeSortAndCountInv()
		for each of the parts */
        mid = (right + left) / 2;

        /* Inversion count will be sum of
		inversions in left-part, right-part
		and number of inversions in merging */
        _mergeSort(arr, left, mid);
        _mergeSort(arr, mid + 1, right);

        /*Merge the two parts*/
        merge(arr, left, mid + 1, right);
    }
    // return inv_count;
}

/* This funt merges two sorted arrays
and returns inversion count in the arrays.*/
void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int inv_count = 0;

    i = left; /* i is index for left subarray*/
    j = mid;  /* j is index for right subarray*/
    k = left; /* k is index for resultant merged subarray*/
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
        {
            i++;
        }
        else
        {
            int val = arr[j];
            int tem = j;
            while (tem != i)
            {
                arr[tem] = arr[tem - 1];
                tem--;
            }
            arr[i] = val;
            i++;
            j++;
            mid++;
            inv_count = inv_count + (mid - i);
        }
    }

    /* Copy the remaining elements of left subarray
(if there are any) to temp*/
    // while (i <= mid - 1)
    //     temp[k++] = arr[i++];

    // /* Copy the remaining elements of right subarray
    // (if there are any) to temp*/
    // while (j <= right)
    //     temp[k++] = arr[j++];

    // /*Copy back the merged elements to original array*/
    // for (i = left; i <= right; i++)
    //     arr[i] = temp[i];
}

// Driver code
int main()
{
    int arr[] = {1, 20, 6, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, n);
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    // cout << " Number of inversions are " << ans;
    return 0;
}

// This is code is contributed by rathbhupendra
