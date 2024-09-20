#include "pch.h"
#include "ListaDeCanales.h"
#include <fstream>

void ListaDeCanales::mostrar()
{
	if (this->esVacia())
	{
		cout << "No hay canales registrados" << endl;
		return;
	}
	Nodo<Canal*>* aux = this->obtenerPrimero();
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

void ListaDeCanales::agregarCanal()
{
	string nombre, direccion, ciudad, distrito, departamento;
	ETipoDeCanal tipoDeCanal;
	cout << "Ingrese el nombre del canal: ";
	cin >> nombre;
	cout << "Ingrese la direccion del canal: ";
	cin >> direccion;
	cout << "Ingrese la ciudad del canal: ";
	cin >> ciudad;
	cout << "Ingrese el distrito del canal: ";
	cin >> distrito;
	cout << "Ingrese el departamento del canal: ";
	cin >> departamento;
	int opcion;
	do {
		cout << "Ingrese el tipo de canal: " << endl;
		cout << "1. WEB" << endl;
		cout << "2. APP" << endl;
		cout << "3. VENTANILLA" << endl;
		cout << "4. AGENTE" << endl;
		cout << "5. YAPE" << endl;
		cin >> opcion;
	} while (opcion < 1 || opcion > 5);

	Canal* nuevoCanal = new Canal(nombre, direccion, ciudad, distrito, departamento, true, opcion);
	this->agregarAlFinal(nuevoCanal);
	escribirEnArchivo();
	cout << "Canal agregado" << endl;
	system("pause");
	system("cls");
}

void ListaDeCanales::agregarCanalRandom()
{
	string nombre, direccion, ciudad, distrito, departamento;
	ETipoDeCanal tipoDeCanal;
	//canal aleatorio
	nombre = "Canal" + to_string(rand() % 100);
	direccion = "Direccion" + to_string(rand() % 100);
	ciudad = "Ciudad" + to_string(rand() % 100);
	distrito = "Distrito" + to_string(rand() % 100);
	departamento = "Departamento" + to_string(rand() % 100);
	int randomTipoDeCanal = rand() % 5 + 1;
	Canal* nuevoCanal = new Canal(nombre, direccion, ciudad, distrito, departamento, true, randomTipoDeCanal);
	this->agregarAlFinal(nuevoCanal);
	escribirEnArchivo();
	cout << "Canal agregado" << endl;
	system("pause");
	system("cls");
}

int ListaDeCanales::buscar(int id)
{
	Nodo<Canal*>* aux = this->obtenerPrimero();
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
	cout << "No se encontro el canal" << endl;
	system("pause");
	system("cls");
	return 0;
}

int ListaDeCanales::buscarPorTipo(ETipoDeCanal tipoDeCanal)
{
	Nodo<Canal*>* aux = this->obtenerPrimero();
	int encontrados = 0;
	while (aux != nullptr)
	{
		if (aux->getDato()->getTipoDeCanal() == tipoDeCanal)
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
	if (encontrados == 0)
	{
		cout << "No se encontro ningun canal en ese tipo" << endl;
	}
	return encontrados;
}

int ListaDeCanales::buscarPorNombre(string nombre)
{
	Nodo<Canal*>* aux = this->obtenerPrimero();
	int encontrados = 0;
	while (aux != nullptr)
	{
		if (aux->getDato()->getNombre() == nombre)
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
	if (encontrados == 0)
	{
		cout << "No se encontro ningun canal en ese nombre" << endl;
	}
	return encontrados;
}

int ListaDeCanales::buscarPorDistrito(string distrito)
{
	Nodo<Canal*>* aux = this->obtenerPrimero();
	int encontrados = 0;
	while (aux != nullptr)
	{
		if (aux->getDato()->getDistrito() == distrito)
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
	if (encontrados == 0)
	{
		cout << "No se encontro ningun canal en ese distrito" << endl;
	}
	return encontrados;
}

int ListaDeCanales::buscarPorDepartamento(string departamento)
{
	Nodo<Canal*>* aux = this->obtenerPrimero();
	int encontrados = 0;
	while (aux != nullptr)
	{
		if (aux->getDato()->getDepartamento() == departamento)
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
	if (encontrados == 0)
	{
		cout << "No se encontro ningun canal en ese Departamento" << endl;
	}
	return encontrados;
}

int ListaDeCanales::buscarPorCiudad(string ciudad)
{
	Nodo<Canal*>* aux = this->obtenerPrimero();
	int encontrados = 0;
	while (aux != nullptr)
	{
		if (aux->getDato()->getCiudad() == ciudad)
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
	if (encontrados == 0)
	{
		cout << "No se encontro ningun canal en esa Ciudad" << endl;
	}
	return encontrados;
}

int ListaDeCanales::buscarPorActivo(bool activo)
{
	Nodo<Canal*>* aux = this->obtenerPrimero();
	int encontrados = 0;
	while (aux != nullptr)
	{
		if (aux->getDato()->getActivo() == activo)
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
	if (encontrados == 0)
	{
		cout << "No se encontro ningun canal con ese estado" << endl;
	}
	return encontrados;
}

void ListaDeCanales::actualizarDatos(int id)
{
	string nombre, direccion, ciudad, distrito, departamento;
	ETipoDeCanal tipoDeCanal;
	cout << "Ingrese el nombre del canal: ";
	cin >> nombre;
	cout << "Ingrese la direccion del canal: ";
	cin >> direccion;
	cout << "Ingrese la ciudad del canal: ";
	cin >> ciudad;
	cout << "Ingrese el distrito del canal: ";
	cin >> distrito;
	cout << "Ingrese el departamento del canal: ";
	cin >> departamento;
	cout << "Ingrese el tipo de canal: " << endl;
	cout << "1. WEB" << endl;
	cout << "2. APP" << endl;
	cout << "3. VENTANILLA" << endl;
	cout << "4. AGENTE" << endl;
	cout << "5. YAPE" << endl;

	int opcion;
	cin >> opcion;
	switch (opcion)
	{
	case 1:
		tipoDeCanal = VENTANILLA;
		break;
	case 2:
		tipoDeCanal = AGENTE;
		break;
	case 3:
		tipoDeCanal = WEB;
		break;
	case 4:
		tipoDeCanal = APP;
		break;
	case 5:
		tipoDeCanal = YAPE;
		break;
	default:
		tipoDeCanal = OTROCANAL;
		break;
	}
	Canal* nuevoCanal = new Canal(nombre, direccion, ciudad, distrito, departamento, true, tipoDeCanal);
	this->reemplazar(id, nuevoCanal);
	escribirEnArchivo();
	cout << "Canal actualizado" << endl;
	system("pause");
	system("cls");
}

void ListaDeCanales::menu()
{
	int opcion;
	int id;
	do
	{
		system("cls");
		cout << "1. Agregar canal" << endl;
		cout << "2. Mostrar canales" << endl;
		cout << "3. Buscar canal" << endl;
		cout << "4. Actualizar canal" << endl;
		cout << "5. Eliminar canal" << endl;
		cout << "6. Agregar canal random" << endl;
		cout << "7. Mostrar Ventanillas" << endl;
		cout << "8. Mostrar Agentes" << endl;
		cout << "9. Salir" << endl;
		cout << "Ingrese una opcion: ";
		cin >> opcion;
		system("cls");
		switch (opcion)
		{
		case 1:
			agregarCanal();
			cout << "Canal agregado" << endl;
			break;
		case 2:
			mostrar();
			break;
		case 3:
			cout << "Ingrese id a buscar: ";
			cin >> id;
			cout << this->buscar(id);
			break;
		case 4:
			cout << "Ingrese id a reemplazar: ";
			cin >> id;
			actualizarDatos(id);
			break;
		case 5:
			cout << "Ingrese id a eliminar: ";
			cin >> id;
			this->eliminar(id);
			break;
		case 6:
			agregarCanalRandom();
			cout << "Canal agregado" << endl;
			break;
		case 7:
			buscarPorTipo(VENTANILLA);
			break;
		case 8:
			buscarPorTipo(AGENTE);
			break;

		case 9:
			cout << "Saliendo del menu de canales" << endl;
			break;
		default:
			cout << "Opcion invalida" << endl;
			break;
		}
	} while (opcion != 9);
}

void ListaDeCanales::escribirEnArchivo()
{
	ofstream file("Canales.csv");
	if (file.is_open()) {
		Nodo<Canal*>* aux = this->obtenerPrimero();
		file << "Id,Nombre,Direccion,Ciudad,Distrito,Departamento,Activo,TipoDeCanal\n";

		while (aux != nullptr)
		{
			file << aux->getId() << ","
				<< aux->getDato()->getNombre() << ","
				<< aux->getDato()->getDireccion() << ","
				<< aux->getDato()->getCiudad() << ","
				<< aux->getDato()->getDistrito() << ","
				<< aux->getDato()->getDepartamento() << ","
				<< aux->getDato()->getActivo() << ","
				<< aux->getDato()->getTipoDeCanal() << "\n";

			aux = aux->getSiguiente();
		}
		file.close();
	}
	else {
		cout << "No se pudo abrir el archivo.\n";
	}
}

void ListaDeCanales::cargarCanales() {
	ifstream file("Canales.csv"); // Open file to read

	if (file.is_open()) {
		string line;

		while (getline(file, line)) {
			string id, nombre, direccion, ciudad, distrito, departamento, tipoDeCanal, activo;
			int pos = 1;
			// ID,Nombre,Direccion,Ciudad,Distrito,Departamento,Activo,TipoDeCanal
			pos = line.find(",");
			id = line.substr(0, pos);
			line = line.substr(pos + 1);
			pos = line.find(",");
			nombre = line.substr(0, pos);
			line = line.substr(pos + 1);
			pos = line.find(",");
			direccion = line.substr(0, pos);
			line = line.substr(pos + 1);
			pos = line.find(",");
			ciudad = line.substr(0, pos);
			line = line.substr(pos + 1);
			pos = line.find(",");
			distrito = line.substr(0, pos);
			line = line.substr(pos + 1);
			pos = line.find(",");
			departamento = line.substr(0, pos);
			line = line.substr(pos + 1);
			pos = line.find(",");
			activo = line.substr(0, pos);
			line = line.substr(pos + 1);
			tipoDeCanal = line;

			//convertir string a int and do not use stoi
			ETipoDeCanal tipoDeCanalInt = WEB;
			if (tipoDeCanal == "1") {
				tipoDeCanalInt = VENTANILLA;
			}
			else if (tipoDeCanal == "2") {
				tipoDeCanalInt = AGENTE;
			}
			else if (tipoDeCanal == "3") {
				tipoDeCanalInt = WEB;
			}
			else if (tipoDeCanal == "4") {
				tipoDeCanalInt = APP;
			}
			else if (tipoDeCanal == "5") {
				tipoDeCanalInt = YAPE;
			}
			else {
				tipoDeCanalInt = OTROCANAL;
			}

			//convertir string a bool
			bool activoBool = activo == "1" ? true : false;

			if (id != "Id" && id != "id" && id != "ID") {
				Canal* nuevoCanal = new Canal(nombre, direccion, ciudad, distrito, departamento, activoBool, tipoDeCanalInt);
				agregarAlFinal(nuevoCanal);
			}
		}

		file.close(); // Close the file
	}
	else {
		cout << "No se pudo abrir el archivo.\n";
	}

}

