#include "TrainMaker.hpp"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

ConsoleTrain::ConsoleTrain()
{
}

ConsoleTrain::~ConsoleTrain()
{
    this->erase();
}

void ConsoleTrain::setup()
{
    if(this->_train.getSize() > 0)
    {
        cout << "\t| ERROR : THIS TRAIN HAS ALREADY BEEN ASSEMBLED, DELETE IT OR USE NEW ONE";
        cout << endl;
        return;
    }

    cout << "\t|welcame to eTrain setap|\n";
    cout << "> how many \"wagons\" do you want to have ? \n < ";
    int inSize;
    cin >> inSize;
    for (int i = 0; i < inSize; i++)
    {
        string str;
        int wInd;
        Wagon* wag = new Wagon;
        this->_memStack.push(wag);
        cout << "> train # " << inSize - i <<"\n";
        cout << "> what type ?\n < ";
        cin >> str;
        wag->setCargoType(str);
        cout << "> what index ?\n < ";
        cin >> wInd;
        wag->setCargoIndex(wInd);
        this->_train.push(wag);
        cout << "___\n";
    }

    cout << "your eTrain is ready, pls put your head on railroad track and wait =)\n";
}

void ConsoleTrain::setupWithTypes(vector<string> types)
{
    if(this->_train.getSize() > 0)
    {
        cout << "\t| ERROR : THIS TRAIN HAS ALREADY BEEN ASSEMBLED, DELETE IT OR USE NEW ONE";
        cout << std::endl;
        return;
    }

    cout << "\t|welcame to eTrain setap|\n";
    cout << "> how many \"wagons\" do you want to have ? \n < ";
    int inSize;
    cin >> inSize;
    for (int i = 0; i < inSize; i++)
    {
        int tInd;
        int wInd;
        Wagon* wag = new Wagon;
        this->_memStack.push(wag);
        cout << "> train # " << inSize - i <<"\n";
        cout << "> what type ?\n";
        cout << "> available types are : \n";

        for(int k = 0; k < types.size(); k++)
        {
            cout << ">\t["<< types[k] <<"] : "<< k <<"\n";
        }

        cout << "> type type (0, "<<types.size()-1<<")\n";

        cin >> tInd;
        wag->setCargoType(types[tInd]);

        cout << "> what index ?\n < ";
        cin >> wInd;
        wag->setCargoIndex(wInd);
        this->_train.push(wag);
        cout << "___\n";
    }
    cout << "your eTrain is ready, pls put your head on railroad track and wait =)\n";
}

Train ConsoleTrain::getTrain()
{
    return this->_train;
}

void ConsoleTrain::erase()
{
    int sz = this->_train.getSize();

    for(int i = 0; i < sz; i++)
    {
        this->_train.pop();
    }

    while(this->_memStack.size() > 0)
    {
        Wagon* p = this->_memStack.top();
        if (p != nullptr) delete p;
        this->_memStack.pop();
    }
}


FileTrain::FileTrain()
{
}

FileTrain::~FileTrain() // later
{
    this->erase();
}

void FileTrain::setup(string filePath)
{
    ifstream file(filePath);

    int fSize;
    string ftype;
    int findex;
    Wagon* wag;
    file >> fSize;
    
    for(int i = 0; i < fSize; i++)
    {
        wag = new Wagon;
        this->_memStack.push(wag);
        file >> ftype >> findex;
        wag->setCargoType(ftype);
        wag->setCargoIndex(findex);
        this->_train.push(wag);
    }
}

Train FileTrain::getTrain()
{
    return this->_train;
}

void FileTrain::erase()
{
    int sz = this->_train.getSize();
    for(int i = 0; i < sz; i++)
    {
        this->_train.pop();
    }
    while(this->_memStack.size() > 0)
    {
        Wagon* p = this->_memStack.top();
        if (p != nullptr) delete p;
        this->_memStack.pop();
    }
}