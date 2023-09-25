#include <iostream>

#include "RedSquare.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"

int main()
{
    RedSquare bigSquare;
    bigSquare.addShape( new Circle(2));
    bigSquare.addShape(new TriAngle(1,4));
    bigSquare.addShape(new Rectangle(1,4));
    std::cout<< bigSquare.calcSquare()<<std::endl;
    return 0;

}
