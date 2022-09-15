#include <iostream>
using namespace std;
void func(int count, int n)
{
    // base case
    if (count < 1)
    {
        return;
    }
    count--;
    func(count, n);
    cout << count; // if the print line is kept after the function call then it backtracks and even if you had asked to print int the sequence it will print in the reverse order
}

// Finding sum using recrsion
int Sum(int n)
{
    if (n == 0)
    {
        return 0;
    }

    return n + Sum(n - 1); //as we use to do during Iterative method, that initializing sum variable as zero here we cannot do that, we have to think everything doing during runtime
}

//Finding Factorial
int Fact(int n){
    if (n == 1)
    {
        return 1;
    }

    return n * Fact(n-1);
    
}

//Iterative
int Factorial(int n){
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
    }
    return fact;
    
}


int main()
{
    // func(5,5);
    // cout << "Sum is " << Sum(2);
    cout << "Factorial is " << Fact(15);
    // cout << "Factorial is " << Factorial(15);
    return 0;
}