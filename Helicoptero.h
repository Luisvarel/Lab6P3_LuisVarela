#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Helicoptero {
private:
	string Nombre = "";
	string tipo_arma = "";
	//Cohete o Misil
	int Velocidad = 0;
	//100-400
	double Resistencia = 0;
	/*
	 se puede decir que es el porcentaje de vida de cada helic�ptero, y su
	 valor se encuentra en un rango entre 100-200
	*/
	int Municion = 0;
	//rango entre 5 y 30 

public:
	~Helicoptero();
	Helicoptero();
	Helicoptero(string Nombre, string tipo_arma, int Velocidad, double Resistencia, int Municion);
	virtual string toString()=0;
	virtual double Atacar()=0;

	//get y set de Nombre
	string GetNombre();
	void SetNombre(string Nombre);
	//get y set de tipo_arma
	string GetTipo_arma();
	void SetTipo_arma(string tipo_arma);
	//get y set de Velocidad
	int GetVelocidad();
	void SetVelocidad(int Velocidad);
	//get y set de Resistencia
	double GetResistencia();
	void SetResistencia(double Resistencia);
	//get y set de Munici�n
	int GetMunicion();
	void SetMunicion(int Municion);
};

