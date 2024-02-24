#include "CampoDeBatalla.h"

CampoDeBatalla::CampoDeBatalla() {

}

CampoDeBatalla::~CampoDeBatalla() {
	for (Helicoptero* miHelicoptero : miVector) {
		delete miHelicoptero;
	}

}

void CampoDeBatalla::AgregarHelicóptero(Helicoptero* nuevo) {
	miVector.push_back(nuevo);
}

void CampoDeBatalla::MostrarInformación() {
	for (Helicoptero* miHelicoptero : miVector) {
		cout << miHelicoptero->toString();
	}
}

void CampoDeBatalla::SimularBatalla(Helicoptero* helicoptero1, Helicoptero* helicoptero2) {
	cout << "**Simulacion de batalla**" << endl;
	bool seguir = 1;
	int turno = 1;
	string tipo_arma1 = helicoptero1->GetTipo_arma();
	int MinimoDeBalas1 = 0;
	string Tipo1 = "";
	if (tipo_arma1 == "Misil") {
		MinimoDeBalas1 = 5;
		Tipo1 = ((Helicoptero_H*)helicoptero1)->getmisil();
	}
	else {
		MinimoDeBalas1 = 2;
		Tipo1 = ((Helicoptero_IA*)helicoptero1)->getInteligenciaCohete();
	}
	string tipo_arma2 = helicoptero2->GetTipo_arma();
	int MinimoDeBalas2 = 0;
	string Tipo2 = "";
	if (tipo_arma2 == "Cohete") {
		MinimoDeBalas2 = 2;
		Tipo2 = ((Helicoptero_IA*)helicoptero2)->getInteligenciaCohete();
	}
	else {
		MinimoDeBalas2 = 5;
		Tipo2 = ((Helicoptero_H*)helicoptero2)->getmisil();
	}

	do {
		if (helicoptero1->GetMunicion() >= MinimoDeBalas1 && turno % 2 != 0) {
			cout << "**Turno" << turno << ":**" << endl;
			cout << "* Helicoptero " << helicoptero1->GetNombre() << " ataca a " << helicoptero2->GetNombre() << " con " << tipo_arma1 << " " << Tipo1 << endl;
			cout << "* Deterioro infligido:" << helicoptero1->Atacar() << "%" << endl;
			int damage = helicoptero1->Atacar();
			if (helicoptero2->GetResistencia() - damage>=0) {
				helicoptero2->SetResistencia(helicoptero2->GetResistencia() - damage);
			}
			else {
				helicoptero2->SetResistencia(0);
			}
			cout << "* Resistencia de "<< helicoptero2->GetNombre() <<": "<< helicoptero2->GetResistencia()<<"%"<<endl;
		}
		else {
			seguir = 0;
		}
		if (turno % 2 == 0 && helicoptero2->GetMunicion() >= MinimoDeBalas2) {
			cout << "**Turno " << turno << ":**" << endl;
			cout << "* Helicoptero " << helicoptero2->GetNombre() << " ataca a " << helicoptero1->GetNombre() << " con " << tipo_arma2 << " " << Tipo2 << endl;
			cout << "* Deterioro infligido:" << helicoptero1->Atacar() << "%" << endl;
			int damage = helicoptero1->Atacar();
			if (helicoptero2->GetResistencia() - damage >= 0) {
				helicoptero2->SetResistencia(helicoptero2->GetResistencia() - damage);
			}
			else {
				helicoptero2->SetResistencia(0);
			}
			cout << "* Resistencia de " << helicoptero2->GetNombre() << ": " << helicoptero2->GetResistencia() << "%" << endl;
		}
		else {
			seguir = 0;
		}
		turno++;
	} while (seguir);
}

