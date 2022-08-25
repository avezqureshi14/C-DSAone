// In Selection Sort we select minimum element

#include <iostream>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void swap(int *xptr, int *yptr)
{
    int temp = *xptr;
    *xptr = *yptr;
    *yptr = temp;
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }

        if (min != i)
        {
            swap(&arr[min], &arr[i]);
        }
    }
}

int main()
{
    int arr[] = {4, 1, 9, 2, 3, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, n);
    print(arr, n);
    return 0;
}

// Time complexity is O(n^2)
