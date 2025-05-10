#pragma once
#include <vector>
#include <string>
#include <sstream>
#include "Admin.h"

using namespace std;  
class Parser {
public:
    static vector<string> split(string line) {
        vector<string> result;
        stringstream s(line);
        string item;
        while (getline(s, item, '#')) {
            result.push_back(item);
        }
        return result;
    }

    static Client parseToClient(string line) {
        vector<string> parts = split(line);
        string name = parts[0];
        int id = stoi(parts[1]);
        string pass = parts[2];
        double balance = stod(parts[3]);
        return Client(name, pass, balance, id);
    }

    static Emp parseToEmp(string line) {
        vector<string> parts = split(line);
        string name = parts[0];
        int id = stoi(parts[1]);
        string pass = parts[2];
        double salary = stod(parts[3]);
        return Emp(name, pass, salary, id);
    }

    static Admin parseToAdmin(string line) {
        vector<string> parts = split(line);
        string name = parts[0];
        int id = stoi(parts[1]);
        string pass = parts[2];
        double salary = stod(parts[3]);
        return Admin(name, pass, salary, id);
    }
};
