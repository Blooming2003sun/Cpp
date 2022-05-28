#include<iostream>
using std::cout;
using std::cin;
int main(void)
{
    int num;
    char chr;
    float flt;
    //taking a integer as input
    cout<<"enter a integer \n";
    cin>>num;
    //taking a charecter as input
    cout<<"enter a charecter \n";
    cin>>chr;
    //taking a float as input
    cout<<"enter a floating point number \n";
    cin>>flt;

    //printing the entered value 
    cout<<"you entered : "<<num<<"\t"<<chr<<"\t"<<flt;

    return 0;
}
