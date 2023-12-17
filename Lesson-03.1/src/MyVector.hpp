#ifndef god_awful_vector_parody
#define god_awful_vector_parody

/*
Задание 1
• Реализовать шаблонный контейнер класс vector поддерживающий следующие методы:
• Конструктор по умолчанию, создает вектор нулевого размера;                        - X
• Конструктор, создающий вектор заданного размера;                                  - X
• Оператор индексирования, возвращающий ссылку на соответствующий элемент вектора   - X
• Метод, добавляющий элемент в произвольную позицию вектора;                        - X
• Метода, добавляющий элемент в конец вектора;                                      - X
• Метод, удаляющий элемент из конца вектора.                                        - X
*/

#include <cstddef> // for size_t

template <typename T>
class MyAwfulVector
{
    public:
    MyAwfulVector();
    MyAwfulVector(size_t vecSize);
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



#endif //god_awful_vector_parody
