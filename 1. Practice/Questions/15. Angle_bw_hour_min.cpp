#include<bits/stdc++.h>

using namespace std;

int main(){
    int hour,minutes;
    cout<<"Enter time in Hour and Minutes\n";
    cin>>hour>>minutes;
    hour = hour%12;
    minutes = minutes%60;        
    double hr =((double)30*hour+(double)minutes/2);  
    double min = (double) 6*minutes;
    double res = fabs(hr-min);
    if(res>180.0)
        res = 360.0-res;
    cout<<"Angle between the hour and minutes hands are : "<<res<<endl;
}

/*
    In 12 hr , hour hands moves 360
    So x hr,   hour hands moves 360*x/12;   //So in 1hr(60min) it moves 30deg
                             => 30x

    In 60min,  min hands moves 360
    So y min,  min hands moves 360*y/60;
                             => 6y

    In 60min , hour hands moves 30 deg  
    So y min,  hour hands moves 30y/60;
                             => y/2


    So angle b/w them :  (30x+y/2) - (6y)

    If angle is greater than 180, we return the smaller angle
        hence 360-res;


*/
