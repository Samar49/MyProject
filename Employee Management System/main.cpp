#include "EmployeeManager.h"
using namespace std;
void showMenu(){
    cout<<"\n========== Employee Management System ==========\n";
    cout<<"1. Add Employee\n";
    cout<<"2. Display All Employees\n";
    cout<<"3. Search Employee by ID\n";
    cout<<"4. Update Employee\n";
    cout<<"5. Delete Employee\n";
    cout<<"6. Exit\n";
    cout<<"Enter your choice: ";
}
int main(){
    EmployeeManager manager;
    int choice;
    do{
        showMenu();
        while(!(cin>>choice)){
            cout<<"Invalid input. Enter number only: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        switch (choice)
        {
        case 1:
            manager.addEmployee();
            break;
        case 2:
            manager.displayAllEmployees();
            break;
        case 3:
            manager.searchEmployeeByID();
            break;
        case 4:
            manager.updateEmployee();
            break;
        case 5:
            manager.deleteEmployee();
            break;
        case 6:
            cout<<"Exiting Program...\n";
            break;
        default:
            cout<<"Invalid choice.\n";
        }
    }while (choice!= 6);
    return 0;
}