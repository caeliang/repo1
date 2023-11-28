#include "division.h"
#include<iostream>
using namespace std;
extern int a, b;
int division::div()
{
    if (b == 0)
    {
        cout << "can't divid by 0! please enter new value: ";
        cin >> b;
    }

    return a / b;
}