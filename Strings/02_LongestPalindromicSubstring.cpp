#include <iostream>
using namespace std;

void printSubString(string s, int low, int high)
{
    for (int i = low; i <= high; i++)
    {
        cout << s[i];
    }
}

void LongestPalindrome(string s)
{
    int low;
    int high;

    int start = 0, end = 1;

    for (int i = 0; i < s.length(); i++)
    {
        // even substring
        low = i - 1;
        high = i;

        while (low >= 0 && high < s.length() && s[low] == s[high])
        {
            if (high - low + 1 > end)
            {
                start = low;
                end = high - low + 1;
            }
            low--;
            high++;
        }

        // odd substring

        low = i - 1;
        high = i + 1;

        while (low >= 0 && high < s.length() && s[low] == s[high])
        {
            if (high - low + 1 > end)
            {
                start = low;
                end = high - low + 1;
            }
            low--;
            high++;
        }
    }

    printSubString(s,start,start+end-1);
}

int main()
{
    string s = "forgeeksskeegfor";
    LongestPalindrome(s);
    return 0;
}