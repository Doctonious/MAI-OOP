/*
Сделать систему, которая решает такую задачу:
Реализованы квадратичная (с квадратичной сложностью, например, пузырьковая) и быстрая (с н лог по н временем выполнения) сортировки, должна выводиться сравнительная таблица: два вектора на 1000000 template-овых (для инта и дабла) элементов и 10 циклов проверки времени сортировки
В таблице три строки: сортировка первая, вторая, третья - из стандартной библиотеки algorithm(кажется?) найти худшее, среднее и лучшее время сортировки
Воспользоваться знаниями по умным указателем, чтобы не плодить копии, генератор случайных массивов для инта и дабла.
*/

/*
P.S. по прикидке на моей машине bubble sort на 1'000'000 эллементов займёт ~2.7 часа
для 10 тестов на 2 типа данных - это 54 часа тестов.
Я не готов потратить на это столько времени, поэтому для теста bubble sort'a я буду брать меньшее число эллементов
*/

#include <iostream>
#include <vector>
#include "bubble.hpp"
#include <chrono>
#include <cstdlib>
#include <iterator>

using namespace std;

template<typename T>
unsigned long long durationFastSort(T &base_vec)
{
    auto copy = base_vec;
    auto start = chrono::high_resolution_clock::now();
    fastSort(copy);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    return duration.count();
}

template<typename T>
unsigned long long durationBubbleSort(T &base_vec) // ms
{
    auto copy = base_vec;
    auto start = chrono::high_resolution_clock::now();
    bubbleSort(copy);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    return duration.count();
}

void display_vector(const vector<double> &v)
{
    std::copy(v.begin(), v.end(),
        std::ostream_iterator<double>(std::cout, " "));
}

int main()
{

    vector<int> base_int_vec = {};
    for(size_t i; i < 1000000; i++){
        base_int_vec.push_back(rand());
    }
    vector<double> base_double_vec = {};
    for(size_t i; i < 1000000; i++){
        base_double_vec.push_back(rand());
    }

    std::cout <<"\n\tvec<int>[1'000'000] fast sort test :\n\n";
    std::cout <<"ind\t|\tduration\n";
    int shortest = -1;
    int longest = -1;
    double mean = 0.;
    int duration;
    for(int i = 0; i < 10; i++){
        duration = durationFastSort(base_int_vec);
        cout <<i+1<<"\t|\t" << duration <<"ms\n";
        if(shortest < 0) shortest = duration;
        if(longest < 0) longest = duration;
        if(longest < duration) longest = duration;
        if(shortest > duration) shortest = duration;
        mean += duration;
    }
    mean /= 10.;

    cout <<"\n";
    cout << "shortest : " << shortest << endl;
    cout << "longest : " << longest << endl;
    cout << "mean : " << mean << endl;

    cout <<"______________________________________________________"<<endl;


    std::cout <<"\n\tvec<double>[1'000'000] fast sort test :\n\n";
    std::cout <<"ind\t|\tduration\n";
    shortest = -1;
    longest = -1;
    mean = 0.;

    for(int i = 0; i < 10; i++){
        duration = durationFastSort(base_double_vec);
        cout <<i+1<<"\t|\t" << duration <<"ms\n";
        if(shortest < 0) shortest = duration;
        if(longest < 0) longest = duration;
        if(longest < duration) longest = duration;
        if(shortest > duration) shortest = duration;
        mean += duration;
    }
    mean /= 10.;

    cout <<"\n";
    cout << "shortest : " << shortest << endl;
    cout << "longest : " << longest << endl;
    cout << "mean : " << mean << endl;


    cout <<"______________________________________________________"<<endl;

    vector<int> base_int_vec_bub = {};
    for(size_t i; i < 10000; i++){
        base_int_vec_bub.push_back(rand());
    }
    vector<double> base_double_vec_bub = {};
    for(size_t i; i < 10000; i++){
        base_double_vec_bub.push_back(rand());
    }

    std::cout <<"\n\tvec<int>[10'000] bubble sort test :\n\n";
    std::cout <<"ind\t|\tduration\n";
    shortest = -1;
    longest = -1;
    mean = 0.;

    for(int i = 0; i < 10; i++){
        duration = durationBubbleSort(base_int_vec_bub);
        cout <<i+1<<"\t|\t" << duration <<"ms\n";
        if(shortest < 0) shortest = duration;
        if(longest < 0) longest = duration;
        if(longest < duration) longest = duration;
        if(shortest > duration) shortest = duration;
        mean += duration;
    }
    mean /= 10.;

    cout <<"\n";
    cout << "shortest : " << shortest << endl;
    cout << "longest : " << longest << endl;
    cout << "mean : " << mean << endl;

    cout <<"______________________________________________________"<<endl;

    std::cout <<"\n\tvec<double>[10'000] bubble sort test :\n\n";
    std::cout <<"ind\t|\tduration\n";
    shortest = -1;
    longest = -1;
    mean = 0.;

    for(int i = 0; i < 10; i++){
        duration = durationBubbleSort(base_double_vec_bub);
        cout <<i+1<<"\t|\t" << duration <<"ms\n";
        if(shortest < 0) shortest = duration;
        if(longest < 0) longest = duration;
        if(longest < duration) longest = duration;
        if(shortest > duration) shortest = duration;
        mean += duration;
    }
    mean /= 10.;

    cout <<"\n";
    cout << "shortest : " << shortest << endl;
    cout << "longest : " << longest << endl;
    cout << "mean : " << mean << endl;



    return 0;
}