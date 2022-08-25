// Quick Sort is based on Partitioning Logic
#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int Partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[j], &arr[low]);
    return j;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int quickPivot = Partition(arr, low, high);
        quickSort(arr, low, quickPivot - 1);
        quickSort(arr, quickPivot + 1, high);
    }
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {4, 6, 2, 5, 7, 9, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    print(arr, n);
    quickSort(arr, 0, n - 1);
    cout << endl;
    print(arr, n);
    return 0;
}

// Time Complexity O(nlogn)