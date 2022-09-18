#include <iostream>
#include <bits/stdc++.h>
using namespace std;


//Ques: Kitne elements unique teh woh return karne ka hai aur unique elements ko samne ek saath lana hai
//Ek variable i ko initialize karo zero se aur j se array traverse karo agar arr[i] != arr[j] mila toh i++ karo aur arr[i]=arr[j] karo
int removeDuplicates(int arr[], int n ){
    if (n == 0)
    {
        return 0; 
    }

    int i = 0;
    for (int j = 0; j < n; j++)
    {
        if (arr[j] != arr[i] )
        {
            i++;
            arr[i] = arr[j];
        }

        
    }
    
        return i + 1;
    
    
}   

void print(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}

int main()
{
    int arr[] = {1,1,1,2,2,2,3,3,3,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<removeDuplicates(arr,n)<<endl;
    print(arr,n);
    return 0;
}