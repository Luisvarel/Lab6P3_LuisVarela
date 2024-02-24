#include "CampoDeBatalla.h"

CampoDeBatalla::CampoDeBatalla() {
}

CampoDeBatalla::~CampoDeBatalla() {
	for (Helicoptero* miHelicoptero : miVector) {
		delete miHelicoptero;
	}

}

void CampoDeBatalla::AgregarHelicoptero(Helicoptero* nuevo) {
	miVector.push_back(nuevo);
}

void CampoDeBatalla::MostrarInformacion() {
	for (Helicoptero* miHelicoptero : miVector) {
		cout << miHelicoptero->toString();
	}
}

int CampoDeBatalla::tam(){
	return miVector.size();
}

void CampoDeBatalla::SimularBatalla(int num1, int num2) {
	Helicoptero* helicoptero1 = miVector[num1];
	Helicoptero* helicoptero2= miVector[num2];
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
		if (helicoptero1->GetMunicion() >= MinimoDeBalas1 && turno % 2 != 0 && helicoptero1->GetResistencia() > 0) {
			cout << "**Turno" << turno << ":**" << endl;
			cout << "* Helicoptero " << helicoptero1->GetNombre() << " ataca a " << helicoptero2->GetNombre() << " con " << tipo_arma1 << " " << Tipo1 << endl;
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
		else if (helicoptero1->GetMunicion() < MinimoDeBalas1 || helicoptero1->GetResistencia() <= 0) {
			cout << "Victoria" << endl;
			cout << "Helicoptero ganador: " << helicoptero2->GetNombre() << endl;
			seguir = 0;
			break;
		}
		if (turno % 2 == 0 && helicoptero2->GetMunicion() >= MinimoDeBalas2 && helicoptero2->GetResistencia() > 0) {
			cout << "**Turno " << turno << ":**" << endl;
			cout << "* Helicoptero " << helicoptero2->GetNombre() << " ataca a " << helicoptero1->GetNombre() << " con " << tipo_arma2 << " " << Tipo2 << endl;
			cout << "* Deterioro infligido:" << helicoptero2->Atacar() << "%" << endl;
			int damage = helicoptero2->Atacar();
			if (helicoptero1->GetResistencia() - damage >= 0) {
				helicoptero1->SetResistencia(helicoptero1->GetResistencia() - damage);
			}
			else {
				helicoptero1->SetResistencia(0);
			}
			cout << "* Resistencia de " << helicoptero1->GetNombre() << ": " << helicoptero1->GetResistencia() << "%" << endl;
		}
		else if(helicoptero2->GetMunicion() < MinimoDeBalas2 && helicoptero2->GetResistencia() <= 0){
			cout << "Victoria" << endl;
			cout << "Helicoptero ganador: " << helicoptero1->GetNombre() << endl;
			seguir = 0;
			break;
		}
		turno++;
	} while (seguir);
}

