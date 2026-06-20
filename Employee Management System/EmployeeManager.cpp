#include "EmployeeManager.h"
#include <fstream>
#include <iomanip>
#include <limits>
#include <sstream>
using namespace std;

// Constructor
EmployeeManager::EmployeeManager(){
    loadFromFile();
}
// Check duplicate ID
bool EmployeeManager::isDuplicateID(int id) const{
    for(const Employee &employee:employees){
        if(employee.getEmployeeID()==id){
            return true;
        }
    }
    return false;
}
// Save all employees to file
void EmployeeManager::saveToFile() const{
    ofstream file("employees.txt");
    if(!file){
        cout<<"Error opening file.\n";
        return;
    }
    for(const Employee &employee:employees){
        file<<employee.toFileString()<<endl;
    }
    file.close();
}
// Load employees from file
void EmployeeManager::loadFromFile(){
    ifstream file("employees.txt");
    if(!file){
        return;
    }
    employees.clear();
    string line;
    while (getline(file, line)){
        stringstream ss(line);
        string idStr, name, ageStr, department, salaryStr;
        getline(ss, idStr, ',');
        getline(ss, name, ',');
        getline(ss, ageStr, ',');
        getline(ss, department, ',');
        getline(ss, salaryStr, ',');
        int id = stoi(idStr);
        int age = stoi(ageStr);
        double salary = stod(salaryStr);
        Employee employee(id, name, age, department, salary);
        employees.push_back(employee);
    }
    file.close();
}
void EmployeeManager::addEmployee(){
    int id, age;
    string name, department;
    double salary;
    cout << "\nEnter Employee ID: ";
    while (!(cin >> id) || id <= 0){
        cout << "Invalid ID. Enter again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    if (isDuplicateID(id)){
        cout << "Employee ID already exists.\n";
        return;
    }
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Age: ";
    while (!(cin >> age) || age <= 0){
        cout << "Invalid Age. Enter again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore();
    cout << "Enter Department: ";
    getline(cin, department);
    cout << "Enter Salary: ";
    while (!(cin >> salary) || salary < 0){
        cout << "Invalid Salary. Enter again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    Employee employee(id, name, age, department, salary);
    employees.push_back(employee);
    saveToFile();
    cout << "Employee added successfully.\n";
}


