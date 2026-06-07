#ifndef EMPLOYEEMANAGER_H
#define EMPLOYEEMANAGER_H

#include "Employee.h"
#include <vector>
class EmployeeManager
{
private:
    vector<Employee> employees;
    bool isDuplicateID(int id) const;
    void saveToFile() const;
public:
    EmployeeManager();
    void loadFromFile();
    void addEmployee();
    void displayAllEmployees() const;
    void searchEmployeeByID() const;
    void updateEmployee();
    void deleteEmployee();
};

#endif