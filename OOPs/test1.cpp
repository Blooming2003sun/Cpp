//topic :- 
//author :- Rudreswar Pal
#include<iostream>
using namespace std;
const int size =3;
int x[size]={5,6,7};
int y[size]={10,11,12};
class vector{
    int a[size];
public:
    vector(){}
    vector(int *x)
    {
        for (int i = 0; i < size; i++)
        {
            a[i]=x[i];
        }
        
    }
    friend vector operator*(vector &x,int b){
        vector c;
        for (int  i = 0; i < size; i++)
        {
            c.a[i]=x.a[i]*b;
        }
        return c;
    }
    friend vector operator*(int b,vector&x){
        vector c;
        for (int  i = 0; i < size; i++)
        {
            c.a[i]=x.a[i]*b;
        }
        return c;
    }
    friend vector operator<<(ostream &a,const vector v){
        for (int i = 0; i < size; i++)
        {
            a<<v.a[i]<<" ";
        }
        cout<<endl;
        
    }
    vector operator=(const vector &v){
        for (int i = 0; i < size; i++)
        {
            this->a[i]=v.a[i];
        }
        
    }

};
int main(void)
{
    cout<<"hello\n";
    vector m=x;
    vector n=y;
    cout<<m;
    cout<<n;
    vector p;
    p=m*2;
   
    vector q;
    q=3*n;


    cout<<p;
    cout<<q;
    return 0;
}
