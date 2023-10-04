# std::hash in C++

### Hash Function in C++

In C++, a hash function is a function that takes an input or key and returns a fixed-sized integer value, called hash code.
Hash functions are used in data structures to quickly map keys to corresponding values. 
The goal is to distribute the key uniformly across a range of hash codes, minimizing collisions (cases where different keys map to the same hash code).

### std::hash in C++

**In C++ STL, std:: hash is a template class that provides a generic interface for creating hash functions for various data types.**
It is commonly used for hashing keys in associative containers such as unordered_set and unordered_map.

```
#include <iostream>
#include <functional>
#include <string>
#include <unordered_map>

using namespace std;


struct Employee
{
    int empId;
    string name;
    int age;

    bool operator ==(const Employee& e) const
    {
        return empId == e.empId && name == e.name && age == e.age;
    }
};

struct EmployeeHash
{
    size_t operator()(const Employee& e) const
    {
        return std::hash<int>{}(e.empId) ^ std::hash<string>{}(e.name) ^ std::hash<int>{}(e.age);
    }    
};


int main()
{
    // Create simple integer hash
    std::hash<int> intHash;
    int key = 43;
    cout << intHash(43) << endl;
    

    //Create custom hash
    std::unordered_map<Employee, int, EmployeeHash> uoEmployeeList;
    Employee jhon{1,"Jhon",23};
    Employee robert{ 2,"Robert",32 };
    Employee kevin{ 3,"Kevin",25 };

    uoEmployeeList[jhon] = 1;
    uoEmployeeList[robert] = 1;
    uoEmployeeList[kevin] = 1;



}

```
