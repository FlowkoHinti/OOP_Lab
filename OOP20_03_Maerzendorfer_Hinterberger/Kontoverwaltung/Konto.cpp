#include "Konto.h"
#include <iostream>
#include <sstream>
#include <fstream>

#include <iomanip>
#include <ctime>


vector <string> split(string& to_split, char delimiter)
{
	vector <string> split_vec;
	size_t delim_ind = 0;
	size_t old_ind = 0;
	delim_ind = to_split.find(delimiter, old_ind);
	while (delim_ind != string::npos)
	{
		split_vec.push_back(to_split.substr(old_ind, (delim_ind - old_ind)));
		old_ind = delim_ind + 1;
		delim_ind = to_split.find(delimiter, old_ind);
	}
	split_vec.push_back(to_split.substr(old_ind, (to_split.length() - old_ind)));
	return split_vec;
}


shared_ptr<Konto> Kontoverwaltung::Kontoeroeffnung(string inhaber)
{
	if (this == nullptr) return nullptr;
	if (inhaber.empty())
	{
		cerr << "Der angegebene Name ist leer, das Konto konnte nicht erstellt werden" << endl;

	}
	else
	{

		auto neues_konto = make_shared<Konto>(inhaber, 0.0);
		if (neues_konto != nullptr)
		{
			kontoliste.push_back(neues_konto);
			return neues_konto;
		}
		else
		{
			cerr << "Fehler bei der Speicherallokation" << endl;
		}
	}

	return nullptr;
}
int Kontoverwaltung::Kontos_speichern() const
{
	if (this == nullptr) return -1;
	ofstream save_file;

	tm tm;
	time_t t = time(nullptr);
	localtime_s(&tm, &t);
	stringstream ss;

	ss << "kontoverwaltung_" << put_time(&tm, "%d_%m_%Y-%H_%M") << ".txt";

	string filename = ss.str();

	save_file.open(filename);
	if (save_file.is_open())
	{
		for (auto& konto : kontoliste)
		{
			save_file << konto->getKontodaten();
		}

	}
	else
	{
		cerr << "Datei konnte nicht gespeichert werden" << endl;
		return -1;
	}


}

int Kontoverwaltung::Kontos_laden(string dateiname)
{
	if (this == nullptr) return -1;
	ifstream in_file;
	in_file.open(dateiname);

	if (in_file.is_open())
	{
		string konto_str;
		vector <string> konto_vec;
		while (getline(in_file, konto_str))
		{
			konto_vec = split(konto_str, ';');
			auto loaded_konto = Kontoeroeffnung(konto_vec[0]);
			loaded_konto->setKontostand(stod(konto_vec[1]));
			for (size_t elem = 2; elem < konto_vec.size(); ++elem)
			{
				loaded_konto->setTransaktion(stod(konto_vec[elem]));
			}
		}
		return 1;
	}
	else
	{
		cerr << "Datei konnte nicht geoeffnet werden" << endl;
		return -1;
	}

}

shared_ptr<Konto> Kontoverwaltung::getKontoByName(string name) {
	if (this == nullptr) return nullptr;
	for (auto& k : kontoliste) {
		if(k->getKontoinhaber()==name){
			return k;
		}
	}
	cerr << "Konto konnte nicht gefunden werden" << endl;
	return nullptr;
}

string Konto::getKontoinhaber() const{
	if (this == nullptr) return "\0";
	return Kontoinhaber;
}

string Konto::getKontodaten() const
{
	if (this == nullptr) return "";
	string ret_string = Kontoinhaber + ";" + to_string(Kontostand) + ";";
	for (auto transaktion = Historie.begin(); transaktion != Historie.end(); ++transaktion)
	{
		if (next(transaktion) == Historie.end()) ret_string.append(to_string(*transaktion) + "\n");
		else ret_string.append(to_string(*transaktion) + ";");
	}
	return ret_string;
}

void Konto::setKontostand(double kontostand)
{
	if (this == nullptr) return;
	Kontostand = kontostand;
}

void Konto::setTransaktion(double transaktion)
{
	if (this == nullptr) return;
	Historie.push_back(transaktion);
}


Konto::Konto(string name, double val)
{
	Kontoinhaber = name;
	Kontostand = val;
}

int Konto::Einzahlen(double val)
{
	if (this == nullptr) return -1;
	if (val >= 0) {
		Kontostand += val;
		Historie.push_back(val);
		return 0;
	}
	else {
		cerr << "Es kann nicht negativ eingezahlt werden!" << endl;
		return -1;
	}
}
int Konto::Abheben(double val)
{
	if (this == nullptr) return -1;
	if (val < 0) {
		cerr << "Es kann nicht negativ abgehoben werden!" << endl;
		return -1;
	}
	if (Kontostand - val < 0) {
		cerr << "Sie haben nicht genug Geld am Konto!" << endl;
		return -1;
	}
	else {
		Kontostand -= val;
		Historie.push_back(-val);
		return 0;
	}
}

void Konto::Kontoauszug() {
	if (this == nullptr) return;
	tm tm;
	time_t t = time(nullptr);
	localtime_s(&tm, &t);

	double sum = 0.0;
	int x = 0;
	cout << "Kontostand am " << put_time(&tm, "%d_%m_%Y:%H_%M") << endl;
	for (auto& i : Historie) {
		if (x % 10 == 0) {
			cout << "|---------------------------|" << endl;
			if (x != 0)cout << "\t Summe:" << sum << " Euro" << endl;
		}
		if (i > 0) {
			cout << "Es wurden " << i << " Euro eingezahlt." << endl;
		}
		else {
			cout << "Es wurden " << i * -1 << " Euro abgehoben." << endl;
		}
		sum += i;
		x++;
	}
	cout << "|---------------------------|" << endl;
	if (x != 0)cout << "\t Summe:" << sum << " Euro" << endl;

}


