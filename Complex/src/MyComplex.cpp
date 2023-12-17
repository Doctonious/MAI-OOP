#include "MyComplex.hpp"

/*class MyComplex
{
public:

    MyComplex(); //default constructor
    MyComplex(mytype r, mytype i);
    MyComplex(const MyComplex& other_obj); //copy constructor
    //MyComplex& operator=(const MyComplex& other_obj); //copy assignment

    MyComplex operator+(const MyComplex& other_obj) const;
    MyComplex operator-(const MyComplex& other_obj) const;
    MyComplex operator*(const MyComplex& other_obj) const;
    mytype real() const;
    mytype imag() const;
    void setReal(mytype);
    void setImag(mytype);

    std::string pretty(); //string serialize

private:
    mytype value;
    mytype i_value; //imajinary value
};*/

MyComplex::MyComplex()
{
}

MyComplex::MyComplex(mytype r, mytype i) : value(r), i_value(i)
{
}

MyComplex::MyComplex(const MyComplex& other_obj) : value(other_obj.real()), i_value(other_obj.imag())
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

std::string MyComplex::pretty()
{
    std::string real, imag;
    real = std::to_string(this->value);
    real.erase ( real.find_last_not_of('0') + 1, std::string::npos );
    real.erase ( real.find_last_not_of('.') + 1, std::string::npos );
    imag = std::to_string(this->i_value);
    imag.erase ( imag.find_last_not_of('0') + 1, std::string::npos );
    imag.erase ( imag.find_last_not_of('.') + 1, std::string::npos );
    return real + " + " + imag + "i";
}