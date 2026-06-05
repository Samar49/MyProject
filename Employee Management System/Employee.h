// These are my header gaurds

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
using namespace std;

class Employee
{
private:
    int employeeID;
    string name;
    int age;
    string department;
    double salary;

public:
    // Constructors
    Employee();
    Employee(int id, string empName, int empAge,
             string empDepartment, double empSalary);

    // Getters
    int getEmployeeID() const;
    string getName() const;
    int getAge() const;
    string getDepartment() const;
    double getSalary() const;

    // Setters
    void setName(const string &empName);
    void setAge(int empAge);
    void setDepartment(const string &empDepartment);
    void setSalary(double empSalary);

    // Utility Functions
    void displayEmployee() const;

    // File Handling
    string toFileString() const;
};

#endif