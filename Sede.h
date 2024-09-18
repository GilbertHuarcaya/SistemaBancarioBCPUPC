#pragma once
#include <string>

using namespace std;
class Sede {
private:
    int id;
    string name;
    string adress;
    string phone;
    bool isActive;

public:
    Sede(int id, string name, string address, string phone);

    // M�todos de acceso
    int getId();
    string getName();
    string getAdress();
    string getPhone();

    // M�todos de manipulaci�n
    void updateName(string name);
    void updateAdress(string adress);
    void updatePhone(string phone);
    void activate();
    void deactivate();
};
