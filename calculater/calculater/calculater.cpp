#include"addition.h"
#include"division.h"
#include"get0numbers.h"
#include"multiplication.h"
#include"operation.h"
#include"substraction.h"
#include<iostream>
using namespace std;
char choise;
int a, b;
int main()
{
    operation op;
    addition add0;
    substraction sub0;
    multiplication multi0;
    division div0;
    get0numbers get0;



    while (true)
    {

        switch (op.oper())
        {
        case '1':
        {
            get0.get01();
            get0.get02();
            cout << "result: " << add0.add() << endl;
        }break;
        case '2':
        {
            get0.get01();
            get0.get02();
            cout << "result: " << sub0.sub() << endl;

        }break;
        case '3':
        {
            get0.get01();
            get0.get02();
            cout << "result: " << multi0.multi() << endl;
        }break;
        case '4':
        {
            get0.get01();
            get0.get02();
            cout << "result: " << div0.div() << endl;
        }break;
        case 'x':
            exit(0);

        default:
            cout << "invaild input!" << endl;
            break;

        }
    }
}
