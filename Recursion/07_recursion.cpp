#include <iostream>
using namespace std;

int Sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return n + Sum(n - 1);
}

int main()
{
    cout<<Sum(3);

    return 0;
}