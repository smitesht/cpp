# String class implementation in C++

### CString class Usage
```
int main()
{
    CString name("Hello");
    name.print();

    CString n1 = name;
    n1.print();

    CString n2 = "World";
    n2.print();

    n2 = name;
    n2.print();
    n2 += n1;
    n2.print();

    CString s1 = "India";

    CString s2 = s1 + n2;
    
}

```

### class declaration

```
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
```

### class implementation

```
// parameterized ctor
CString::CString(const char str[])
{
	  len = 0;
	  while (str[len] != '\0')
		  len++;

	  m_str = new char[len + 1];

	  for (int ind = 0; ind < len; ind++)
		   m_str[ind] = str[ind];

	  m_str[len] = '\0';
}

//copy ctor

CString::CString(const CString& str)
{
	// take old string length
	len = str.length();

	// create memory for the new
	m_str = new char[len + 1];

	//copy each elements
	for (int ind = 0; ind < len; ind++)
		 m_str[ind] = str[ind];

	//assign last to null
	m_str[len] = '\0';
} 

//index operators
char& CString::operator[](int index)
{
	 assert((index >= 0) && (index < len));
	 return m_str[index];
}

//index operators
char CString::operator[](int index) const
{
	 assert((index >= 0) && (index < len));
	 return m_str[index];
}

void CString::print()
{
	 if(m_str != nullptr)
		 cout << m_str << endl;
}

// return length
int CString::length() const
{
	return len;
}

//assignment operator
CString& CString::operator=(const CString& str)
{
	// check if self assignment, if yes return the same
	if (this != &str)
	{
		// delete old string
		delete[] m_str; // delete old buffer

		//create new string by allocating new memory
		len = str.length();
		m_str = new char[len + 1];

		for (int ind = 0; ind < len; ind++)
			m_str[ind] = str[ind];

		m_str[len] = '\0';
	}
	return *this;
}

// addition operator
CString& CString::operator+(const CString& str)
{
	return operator+=(str);
}

// addition operator
CString& CString::operator+=(const CString& str)
{
	// take current lebgth
	int currLen = length();

	// take right or param length
	int rightlen = str.length();

	// add both lengths
	len = currLen + rightlen;

	// create space for the both strings
	char* newstr = new char[len + 1];

	// copy both strings elements to new

	for (int ind = 0; ind < currLen; ind++)
		newstr[ind] = m_str[ind];

	for (int ind = 0; ind < rightlen; ind++)
		newstr[currLen + ind] = str[ind];

	newstr[len] = '\0';

	// reassign m_str

	delete[] m_str;
	m_str = newstr;

	return *this;
}

//dtor

CString::~CString()
{
	delete[] m_str;
}
```

