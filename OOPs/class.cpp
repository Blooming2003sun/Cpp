//topic :- claas
//author :- Rudreswar Pal
#include<iostream>
using namespace std;
class Complex
{
private:
    int real,comp;
public:
    void setData(int a,int b){
        real=a,comp=b;
    }
    void display(){
        cout<<real<<" + i "<<comp;
    }   
};

int main(void)
{
    Complex c1;
    c1.setData(15,012);
    c1.display();
    return 0;
}