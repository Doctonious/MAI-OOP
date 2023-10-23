#include <iostream>

using namespace std;

class My_Shared_ptr{
    private:
        int* _data;
        unsigned int* _count = 0;

        void predestruct(){//оптимизировать
            cout << "predestruct start..." << endl;
            (*_count)--;                                    //Уменьшаем счетчик на 1
           /*
            if(_count == 0)                                 //Если счетчик равен 0, удаляем данные и счетчик
            {
                cout << _count << " Memory dealocated\n";
                delete _data;
                delete _count;
            }*/
        };

    public:
    My_Shared_ptr(int* data){ //Конструктор класса. Передается значение типа int

        _data = data;                                       //Инициализация поля _data класса My_shared_ptr
        _count = new unsigned int(1);                       //Инициализация поля _count класса My_shared_ptr. 
                                                            //Создание объекта со значением 1
    }
    My_Shared_ptr(My_Shared_ptr& r){                        //Конструктор копирования. Передает ссылку на предыдущий объект
        this->_data = r._data;                              //Передаем значение предыдущего объекта
        this->_count = r._count;                            //Передаем счетчик ссылок предыдущего объекта
        (*_count)++;                                        //Увеличиваем на 1, т.к. мы создали новый объект

    }
    ~My_Shared_ptr(){                                       //Деструктор    
        if(*_count > 0)                                  
            cout << "Count: " << this->use_count() << endl; //Выводим значение счетчика, если он больше нуля  
        predestruct();                                      //Вызов метода predestruct()
        
        if(*_count == 0)                                    //Если счетчик равен 0, удаляем данные и счетчик
            {
                cout << "Count: " << 0 << endl;             //Выводим счетчик, если он равен нулю
                cout << *_count << " Memory dealocated\n";
                delete _data;
                delete _count;
            }
            
       // _count--;

    }

    int& operator*(){ 
        //cout << "operator*: " << *_data << endl;            
        return *_data;                                      //Возвращаем значение объекта
    }
    int* operator->(){              
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

    void swap(My_Shared_ptr& r){                                //Метод меняет значения местами
        
        int* someValue = 0;
        someValue = r._data;
        r._data = this->_data;
        this->_data = someValue;

        this->_count = r._count;
        delete someValue;
        cout << "----------Swap test:----------" << endl;
        cout << "p1 = " << *r._data << endl;
        cout << "p4 = " << *_data << endl << endl;
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
    My_Shared_ptr p4(new int(4));

    //p4 = move(p1);
    p4.swap(p1);
    cout << "----------check_ptr start:----------" << endl;
    //cout << "p1-count: " << p1.use_count() << endl;
    //cout << "p2-count: " << p2.use_count() << endl;
    //cout << "p3-count: " << p3.use_count() << endl;
    //cout << "p4-count: " << p4.use_count() << endl;
    //cout << "Data: " << *p1 << endl;
    cout << "Data: " << *p2 << endl;
    //cout << "Data: "<< *p4 << endl;
}

int main(){
    cout<< "HELLO! I AM HERE\n";
    check_ptr();
    return 0;
}
