#include "Helicoptero_H.h"
void Agregar() {

}

void MostrarInfo() {

}

void Simular() {

}

void menu() {
	bool seguir = 1;
	do {
		cout << "1.Agregar Helicopteros" << endl;
		cout << "2.Mostrar información de helicópteros" << endl;
		cout << "3.Simular Batalla" << endl;
		cout << "4.Salir" << endl;
		int opcion = 0;
		cin >> opcion;
		switch (opcion) {
		case 1: {
			Agregar();
			break;
		}
		case 2: {
			MostrarInfo();
			break;
		}
		case 3: {
			Simular();
			break;
		}
		case 4: {
			seguir = 0;
			break;
		}
		default:
			cout << "Error"<<endl;
			break;
		}
	} while (seguir);
}

int main() {
	menu();
}
