#pragma once
#include"FilesHelper.h"
#include "DataSourceInterface.h"

class FileManager : public DataSourceInterface {
public:

    static void addClient(Client& client) {
        FilesHelper::SaveClient(client);
    }

    static  void addEmp(Emp& emp) {
        FilesHelper::SaveEmp(emp);
    }

    static void addAdmin(Admin& admin) {
        FilesHelper::SaveAdmin(admin);
    }

    static void getAllClients() {
        FilesHelper::getClients();
    }

    static void getAllEmps() {
        FilesHelper::getEmployees();
    }

    static void getAllAdmins() {
        FilesHelper::getAdmins();
    }

   static void removeAllClients() {
        FilesHelper::clearFile("Client.txt", "ClientLastId.txt");
    }

    static void removeAllEmps() {
        FilesHelper::clearFile("Emp.txt", "EmpLastId.txt");
    }

    static void removeAllAdmins() {
        FilesHelper::clearFile("Admin.txt", "AdminLastId.txt");
    }
public:
    static void getAllData() {
        getAllClients();
        getAllEmps();
        getAllAdmins();
    }
    static void updateClient() {
        fstream file;
        file.open("Client.txt", ios::out);
        for (auto& c : allClients) {
            file << c.getName() << "#" << c.getID() << "#" << c.getPass() << "#" << c.getBalance() << "\n";
        }
        file.close();
    }
};
