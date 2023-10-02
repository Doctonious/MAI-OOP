#include <iostream>

using namespace std;
/*
template <typename Type> Type sum (Type a, Type b){
    return a + b;
}

template <typename Type> Type difference (Type a, Type b){
    return a - b;
}

template <typename Type> Type multiply (Type a, Type b){
    return a * b;
}

template <typename Type> Type division (Type a, Type b){
    return a / b;
}

*/
int sum (int a, int b){
    return a + b;
}

double sum (double a, double b){
    return a + b;
}

char sum (char a, char b){
    return a + b;
}

int difference (int a, int b){
    return a - b;
}

double difference (double a, double b){
    return a - b;
}

char difference (char a, char b){
    return a - b;
}

int multiply (int a, int b){
    return a * b;
}

double multiply (double a, double b){
    return a * b;
}

char multiply (char a, char b){
    return a * b;
}

int division (int a, int b){
    return a / b;
}

double division (double a, double b){
    return a / b;
}

char division (char a, char b){
    return a / b;
}

int main()
{
    cout << "Program started..." << endl;

    int num1 = 2, num2 = 2;
    //char num1 = '1', num2 = '2';
    //double num1 = 123.1, num2 = 22.67;
/*
    cout << "Template test:" << endl;
    cout << "sum: " << sum(num1, num2) << endl;
    cout << "difference: " << difference(num1,num2) << endl;
    cout << "multiply: " << multiply(num1,num2) << endl;
    cout << "division: " << division(num1,num2) << endl;
*/
    cout << "Overload test:" << endl;
    cout << "sum: " << sum(num1, num2) << endl;
    cout << "difference: " << difference(num1,num2) << endl;
    cout << "multiply: " << multiply(num1,num2) << endl;
    cout << "division: " << division(num1,num2) << endl;


    return 0;
}




