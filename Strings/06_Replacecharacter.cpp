#include <iostream>
using namespace std;
void Replacecharacter(string &s, char a, char b)
{

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == b)
        {
            s[i] = a;
        }
        else if (s[i] == a)
        {
            s[i] = b;
        }
    }
}

void print(string &s)
{
    for (int i = 0; i < s.length(); i++)
    {
        cout << s[i] << " ";
    }
}
int main()
{
    string s = "apples";
    Replacecharacter(s, 'a', 'p');
    print(s);

    return 0;
}