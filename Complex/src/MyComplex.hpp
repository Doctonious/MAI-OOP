#ifndef COMPLEXGUARD
#define COMPLEXGUARD
#include <string>

using namespace std;

typedef double mytype;


class MyComplex
{
public:
    MyComplex();
    MyComplex(mytype r, mytype i);
    MyComplex(const MyComplex& other_obj);
    mytype real() const;
    mytype imag() const;
    void setReal(mytype);
    void setImag(mytype);
    MyComplex operator+(const MyComplex& other_obj) const;
    MyComplex operator-(const MyComplex& other_obj) const;
    MyComplex operator*(const MyComplex& other_obj) const;
    string pretty();

private:
    mytype value;
    mytype i_value;
};

#endif