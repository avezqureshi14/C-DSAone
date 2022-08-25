#include <iostream>
using namespace std;

void Linear(int i, int n)
{
    if (i > n)
    {
        return;
    }
    Linear(i+1,n);
    cout<<i<<endl;;
    

}

int main()
{
    Linear(1, 10);
    return 0;
}