#pragma once
#include <vector>
#include <memory>
#include <string>
#include <list>

using namespace std;

class Konto
{
private:
	string Kontoinhaber;
	double Kontostand;
	list<double> Historie;

	

public:
	Konto(string name, double val);
	int Einzahlen(double val);
	int Abheben(double val);
	void Kontoauszug();
	string getKontodaten() const;
	string getKontoinhaber() const;
	void setKontostand(double kontostand);
	void setTransaktion(double transaktion);

};

class Kontoverwaltung
{
public:

	shared_ptr<Konto> Kontoeroeffnung(string inhaber);
	int Kontos_speichern() const;
	int Kontos_laden(string dateiname);
	shared_ptr<Konto> getKontoByName(string name);
		


private:
	vector<shared_ptr<Konto>> kontoliste;
};


