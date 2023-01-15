// templates.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

// function template example

template <class T>
T myMin(T a, T b)
{
    return (a < b) ? a : b;
}

// function template with multiple types of arguments

template<class T, class J, class K>
void fun(T n1, J n2, K n3)
{
    cout << n1 << n2 << n3 << endl;
}


template <class T>
class MyClass {
private: 
    T m_X1, m_X2;

public:
    MyClass() {};

    MyClass(T m, T n) : m_X1(m), m_X2(n) {};

    void printVal();
};

template <class T>
void MyClass<T>::printVal()
{
    cout << "MyClass template"<<m_X1<<m_X2 << endl;
}

int main()
{
    int i = 10, j = 20;
    cout << myMin(i, j) << endl;

    float n1 = 5.4f, n2 = 3.5f;
    cout << myMin(n1, n2) << endl;


    // function template with multiple arguments
    string str = "Ramesh";
    fun(i, j, str);
    fun(str, i, j);

    // class template

    MyClass<int> c1, c2(20, 30);
    c2.printVal();
}


