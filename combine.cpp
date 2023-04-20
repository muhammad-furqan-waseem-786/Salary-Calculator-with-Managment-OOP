#include <iostream>
#include <stdio.h>
#include "class.h"
using namespace std;
int main()
{
    int salary,choice;
    ceo obj(salary);
    employee obj2(salary);

    cout<<"press 1 if you are ceo \npress 2 if you are employee : ";
    cin>>choice;

    if (choice == 1)
    {
        system("CLS");
        obj.password();
    }
    else if (choice == 2)
    {
        obj2.name();
        cout<<"enter the basic salary : " ;
        cin>>salary;
        employee obj2(salary);
        obj2.salary_calculator();
    }



    return 0;
}
