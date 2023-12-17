#include <iostream>
#include <string>

#include "MyComplex.hpp"

using namespace std;

int main(int, char**){

    cout << "Program start" << endl;

    MyComplex a, b, c, d;

    a = MyComplex(4.1, 15.);
    b = MyComplex(a);

    c = a - b;
    d = a * b;
    b = a + b;

    cout << "a = " << a.pretty() << endl;
    cout << "b = " << b.pretty() << endl;
    cout << "c = " << c.pretty() << endl;
    cout << "d = " << d.pretty() << endl;

    return 0;
}
