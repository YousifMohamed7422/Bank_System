#pragma once
#include <vector>
#include "Client.h"
#include "Emp.h"
#include "Admin.h"
using namespace std;

class DataSourceInterface {
public:
    virtual void addClient(Client c) = 0;
    virtual void addEmp(Emp e) = 0;
    virtual void addAdmin(Admin a) = 0;

    virtual vector<Client> getAllClients() = 0;
    virtual vector<Emp> getAllEmps() = 0;
    virtual vector<Admin> getAllAdmins() = 0;

    virtual void removeAllClients() = 0;
    virtual void removeAllEmps() = 0;
    virtual void removeAllAdmins() = 0;

    virtual ~DataSourceInterface() {}
};