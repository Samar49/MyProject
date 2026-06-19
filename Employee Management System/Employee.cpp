#include "Employee.h"
#include <iomanip>
#include <sstream>

// Default Constructor
Employee::Employee()
{
    employeeID=0;
    name="";
    age=0;
    department="";
    salary=0.0;
}

// Parameterized Constructor
Employee::Employee(int id, string empName, int empAge,
                string empDepartment, double empSalary)
{
    employeeID=id;
    name=empName;
    age=empAge;
    department=empDepartment;
    salary=empSalary;
}

// Getters
int Employee::getEmployeeID() const
{
    return employeeID;
}

string Employee::getName() const
{
    return name;
}

int Employee::getAge() const
{
    return age;
}

string Employee::getDepartment() const
{
    return department;
}

double Employee::getSalary() const
{
    return salary;
}

// Setters
void Employee::setName(const string &empName)
{
    name=empName;
}

void Employee::setAge(int empAge)
{
    age=empAge;
}

void Employee::setDepartment(const string &empDepartment)
{
    department=empDepartment;
}

void Employee::setSalary(double empSalary)
{
    salary=empSalary;
}

// For displaying Employee
void Employee::displayEmployee() const
{
    cout << left <<setw(10)<<employeeID
         << setw(20)<<name
         << setw(10)<<age
         << setw(20)<<department
         << fixed<<setprecision(2)
         << setw(15)<<salary<<endl;
}
// Converting object to file string
string Employee::toFileString() const
{
    stringstream ss;
    ss << employeeID<<","
       << name<<","
       << age<<","
       << department<<","
       << salary;
    return ss.str();
}