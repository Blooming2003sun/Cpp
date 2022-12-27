// topic :- template making
// author :- Rudreswar Pal
#include <iostream>
using namespace std;
template <class t>
class Arithmatic
{
private:
    t a;
    t b;

public:
    Arithmatic() {}
    Arithmatic(t a, t b);
    t add();
    t sub();
    ~Arithmatic();
};
template <class t>
Arithmatic<t>::Arithmatic(t a, t b)
{
    this->a = a;
    this->b = b;
}
template <class t>
t Arithmatic<t>::add(void)
{
    t c = a + b;
    cout << c << endl;
    return c;
}
template <class t>
t Arithmatic<t>::sub(void)
{
    t c = a - b;
    cout << c << endl;
    return c;
}
template <class t>
Arithmatic<t>::~Arithmatic()
{
    cout << "destructed" << endl;
}
int main(void)
{
    Arithmatic<int> x(4, 3);
    {
        Arithmatic<float> y(4.52f, 3.7f);
        y.add();
    }
    x.sub();
    return 0;
}