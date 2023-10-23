#include "Wagon.hpp"

using namespace std;

Wagon::Wagon()
{
    this->next = nullptr;
};

Wagon::Wagon(string type, int ind) : _cargoType(type), _cargoIndex(ind), next(nullptr)
{
}

Wagon::~Wagon()
{
}

string Wagon::getCargoType()
{
    return this->_cargoType;
}

void Wagon::setCargoType(string str)
{
    this->_cargoType = str;
}

int Wagon::getCargoIndex()
{
    return this->_cargoIndex;
}

void Wagon::setCargoIndex(int in)
{
    this->_cargoIndex = in;
}