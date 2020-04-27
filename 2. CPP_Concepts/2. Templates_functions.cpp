//  A template is a simple and yet very powerful tool in C++. The simple idea is to pass data type as a parameter 
//  so that we don’t need to write the same code for different data types. 
//  For example, a software company may need sort() for different data types. Rather than writing and maintaining the multiple codes, 
//  we can write one sort() and pass data type as a parameter.

//C++ adds two new keywords to support templates: ‘template’ and ‘typename’. The second keyword can always be replaced by keyword ‘class’.

//How templates work?
//Templates are expanded at compiler time. This is like macros. The difference is, compiler does type checking before template expansion. The idea is simple, source code contains only function/class, but compiled code may contain multiple copies of same function/class

// Templates are the foundation of generic programming, which involves writing code in a way that is independent of any particular type.

// ***********A template is a blueprint or formula for creating a generic class or a function. The library containers like iterators and algorithms are examples of generic programming and have been developed using template concept. **********

//There is a single definition of each container, such as vector, but we can define many different kinds of vectors for example, vector <int> or vector <string>.

#include<iostream>

using namespace std;

template <typename T>
T add(T a,T b){
    return a+b;
}


int main(){
    cout<<add<int>(43,2)<<endl;
    cout<<add<float>(4.3,2.2)<<endl;
    return 0;
}

