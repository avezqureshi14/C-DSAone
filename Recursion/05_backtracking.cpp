#include <iostream>
using namespace std;

void Linear(int i, int n)
{
    if (i < 1)
    {
        return;
    }
    Linear(i-1,n);
    cout<<i<<endl;
}

int main()
{
    Linear(3, 3);
    return 0;
}