#pragma once
#include "Admin.h"
#include"FileManger.h"
#include <string>
#include <iostream>
using namespace std;

class LoginManger
{

	static Client* validUser(int id, string pass) {
		for (auto& c : allClients) {
			if (c.getID() == id && c.getPass() == pass) {
				return &c;
			}
		}
		return nullptr;
	}

	static Client* validUser(int id) {
		for (auto& c : allClients) {
			if (c.getID() == id) {
				return &c;
			}
		}
		return nullptr;
	}

	static void updatePass(Person* p) {
		string pass;
		cout << "Enter your new password: ";
		getline(cin, pass);
		p->setPass(pass);
	}
public:
    static void login() {
        int n;
        bool validChoice = false;

        while (!validChoice) {
            cout << "If you are an employee, enter 1 \n"
                << "If you are a Client, enter 2.\n"
                << "If you are an Admin, enter 3 \n";
            cin >> n;

            if (n == 1 || n == 2 || n == 3) {
                validChoice = true;
            }
            else {
                cout << "Invalid input, please try again.\n";
            }
        }

        if (n == 1) {
            Emp e;
            cout << "Enter your ID: \n";
            int id;
            cin >> id;
            e.setId(id);

            cout << "Enter the Password: \n";
            string pass;
            cin >> pass;
            e.setPass(pass);

            if (validUser(e.getID(), e.getPass()) != nullptr) {
                int option;
                cout << "Welcome Mr " << e.getName() << ", let's start our tasks.\n";

                while (true) {
                    validChoice = false;
                    while (!validChoice) {
                        cout <<"1: Add new Client \n"
                            << "2: Search for Client \n"
                            << "3: Edit Client \n"
                            << "4: Delete Client \n"
                            << "5: Display all Clients \n"
                            << "6: Change password \n"
                            << "7: Exit\n";
                        cin >> option;

                        if (option >= 1 && option <= 7) {
                            validChoice = true;
                        }
                        else {
                            cout << "Invalid input, please try again.\n";
                        }
                    }

                    if (option == 1) {
                        Client c;
                        e.addClient(c);
                    }
                    else if (option == 2) {
                        int id;
                        cout << "Enter the ID of the client you want to search for: \n";
                        cin >> id;
                        e.searchClient(id);
                    }
                    else if (option == 3) {
                        int id;
                        double balance;
                        cout << "Enter the ID of the client you want to edit: \n";
                        cin >> id;
                        cout << "Enter the new balance: \n";
                        cin >> balance;
                        e.editClient(id, balance);
                        FileManager::updateClient();
                    }
                    else if (option == 4) {
                        int id;
                        cout << "Enter the ID of the client you want to delete: \n";
                        cin >> id;
                        e.deleteClient(id);
                    }
                    else if (option == 5) {
                        e.listClient();
                    }
                    else if (option == 6) {
                        updatePass(&e);
                    }
                    else if (option == 7) {
                        return;
                    }
                }
            }
        }
        else if (n == 2) {
            Client c;
            cout << "Enter the ID: \n";
            int id;
            cin >> id;
            c.setId(id);

            cout << "Enter the Password: \n";
            string pass;
            cin >> pass;
            c.setPass(pass);

            if (validUser(c.getID(), c.getPass()) != nullptr) {
                int option;
                cout << "Welcome Mr " << c.getName() << ", Tell us how we can help you.\n";

                while (true) {
                    validChoice = false;
                    while (!validChoice) {
                        cout << "1: Deposit\n"
                            << "2: Withdraw\n"
                            << "3: Transfer\n"
                            << "4: Change password\n"
                            << "5: Check balance\n"
                            << "6: Display all information\n"
                            << "7: Exit\n";
                        cin >> option;

                        if (option >= 1 && option <= 7) {
                            validChoice = true;
                        }
                        else {
                            cout << "Invalid input, please try again.\n";
                        }
                    }

                    if (option == 1) {
                        c.deposit();
                    }
                    else if (option == 2) {
                        c.withdraw();
                    }
                    else if (option == 3) {
                        Client tmp;
                        int id;
                        cout << "Enter the ID of the client you want to transfer to: \n";
                        cin >> id;
                        if (validUser(id) != nullptr) {
                            tmp = *validUser(id);
                            c.transferTo(tmp);
                        }
                        else {
                            cout << "The user was not found.\n";
                        }
                    }
                    else if (option == 4) {
                        updatePass(&c);
                    }
                    else if (option == 5) {
                        c.CheckBalance();
                    }
                    else if (option == 6) {
                        c.displayInfo();
                    }
                    else if (option == 7) {
                        return;
                    }
                }
            }
        }
        else if (n == 3) {
            Admin a;
            cout << "Enter your ID: \n";
            int id;
            cin >> id;
            a.setId(id);

            cout << "Enter the Password: \n";
            string pass;
            cin >> pass;
            a.setPass(pass);

            if (validUser(a.getID(), a.getPass()) != nullptr) {
                int option;
                cout << "Welcome Mr " << a.getName() << ", let's start our tasks.\n";

                while (true) {
                    validChoice = false;
                    while (!validChoice) {
                        cout << "1: Add new Employee \n"
                            << "2: Search for Employee \n"
                            << "3: Edit Employee \n"
                            << "4: Delete Employee \n"
                            << "5: Display all Employees \n"
                            << "6: Change password \n"
                            << "7: Add new Client\n"
                            << "8: Delete Client \n"
                            << "9: Display all Clients \n"
                            << "10: Update Client\n"
                            << "11: Exit\n";
                        cin >> option;

                        if (option >= 1 && option <= 11) {
                            validChoice = true;
                        }
                        else {
                            cout << "Invalid input, please try again.\n";
                        }
                    }

                    if (option == 1) {
                        Emp e;
                        a.addEmp(e);
                    }
                    else if (option == 2) {
                        int id;
                        cout << "Enter the ID of the Employee you want to search for: \n";
                        cin >> id;
                        a.searchEmp(id);
                    }
                    else if (option == 3) {
                        int id;
                        double salary;
                        cout << "Enter the ID of the Employee you want to edit: \n";
                        cin >> id;
                        cout << "Enter the new salary: \n";
                        cin >> salary;
                        a.editEmp(id, salary);
                    }
                    else if (option == 4) {
                        int id;
                        cout << "Enter the ID of the Employee you want to delete: \n";
                        cin >> id;
                        a.deleteEmp(id);
                    }
                    else if (option == 5) {
                        a.listEmp();
                    }
                    else if (option == 6) {
                        updatePass(&a);
                    }
                    else if (option == 7) {
                        Client c;
                        a.addClient(c);
                    }
                    else if (option == 8) {
                        int id;
                        cout << "Enter the ID of the client you want to delete: \n";
                        cin >> id;
                        a.deleteClient(id);
                    }
                    else if (option == 9) {
                        a.listClient();
                    }
                    else if (option == 10) {
                        int id;
                        double balance;
                        cout << "Enter the ID of the client you want to edit: \n";
                        cin >> id;
                        cout << "Enter the new balance: \n";
                        cin >> balance;
                        a.editClient(id, balance);
                    }
                    else if (option == 11) {
                        return;
                    }
                }
            }
        }
    }

};

