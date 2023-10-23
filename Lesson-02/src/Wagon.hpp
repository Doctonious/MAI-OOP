#ifndef WAGONGUARD
#define WAGONGUARD

#include <string>

using namespace std;

class Wagon
{
public:
    Wagon* next;
    Wagon();
    Wagon(string, int);
    ~Wagon();

    string getCargoType();
    void setCargoType(string);
    int getCargoIndex();
    void setCargoIndex(int);
private:
    string _cargoType;
    int _cargoIndex;
};

#endif //WAGONGUARD