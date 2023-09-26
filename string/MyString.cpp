// MyString.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CString.h"

int main()
{
    CString name("Smitesh");
    name.print();

    CString n1 = name;
    n1.print();

    CString n2 = "Amit";
    n2.print();

    n2 = name;
    n2.print();
    n2 += n1;
    n2.print();

    CString s1 = "Ramesh";

    CString s2 = s1 + n2;
    
}


