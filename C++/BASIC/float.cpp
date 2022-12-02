//topic :- float data type      
//author :- Rudreswar Pal
#include<iostream>
#include<iomanip>
#include<limits>
using namespace std;
int main(void)
{
    float f =12.55757465468f;//4byte 7 digit precision
    double d = 12345.68584585875584556546565;//8byte 15 digit precission
    long double ld = 123466.795694365495648568L;//12 byte 18 digit precission
    //cout precision 6 digit
    cout<<setprecision(8);
    cout<<f<<endl;
    cout<<setprecision(18);
    cout<<d<<endl;
    cout<<setprecision(20);
    cout<<ld<<endl;
    cout<<numeric_limits<float>::digits10;
  
    return 0;
}