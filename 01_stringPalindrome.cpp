#include <iostream>
using namespace std;

//JUST DRY RUN YOU WILL UNDERSTAND EVERYTHING

bool isPalin(string s, int left, int right)
{
    if (left >= right) //condition for single thing //base case
    {
        return true;
    }
    if(s[left] != s[right])
    {
        return false;
    }

    return isPalin(s,left + 1, right - 1);
    
}

int main()
{
    string s = "racecar";
    int strlength = s.length();
    bool decide = isPalin(s,0,strlength-1);

    if (decide == true)
    {
        cout<<"The given String is a Palindrome";
    }
    else{
        cout<<"The given string is not a Palindrome";
    }

    return 0;
}


// The Time Complexity of this algorithm is O(n) because we are traversing each element of the string 

//check karo kya left right se greater ya equal too hai agar hai toh return karo it is a palindrome
// agar nahi toh agli condition par move karo ,ki kahi jo left aur right position par elements , kya woh dono unequal toh nahi agar unequal hai toh bolo it is not a palindrome
// wahi firr function ko aage ke doh elements ke liye call karo  