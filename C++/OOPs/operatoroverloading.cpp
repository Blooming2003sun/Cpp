// topic :- operator overloading
// author :- Rudreswar Pal
#include <iostream>
using namespace std;
class complex
{
    int x, y;

public:
    complex()
    {
    }
    complex(int m, int n)
    {
        x = m;
        y = n;
    }
    friend istream &operator>>(istream &, complex &);
    friend ostream &operator<<(ostream &, const complex&);
};
istream & operator>>(istream & in, complex & m)
{
    int p= m.x;
    cout << "enter x : ";
    in >> m.x ;
    cout << "enter y : ";
    in >> m.y ;
    return in ;
}
ostream & operator<<(ostream & out, const complex & m){
    out << m.x;
    out << "+ i" << m.y << endl;
    return out;
}

int main(void)
{
    complex y(6, 7), z;
    cout << y;
    cin>>z;
    cout << z;
    return 0;
}