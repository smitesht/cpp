# std::hash in C++

### Hash Function in C++

In C++, a hash function is a function that takes an input or key and returns a fixed-sized integer value, called hash code.
Hash functions are used in data structures to quickly map keys to corresponding values. 
The goal is to distribute the key uniformly across a range of hash codes, minimizing collisions (cases where different keys map to the same hash code).

### std::hash in C++

**In C++ STL, std:: hash is a template class that provides a generic interface for creating hash functions for various data types.**
It is commonly used for hashing keys in associative containers such as unordered_set and unordered_map.
