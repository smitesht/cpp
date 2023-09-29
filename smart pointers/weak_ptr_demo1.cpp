// weak_ptr_demo1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <memory>
#include <sstream>

using namespace std;

class C;

class A
{
private:
    //shared_ptr<C> ptr;
    weak_ptr<C> ptr;
public:
    A() {
        cout << "ctor A" << endl;
    }

    ~A() {
        cout << "dtor A" << endl;
    }

    void setObject(weak_ptr<C> ptr) {
        this->ptr = ptr;
    }
};

class B
{
private:
    //shared_ptr<C> ptr;
    weak_ptr<C> ptr;
public:
    B() {
        cout << "ctor B" << endl;
    }

    ~B() {
        cout << "dtor B" << endl;
    }

    void setObject(weak_ptr<C> ptr) {
        this->ptr = ptr;
    }
};

class C {
private:
    shared_ptr<A> ptr1;
    shared_ptr<B> ptr2;

public:
    C(shared_ptr<A> ptr1, shared_ptr<B> ptr2) {
        cout << "ctor C" << endl;
        this->ptr1 = ptr1;
        this->ptr2 = ptr2;
    }

    ~C() {
        cout << "dtor" << endl;
    }

};


int main()
{
    shared_ptr<A> a(new A());
    shared_ptr<B> b(new B());
    shared_ptr<C> c( new C(a, b));

    a->setObject(c);
    b->setObject(c);

    //PROBLEMl
    /* This code never call the destructor.
    */

    return 0;

}


