#pragma once
#include <fstream>
#include <string>
#include <vector>
#include "Emp.h"
#include "FilesHelper.h"

using namespace std;

class Admin : public Emp {

public:
    Admin() {}

    Admin(string name, string pass, double salary, int id) : Emp(name, pass, salary, id) {}

    double getSalary() {
        return salary * 0.2;
    }

    void addEmp(Emp& Emp) {
        cout << "Enter Employee Name: \n";
        std::cin >> std::ws;
        getline(cin, name);
        Emp.setName(name);
        cout << "Enter Employee Password: \n";
        getline(cin, pass);
        Emp.setPass(pass);
        cout << "Enter Employee Salary:  \n";
        double salary;
        cin >> salary;
        Emp.setSalary(salary);
        emps.push_back(Emp);
        FilesHelper::SaveEmp(Emp);
        cout << "mr " << Emp.getName() << " added successfully.\n";
    }

    Emp* searchEmp(int id) {
        for (auto& emp : emps) {
            if (emp.getID() == id) {
                return &emp;
            }
        }
        return nullptr;
    }

    void editEmp(int id, double salary) {
        Emp* emp = searchEmp(id);
        if (emp != nullptr) {
            cout << "Enter the new name : \n";
            getline(cin, name);
            emp->setName(name);
            cout << "Enter the new password : \n";
            getline(cin, pass);
            emp->setPass(pass);
            cout << "Enter the Salary : \n";
            cin >> salary;
            emp->setSalary(salary);
        }
    }

    void listEmp() {
        for (auto& emp : emps) {
            emp.displayInfo();
        }
    }
    void deleteEmp(int id) {
        auto it = std::find_if(emps.begin(), emps.end(), [id](const Emp& emp) {
            return emp.getID() == id;
            });

        if (it != emps.end()) {
            FilesHelper::SaveEmp(*it); 
            emps.erase(it);
            cout << "Employee deleted successfully.\n";
        }
        else {
            cout << "Employee not found.\n";
        }
    }

    void displayInfo() {
        cout << "Admin Name: " << getName() << ", ID: " << getID() << ", Salary: " << getSalary() << endl;
    }

    ~Admin() {}
};

static vector<Admin> admins;
static vector<Admin> ::iterator adminsit;