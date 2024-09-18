#include "pch.h"
#include "ListaDeClientes.h"

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
		cout << "1. Agregar cliente" << endl;
		cout << "2. Mostrar clientes" << endl;
		cout << "3. Buscar clientes" << endl;
		cout << "4. Actualizar cliente" << endl;
		cout << "5. Eliminar cliente" << endl;
		cout << "6. Agregar cliente random" << endl;
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
