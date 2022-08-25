#include <iostream>
using namespace std;
void Linear( int i, int n )
{
    if (n <= 0   )
    {
        return;
    }
    cout<<n<<endl;
    Linear(i,n-1);
    
}
int main()
{
    Linear(1,10);
    return 0;
}