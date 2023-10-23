#include <iostream>
#include <string>
#include "Train.hpp"
#include "Wagon.hpp"
#include "TrainMaker.hpp"

using namespace std; 

int main(int, char**){

    cout << "Hello, from lesson_02!\n";

    Train tr;

    ConsoleTrain cTrain;

    cTrain.setupWithTypes(vector<string>{"wood","coal"});

    tr = cTrain.getTrain();

    tr.info();

    FileTrain fTrain;

    fTrain.setup("trainData.txt");

    tr = fTrain.getTrain();

    tr.info();

    int sz = tr.getSize();

    Train tr1, tr2;
    Wagon* cur;
    for(int i = 0; i < sz; i++)
    {

        cur = tr.at(0);
        tr.pop();
        if(cur->getCargoType() == "coal")
        {
            tr1.push(cur);
        }else{
            tr2.push(cur);
        }

    }

    cout << "\ntr1.size = " << tr1.getSize() << endl;
    tr1.info();
    cout << "tr2.size = " << tr2.getSize() << endl;
    tr2.info();



    return 0;
}
