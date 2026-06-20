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
