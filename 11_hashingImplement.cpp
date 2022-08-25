// insert an element
// How to find particular element in an unordered set 
// How to clear unordered set 
// How to know the size of an unordered set 


#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    unordered_set <int> num;
    
    //How to insert element in an unordered set
    num.insert(25);
    num.insert(5);
    num.insert(15);

    //How to find a particular element in an unordered set
    if (num.find(5) == num.end())
    {
        cout<<"Element not found"<<endl;
    }
    else
    {
        cout<<"Element found"<<endl;
    }

    //How to print all the element from the unordered set

    for (auto it = num.begin(); it != num.end(); it++)
    {
        cout<<(*it)<<" ";
    }
    cout<<endl;

    //How to clear our unordered set

    // num.clear();

    //How to know the size of an unordered set

    cout<<num.size();

    cout<<endl;

    //count() is another function to find an element from the unordered set , It returns '1' if the element is present and it returns '0' when the element is not present

    cout<<"Boolean '1',element is present in our unordered set"<<num.count(15);
    if(num.count(15) == 0)
    {
        cout<<"Boolean '0', Not Present   ";
    }

    //Above we have seen a function clear(),  to clear the complete unordered set, erase() is used to clear range of or particular element in an unordered set 

    num.erase(15); //removes 15 from unordered set

    num.erase(num.begin(), num.end()); //clears complete unordered set
    
    

    return 0;
}