#include "CampoDeBatalla.h"

CampoDeBatalla::CampoDeBatalla(){

}

CampoDeBatalla::~CampoDeBatalla(){
	for (Helicoptero* miHelicoptero : miVector) {
		delete miHelicoptero;
	}

}

void CampoDeBatalla::AgregarHelicóptero(Helicoptero* nuevo){
	miVector.push_back(nuevo);
}

void CampoDeBatalla::MostrarInformación(){
	for (Helicoptero* miHelicoptero : miVector) {
		cout << miHelicoptero->toString();
	}
}

void CampoDeBatalla::SimularBatalla(Helicoptero* helicoptero1, Helicoptero* helicoptero2){
	bool seguir = 1;
	int turno = 1;
	do{
		if (helicoptero1->GetMunicion()>5 && turno % 2 != 0) {

		}
		else {

		}
		if (turno % 2 == 0 && helicoptero2->GetMunicion()) {

		}else {

		}
		turno++;
	} while (seguir);
}

