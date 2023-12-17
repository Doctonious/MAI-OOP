#include <iostream>
#include "shared_ptr.hpp"

using namespace std;

int main()
{
    {
        int a = 3;
        Shared_Ptr<int> ptr1(&a);
        Shared_Ptr<int> ptr2 = ptr1;
        Shared_Ptr<int> ptr3 = ptr2;
        cout << "Program start" << endl;
        cout << "sharedCounter: " << ptr1.count().sharedCounter << endl;
        ptr3.reset();
        cout << "sharedCounter: " << ptr1.count().sharedCounter << endl;
        ptr2.reset();
        cout << "sharedCounter: " << ptr1.count().sharedCounter << endl;
    }

    return 0;
}