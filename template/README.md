# Template in C++

### What is template in C++

By using templates, we can design a single class or function that operates on data of many types of datatypes instead of having to create a separate class or function for each type.

When used with functions they are known as function templates, whereas when used wuth classes they are called as class templates.

# Function template

Function template are used to create generic function that work on different types of datatype along with user defined datatype. Instead of creating different function for each datatype, function template helps to prevent repetitive work and just create a single function template that work on all the types of datatypes.

Function template reuse the source code.

example of function template

```
template <class T>
T myMin(T a, T b)
{
    return (a < b) ? a : b;
}

int main()
{
    int i = 10, j = 20;
    cout << myMin(i, j) << endl;

    float n1 = 5.4f, n2 = 3.5f;
    cout << myMin(n1, n2) << endl;
}
```

### What happens at compile time?

During compile time, compiler just remember the function template for the future use and do not perform any action. The compiler cannot generate any code because it doesnot know yet what datatype the function will be working with. The code generation takes place when the function is actually called from within the program.

For example, myMin(i,j);

When the compiler sees such a function call, it knows the actual datatype and generate a specific version of the myMin() for that datatype by replacing every T with actual datatype. This process is called the instantiating the function template.

Compiler create only one version of function template for each datatype irrespective of the number of calls that have been made for that type.

### Multiple types of arguments

We can write a function template that takes multiple types of arguments during one call.

```
// function template with multiple types of arguments

template<class T, class J, class K>
void fun(T n1, J n2, K n3)
{
    cout << n1 << n2 << n3 << endl;
}

int main()
{
    int i = 10, j = 20;
    float n1 = 5.4f, n2 = 3.5f;

    // function template with multiple arguments
    string str = "Ramesh";
    fun(i, j, str);
    fun(str, i, j);
}

```

### Template vs Macro

- The macro is expanded without any type checking, means it does not do any datatype cheking, while template checks
- The macro evaluate parameters twice.

### Class Template

Class templates are used to create generic class that support different dataypes instead of creating separate class of each datatype.

for example, List, Stack, Queue classes can be created using template classes.

When compiler see the class template, it do not generate any code but it remember the place. When it sees the actual object creation with the supplied datatype whether built-in or user defined datatype, it generate the single version of code for that datatpe, and create instance of that version of the class.

```
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
    // class template

    MyClass<int> c1, c2(20, 30);
    c2.printVal();
}
```
