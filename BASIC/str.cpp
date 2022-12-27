//topic :- string manipulation
//author :- Rudreswar Pal
#include<iostream>
#include<cstring>
#include<stdlib.h>
using namespace std;
int main(void)
{
    char s[10];
    char p[10];
    gets(s);
    gets(p);
    cout<<strlen(s)<<endl;
    cout<<strlen(p)<<endl;

    cout<<s;
    cout<<p;

    return 0;
}