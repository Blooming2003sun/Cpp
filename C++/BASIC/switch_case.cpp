//topic :- switch case
//author :- Rudreswar Pal
#include<iostream>
using namespace std;
int main(void)
{
    int y;
    cin>>y;
    switch (y)
    {
    case 1:{
        int x=78;
        cout<<"inside case1";
        //cin>>x;
        cout<<x*y;}
        break;
    case 2:
        cout<<"inside case2";
        break;
    case 3:
        cout<<"inside case3";
        break;
    case 4:
        cout<<"inside case4";
        break;    
    default:
        break;
    }
    return 0;
}