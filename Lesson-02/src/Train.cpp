#include "Train.hpp"
#include <iostream>

using namespace std;

Train::Train()
{
    this->_start = nullptr;
    this->_size = 0;
}

Wagon* Train::at(int i)
{
    if (i >= this->_size) return nullptr;
    Wagon* ans = this->_start;
    while(i > 0)
    {
        if (ans->next == nullptr) return nullptr;
        ans = ans->next;
        i--;
    }
    return ans;
}

void Train::push(Wagon* pWag)
{
    pWag->next = this->_start;
    this->_start = pWag;
    this->_size++;
}

void Train::pop()
{
    if(this->_size < 1) return;
    this->_start = this->_start->next;
    this->_size--;
}

int Train::getSize()
{
    return this->_size;
}


void Train::info()
{
    cout << "train size = " << this->_size << "\n";
    Wagon* current = this->_start;
    for(int i = 0; i < this->_size; i++)
    {
        cout << "wagon # "<<i<<" :\n";
        cout << "cargo type : " << current->getCargoType() << "\n";
        cout << "cargo index : " << current->getCargoIndex() << "\n";
        current = current->next;
    }
}