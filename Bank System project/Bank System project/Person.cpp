#include "Person.h"
static int id = 0000000;

// Default constructor
Person::Person() : id(0) {
}

// Parameterized constructor
Person::Person(string name, string pass, int id) {
    this->name = name;
    this->id = id;
    this->pass = pass;
}

// Setters
void Person::setName(string name) {
    this->name = nameOrg(name);
}

void Person::setPass(string pass) {
    this->pass = pass;
}

// Getters
string Person::getName() {
    return name;
}

void Person::setId(int id) {
    this->id = id;
}

int Person::getID() const {
    return id;
}

string Person::getPass() {
    return pass;
}

// Name Organization
string Person::nameOrg(string name) {
    while (true) {
        bool isValid = true;

        for (int i = 0; i < name.length(); i++) {
            if (!(isalpha(name[i]) || name[i] == ' ')) {
                isValid = false;
                break;
            }
        }

        if (!isValid) {
            cout << "Invalid input. Please enter a valid name (only letters and spaces, exactly 3 words): " << endl;
            getline(cin, name);
            continue;
        }

        int wordCount = 0;
        bool inWord = false;
        for (int i = 0; i < name.length(); i++) {
            if (name[i] != ' ') {
                if (!inWord) {
                    wordCount++;
                    inWord = true;
                }
            }
            else {
                inWord = false;
            }
        }

        if (wordCount != 3) {
            cout << "Name must consist of exactly 3 words. Please try again." << endl;
            getline(cin, name);
            continue;
        }

        size_t first = name.find_first_not_of(" ");
        size_t last = name.find_last_not_of(" ");
        name = name.substr(first, (last - first + 1));

        break;
    }

    return name;
}

// Destructor
Person::~Person() {
}