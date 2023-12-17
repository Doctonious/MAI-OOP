#include <iostream>

#include "MyVector.hpp"
#include "MyVector.cpp"

using namespace std;

int main()
{
    MyVector<int> Mvector;
    cout << "mv1 v_size = " << Mvector.size() << endl;
    cout << "mv1 mem_size = " << Mvector._getMemSize() << endl;
    Mvector.push_back(3); 
    Mvector.push_back(2); 
    Mvector.push_back(1); 
    Mvector.push_back(0); 
    Mvector.push_back(0); 
    Mvector.pop();        
    cout << "mv1 v_size = " << Mvector.size() << endl;
    cout << "mv1 mem_size = " << Mvector._getMemSize() << endl;

    return 0;
}