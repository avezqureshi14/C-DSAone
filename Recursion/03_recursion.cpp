#include <iostream>
using namespace std;
void Linear( int i , int n )
{
    if (i > n)
    {
        return;
    }
    cout<<i<<endl;
    Linear(i+1,n);
}
int main()
{
    Linear(1,5);  
    return 0;
}