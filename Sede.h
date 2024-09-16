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

    // Métodos de acceso
    int getId();
    string getName();
    string getAddress();
    string getPhone();

    // Métodos de manipulación
    void updateName();
    void updateAddress(string address);
    void updatePhone(string phone);
    void activate();
    void deactivate();
};
