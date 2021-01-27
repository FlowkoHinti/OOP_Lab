#include "Konto.h"


int main(int argc, char* argv[])
{

	Konto* k = new Konto("abc", 123);
	k->Kontoauszug();

	Kontoverwaltung Konten;

	//Konten.Kontos_laden("kontoverwaltung_12_11_2020-19_08.txt");

	Konten.Kontoeroeffnung("Dave Marchenvillager");
	Konten.Kontoeroeffnung("Flow to the Mic Check");
	Konten.Kontoeroeffnung("R J Duke");

	shared_ptr<Konto> d_konto = Konten.getKontoByName("Dave Marchenvillager");
	shared_ptr<Konto> f_konto = Konten.getKontoByName("Flow to the Mic Check");
	shared_ptr<Konto> r_konto = Konten.getKontoByName("R J Duke");

	Konten.Kontos_laden("kontoverwaltung_13_11_2020-11_08.txt");
	
}