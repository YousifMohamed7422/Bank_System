#pragma once
#include <fstream>
#include <string>
#include <vector>
#include "Admin.h"
#include "Parser.h"

using namespace std; 

class FilesHelper {
public:
 

    static void saveLast(string fileName, int id) {
        fstream file;
        file.open(fileName,ios::app);
        file << id;
        file.close();
    }

    static int getLast(string fileName) {
        ifstream file;
        file.open(fileName);
        int lastId;
        file >> lastId;
        file.close();
        return lastId;
    }

    static void SaveClient(Client c) {
        int id = getLast("ClientLastId.txt");
        fstream file;
        file.open("Client.txt", ios::app);
        file << c.getName() << "#" << id + 1 << "#" << c.getPass() << "#" << c.getBalance() << "\n";
        file.close();
        saveLast("ClientLastId.txt", id + 1);
    }

    static void SaveEmp(Emp e) {
        int id = getLast("EmpLastId.txt");
        fstream file;
        file.open("Emp.txt", ios::app);
        file << e.getName() << "#" << id + 1 << "#" << e.getPass() << "#" << e.getSalary() << "\n";
        file.close();
        saveLast("EmpLastId.txt", id + 1);
       
    }
    static void SaveAdmin(Admin a) {
        int id = getLast("AdminLastId.txt");
        fstream file;
        file.open("Admin.txt", ios::app);
        file << a.getName() << "#" << id + 1 << "#" << a.getPass() << "#" << a.getSalary() << "\n";
        file.close();
        saveLast("AdminLastId.txt", id + 1);
    }


    static void getClients() {
        fstream file;
        file.open("Client.txt",ios::in);
        string line;
        while (getline(file, line)) {
            
            allClients.push_back(Parser::parseToClient(line));
        }
        file.close();
    }

    static void getEmployees() {
        fstream file;
        file.open("Emp.txt",ios::in);
        string line;
        while (getline(file, line)) {
            emps.push_back(Parser::parseToEmp(line));
        }
        file.close();
    }

    static void getAdmins() {
        fstream file;
        file.open("Admin.txt",ios::in);
        string line;
        while (getline(file, line)) {
            admins.push_back(Parser::parseToAdmin(line));
        }
        file.close();
    }

    static void clearFile(string fileName, string lastIdFile) {
        fstream file;
        file.open(fileName, ios::trunc);
        file.close();
        saveLast(lastIdFile, 0);
    }
    
};
