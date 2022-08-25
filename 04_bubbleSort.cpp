#include <bits/stdc++.h>
using namespace std;
// doh loop chalane ka ek n-1 tak (outer loop) aur dusra  n-i-1 tak (inner loop).Fir condition likhne ka ki agar left wala right wale se bda hai toh usko swap karo , uske saath saath swapping manage karne ke liye swapped true , false bhi karne ka  
//pehla loop dusre loop ko n-1 times run karta
void print(int arr[], int n)
{
    for (int i; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void swap(int*a, int*b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n)
{
    bool swapped;
    for (int i = 0; i < n - 1 ; i++)
    {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
                swapped = true;
            }
        }

        if(swapped == false)
        {
            break;
        }
    }
}

int main()
{
    int arr[] = {1, 88, 7, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    print(arr, n);
    cout<<endl;
    bubbleSort(arr,n);
    print(arr,n);

    return 0;
}


//Check whether the right element is smaller than the left element if it is small than just swap it

//  3  4  5  8
//  L  R

// Check R<L if yes swap(R,L)

//In this way our will be getting automatically sorted from ending to starting 

//If we will run only the inner loop it will swap the first pair which is staisfying the condition, but we want this to be occur again and again thats why we are using the outer loop  

// Time complexity is O(n^2)