#include <iostream>
using namespace std;
int main()
{
    cout<<"What is your name?"<<endl;
    string name;
    cin>>name;
    cout<<"Hello "<<name<<"."<<endl;

    cout<<"What is your Student ID?"<<endl;
    string studentID;
    cin>>studentID;
    cout<<"Your ID is "<<studentID<<"."<<endl;

--------------------------------------------------------------------------------------

    double var1, var2;
    double sum, diff, prod;

    cout << "Enter the value of var1: ";
    cin >> var1;
    cout << "Enter the value of var2: ";
    cin >> var2;

    sum = var1 + var2;
    diff = var1 - var2;
    prod = var1 * var2;

    cout << "var1 = " << var1 << endl;
    cout << "var2 = " << var2 << endl;
    cout << "Sum = " << sum << endl;
    cout << "Difference = " << diff << endl;
    cout << "Product = " << prod << endl;
    
--------------------------------------------------------------------------------------
    
    string name;
    double lab_grade, midterm_grade, final_grade, last_score;

    cout << "Enter the name of the student: ";
    getline(cin, name);
    cout << "Enter the lab grade: ";
    cin >> lab_grade;
    cout << "Enter the midterm grade: ";
    cin >> midterm_grade;
    cout << "Enter the final grade: ";
    cin >> final_grade;

    last_score = 0.25 * lab_grade + 0.35 * midterm_grade + 0.4 * final_grade;

    cout << "Name: " << name << endl;
    cout << "Lab: " << lab_grade << endl;
    cout << "Midterm: " << midterm_grade << endl;
    cout << "Final: " << final_grade << endl;
    cout << "Last Score: " << last_score << endl;
    
--------------------------------------------------------------------------------------
    
    cout << "*\n**\n***\n**\n*\n";
    
    return 0;
}