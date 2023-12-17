#include <iostream>

#include "MyVector.hpp"
#include "MyVector.cpp"

using namespace std;

int main()
{
    MyAwfulVector<int> mv1;
    cout << "mv1 v_size = "<<mv1.size()<<endl;
    cout << "mv1 mem_size = "<<mv1._getMemSize()<<endl;
    mv1.push_back(3); //1
    mv1.push_back(2); //2
    mv1.push_back(1); //3
    mv1.push_back(0); //4
    mv1.push_back(0); //5
    mv1.pop();        //4
    cout << "mv1 v_size = "<<mv1.size()<<endl;
    cout << "mv1 mem_size = "<<mv1._getMemSize()<<endl;

    return 0;
}