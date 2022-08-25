#include <iostream>
using namespace std;

// DRY RUN this for abc 

//SIMPLE FUNDA ek baar element ko lene ka, ek baar chodne ka. kab tak karne ka, jab tak apne index ki value increment ho ho kar string ki length ke equal nahi hoti 

void powerSet(string s, int index = 0, string current = "")
{
    if (index == s.length())
    {
        cout<<current<<endl;
        return;
    }
    powerSet(s, index + 1, current + s[index]); //ek baar lene ka
    powerSet(s, index + 1, current); //ek baar nahi lene ka
    
}

int main()
{
    string s = "abc";
    int n = s.length();

    // cout<<"There will be "<<2^n<<" powerset, They are"<endl;

    powerSet(s);
        
    return 0;
}
/*
output 
abc 
ab 
ac 
a 
bc 
b 
c 
""
*/