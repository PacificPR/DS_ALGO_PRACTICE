
#include<iostream>

//tempalate <class T>

using namespace std;
class something{
    public:                 //public type
        int a[2];           //Global variable declared
        int add();          //Function declared
        something();        //Constructor declared
};

something::something(){ //Constructor intialized
    cout<<"Enter two numbers"<<endl;
    cin>>a[0]>>a[1];
}

int something::add(){   //add function of class something returns int type
    return a[0]+a[1];
}


int main(){
    something example;      //Creating object of class
    cout<<example.add();    //Calling function for the object example
    return 1;
}


