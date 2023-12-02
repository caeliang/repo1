#include "get0numbers.h"
#include <iostream>
using namespace std;
extern int a, b;
int get0numbers::get01()
{
    cout << "enter 1.number: ";
    cin >> a;
    return a;
}
int get0numbers::get02()
{
    cout << "enter 2.number: ";
    cin >> b;
    return b;
}


