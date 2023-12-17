#include <iostream>
#include <string>

using namespace std;

template<typename T>
bool comparison(T a, T b)
{
    return a <= b;
}

template<>
bool comparison<string> (string a, string b)
{
    return a.size() <= b.size();
}


using namespace std;

int main()
{
    string str1 = "The inevitable price we pay for our happiness is eternal fear to lose it.";
    string str2 = "Now or never!";

    int num1 = -7;
    int num2 = 1000;

    cout << comparison<string> (str1, str2) << endl;
    cout << comparison<int> (num1, num2);


    return 0;
}