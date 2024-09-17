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

    // Métodos de acceso
    int getId();
    string getName();
    string getAdress();
    string getPhone();

    // Métodos de manipulación
    void updateName(string name);
    void updateAdress(string adress);
    void updatePhone(string phone);
    void activate();
    void deactivate();
};
int Sede::getId() { return id;}
string Sede::getName() { return name;}
string Sede::getAdress() { return adress;}
string Sede::getPhone() { return phone;}
void Sede::updateName(string name) { this->name = name;}
void Sede::updateAdress(string adress) { this->adress = adress;}
void Sede::updatePhone(string phone) { this->phone = phone;}