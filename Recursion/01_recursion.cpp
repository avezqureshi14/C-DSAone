#include <iostream>
using namespace std;
int count = 10;
void recursiveFunc()
{
    //Base Condition
    if (count == 4)
    {
        return;
    }
    
    cout<<count++;

    //recursive call 
    recursiveFunc();
}

// If we will recurssively call a function without a base condition then that function will run until it runs out of memory

void name()
{
    if (count == 4)
    {
        return;
    }
    
    cout<<"Avez"<<endl;
    count++;
    name();
}

void Linear1()
{
    if (count == 10)
    {
        return;
    }
    
    cout<<count++<<endl;;
    Linear1();
}

void Linear2()
{
    if (count == 0)
    {
        return;
    }
    
    cout<<count--<<endl;;
    Linear2();
}

int main()
{
    // recursiveFunc();
    // name();
    Linear2();
    return 0;
}