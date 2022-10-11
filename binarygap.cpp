#include <iostream>
using namespace std;
int binaryGap(int n)
{
    int lastone = 40;
    int ans = 0;
    for (int i = 0; i < 40; i++)
    {
        if (n & (1 << i))
        {
            ans = max(ans, i - lastone);
            lastone = i;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    binaryGap(n);
    return 0;
}