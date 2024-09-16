#pragma once
#include <string>

using namespace std;
class Sede {
private:
    int id;
    string name;
    string address;
    string phone;
    bool isActive;

public:
    Sede(int id, string name, string address, string phone);

    // M�todos de acceso
    int getId();
    string getName();
    string getAddress();
    string getPhone();

    // M�todos de manipulaci�n
    void updateName();
    void updateAddress(string address);
    void updatePhone(string phone);
    void activate();
    void deactivate();
};
