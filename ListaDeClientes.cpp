#include "pch.h"
#include "ListaDeClientes.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Lista.h"

void ListaDeClientes::mostrar()
{
	if (this->esVacia())
	{
		cout << "No hay clientes registrados" << endl;
		return;
	}
	Nodo<Cliente*, nullptr>* aux = this->obtenerInicial();
	while (aux != nullptr)
	{
		cout << endl;
		cout << "ID: " << aux->getId() << endl;
		cout << aux->getDato()->descripcion() << endl << endl;
		cout << "----------------------" << endl;
		cout << endl;
		aux = aux->getSiguiente();
	}
	system("pause");
	system("cls");
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
	escribirEnArchivo();
	cout << "Cliente agregado" << endl;
	system("pause");
	system("cls");
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
	escribirEnArchivo();
	cout << "Cliente agregado" << endl;
	system("pause");
	system("cls");
}


int ListaDeClientes::buscar(int id)
{
	Nodo<Cliente*, nullptr>* aux = this->obtenerInicial();
	while (aux != nullptr)
	{
		if (aux->getId() == id)
		{
			cout << endl;
			cout << "ID: " << aux->getId() << endl;
			cout << aux->getDato()->descripcion() << endl << endl;
			cout << "----------------------" << endl;
			cout << endl;
			system("pause");
			system("cls");
			return aux->getId();
		}
		aux = aux->getSiguiente();
	}
	cout << "No se encontro el cliente" << endl;
	system("pause");
	system("cls");
	return 0;
}


int ListaDeClientes::buscarPorDNI(string DNI)
{
	Nodo<Cliente*, nullptr>* aux = this->obtenerInicial();
	while (aux != nullptr)
	{
		if (aux->getDato()->getDNI() == DNI)
		{
			cout << endl;
			cout << "ID: " << aux->getId() << endl;
			cout << aux->getDato()->descripcion() << endl << endl;
			cout << "----------------------" << endl;
			cout << endl;
			system("pause");
			system("cls");
			return aux->getId();
		}
		aux = aux->getSiguiente();
	}
	cout << "No se encontro el cliente" << endl;
	system("pause");
	system("cls");
	return 0;
}


int ListaDeClientes::buscarPorTelefono(string tlf) 
{
	int encontrado = 0;
	Nodo<Cliente*, nullptr>* aux = this->obtenerInicial();
	while (aux != nullptr)
	{
		if (aux->getDato()->getTelefono() == tlf)
		{
			cout << endl;
			cout << "ID: " << aux->getId() << endl;
			cout << aux->getDato()->descripcion() << endl << endl;
			cout << "----------------------" << endl;
			cout << endl;
			system("pause");
			system("cls");
			encontrado++;
		}
		aux = aux->getSiguiente();
	}
	if(encontrado==0)
	{
		cout << "No se encontro el cliente" << endl;
	}
	system("pause");
	system("cls");
	return 0;
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
	this->modificarPorId(nuevoCliente, id);
	escribirEnArchivo();
	cout << "Cliente actualizado" << endl;
	system("pause");
	system("cls");
}


void ListaDeClientes::menu()
{
	int opcion;
	string tlf;
	int id;
	do
	{
		system("cls");
		cout << "1. Registrar cliente" << endl;
		cout << "2. Listar clientes" << endl;
		cout << "3. Consultar cliente por id" << endl;
		cout << "4. Consultar cliente por telefono"<<endl;
		cout << "5. Editar datos del cliente" << endl;
		cout << "6. Eliminar cliente" << endl;
		cout << "7. Agregar cliente random" << endl;
 		cout << "8. Salir" << endl;
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
			break;
		case 3:
			cout << "Ingrese id del cliente a consultar: ";
			cin >> id;
			cout << this->buscar(id);
			break;
		case 4:
			cout << "Ingrese el telefono del cliente a consultar: ";
			cin >> tlf;
			buscarPorTelefono(tlf);
			break;
		case 5:
			cout << "Ingrese id del cliente para actualizar sus datos: ";
			cin >> id;
			actualizarDatos(id);
			break;
		case 6:
			cout << "Ingrese id del cliente para eliminar: ";
			cin >> id;
			this->eliminarPorId(id);
			break;
		case 7:
			agregarClienteRandom();
			cout << "Cliente agregado" << endl;
			break;
		case 8:
			cout << "Saliendo del menu de clientes" << endl;
			break;
		default:
			cout << "Opcion invalida" << endl;
			break;
		}
	} while (opcion != 8);
}


void ListaDeClientes::menuCliente()
{
	ListaDeCuentasBancarias* listaCuentasBancarias = new ListaDeCuentasBancarias();
	listaCuentasBancarias->cargarCuentasBancarias();
	int opcion;
	int idCliente;
	string DNI;
	Nodo<Cliente*>* clienteActual;
	do
	{
		system("cls");
		cout << "1. Identificar al cliente por el DNI" << endl;
		cout << "2. Salir" << endl;
		cout << "Ingrese una opcion: ";
		cin >> opcion;
		system("cls");
		switch (opcion)
		{
		case 1:
			cout << "Ingrese su DNI: ";
			cin >> DNI;
			idCliente = buscarPorDNI(DNI);
			if (idCliente != 0)
			{
                clienteActual = obtenerNodoPorId(idCliente);
				if (clienteActual->getId() != 0) {
					cout << "Cliente identificado" << endl;
					system("pause");
					listaCuentasBancarias->menuCuentasBancariasPorCliente(clienteActual);
				}
			}
			else
			{
				cout << "Cliente no encontrado" << endl;
				system("pause");
			}
			break;
		case 2:
			cout << "Saliendo del menu de cliente" << endl;
			system("pause");
			break;
		default:
			cout << "Opcion invalida" << endl;
			system("pause");
			break;
		}
	} while (opcion != 2);
}


void ListaDeClientes::escribirEnArchivo()
{
	ofstream file("Clientes.csv");
	if (file.is_open()) {
		Nodo<Cliente*, nullptr>* aux = this->obtenerInicial();
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
		cout << "No se pudo abrir el archivo.\n";
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
			if (id != "Id" && id != "id" && id != "ID") {
				Cliente* nuevoCliente = new Cliente(nombre, apellido, direccion, telefono, email, DNI);
				agregarAlFinal(nuevoCliente);
			}
			
		}

		file.close(); // Close the file
	}
	else {
		cout << "No se pudo abrir el archivo.\n";
	}

}