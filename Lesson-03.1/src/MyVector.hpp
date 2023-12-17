#ifndef vector
#define vector
#include <cstddef>

using namespace std;

template <typename T>
class MyVector
{
    public:
    MyVector();
    MyVector(size_t vecSize);
    T& operator[](size_t index);
    bool insert(size_t index);
    bool push_back(T val);
    bool pop();

    size_t size();
    size_t _getMemSize();
    bool _memClean();

    private:
    T* dataPointer;
    size_t v_size;
    size_t mem_size;
};



#endif
