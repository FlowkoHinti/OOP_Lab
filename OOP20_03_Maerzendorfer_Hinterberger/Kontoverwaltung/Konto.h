#pragma once
#include <vector>
#include <memory>
#include <string>
#include <list>
#include <iostream>

using namespace std;


class Transaktion
{
public:
	double Betrag{ 0.0 };
	string Ziel{ "" };
	string Zweck{ "" };
	string Zeit{ "00_00_00-00_00" };
	string getTransString();
	string getFancyTransString();
};

class Konto
{
private:
	unsigned int ID;
	string Kontoinhaber;
	double Kontostand;
	bool offen;
	list<shared_ptr<Transaktion>> Historie;



public:
	
	Konto(string name, double val);
	Konto(Konto& k);
	~Konto();
	int Einzahlen(double val);
	int Abheben(double val);

	void Kontoauszug();
	string getKontodaten();
	string getKontoinhaber() const;
	bool getOffen() const;
	void setOffen(bool b);
	void setKontostand(double kontostand);
	double getKontostand() const;
	void addTransaktion(shared_ptr<Transaktion> transaktion);


};

class Kontoverwaltung
{
public:
	static unsigned int konto_seed;

	shared_ptr<Konto> Kontoeroeffnung(string inhaber);
	int Kontoschliessen(shared_ptr<Konto> konto);
	int Kontos_speichern() const;
	int Kontos_laden(string dateiname);
	shared_ptr<Konto> getKontoByName(string name);
	static unsigned int get_new_Id();

	int Ueberweisen(double val, shared_ptr<Konto>& quelle, shared_ptr<Konto>& ziel, ostream stream, string verwendungszweck = "");
	int Ueberweisen(double val, shared_ptr<Konto>& quelle, shared_ptr<Konto>& ziel, string verwendungszweck = "");

private:
	vector<shared_ptr<Konto>> kontoliste;
};


