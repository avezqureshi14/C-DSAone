#include <iostream>
using namespace std;

void Merge(int arr1[], int arr2[], int n, int m, int arr3[]){
    int i = 0, j = 0;
    int k = 0;
    while (i<n && j<m)
    {
        if(arr1[i] < arr2[j]){
            arr3[k] = arr1[i];
            k++;
            i++;

        }
        else{
            arr3[k] = arr2[j];
            k++;
            j++;
        }
    }

    //copy first array k element 
    while (i < n)
    {
        arr3[k] = arr1[i];
        k++;
        i++;
    }

    //copy second array k remaining element
    while (j < m)
    {
        arr3[k] = arr2[j];
        k++;
        j++;
    }
}

void print(int ans[], int n){
    for (int i = 0; i < n; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    
}

int main()
{
    int arr1[4] = {1,3,5,7};
    int arr2[3]= {2,4,6};
    int arr3[7] = {0};

    Merge(arr1,arr2,4,3,arr3);
    print(arr3,7);
    return 0;
}