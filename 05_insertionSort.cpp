#include <iostream>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}

//doh loop chalane ka pehla wala loop 1 se shuru karne ka aur us 1st index wale element ko temp variable meh store karne ka fir 
// second wala loop chalane ka jo i-1 se start hota (while loop) fir usko reverse chalane ka kab tak jab tak j>=0 aur arr[j] > temp loop chalate wakt dhyan dene ka ki agar upar ki condition satisfy ho rahi hai toh j+1 element ko j banae ka aur fir bachi hui khali jagah meh temp variable stor karne ka  

void insertionSort(int arr[], int n)
{
    int temp;
    for (int i = 1; i < n; i++)
    {
        temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
        

    }
    
}

//4 5 4 8 9 4
//j i 4 8 9 4

int main()
{
    int arr[] = {8,4,1,5,9,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    print(arr,n);
    cout<<endl;
    insertionSort(arr,n);
    print(arr,n);

    return 0;
}

// Time complexity is O(n^2)
