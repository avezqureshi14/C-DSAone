#include <iostream>
using namespace std;
class A{
    public:
    A(){
        cout<<"A";
    }
    ~A(){
        cout<<"~A";
    }


};

class B : virtual public A{
    public:
     B(){
        cout<<"B";
     }
     ~B(){
        cout<<"~B";
     }
};

class C : virtual public A{
    public:
     C(){
        cout<<"C";
     }
     ~C(){
        cout<<"~C";
     }
};

class D: public B, public C{
    public:
    D(){
        cout<<"D";
    }
    ~D(){
        cout<<"~D";
    }
};


int main()
{
    A*ptr = new D();
    delete(ptr);
    return 0;
    
    return 0;
}