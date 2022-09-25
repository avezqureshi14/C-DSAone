#include <iostream>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
    cout<<arr[i]<<" ";
    }
    
}

void minNmax(int arr[], int n)
{
    int min, max;
    if (n == 0)
    {
        cout<<"Empty array"<<endl;
    }//
    if(n == 1)
    {
        min = arr[0];
        max = arr[0];
    }
    else{
        if (arr[1]>arr[0])
        {
            max = arr[1];
            min = arr[0];
        }
        else{
            max = arr[0];
            min = arr[1];
        }
        for (int i = 2; i < n; i++)
        {
            if (arr[i]>max)
            {
                max = arr[i];
            }
            if (arr[i]<min)
            {
                min = arr[i];
            }

            
            
        }
        
        
    }
    cout << "Minimum element is " << min << endl;
    cout << "Maximum element is " << max << endl;
    
}

int main()
{
    int arr[] = {25,45,0,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    print(arr,n);
    cout<<endl;
    minNmax(arr,n);
    

    return 0;
}