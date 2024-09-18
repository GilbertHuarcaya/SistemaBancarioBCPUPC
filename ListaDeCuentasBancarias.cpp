#include "pch.h"
#include "ListaDeCuentasBancarias.h"
#include <iostream>
#include <fstream>
#include <string>

void ListaDeCuentasBancarias::mostrar()
{
	if (this->esVacia())
	{
		cout << "No hay cuentasbancarias registrados" << endl;
		return;
	}
	Nodo<CuentaBancaria*>* aux = this->obtenerPrimero();
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

void ListaDeCuentasBancarias::agregarCuentaBancaria()
{
	string Contrasenia, NombreCliente, FechaCreacion;
	int idCliente, TipoCuenta;
	cout << "Ingrese el id del Cliente: ";
	cin >> idCliente;
	cout << "Ingrese el telefono del Contrasenia: ";
	cin >> Contrasenia;
	cout << "Ingrese el email del NombreCliente: ";
	cin >> NombreCliente;
	cout << "Ingrese el apellido del cuentabancaria: ";
	cin >> TipoCuenta;
	cout << "Ingrese FechaCreacion: ";
	cin >> FechaCreacion;
	CuentaBancaria* nuevoCuentaBancaria = new CuentaBancaria(Contrasenia, NombreCliente, TipoCuenta, FechaCreacion, idCliente);
	this->agregarAlFinal(nuevoCuentaBancaria);
}

void ListaDeCuentasBancarias::agregarCuentaBancariaRandom()
{
	
	string Contrasenia, NombreCliente, FechaCreacion;
	int idCliente, TipoCuenta;

	nombre = "nombre";
	direccion = "direccion";
	telefono = "telefono";
	email = "email";
	apellido = "apellido";
	int randomDNI = rand() % 90000000 + 10000000; // Generate random 8-digit DNI
	DNI = to_string(randomDNI);
	CuentaBancaria* nuevoCuentaBancaria = new CuentaBancaria(Contrasenia, NombreCliente, TipoCuenta, FechaCreacion, idCliente);
	this->agregarAlFinal(nuevoCuentaBancaria);
}

bool ListaDeCuentasBancarias::buscar(int id)
{
	Nodo<CuentaBancaria*>* aux = this->obtenerPrimero();
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
	cout << "No se encontro el cuentabancaria" << endl;
	return false;
}

bool ListaDeCuentasBancarias::buscarPorIdDeCliente(int idCliente)
{
	Nodo<CuentaBancaria*>* aux = this->obtenerPrimero();
	while (aux != nullptr)
	{
		if (aux->getDato()->getIdCliente() == idCliente)
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
	cout << "No se encontro el cuentabancaria" << endl;
	return false;
}

void ListaDeCuentasBancarias::actualizarDatos(int id)
{
	string Contrasenia, NombreCliente, FechaCreacion;
	int idCliente, TipoCuenta;
	cout << "Ingrese el id del Cliente: ";
	cin >> idCliente;
	cout << "Ingrese el telefono del Contrasenia: ";
	cin >> Contrasenia;
	cout << "Ingrese el email del NombreCliente: ";
	cin >> NombreCliente;
	cout << "Ingrese el apellido del cuentabancaria: ";
	cin >> TipoCuenta;
	cout << "Ingrese FechaCreacion: ";
	cin >> FechaCreacion;
	CuentaBancaria* nuevoCuentaBancaria = new CuentaBancaria(Contrasenia,  NombreCliente,  TipoCuenta,  FechaCreacion,  idCliente);
	this->reemplazar(id, nuevoCuentaBancaria);
}

void ListaDeCuentasBancarias::menu()
{
	int opcion;
	int id;
	do
	{
		system("cls");
		escribirEnArchivo();
		cout << "1. Agregar cuentabancaria" << endl;
		cout << "2. Mostrar cuentasbancarias" << endl;
		cout << "3. Buscar cuentasbancarias" << endl;
		cout << "4. Actualizar cuentabancaria" << endl;
		cout << "5. Eliminar cuentabancaria" << endl;
		cout << "6. Agregar cuentabancaria random" << endl;
		cout << "7. Salir" << endl;
		cout << "Ingrese una opcion: ";
		cin >> opcion;
		system("cls");
		switch (opcion)
		{
		case 1:
			agregarCuentaBancaria();
			cout << "CuentaBancaria agregado" << endl;
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
			agregarCuentaBancariaRandom();
			cout << "CuentaBancaria agregado" << endl;
			system("pause");
			break;
		case 7:
			cout << "Saliendo del menu de cuentasbancarias" << endl;
			break;
		default:
			cout << "Opcion invalida" << endl;
			break;
		}
	} while (opcion != 7);
}

void ListaDeCuentasBancarias::escribirEnArchivo()
{
	ofstream file("CuentasBancarias.csv");
	if (file.is_open()) {
		Nodo<CuentaBancaria*>* aux = this->obtenerPrimero();
		file << "Id,FechaCreacion,IdCliente,NombreCliente,TipoCuenta\n"; // Header
		while (aux != nullptr)
		{
			file << aux->getId() << ","
				<< aux->getDato()->getFechaCreacion() << ","
				<< aux->getDato()->getIdCliente() << ","
				<< aux->getDato()->getNombreCliente() << ","
				<< aux->getDato()->getTipoCuenta() << "\n";
			aux = aux->getSiguiente();
		}
		file.close();
	}
	else {
		cout << "Unable to open file.\n";
	}
}

void ListaDeCuentasBancarias::cargarCuentasBancarias() {
	ifstream file("CuentasBancarias.csv"); // Open file to read

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
				CuentaBancaria* nuevoCuentaBancaria = new CuentaBancaria(nombre, apellido, direccion, telefono, email, DNI);
				agregarAlFinal(nuevoCuentaBancaria);
			}

		}

		file.close(); // Close the file
	}
	else {
		cout << "Unable to open file.\n";
	}

}