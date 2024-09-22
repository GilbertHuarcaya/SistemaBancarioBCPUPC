#include "pch.h"
#include "ListaDeCuentasBancarias.h"
#include <iostream>
#include <fstream>
#include <string>
#include "DatosRandom.h"
#include "ListaDeTarjetas.h"

void ListaDeCuentasBancarias::mostrar()
{
	if (this->esVacia())
	{
		cout << "No hay cuentasbancarias registradas" << endl;
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
	system("pause");
}

void ListaDeCuentasBancarias::agregarCuentaBancaria()
{
	string Contrasenia, NombreCliente, ApellidoCliente, FechaCreacion;
	int idCliente, TipoCuenta;
	cout << "Ingrese el id del Cliente: ";
	cin >> idCliente;
	cout << "Ingrese la Contrasenia de la Cuenta Bancaria: ";
	cin >> Contrasenia;
	cout << "Ingrese el Nombre del cliente de la Cuenta Bancaria: ";
	cin >> NombreCliente;
	cout << "Ingrese el Apellido del cliente: ";
	cin >> ApellidoCliente;
	cout << "Ingrese el Tipo de Cuenta: \n";
	cout << "(1:CREDITO, 2:DEBITO, 3:OTRO)\n";
	cin >> TipoCuenta;
	cout << "Ingrese la Fecha de creacion de la Cuenta Bancaria: ";
	cin >> FechaCreacion;
	CuentaBancaria* nuevoCuentaBancaria = new CuentaBancaria(Contrasenia, NombreCliente, ApellidoCliente, TipoCuenta, FechaCreacion, idCliente);
	this->agregarAlFinal(nuevoCuentaBancaria);
	escribirEnArchivo();
	cout << "Cuenta agregada correctamente.\n";
	system("pause");
	system("cls");
}

void ListaDeCuentasBancarias::agregarCuentaBancariaPorIdDelCliente(int idCliente)
{
	string Contrasenia, NombreCliente, ApellidoCliente, FechaCreacion;
	int TipoCuenta;
	cout << "Ingrese la Contrasenia de la Cuenta Bancaria: ";
	cin >> Contrasenia;
	cout << "Ingrese el Nombre del cliente de la Cuenta Bancaria: ";
	cin >> NombreCliente;
	cout << "Ingrese el Apellido del cliente: ";
	cin >> ApellidoCliente;
	cout << "Ingrese el Tipo de Cuenta: \n";
	cout << "(1:CREDITO, 2:DEBITO, 3:OTRO)\n";
	cin >> TipoCuenta;
	cout << "Ingrese la Fecha de creacion de la Cuenta Bancaria: ";
	cin >> FechaCreacion;
	CuentaBancaria* nuevoCuentaBancaria = new CuentaBancaria(Contrasenia, NombreCliente, ApellidoCliente, TipoCuenta, FechaCreacion, idCliente);
	agregarAlFinal(nuevoCuentaBancaria);
	cout << "Cuenta agregada correctamente.\n";
}

void ListaDeCuentasBancarias::agregarCuentaBancariaPorCliente(Nodo<Cliente*>* clienteActual)
{
	string Contrasenia, FechaCreacion;
	int TipoCuenta;
	cout << "Ingrese el Tipo de Cuenta: \n";
	cout << "(1:CREDITO, 2:DEBITO, 3:OTRO)\n";
	cin >> TipoCuenta;
	cout << "Ingrese la Contrasenia de la Cuenta Bancaria: ";
	cin >> Contrasenia;
	cout << "Ingrese la Fecha de creacion de la Cuenta Bancaria: ";
	cin >> FechaCreacion;
	CuentaBancaria* nuevoCuentaBancaria = new CuentaBancaria(Contrasenia, clienteActual->getDato()->getNombre(), clienteActual->getDato()->getApellido(), TipoCuenta, FechaCreacion, clienteActual->getId());
	agregarAlFinal(nuevoCuentaBancaria);
	cout << "Cuenta agregada correctamente.\n";
}

void ListaDeCuentasBancarias::agregarCuentaBancariaRandom()
{
	string Contrasenia, NombreCliente, ApellidoCliente, FechaCreacion;
	int idCliente, TipoCuenta;

	Contrasenia = generar_telefono();
	NombreCliente = generar_nombre();
	ApellidoCliente = generar_nombre();
	FechaCreacion = "09/24";
	idCliente = 0;
	TipoCuenta = 1;
	CuentaBancaria* nuevoCuentaBancaria = new CuentaBancaria(Contrasenia, NombreCliente, ApellidoCliente, TipoCuenta, FechaCreacion, idCliente);
	agregarAlFinal(nuevoCuentaBancaria);
	cout << "Cuenta agregada correctamente.\n";
}

void ListaDeCuentasBancarias::agregarCuentaBancariaRandomPorIdDeCliente(int idCliente)
{
	string Contrasenia, NombreCliente, ApellidoCliente, FechaCreacion;
	int TipoCuenta;

	Contrasenia = generar_telefono();
	NombreCliente = generar_nombre();
	ApellidoCliente = generar_nombre();
	FechaCreacion = "09/24";
	TipoCuenta = 1;
	CuentaBancaria* nuevoCuentaBancaria = new CuentaBancaria(Contrasenia, NombreCliente, ApellidoCliente, TipoCuenta, FechaCreacion, idCliente);
	this->agregarAlFinal(nuevoCuentaBancaria);
	cout << "Cuenta agregada correctamente.\n";
}

int ListaDeCuentasBancarias::buscar(int id)
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
			system("pause");
			system("cls");
			return aux->getId();
		}
		aux = aux->getSiguiente();
	}
	cout << "No se encontro la Cuenta Bancaria" << endl;
	return 0;
}

void ListaDeCuentasBancarias::listarPorIdDeCliente(int idCliente)
{
	int encontrados = 0;
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
			encontrados++;
		}
		aux = aux->getSiguiente();
	}
	if (encontrados == 0) {
		cout << "No se encontro la Cuenta Bancaria" << endl;
	}
	system("pause");
}

int ListaDeCuentasBancarias::buscarPorIdDeTarjeta(int idTarjeta)
{
	Nodo<CuentaBancaria*>* aux = this->obtenerPrimero();
	while (aux != nullptr)
	{
		if (aux->getDato()->getIdTarjeta() == idTarjeta)
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
	cout << "No se encontro la Cuenta Bancaria" << endl;
	return 0;
}

void ListaDeCuentasBancarias::actualizarDatos(int id)
{
	Nodo<CuentaBancaria*> aux;
	string Contrasenia, NombreCliente, ApellidoCliente, FechaCreacion;
	int idCliente=0, TipoCuenta;
	cout << "Ingrese la Contrasenia de la Cuenta Bancaria: ";
	cin >> Contrasenia;
	cout << "Ingrese el Nombre del cliente: ";
	cin >> NombreCliente;
	cout << "Ingrese el Apellido del cliente: ";
	cin >> ApellidoCliente;
	cout << "Ingrese el Tipo de Cuenta de la Cuenta Bancaria: \n";
	cout << "(1: CREDITO, 2: DEBITO, 3: OTRO";
	cin >> TipoCuenta;
	cout << "Ingrese la Fecha de creacion de la Cuenta Bancaria: ";
	cin >> FechaCreacion;
	CuentaBancaria* nuevoCuentaBancaria = new CuentaBancaria(Contrasenia,  NombreCliente, ApellidoCliente,  TipoCuenta,  FechaCreacion,  idCliente);
	reemplazar(id, nuevoCuentaBancaria);
	cout << "Se reemplazo correctamente los datos.\n";
}

void ListaDeCuentasBancarias::menu()
{
	int aux;
	int opcion;
	int id;
	do
	{
		system("cls");
		escribirEnArchivo();
		cout << "1. Listar Cuentas Bancarias" << endl;
		cout << "2. Consultar Cuenta Bancaria" << endl;
		cout << "3. Eliminar Cuenta Bancaria" << endl;
		cout << "4. Listar Cuentas Bancarias por Id del Cliente" << endl;
		cout << "5. Listar Cuentas Bancarias por Tipo de Cuenta:" << endl;
		cout << "6. Salir" << endl;
		cout << "Ingrese una opcion: ";
		cin >> opcion;
		system("cls");
		switch (opcion)
		{
		case 1:
			mostrar();
			break;
		case 2:
			cout << "Ingrese id de la Cuenta Bancaria a buscar: ";
			cin >> id;
			cout << this->buscar(id);
			break;
		case 3:
			cout << "Ingrese id de la Cuenta Bancaria a eliminar: ";
			cin >> id;
			this->eliminar(id);
			break;
		case 4:
			cout << "Ingrese el id del cliente: ";
			cin >> id;
			listarPorIdDeCliente(id);
			break;
		case 5:
		{
			ETipoCuenta TipoCuentaEnum;
			cout << "Ingrese el tipo de cuenta que desea buscar: \n";
			cout << "(1: DEBITO, 2:CREDITO, 3: OTRO)\n";
			cin >> aux;
			switch (aux) {
			case 1:
				TipoCuentaEnum = DEBITO;
				break;
			case 2:
				TipoCuentaEnum = CREDITO;
				break;
			default:
				TipoCuentaEnum = OTRACUENTA;
				break;
			}
			buscarPorTipoCuenta(TipoCuentaEnum);
			break;
		}
		case 6:
			cout << "Saliendo del menu de cuentas bancarias" << endl;
			break;
		default:
			cout << "Opcion invalida" << endl;
			break;
		}
	} while (opcion != 6);
}

void ListaDeCuentasBancarias::menuCuentasBancariasPorCliente(Nodo<Cliente*>* clienteActual)
{
	Nodo<CuentaBancaria*>* cuentaBancariaActual;
	int opcion;
	int idCuentaBancaria;

	do
	{
		system("cls");
		escribirEnArchivo();
		cout << "1. Agregar una Cuenta Bancaria al Cliente" << endl;
		cout << "2. Mostrar las Cuentas Bancarias del Cliente" << endl;
		cout << "3. Acceder a la Cuenta Bancaria del Cliente" << endl;
		cout << "4. Eliminar una Cuenta Bancaria del Cliente" << endl;
		cout << "5. Agregar Cuenta Bancaria Random al Cliente" << endl;
		cout << "6. Salir" << endl;
		cout << "Ingrese una opcion: ";
		cin >> opcion;
		system("cls");
		switch (opcion)
		{
		case 1:
			agregarCuentaBancariaPorCliente(clienteActual);
			cout << "Cuenta Bancaria agregada" << endl;
			system("pause");
			break;
		case 2:
			listarPorIdDeCliente(clienteActual->getId());
			break;
		case 3:
			cout << "Ingrese id de su cuenta bancaria: ";
			cin >> idCuentaBancaria;
			cuentaBancariaActual = obtenerNodoPorId(idCuentaBancaria);

			if (cuentaBancariaActual->getId() != 0) {
				if (cuentaBancariaActual->getDato()->getIdCliente() == clienteActual->getId()) {
					menuCuentaBancariaIndividual(cuentaBancariaActual);
				}
				else {
					cout << "No se puede acceder a una cuenta bancaria que no es tuya" << endl;
					system("pause");
				}
			} else {
				cout << "No existe esta cuenta" << endl;
				system("pause");
			}
			break;
		case 4:
			cout << "Ingrese id de su cuenta bancaria a eliminar: ";
			cin >> idCuentaBancaria;
			cuentaBancariaActual = obtenerNodoPorId(idCuentaBancaria);
			if (cuentaBancariaActual->getId() != 0) {

				if (cuentaBancariaActual->getDato()->getIdCliente() == clienteActual->getId()) {
					eliminar(idCuentaBancaria);
				}
				else {
					cout << "No se puede acceder a una cuenta bancaria que no es tuya" << endl;
					system("pause");
				}
			}
			else {
				cout << "No existe esta cuenta" << endl;
				system("pause");
			}
			break;
		case 5:
			agregarCuentaBancariaRandomPorIdDeCliente(clienteActual->getId());
			break;
		case 6:
			cout << "Saliendo del menu de clientes" << endl;
			break;
		default:
			cout << "Opcion invalida" << endl;
			break;
		}
	} while (opcion != 6);
}

void ListaDeCuentasBancarias::menuCuentaBancariaIndividual(Nodo<CuentaBancaria*>* cuentaBancariaActual)
{
	ListaDeTarjetas* listaTarjetas = new ListaDeTarjetas();
	listaTarjetas->cargarTarjetas();
	int opcion;
	int idCuentaBancaria;
	int idTarjeta;
	Nodo<Tarjeta*>* tarjetaActual;
	if (cuentaBancariaActual->getDato()->getIdTarjeta() != 0) {
		do
		{
			system("cls");
			cout << "1. Acceder a la Tarjeta de la Cuenta Bancaria" << endl;
			cout << "2. Mostrar la Tarjeta de la Cuenta Bancaria" << endl;
			cout << "3. Eliminar la Tarjeta de la Cuenta Bancaria" << endl;
			cout << "4. Renovar la Tarjeta de la Cuenta Bancaria" << endl;
			cout << "5. Salir" << endl;
			cout << "Ingrese una opcion: ";
			cin >> opcion;
			system("cls");
			switch (opcion)
			{
			case 1:			
				tarjetaActual = listaTarjetas->obtenerNodoPorId(cuentaBancariaActual->getDato()->getIdTarjeta());
				if (tarjetaActual->getId() != 0) {
					listaTarjetas->menuTarjetaIndividual(tarjetaActual);
				}
				else {
					cout << "No se encontro la tarjeta" << endl;
				}
				break;
			case 2:
				listaTarjetas->obtenerIdDeTarjetaPorIdDeCuentaBancaria(cuentaBancariaActual->getId());
				break;
			case 3:
				cuentaBancariaActual->getDato()->setIdTarjeta(0);
				system("pause");
				system("cls");
				return;
				break;
			case 4:
				//TODO
				break;
			case 5:
				cout << "Saliendo del menu de Cuentas Bancarias" << endl;
				break;
			default:
				cout << "Opcion invalida" << endl;
				break;
			}
		} while (opcion != 5);
	}
	else {
		do
		{
			system("cls");
			cout << "1. Agregar una Tarjeta" << endl;
			cout << "2. Agregar una Tarjeta Random" << endl;
			cout << "3. Salir" << endl;
			cout << "Ingrese una opcion: ";
			cin >> opcion;
			system("cls");
			switch (opcion)
			{
			case 1:
				if (cuentaBancariaActual->getDato()->getIdTarjeta() == 0) {
					listaTarjetas->agregarTarjetaPorCuentaBancaria(cuentaBancariaActual);
					idTarjeta = listaTarjetas->obtenerIdDeTarjetaPorIdDeCuentaBancaria(cuentaBancariaActual->getId());
					cuentaBancariaActual->getDato()->setIdTarjeta(idTarjeta);
					escribirEnArchivo();
					cout << "Tarjeta agregada" << endl;
				}
				else {
					cout << "Ya tienes una tarjeta asociada a esta cuenta bancaria" << endl;
				}
				system("pause");
				system("cls");
				return;
				break;
			case 2:
				if (cuentaBancariaActual->getDato()->getIdTarjeta() == 0) {
					listaTarjetas->agregarTarjetaRandomPorCuentaBancaria(cuentaBancariaActual);
					idTarjeta = listaTarjetas->obtenerIdDeTarjetaPorIdDeCuentaBancaria(cuentaBancariaActual->getId());
					cuentaBancariaActual->getDato()->setIdTarjeta(idTarjeta);
					escribirEnArchivo();
					cout << "Tarjeta agregada" << endl;
				}
				else {
					cout << "Ya tienes una tarjeta asociada a esta cuenta bancaria" << endl;
				}
				system("pause");
				system("cls");
				return;
				break;
			case 3:
				cout << "Saliendo del menu de cuenta bancaria" << endl;
				break;
			default:
				cout << "Opcion invalida" << endl;
				break;
			}
		} while (opcion != 3);
	}

}

void ListaDeCuentasBancarias::escribirEnArchivo()
{
	ofstream file("CuentasBancarias.csv");
	if (file.is_open()) {
		Nodo<CuentaBancaria*>* aux = this->obtenerPrimero();
		file << "Id,NombreCliente,ApellidoCliente,IdCliente,idTarjeta,TipoCuenta,Contrasenia,FechaCreacion,\n"; // Header
		while (aux != nullptr)
		{
			file << aux->getId() << ","
				<< aux->getDato()->getNombreCliente() << ","
				<< aux->getDato()->getApellidoCliente() << ","
				<< aux->getDato()->getIdCliente() << ","
				<< aux->getDato()->getIdTarjeta() << ","
				<< aux->getDato()->getTipoCuenta() << ","
				<< aux->getDato()->getContrasenia() << ","
				<< aux->getDato()->getFechaCreacion() << "\n";
			aux = aux->getSiguiente();
		}
		file.close();
	}
	else {
		cout << "No se pudo abrir el archivo.\n";
	}
}

void ListaDeCuentasBancarias::cargarCuentasBancarias() {
	ifstream file("CuentasBancarias.csv"); // Abre archivo
	if (file.is_open()) {
		string line;
		getline(file, line);//Ignora primera linea 
		while (getline(file, line)) {
			int id, IdCliente, idTarjeta, TipoCuenta;
			string Contrasenia,FechaCreacion, NombreCliente, ApellidoCliente;
			int pos = 1;
			// Id,Contrasenia,FechaCreacion,IdCliente,NombreCliente,TipoCuenta
			//Esto es un
			pos = line.find(",");
			id = stoi(line.substr(0, pos));
			line = line.substr(pos + 1);
			//solo tramo de busqueda, repetir cuantas veces sea necesario
			pos = line.find(",");
			NombreCliente = line.substr(0, pos);
			line = line.substr(pos + 1);
			pos = line.find(",");
			ApellidoCliente = line.substr(0, pos);
			line = line.substr(pos + 1);
			pos = line.find(",");
			IdCliente = stoi(line.substr(0, pos));
			line = line.substr(pos + 1);
			pos = line.find(",");
			idTarjeta = stoi(line.substr(0, pos));
			line = line.substr(pos + 1);
			pos = line.find(",");
			TipoCuenta = stoi(line.substr(0, pos));
			line = line.substr(pos + 1);
			pos = line.find(",");
			Contrasenia = line.substr(0, pos);
			line = line.substr(pos + 1);
			pos = line.find(",");
			FechaCreacion = line.substr(0, pos);
			line = line.substr(pos + 1);
			CuentaBancaria* nuevoCuentaBancaria = new CuentaBancaria(Contrasenia,NombreCliente,ApellidoCliente,TipoCuenta,FechaCreacion,IdCliente,idTarjeta);
			agregarAlFinal(nuevoCuentaBancaria);
		}
		file.close(); // Cierra archivo
		cout << "Cuentas cargadas correctamente.\n";
	}
	else {
		cout << "No se pudo abrir el archivo.\n";
	}

}

void ListaDeCuentasBancarias::buscarPorTipoCuenta(ETipoCuenta tipoDeCuenta) {
	Nodo<CuentaBancaria*>* aux = this->obtenerPrimero();
	while (aux != nullptr) {
		if (aux->getDato()->getTipoCuenta() == tipoDeCuenta) {
			cout << endl;
			cout << "ID: " << aux->getId()<<endl;
			cout << aux->getDato()->descripcion() << endl;
		}
		aux = aux->getSiguiente();
		cout << "Cuenta(s) Bancaria(s) encontrada(s)\n";
		return;
	}
	cout << "No se encontro ninguna Cuenta Bancaria\n";
}