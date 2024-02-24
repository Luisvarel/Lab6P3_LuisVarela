#pragma once
#include "Helicoptero.h"
#include "Helicoptero_H.h"
#include "Helicoptero_IA.h"

using namespace std;
class CampoDeBatalla{
private:
	vector<Helicoptero*> miVector;
public:
	CampoDeBatalla();
	~CampoDeBatalla();
	//get y set de miVector
	void AgregarHelicoptero(Helicoptero*nuevo);
	void MostrarInformacion();
	int tam();
	void SimularBatalla(int num1, int num2);
};

