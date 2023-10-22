#include <iostream>

using namespace std;

class My_Shared_ptr{
    private:
        int* _data;
        unsigned int* _count = 0;
        void predestruct(){//оптимизировать
        (*_count)--;
        if(_count == 0)
        {
            cout <<*_count<< "Memory dealocated\n";
            delete _data;
            delete _count;
        }
        };

    public:
    My_Shared_ptr(int* data){

        _data = data;
        _count = new unsigned int(1);
    }
    My_Shared_ptr(My_Shared_ptr& r){
        this->_data = r._data;
        this->_count = r._count;
        (*_count)++;

    }
    ~My_Shared_ptr(){
        cout << "Count: " <<this->use_count() << endl;
        predestruct();
       // _count--;

    }

    int& operator* (){
        return *_data;
    }
    int* operator-> (){
        return _data;
    }
    
    My_Shared_ptr& operator=(const My_Shared_ptr& r) noexcept
    {
        predestruct();
        this->_data = r._data;
        this->_count = r._count;
        (*_count)++;

        return *this;
    }
    My_Shared_ptr& operator=(My_Shared_ptr&& r) noexcept
    {
        predestruct();
        this->_data = move(r._data);
        this->_count = move(r._count);
        r._data = nullptr;
        r._count = nullptr;
        return *this;
    }

    void swap (My_Shared_ptr& r ){

    }

    unsigned int use_count() const
    {
        return *_count;
    }
};

void check_ptr(){
    My_Shared_ptr p1(new int(1));
    My_Shared_ptr p2(p1);
    My_Shared_ptr p3(p2);
    My_Shared_ptr p4(new int(253));

    //p4 = move(p1);
 
    //cout << "p1-count: " << p1.use_count() << endl;
    //cout << "p2-count: " << p2.use_count() << endl;
    //cout << "p3-count: " << p3.use_count() << endl;
    //cout << "p4-count: " << p4.use_count() << endl;
    //cout << "Data: " << *p1 << endl;
    //cout << "Data: " << *p2 << endl;
    cout << "Data: "<< *p4 << endl;
}

int main(){
    cout<< "HELLO! I AM HERE\n";
    check_ptr();
    return 0;
}
