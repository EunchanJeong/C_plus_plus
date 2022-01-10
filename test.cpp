#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int a = 10;

    int* p = &a;
    int& r = a;

    cout << p << endl;
    cout << r << endl;
}