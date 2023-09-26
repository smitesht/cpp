#pragma once

#include <iostream>
#include <cassert>

using namespace std;

class CString
{
private:
	char* m_str;
	int len;
public:
	// default ctor
	CString() :m_str(nullptr){}

	//parameterized ctor
	CString(const char str[]);

	//copy ctor
	CString(const CString& str);

	//index operators
	char& operator[](int index);
	char operator[](int index) const;

	//assignment operator
	CString& operator=(const CString& str);

	//addition operator
	CString& operator+(const CString& str);
	
	CString& operator+=(const CString& str);

	void print();
	int length() const;

	//dtor
	~CString();
};

