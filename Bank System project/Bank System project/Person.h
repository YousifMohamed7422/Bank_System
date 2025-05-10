#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Person {
protected:
    string name;
    int id;
    string pass;

public:
    Person();
    Person(string name, string pass, int id);
    void setId(int id);
    void setName(string name);
    void setPass(string pass);
    string getName();
    int getID() const;
    string getPass();
    string nameOrg(string name);

    ~Person();
};

inline int Person::getID() const {
    return id;
}