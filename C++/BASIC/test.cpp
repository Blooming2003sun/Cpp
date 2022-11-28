//topic :- 
//author :- Rudreswar Pal
#include<iostream>
using namespace std;
int main(void)
{
    int x,y=2,z;
    x=10,y=20;
    z=x-- - x++ + --y - ++y + --x - y--+ ++x - y++;
    cout<<z<<endl<<x;
    return 0;
}