#include <iostream> //including input output header file
#include <fstream> //this header file is used for opening the the file at the back end of the program
#include <stdio.h> //this header file is used for clearing the screen
void read_data(int counter); //function prototyping
using namespace std;

class calculator //calculator class is created
{
private: //private variable are initialized . So we can use it within the class scope
        int house_allowance,conveyance,utility_allowance,bonus,medical_allowance,gross_salary,others; //private variable are initialized
protected : //protected variable are initialized . So we can use the variable in the base class and in the derived classes
        ifstream in; //this is used for reading the data from the file
        ofstream out; //this is used for writing the data in the file
        string designation,first_name,last_name,cnic,email,number_of_lines,enterd_password,read_password;
        char new1,del,read;
        int index,i=0,divide,j=1,salary,choice,basic_salary,number,button_pressed;
public : //public is used so we can use it outsibe of the scope
    calculator () //default constructor is used
    {
        basic_salary=0;
        house_allowance=0;
        conveyance=0;
        utility_allowance=0;
        bonus=0;
        medical_allowance=0;
        gross_salary=0;
        others=0;
    }
    calculator (int get_basic_salary) //parameterized constructor is used
    {
        basic_salary = get_basic_salary;
    }
    int salary_calculator() //function is made
    {
    gross_salary=(basic_salary*100)/40;
    house_allowance=gross_salary*(0.15);
    conveyance=gross_salary*(0.1);
    utility_allowance=gross_salary*(0.1);
    bonus=gross_salary*(0.0833334);
    others=gross_salary*(0.066667);
    medical_allowance=gross_salary*(0.1);

    cout<<"basic salary : "<<"\t\t"<<basic_salary<<endl;
    cout<<"house allowance : "<<"\t"<<house_allowance<<endl;
    cout<<"conveyance : "<<"\t\t"<<conveyance<<endl;
    cout<<"utility allowance : "<<"\t"<<utility_allowance<<endl;
    cout<<"bonus : "<<"\t\t"<<bonus<<endl;
    cout<<"others : "<<"\t\t"<<others<<endl;
    cout<<"medical allowance : "<<"\t"<<medical_allowance<<endl;
    cout<<"gross salary : \t\t"<<gross_salary;

    return gross_salary;
    }

};
class employee : public calculator //derived class is created and inherited from the base class (calculator)
{
private: //private variable are initialized
    int basic_salary_of_employee;
public: //public is used for we can use the function out of the scope
    void name() //function
    {
    cout<<"enter your first name : ";
    cin>>first_name ;
    cout<<"enter your last name : ";
    cin>>last_name ;
    cout<<"enter your designation : ";
    cin>>designation;
    }
    employee(int get_basic_salary) : calculator (get_basic_salary) //constructor is used and call the constructor from the base class
    {
        basic_salary_of_employee = get_basic_salary;
    }
};
class ceo : public calculator // derived class is created and inherited from the base class (calculator)
{
public : // public is used so we can use the function outside of the scope
    void password() //function is created which will get the password from the user
    {
        in.open("password.txt"); //opening the file

    while (!in.eof()) //this will run until the end of the end of the file;
    {
        in>>read_password; //read_password store the password from the file
    }

    in.close(); //closing the file

    for (int i=5;i>=0;i--) //loop

    {
         cout<<"enter the password : "; //display on console screen
         cin>>enterd_password; //get the password from the user

    if (enterd_password == read_password) //applying the condition that will check the password that the user entered with the password from the file
    {
        cout<<"\nyou have successfully login "<<endl; //display on console screen
        cout<<"\npress 1 if you want to read the employees and their data \npress 2 if you want to delete the employee \npress 3 if you want to add the new employee \npress 4 if you want the salary calculator : ";
        cin>>button_pressed;
        if (button_pressed == 1)
        {
            system("CLS");
            read_employee();
        }
        else if (button_pressed == 2)
        {
            system("CLS");
            delete_employee();
        }
        else if (button_pressed == 3)
        {
            system("CLS");
            save_employee();
        }
        else if (button_pressed == 4)
        {
            system("CLS");
            cout<<"enter the basic salary : ";
            cin>>basic_salary;
            ceo obj(basic_salary);
            obj.salary_calculator();
        }
        break;
    }
        else if (i==0) // if " i " is equal to zero then this condition will run
    {
        cout<<"\nyour system is locked try again later"<<endl;
    }
        else if (enterd_password != read_password) // if entered password is not equal to zero then this condition will run
    {
        system ("CLS");//clear the screen
        cout<<"you enter the wrong password "<<endl;//this will display on screen
        cout<<"\nyou have "<<i<<" chances left\n"<<endl; //display on console screen
    }
    }

    }
    ceo (int get_basic_salary) : calculator (get_basic_salary) //constructor is used and call the constructor from the base class
    {
        basic_salary=get_basic_salary;
    }
    void save_employee() //function is created which will save the new employee
    {
    cout<<"enter the total number of employees whose data you want to save : ";  //display on console screen
    cin>>number; //get the number from the user that the user want to save how many employees

    out.open("employees.txt" , ios :: app); //open the file

    for (int i=1;i<=number;i++) //loop
    {
    cout<<"enter the first name of the employee "<<i<<" : "; //display on console screen
    cin>>first_name; //get the first name from the user
    out<<first_name<<" "; //write it in the file

    cout<<"enter the last name of the employee "<<i<<" : "; //display on console screen
    cin>>last_name; //get the last name from the user
    out<<last_name<<endl; //write it in the file

    cout<<"\npress 1 if you are CEO \npress 2 if you are clerk \npress 3 if you are assistant \npress 4 if you are in Human Resource \npress 5 if you are probation : "; //display on console screen
    cin>>choice; //get the option from the user

    switch (choice)
    {
        case 1:

            designation="CEO";

           break;

        case 2:

            designation="clerk";

            break;

        case 3:

             designation="assistant";

            break;

        case 4:

            designation="HR";

            break;

        case 5:

            designation="probation";

            break;

    }

    out<<designation<<endl; //write it in the file

    cout<<"enter the cnic of the employee "<<i<<" : "; //display on console screen
    cin>>cnic; //get the cnic from the user
    out<<cnic<<endl; //write it in the file

    cout<<"enter the email address of the employee "<<i<<" : "; //display on console screen
    cin>>email; //get the email from the user
    out<<email<<endl; //write it in the file

    cout<<"enter the salary of the employee "<<i<<" : "; //display on console screen
    cin>>salary; //get the salary from the user
    out<<salary<<endl; //write it in the file
    }

    out.close(); //close the file

    }
    void read_employee() //function is created which will read the employee and its data
    {

    in.open("employees.txt" , ios::in); //opening the file employee.txt for reading

    while (getline(in,number_of_lines)) //loop is used which will read the number of total number of line
    {
        i++; //counter
    }
    in.close(); //close the file

    read_data(i); //called the function

    }

    void delete_employee() //function is created which will delete the employee and its data from the file
    {
        in.open("employees.txt" , ios::in); //opening the file employee.txt for reading

    while (getline(in,number_of_lines)) //loop is used which will read the number of total number of line
    {
        i++; //counter
    }
    in.close(); //close the file

    read_data(i); //function is called

    cout<<"enter the index of the employee whose data you want to delete : "; //display on console screen
    cin>>index; //get the index from the user foe deleting the employee and the employee data

    in.open("employees.txt" , ios::in); //opening the file employee.txt for reading
    out.open("temp.txt" , ios::out); //opening the temp.txt (temporary file) for writing the data in the temp.txt

    while (!in.eof()) //loop is used which will until the end of the file
    {
    if (j == index) //if the number that user enter is equal to the number of the counter then it will only read it
        {
            in>>first_name;
            in>>last_name;
            in>>designation;
            in>>cnic;
            in>>email;
            in>>salary;
      }
    else //else it will read it and write it
        {
            in>>first_name;
            in>>last_name;
            in>>designation;
            in>>cnic;
            in>>email;
            in>>salary;
            out<<first_name<<" "<<last_name<<endl;
            out<<designation<<endl;
            out<<cnic<<endl;
            out<<email<<endl;
            out<<salary<<endl;

        }
        j++; //counter is used
    }
    out.close(); //close the file
    in.close(); //close the file

        divide = i/5; //dividing the number of lines from the 5 so we will get the total number of remaining employees from the file

    in.open("temp.txt" , ios::in); //open the temp.txt for reading
    out.open("employees.txt" , ios::out); //open the employee.txt for writing

    for (int j=1; j<=(divide-1) ;j++) //loop
    {
            in>>first_name;
            in>>last_name;
            in>>designation;
            in>>cnic;
            in>>email;
            in>>salary;
            out<<first_name<<" "<<last_name<<endl;
            out<<designation<<endl;
            out<<cnic<<endl;
            out<<email<<endl;
            out<<salary<<endl;
    }
    out.close(); //close the file
    in.close(); //close the file

    cout<<"after deleting the data "<<endl;
    i=i-1;
    read_data(i); //show the list deleting the employee
    }
};

void read_data(int counter) //function is created which will display the list of employees before and after deletion
    {
        ifstream in;
        string first_name,last_name,designation,cnic,email,number_of_lines;
        int salary,divide,i=0;

     divide = counter/5;


    cout<<"name\t\t\t\tdesignation\t\tcnic\t\t\temail\t\t\tsalary\n"<<endl; //display on screen

    in.open("employees.txt"); //open the employees.txt file

    for (int j=1;j<=divide;j++) //this will run until the end of the end of the file
    {
        in>>first_name; //read the first name from the file
        in>>last_name; //read the  last name from the file
        in>>designation; //read the designation from the file
        in>>cnic; //read the cnic from the file
        in>>email; //read the email address from the file
        in>>salary; //read the salary from the file
        cout<<"["<<j<<"]"<<first_name<<" "<<last_name<<"\t\t"<<designation<<"\t\t"<<cnic<<"\t\t"<<email<<"\t\t"<<salary<<endl;
    }
    in.close(); //closing the file
    }
