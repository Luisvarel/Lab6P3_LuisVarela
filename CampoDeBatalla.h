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
	void AgregarHelic�ptero(Helicoptero*nuevo);
	void MostrarInformaci�n();
	void SimularBatalla(Helicoptero* helicoptero1, Helicoptero* helicoptero2);
};

