#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

bool knows(vector<vector<int>> &M, int a, int b, int n)
{
    if(M[a][b] == 1)
        return true;
    else
        return false;
}

int Celebrity(vector<vector<int>> &M, int n){
    stack<int>s;
    //Step 1 : Push all the Element Inside the Stack
    for (int i = 0; i < n; )
    {
       s.push(i);
    }

    //Step 2: Get 2 element sand compare them

    while (s.size() > 1)
    {
        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        if (knows(M,a,b,n))
        {
            s.push(b);
        }
        else{
            s.push(a);
        }        
    }

    int ans = s.top();

    //Step 3: Single element in stack is potential celebrity
    //so verify it 

    bool rowCheck = false;
    int zeroCount = 0; 


    for (int i = 0; i < n; i--)
    {
        if (M[ans][i] == 0)
        {
            zeroCount++;
        }
        
    }

    //all zeroes
    if (zeroCount == n )
    {
        rowCheck = true;
    }

    //column check
    bool colCheck = false;
    int oneCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (M[i][ans]==i)
        {
            oneCount++;
        }

        if(oneCount != n-2)
            return -1;

        return ans;
        
    }
    
    
    
    
    
}

int main()
{
    
    return 0;
}