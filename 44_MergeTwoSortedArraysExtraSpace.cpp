#include <iostream>
using namespace std;

// Note: The input must also need to be sorted 
//Take three arrays 2 filled 1 empty
//Check if current element of first array is smaller than current element of second array if yes than add that element in the third array if no that add second array element in the third array
//Copy remaining elements from the first array
//Copy remaining elements from the second array

void MergeArrays(int arr1[], int arr2[], int n, int m, int arr3[])
{
    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
         
        if (arr1[i] < arr2[j])
        {
            arr3[k++] = arr1[i++];
        }
        else
        {
            arr3[k++] = arr2[j++];
        }
    }
    //Copy remaining elements from the first array
    while (i<n)
    {
       arr3[k++] = arr1[i++]; 
    }

    //Copy remaining elements from the second array 
    while (j<n)
    {
       arr3[k++] = arr2[j++]; 
    }
    
    
}

void print(int arr[], int n){
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int arr1[] = {4,6,7,8};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    int arr2[] = {1,2,3,8};
    int m = sizeof(arr2)/sizeof(arr2[0]);
    int arr3[m+n];
    MergeArrays(arr1,arr2,n,m,arr3);
    print(arr3,(m+n));
    return 0;
}