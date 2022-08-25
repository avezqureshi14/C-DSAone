//   First divide our array into two parts by finding the mid then check whether our array is sorted (Consider left part is sorted) and then find the element in that part of the array , if the element is not present in the array discard left part and try searching in the right part
#include <bits/stdc++.h>

using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int modifiedBinarySearch(int arr[], int low, int high, int key)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        if (arr[low] < arr[mid])
        {
            if (key >= arr[low] && key < arr[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (key <= arr[high] && key > arr[mid])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }

    return -1;
}

int main()
{
    int arr[] = {20, 30, 40, 50, 60, 5, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    print(arr, n);
    cout << endl;
    int results = modifiedBinarySearch(arr, 0, n - 1, 5);
    cout << "The element is present at index " << results;

    return 0;
}

// Time Complexity of Binary Search is O(logn)
