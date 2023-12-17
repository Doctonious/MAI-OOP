#include <iostream>
#include <string>

#include "MyComplex.hpp"

using namespace std; //CAN'T STOP ME NOW

int main(int, char**){

    cout << "hello from lesson_03" << endl;

    MyComplex A, B, C, D;

    A = MyComplex(3.5, 15.);
    B = MyComplex(A);

    C = A - B;
    D = A * B;
    B = A + B;

    cout << "A = " << A.pretty() << endl;
    cout << "B = " << B.pretty() << endl;
    cout << "C = " << C.pretty() << endl;
    cout << "D = " << D.pretty() << endl;

    return 0;
}
