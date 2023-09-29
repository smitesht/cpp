// SmartPointer001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <memory>
//#include "CSmartPointer.h"


using namespace std;


// Problem with the raw pointer
class MyClass {
public:
    void method()
    {
        int* ptr = new int();
        *ptr = 100;
        int res = *ptr / 0;  // Division by zero error and program crash
        delete ptr; // never call this line due to exception and memory leak happened
    }
};

// Smart Pointer implementation in C++

template <class T>
class CSmartPointer
{
private:
    T* m_ptr;

public:

    // ctor
    explicit CSmartPointer(T* t = nullptr) :m_ptr(t) {}

    //dtor
    ~CSmartPointer() {

        // release memory
        delete m_ptr;
    }
   
    // overload dereference operator
    T& operator* ()
    {
        return *m_ptr;
    }
       
    // overload arrow operator
    T* operator->()
    {
        return m_ptr;
    }

};


class Student {
private: 
    int _id;
    string _name;
    int _age;
    static int counter;

public:
    Student() {
        counter++;
    };
    Student(int id, string name, int age) {
        this->_id = id;
        this->_name = name;
        this->_age = age;
        counter++;
    }

    ~Student() {
        cout << "Student destructor"<< counter << endl;
        counter--;
    }

    void print() {
        cout << counter << endl;
    }

};

int Student::counter = 0;

int main()
{
   // MyClass m1;
   // m1.method();

    //Use our own smart pointer class
    //CSmartPointer<Student> ptr(new Student(1, "Sachin", 32));

    //When control goes out of scope, the ptr will automatically deleted.

   // auto_ptr<Student> ptr1(new Student(1, "ptr1", 3));
   // auto_ptr<Student> ptr2(new Student(2, "ptr2", 4));

    shared_ptr<Student> s1(new Student(1, "S1", 23));
    shared_ptr<Student> s2 = s1;
    shared_ptr<Student> s3;

    s3 = s2;
    cout << s1.use_count();


    return 0;
    
}

