#include "MyComplex.hpp"


MyComplex::MyComplex()
{
}

MyComplex::MyComplex(mytype r, mytype i):value(r), i_value(i)
{
}

MyComplex::MyComplex(const MyComplex& other_obj):value(other_obj.real()), i_value(other_obj.imag())
{
}

mytype MyComplex::real() const
{
    return this->value;
}

mytype MyComplex::imag() const
{
    return this->i_value;
}

void MyComplex::setReal(mytype val)
{
    this->value = val;
}

void MyComplex::setImag(mytype i_val)
{
    this->i_value = i_val;
}

MyComplex MyComplex::operator+(const MyComplex& other_obj) const
{
    mytype real, imag;
    real = this->value + other_obj.real();
    imag = this->i_value + other_obj.imag();
    return MyComplex(real, imag);
}

MyComplex MyComplex::operator-(const MyComplex& other_obj) const
{
    mytype real, imag;
    real = this->value - other_obj.real();
    imag = this->i_value - other_obj.imag();
    return MyComplex(real, imag);
}

MyComplex MyComplex::operator*(const MyComplex& other_obj) const
{
    mytype real, imag;
    real = this->value * other_obj.real() - this->i_value * other_obj.imag();
    imag = this->value * other_obj.imag() + this->i_value * other_obj.real();
    return MyComplex(real, imag);
}

string MyComplex::pretty()
{
    string real, imag;
    real = to_string(this->value);
    real.erase (real.find_last_not_of('0') + 1, string::npos);
    real.erase (real.find_last_not_of('.') + 1, string::npos);
    imag = to_string(this->i_value);
    imag.erase (imag.find_last_not_of('0') + 1, string::npos);
    imag.erase (imag.find_last_not_of('.') + 1, string::npos);
    return real + " + " + imag + "i";
}