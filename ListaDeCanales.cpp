#include "pch.h"
#include "ListaDeCanales.h"

#include "pch.h"
#include "ListaDeCanales.h"

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
}

void ListaDeCanales::agregarCanal()
{
	string nombre, direccion, ciudad, distrito, departamento, fechaCreacion, fechaModificacion;
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
	cout << "Ingrese la fecha de creacion del canal: ";
	cin >> fechaCreacion;
	cout << "Ingrese la fecha de modificacion del canal: ";
	cin >> fechaModificacion;
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

	Canal* nuevoCanal = new Canal(nombre, direccion, ciudad, distrito, departamento, fechaCreacion, fechaModificacion, true, opcion);
	this->agregarAlFinal(nuevoCanal);
}

void ListaDeCanales::agregarCanalRandom()
{
	string nombre, direccion, ciudad, distrito, departamento, fechaCreacion, fechaModificacion;
	ETipoDeCanal tipoDeCanal;
	//canal aleatorio
	nombre = "Canal" + to_string(rand() % 100);
	direccion = "Direccion" + to_string(rand() % 100);
	ciudad = "Ciudad" + to_string(rand() % 100);
	distrito = "Distrito" + to_string(rand() % 100);
	departamento = "Departamento" + to_string(rand() % 100);
	fechaCreacion = "FechaCreacion" + to_string(rand() % 100);
	fechaModificacion = "FechaModificacion" + to_string(rand() % 100);
	int randomTipoDeCanal = rand() % 5 + 1;
	Canal* nuevoCanal = new Canal(nombre, direccion, ciudad, distrito, departamento, fechaCreacion, fechaModificacion, true, randomTipoDeCanal);
	this->agregarAlFinal(nuevoCanal);
}

bool ListaDeCanales::buscar(int id)
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
			return true;
		}
		aux = aux->getSiguiente();
	}
	cout << "No se encontro el canal" << endl;
	return false;
}

void ListaDeCanales::actualizarDatos(int id)
{
	string nombre, direccion, ciudad, distrito, departamento, fechaCreacion, fechaModificacion;
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
	cout << "Ingrese la fecha de creacion del canal: ";
	cin >> fechaCreacion;
	cout << "Ingrese la fecha de modificacion del canal: ";
	cin >> fechaModificacion;
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
		tipoDeCanal = WEB;
		break;
	case 2:
		tipoDeCanal = APP;
		break;
	case 3:
		tipoDeCanal = VENTANILLA;
		break;
	case 4:
		tipoDeCanal = AGENTE;
		break;
	case 5:
		tipoDeCanal = YAPE;
		break;
	default:
		tipoDeCanal = OTRO;
		break;
	}
	Canal* nuevoCanal = new Canal(nombre, direccion, ciudad, distrito, departamento, fechaCreacion, fechaModificacion, true, tipoDeCanal);
	this->reemplazar(id, nuevoCanal);
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
		cout << "3. Buscar canales" << endl;
		cout << "4. Actualizar canal" << endl;
		cout << "5. Eliminar canal" << endl;
		cout << "6. Agregar canal random" << endl;
		cout << "7. Salir" << endl;
		cout << "Ingrese una opcion: ";
		cin >> opcion;
		system("cls");
		switch (opcion)
		{
		case 1:
			agregarCanal();
			cout << "Canal agregado" << endl;
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
			agregarCanalRandom();
			cout << "Canal agregado" << endl;
			system("pause");
			break;
		case 7:
			cout << "Saliendo del menu de canales" << endl;
			break;
		default:
			cout << "Opcion invalida" << endl;
			break;
		}
	} while (opcion != 7);
}

