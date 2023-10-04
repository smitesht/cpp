// hash001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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
