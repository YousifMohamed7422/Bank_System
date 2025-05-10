#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Person.h"

using namespace std;

class Client : public Person {
    double balance;
    int total_trans = 0;
    int num_deposite = 0;

public:
    Client() {
        this->balance = 0;
    }

    Client(string name, string pass, double balance, int id) : Person(name, pass,id) {
        this->balance = balance;
        this->id = id;
    }

    void setBalance(double balance) {
        this->balance = balance;
    }

    double getBalance() {
        return balance;
    }
    void setId(int id) {
        this->id = id;
    }
    void deposit() {
        double amount;
        while (true) {
            cout << "Enter your amount to deposit: \n";
            cin >> amount;
            if (amount > 50 && amount <= 160000) {
                balance += amount;
                cout << "Deposited " << amount << " successfully." << endl;
                cout << "Your balance after deposit is: " << balance << endl;
                break;
            }
            else if (amount > 160000) {
                cout << "You can't deposit more than 160000 at once. Please enter a valid amount.\n";
            }
            else {
                cout << "You can't deposit less than 50. Please enter a valid amount.\n";
            }
        }
        num_deposite++;
        total_trans++;
    }

    void withdraw() {
        double amount;
        while (true) {
            cout << "Enter your amount to withdraw: \n";
            cin >> amount;
            if (amount > 50 && amount <= 16000) {
                if (amount <= balance) {
                    balance -= amount;
                    cout << "Withdrew " << amount << " successfully." << endl;
                    cout << "Your balance after withdrawal is: " << balance << endl;
                    break;
                }
                else {
                    cout << "You don't have enough balance to withdraw this amount. Please enter a valid amount.\n";
                }
            }
            else if (amount > 16000) {
                cout << "You can't withdraw more than 16000 at once. Please enter a valid amount.\n";
            }
            else {
                cout << "You can't withdraw less than 50. Please enter a valid amount.\n";
            }
        }
        total_trans++;
    }

    void transferTo(Client& client) {
        double amount;
        while (true) {
            cout << "Enter the amount you want to transfer: \n";
            cin >> amount;
            if (amount > 50 && amount <= 16000) {
                if (amount <= balance) {
                    balance -= amount;
                    client.balance += amount;
                    cout << "Transferred " << amount << " successfully to " << client.getName() << "." << endl;
                    cout << "Your balance after transfer is: " << balance << endl;
                    break;
                }
                else {
                    cout << "You don't have enough balance to transfer this amount. Please enter a valid amount.\n";
                }
            }
            else if (amount > 16000) {
                cout << "You can't transfer more than 16000 at once. Please enter a valid amount.\n";
            }
            else {
                cout << "You can't transfer less than 50. Please enter a valid amount.\n";
            }
        }
        total_trans++;
    }

    double benefits() {
        if (balance >= 20000 && num_deposite >= 10)
            balance *= 0.13;

        return balance;
    }

    void CheckBalance() {
        cout << "Your balance is: " << getBalance() << endl;
    }

    int getTotalTrans() {
        return total_trans;
    }



    void displayInfo() {
        cout << "The user name is: " << getName() << endl;
        cout << "The user id is: " << getID() << endl;
        cout << "The user balance is: " << getBalance() << endl;
        cout << "The number of transactions the user has done: " << total_trans << endl;
    }



    ~Client() {}
};

static vector<Client> allClients;
static vector <Client>::iterator clientit;