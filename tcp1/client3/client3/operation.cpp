#include "operation.h"
#include<iostream>
#include<string>
using namespace std;
extern string choise;

string operation::oper()
{
    cout << "1.addition" << endl;
    cout << "2.substraction" << endl;
    cout << "3.multiplication" << endl;
    cout << "4.division" << endl;
    cout << "x.exit" << endl;
    cout << "enter your choise: ";
    getline(cin,choise);

    return choise;
}
