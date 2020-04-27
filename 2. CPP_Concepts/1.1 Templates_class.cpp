
#include<iostream>

//tempalate <class T>

using namespace std;

template <class T>          //Template class T
class something{
    public:                 //public type
        T a[2];           //Global variable of type T
        T add();          //Function declared of return type T
        something();        //Constructor declared
};

template <class T>          //Before every function initialization we have to write this
something<T>::something(){ //Constructor intialized
    cout<<"Enter two numbers"<<endl;
    cin>>a[0]>>a[1];
}

template <class T>
T something<T>::add(){   //add function of class something returns int type
    return a[0]+a[1];
}


int main(){
    something<float> example;      //Creating object of class of type float
    cout<<example.add()<<endl;    //Calling function for the object example
    return 1;
}


