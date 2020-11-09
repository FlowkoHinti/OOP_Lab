#include "Konto.h"


int main(int argc, char* argv[])
{
	Kontoverwaltung Konten;

	Konten.Kontos_laden("kontoverwaltung_08_11_2020-16_09.txt");
	auto konto_1 = Konten.getKontoByName("David Maerzendorfer");
	konto_1->Kontoauszug();
	auto konto_2 = Konten.getKontoByName("Florian Hinterberger");
	konto_2->Kontoauszug();

	auto konto_3 = Konten.getKontoByName("dsds");
	konto_3->Kontoauszug();

	konto_1->Abheben(-333);
	konto_2->Einzahlen(-122);
	konto_1->Abheben(12);
	konto_2->Einzahlen(22);

	Konten.Kontos_speichern();
}