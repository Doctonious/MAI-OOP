#include "MyVector.hpp"

#define MACRO_MYAWFULVECTOR_TYPE 1
/*
*
*   MyAwfulVector types - descrybes vector memory logic
*   type 0 - allocated just enough memory (memory allocation on every insert/push_back)
*   type 1 - allocate memory in power of 2 (if v_size == mem_size -> allocate(mem_size * 2))
*/

template< class T> MyAwfulVector<T>::MyAwfulVector( void )
{
    this->dataPointer = nullptr;
    this->v_size = 0;
    this->mem_size = 0;
};


template< class T> MyAwfulVector<T>::MyAwfulVector(size_t vecSize)
{
    this->dataPointer = new T(vecSize);
    this->v_size = vecSize;
    this->mem_size = 0;
}

template< class T> T& MyAwfulVector<T>::operator[](size_t index)
{
    return this->dataPointer[index];
}

template< class T> bool MyAwfulVector<T>::insert(size_t index)
{
    if (index > this->v_size) return false; //fuck this



    #if MACRO_MYAWFULVECTOR_TYPE == 0
// 0 1 2 3 _
// 0 1 _ 2 3
        T* ndataPointer;
        if (v_size == mem_size)
        {
            ndataPointer = new T(v_size + 1);
            mem_size++;
        }else{
            ndataPointer = this->dataPointer;
        }

        size_t ii = 0;
        for(size_t i = 0; i < v_size + 1; i++)
        {
            if(i != index)
            {
                ndataPointer[i] = dataPointer[ii];
            }else{
                ii--;
            }
            ii++;
        }

        v_size++;

        if(dataPointer != ndataPointer)
        {
        delete this->dataPointer;
        this->dataPointer = ndataPointer;
        }

    #elif MACRO_MYAWFULVECTOR_TYPE == 1
        // 0 1 2 3 _
        // 0 1 _ 2 3
        if (index < this->mem_size)
        {
            for(size_t i = v_size-1; i > index; i--)
            {
                dataPointer[i] = dataPointer[i-1];
            }
        }else{
            mem_size *= 2;
            if (mem_size == 0) mem_size = 1;
            T* ndataPointer = new T(mem_size);
            size_t ii = 0;
            for(size_t i = 0; i < v_size + 1; i++)
            {
                if(i != index)
                {
                    ndataPointer[i] = dataPointer[ii];
                }else{
                    ii--;
                }
                ii++;
            }
            delete this->dataPointer;
            this->dataPointer = ndataPointer;
        }
        this->v_size++;

    #endif

    return true;
}

template< class T> bool MyAwfulVector<T>::push_back(T val) //heh
{
    bool ans =  this->insert(this->v_size);
    if(ans) this->dataPointer[this->v_size-1] = val;
    return ans;
}

template< class T> bool MyAwfulVector<T>::pop() //got lazy
{
    this->v_size--;
    return true;
}

template< class T> size_t MyAwfulVector<T>::size()
{
    return this->v_size;
}

template< class T> size_t MyAwfulVector<T>::_getMemSize()
{
    return this->mem_size;
}

template< class T> bool MyAwfulVector<T>::_memClean() //mem_pop
{
    if(v_size == mem_size) return false;
    T* ndataPointer = new T(v_size);
    for(size_t i = 0; i < v_size; i++)
    {
        ndataPointer[i] = dataPointer[i];
    }
    delete dataPointer;
    dataPointer = ndataPointer;
    return true;
}

