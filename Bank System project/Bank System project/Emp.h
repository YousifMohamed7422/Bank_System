
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Client.h"
#include"FilesHelper.h"

using namespace std;

class Emp : public Person {
protected:
    double salary;

public:
    Emp() : Person() {
        this->salary = 5000;
    }

    Emp(string name, string pass, double salary, int id) : Person(name, pass,id) {
        setSalary(salary);
        this->id = id;
    }

    void setSalary(double salary) {
        if (salary >= 5000)
            this->salary = salary;
        else
            cout << "Minimum salary must be at least 5000.\n";
    }
    void setId(int id) {
        this->id = id;
    }

    double getSalary() const{
        return salary;
    }


      void addClient(Client& client) {
         cout << "Enter Client Name: \n";
         getline(cin, name);
         client.setName(name);
         cout << "Enter Client Password: \n";
         getline(cin, pass);
         client.setPass(pass);
         cout << "Enter Client Balance: \n";
         double balance;
         cin >> balance;
         client.setBalance(balance);
        allClients.push_back(client); 
       FilesHelper::SaveClient(client);

        cout << "Mr. " << client.getName() << " added successfully.\n";
    }

    Client* searchClient(int id) {
        for (auto& c :allClients) {
            if (c.getID() == id) {
                return &c;
            }
        }
        return nullptr;
    }

 

    void listClient() {
        for (auto& c : allClients) {
            c.displayInfo();
        }
    }

   void deleteClient(int id) {
    auto it = std::find_if(allClients.begin(), allClients.end(), [id](const Client& c) {
        } );

    if (it != allClients.end()) {
        allClients.erase(it);
        cout << "Client deleted successfully.\n";
    } else {
        cout << "Client not found.\n";
    }
}

    void editClient(int id, double balance) {
        Client* c = searchClient(id);
        if (c != nullptr) {
            cout << "Enter the new name : \n";
            getline(cin, name);
            c->setName(name);
            cout << "Enter the new password : \n";
            getline(cin, pass);
            c->setPass(pass);
            cout << "Enter the Balance : \n";
            cin >> balance;
            c->setBalance(balance);
        }
    }

    void displayInfo() {
        cout << "Employee Name: " << getName() << ", ID: " << getID() << ", Salary: " << salary << endl;
    }

    ~Emp() {}
};

static vector<Emp> emps;
static vector<Emp> ::iterator empsit;