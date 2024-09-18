#include "pch.h"
#include "ListaDeClientes.h"
#include <iostream>
#include <fstream>
#include <string>

void ListaDeClientes::mostrar()
{
	if (this->esVacia())
	{
		cout << "No hay clientes registrados" << endl;
		return;
	}
	Nodo<Cliente*>* aux = this->obtenerPrimero();
	while (aux != nullptr)
	{
		cout << endl;
		cout << "ID: " << aux->getId() << endl;
		cout << aux->getDato()->descripcion() << endl << endl;
		cout << "----------------------" << endl;
		cout << endl;
		aux = aux->getSiguiente();
	}
}

void ListaDeClientes::agregarCliente()
{
	string nombre, direccion, telefono, email, apellido, DNI;
	cout << "Ingrese el nombre del cliente: ";
	cin >> nombre;
	cout << "Ingrese la direccion del cliente: ";
	cin >> direccion;
	cout << "Ingrese el telefono del cliente: ";
	cin >> telefono;
	cout << "Ingrese el email del cliente: ";
	cin >> email;
	cout << "Ingrese el apellido del cliente: ";
	cin >> apellido;
	cout << "Ingrese el DNI del cliente: ";
	cin >> DNI;
	Cliente* nuevoCliente = new Cliente(nombre, apellido, direccion, telefono, email, DNI);
	this->agregarAlFinal(nuevoCliente);
}

void ListaDeClientes::agregarClienteRandom()
{
    string nombre, direccion, telefono, email, apellido, DNI;
    nombre = "nombre";
    direccion = "direccion";
    telefono = "telefono";
    email = "email";
    apellido = "apellido";
    int randomDNI = rand() % 90000000 + 10000000; // Generate random 8-digit DNI
    DNI = to_string(randomDNI);
    Cliente* nuevoCliente = new Cliente(nombre, apellido, direccion, telefono, email, DNI);
    this->agregarAlFinal(nuevoCliente);
}

bool ListaDeClientes::buscar(int id)
{
	Nodo<Cliente*>* aux = this->obtenerPrimero();
	while (aux != nullptr)
	{
		if (aux->getId() == id)
		{
			cout << endl;
			cout << "ID: " << aux->getId() << endl;
			cout << aux->getDato()->descripcion() << endl << endl;
			cout << "----------------------" << endl;
			cout << endl;
			return true;
		}
		aux = aux->getSiguiente();
	}
	cout << "No se encontro el cliente" << endl;
	return false;
}

bool ListaDeClientes::buscarPorDNI(string DNI)
{
	Nodo<Cliente*>* aux = this->obtenerPrimero();
	while (aux != nullptr)
	{
		if (aux->getDato()->getDNI() == DNI)
		{
			cout << endl;
			cout << "ID: " << aux->getId() << endl;
			cout << aux->getDato()->descripcion() << endl << endl;
			cout << "----------------------" << endl;
			cout << endl;
			return true;
		}
		aux = aux->getSiguiente();
	}
	cout << "No se encontro el cliente" << endl;
	return false;
}

void ListaDeClientes::actualizarDatos(int id)
{
	string nombre, direccion, telefono, email, apellido, DNI;
	cout << "Ingrese el nombre del cliente: ";
	cin >> nombre;
	cout << "Ingrese la direccion del cliente: ";
	cin >> direccion;
	cout << "Ingrese el telefono del cliente: ";
	cin >> telefono;
	cout << "Ingrese el email del cliente: ";
	cin >> email;
	cout << "Ingrese el apellido del cliente: ";
	cin >> apellido;
	cout << "Ingrese el DNI del cliente: ";
	cin >> DNI;
	Cliente* nuevoCliente = new Cliente(nombre, apellido, direccion, telefono, email, DNI);
	this->reemplazar(id, nuevoCliente);
}

void ListaDeClientes::menu()
{
	int opcion;
	int id;
	do
	{
		system("cls");
		escribirEnArchivo();
		cout << "1. Agregar cliente" << endl;
		cout << "2. Mostrar clientes" << endl;
		cout << "3. Buscar clientes" << endl;
		cout << "4. Actualizar cliente" << endl;
		cout << "5. Eliminar cliente" << endl;
		cout << "6. Agregar cliente random" << endl;
		cout << "7. Mostrar cuentas bancarias" << endl;
 		cout << "7. Salir" << endl;
		cout << "Ingrese una opcion: ";
		cin >> opcion;
		system("cls");
		switch (opcion)
		{
		case 1:
			agregarCliente();
			cout << "Cliente agregado" << endl;
			system("pause");
			break;
		case 2:
			mostrar();
			system("pause");
			break;
		case 3:
			cout << "Ingrese id a buscar: ";
			cin >> id;
			cout << this->buscar(id);
			system("pause");
			break;
		case 4:
			cout << "Ingrese id a reemplazar: ";
			cin >> id;
			actualizarDatos(id);
			system("pause");
			break;
		case 5:
			cout << "Ingrese id a eliminar: ";
			cin >> id;
			this->eliminar(id);
			system("pause");
			break;
		case 6:
			agregarClienteRandom();
			cout << "Cliente agregado" << endl;
			system("pause");
			break;
		case 7:
			cout << "Saliendo del menu de clientes" << endl;
			break;
		default:
			cout << "Opcion invalida" << endl;
			break;
		}
	} while (opcion != 7);
}

void ListaDeClientes::escribirEnArchivo()
{
	ofstream file("Clientes.csv");
	if (file.is_open()) {
		Nodo<Cliente*>* aux = this->obtenerPrimero();
		file << "Id,Nombre,Apellido,Direccion,Telefono,Email,DNI\n"; // Header
		while (aux != nullptr)
		{
			file << aux->getId() << ","
				<< aux->getDato()->getNombre() << ","
				<< aux->getDato()->getApellido() << ","
				<< aux->getDato()->getDireccion() << ","
				<< aux->getDato()->getTelefono() << ","
				<< aux->getDato()->getEmail() << ","
				<< aux->getDato()->getDNI() << "\n";
			aux = aux->getSiguiente();
		}
		file.close();
	}
	else {
		cout << "Unable to open file.\n";
	}
}

void ListaDeClientes::cargarClientes() {
	ifstream file("Clientes.csv"); // Open file to read

	if (file.is_open()) {
		string line;

		while (getline(file, line)) {
			string id, nombre, apellido, direccion, telefono, email, DNI;
			int pos = 1;
			// Id,Nombre,Apellido,Direccion,Telefono,Email,DNI 
			// 1, Nombre, Apellido, Direccion, Telefono, Email, DNI
			//ignore the first line and ignore the first col of id for each read
			pos = line.find(",");
			id = line.substr(0, pos);
			line = line.substr(pos + 1);
			pos = line.find(",");
			nombre = line.substr(0, pos);
			line = line.substr(pos + 1);
			pos = line.find(",");
			apellido = line.substr(0, pos);
			line = line.substr(pos + 1);
			pos = line.find(",");
			direccion = line.substr(0, pos);
			line = line.substr(pos + 1);
			pos = line.find(",");
			telefono = line.substr(0, pos);
			line = line.substr(pos + 1);
			pos = line.find(",");
			email = line.substr(0, pos);
			line = line.substr(pos + 1);
			DNI = line;
			if (id != "Id" && id != "id") {
				Cliente* nuevoCliente = new Cliente(nombre, apellido, direccion, telefono, email, DNI);
				agregarAlFinal(nuevoCliente);
			}
			
		}

		file.close(); // Close the file
	}
	else {
		cout << "Unable to open file.\n";
	}

}