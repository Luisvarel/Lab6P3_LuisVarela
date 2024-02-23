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

}

