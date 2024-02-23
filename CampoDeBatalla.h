#pragma once
#include "Helicoptero.h"

using namespace std;
class CampoDeBatalla{
private:
	vector<Helicoptero*> miVector;
public:
	CampoDeBatalla();
	~CampoDeBatalla();
	//get y set de miVector
	void AgregarHelicóptero(Helicoptero*nuevo);
	void MostrarInformación();
	void SimularBatalla(Helicoptero* helicoptero1, Helicoptero* helicoptero2);
};

