#ifndef TRAINMAKERGUARD
#define TRAINMAKERGUARD

#include "Train.hpp"
#include <vector>
#include <stack>
#include <string>

using namespace std;

class ConsoleTrain
{
public:
    ConsoleTrain();
    ~ConsoleTrain();

    void setup();
    void setupWithTypes(vector<string>);
    Train getTrain();
    void erase();
private:
    Train _train;
    std::stack<Wagon*> _memStack;

};

class FileTrain
{
public:
    FileTrain();
    ~FileTrain();

    void setup(string);
    Train getTrain();
    void erase();
private:
    Train _train;
    stack<Wagon*> _memStack;

};

#endif //TRAINMAKERGUARD