#include <iostream>
using namespace std;

int main()
{

    int arr[] = {2,5,4};
    int n = 3;
   int sum = 0;
   for (int i = 0; i < n; i++)
   {
    sum += arr[i];
   }

   cout<<sum;
   
    return 0;
}
