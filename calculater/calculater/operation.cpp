#include "operation.h"
#include<iostream>
using namespace std;
extern char choise;

    int operation::oper()
    {
        cout << "1.addition" << endl;
        cout << "2.substraction" << endl;
        cout << "3.multiplication" << endl;
        cout << "4.division" << endl;
        cout << "x.exit" << endl;
        cout << "enter your choise: ";
        cin >> choise;

        return choise;
    }

