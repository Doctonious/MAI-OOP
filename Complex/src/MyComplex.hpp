#ifndef COMPLEXGUARD
#define COMPLEXGUARD

#include <string>

typedef double mytype;

/*
Вот к нам с 12 ударом часов,
В санях запряженных милионами писцов.
С мешком дефектов и эпичнейших люлей,
Летит самый страшный персонаж на земле.

Эй дизайнер, прогер и дажы ты, с master.com,
Тебе этот герой обязательно знаком!
Он еще в пути, но он прибудет на рассвете,
Давайте же все вместе позовем его дети!

Припев:
Дедлайн, Дедлайн, Дедлайн А! опять!
Дедлайн, Дедлайн, Дедлайн А! опять!
Дедлайн, Дедлайн, Дедлайн А! опять!
Дедлайн, Дедлайн, Дедлайн А! опять!

Менеджер проекта издает протяжный вой,
Ему перед заказчиком в коленно-локтевой.
Приводит к продакшене небольшая неточность,
К разработке и тестированию с интер на прочность.

Кто это кричит как на пожаре инвалид?
Ты что не узнал? Это же наш тимлит!
Он не хочет завтра торговать на рынке,
Качаются под воплем админские ботинки.

Припев.

Утро. Палата. Вторая больница...
В палате одни только знакомые лица...
Почки, давление, серца порок,
Пульс нитевидный, но мы сдали в срок!

(с) НТР
*/

class MyComplex
{
public:

    MyComplex(); //default constructor
    MyComplex(mytype r, mytype i);
    MyComplex(const MyComplex& other_obj); //copy constructor
    //MyComplex& operator=(const MyComplex& other_obj); //copy assignment

    mytype real() const;
    mytype imag() const;
    void setReal(mytype);
    void setImag(mytype);

    MyComplex operator+(const MyComplex& other_obj) const;
    MyComplex operator-(const MyComplex& other_obj) const;
    MyComplex operator*(const MyComplex& other_obj) const;

    std::string pretty(); //string serialize

private:
    mytype value;
    mytype i_value; //imajinary value
};

#endif //COMPLEXGUARD