#include<iostream>
#include<Fraction.h>
using namespace std;
int main()
{
    Fraction a,b,c;
    
    a.AddFra(2,3);
    b.AddFra(1,3);
    c = a + b;
    c.simplify();
    cout<<c.getnumer()<<"/"<<c.getdeno();
    return 0;
}