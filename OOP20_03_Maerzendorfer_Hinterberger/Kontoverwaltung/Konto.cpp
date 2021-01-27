#include "Konto.h"
#include <iostream>
#include <sstream>
#include <fstream>

#include <iomanip>
#include <ctime>
#include <iomanip>

// TODO
// 1. Konstruktor
// 2. erweitern der Klasse Konto
// 3. Copy konstruktor-->done, hab offen als true gesetzt
// 4. methode schließen
// 5. methode überweisen
// 6. Logging ein/aus --> ziel, betrag, verwendungszweck, zeitstempel (Klasse Transaktion)
// 7. destruktor



string get_time()
{
	tm tm;
	time_t t = time(nullptr);
	localtime_s(&tm, &t);
	stringstream ss;
	ss << put_time(&tm, "%d_%m_%Y-%H_%M");
	return ss.str();
}

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

unsigned int Kontoverwaltung::konto_seed = 0;

unsigned int Kontoverwaltung::get_new_Id()
{
	return ++konto_seed;
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

int Kontoverwaltung::Kontoschliessen(shared_ptr<Konto> konto)
{
	if (this == nullptr) return -1;

	if (konto->getOffen() && konto->getKontostand() == 0)
	{
		konto->setOffen(false);
		return 1;
	}
	else cerr << "Konto ist schon geschlossen oder das Konto hat noch Guthaben" << endl;
}

int Kontoverwaltung::Kontos_speichern() const
{
	if (this == nullptr) return -1;
	ofstream save_file;
	string filename = "kontoverwaltung_" + get_time() + ".txt";

	save_file.open(filename);
	if (save_file.is_open())
	{
		for (auto& konto : kontoliste)
		{
			save_file << konto->getKontodaten();
		}
		save_file.close();

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
			for (size_t elem = 2; elem < konto_vec.size(); elem += 4)
			{
				loaded_konto->addTransaktion(make_shared<Transaktion>(Transaktion{ stod(konto_vec[elem]), konto_vec[elem + 1], konto_vec[elem + 2], konto_vec[elem + 3] }));
			}
		}
		in_file.close();
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
		if (k->getKontoinhaber() == name) {
			return k;
		}
	}
	cerr << "Konto konnte nicht gefunden werden" << endl;
	return nullptr;
}


int Kontoverwaltung::Ueberweisen(double val, shared_ptr<Konto>& quelle, shared_ptr<Konto>& ziel, ostream stream, string verwendungszweck)
{
	if (this == nullptr) return -1;
	if (val > quelle->getKontostand()) { cerr << "Es ist nicht genug Geld am Konto" << endl; return -1; }
	if (val < 0) { cerr << "Es kann kein negativer Betrag ueberwiesen werden" << endl; return -1; }
	if (!quelle->getOffen()) { cerr << "Dein Konto ist schon geschlossen keine Ueberweisungen mehr moeglich" << endl; return -1; }
	if (!ziel->getOffen()) { cerr << "Das Zielkonto ist schon geschlossen es kann also nicht darauf ueberwiesen werden" << endl; return -1; }
	//auf ein anders konto überweisen
	//our side
	quelle->setKontostand(quelle->getKontostand() - val);
	quelle->addTransaktion(make_shared<Transaktion>(Transaktion{ -val, ziel->getKontoinhaber(), "Verwendung: " + verwendungszweck, get_time() }));

	//others side
	ziel->setKontostand(ziel->getKontostand() + val);
	ziel->addTransaktion(make_shared<Transaktion>(Transaktion{ val, ziel->getKontoinhaber(), "Verwendung: " + verwendungszweck, get_time() }));
	stream << get_time() << ": " << "Ueberweisung von " << val << " Euro von " << quelle->getKontoinhaber() << " auf " << ziel->getKontoinhaber() << endl;


	return 1;
}

int Kontoverwaltung::Ueberweisen(double val, shared_ptr<Konto>& quelle, shared_ptr<Konto>& ziel, string verwendungszweck)
{

	if (this == nullptr) return -1;
	if (val > quelle->getKontostand()) { cerr << "Es ist nicht genug Geld am Konto" << endl; return -1; }
	if (val < 0) { cerr << "Es kann kein negativer Betrag ueberwiesen werden" << endl; return -1; }
	if (!quelle->getOffen()) { cerr << "Dein Konto ist schon geschlossen keine Ueberweisungen mehr moeglich" << endl; return -1; }
	if (!ziel->getOffen()) { cerr << "Das Zielkonto ist schon geschlossen es kann also nicht darauf ueberwiesen werden" << endl; return -1; }
	
	//auf ein anders konto überweisen
	//our side
	quelle->setKontostand(quelle->getKontostand() - val);
	quelle->addTransaktion(make_shared<Transaktion>(Transaktion{ -val, ziel->getKontoinhaber(), "Verwendung: " + verwendungszweck, get_time() }));

	//others side
	ziel->setKontostand(ziel->getKontostand() + val);
	ziel->addTransaktion(make_shared<Transaktion>(Transaktion{ val, ziel->getKontoinhaber(), "Verwendung: " + verwendungszweck, get_time() }));
	cout << get_time() << ": " << "Ueberweisung von " << val << " Euro von " << quelle->getKontoinhaber() << " auf " << ziel->getKontoinhaber() << endl;

	return 1;
	
}



string Konto::getKontoinhaber() const {
	if (this == nullptr) return "\0";
	return Kontoinhaber;
}

string Konto::getKontodaten()
{
	if (this == nullptr) return "";
	string ret_string = Kontoinhaber + ";" + to_string(Kontostand) + ";";
	for (auto transaktion = this->Historie.begin(); transaktion != this->Historie.end(); ++transaktion)
	{
		if (next(transaktion) == this->Historie.end()) ret_string.append((*transaktion)->getTransString() + "\n");
		else ret_string.append((*transaktion)->getTransString() + ";");
	}
	return ret_string;
}

void Konto::addTransaktion(shared_ptr<Transaktion> transaktion)
{
	if (this == nullptr) return;
	this->Historie.push_back(transaktion);
}

string Transaktion::getTransString()
{
	return to_string(this->Betrag) + ";" + this->Ziel + ";" + this->Zweck + ";" + this->Zeit;
}

string Transaktion::getFancyTransString() {
	ostringstream s;
	s << fixed;
	s << setprecision(2);
	s << Betrag;
	return "---\n" + Zeit + ": \n---\nZweck: " + Zweck + "\nZiel: " + Ziel + "\nBetrag: " + s.str() + "Euro \n";
}

bool Konto::getOffen() const {
	if (this == nullptr)return false;
	return this->offen;
}
void Konto::setOffen(bool b) {
	if (this == nullptr) return;
	this->offen = b;
}
void Konto::setKontostand(double kontostand) {
	if (this == nullptr) return;
	this->Kontostand = kontostand;
}
double Konto::getKontostand()const {
	return this->Kontostand;
}


Konto::Konto(string name, double val)
{
	this->Kontoinhaber = name;
	this->Kontostand = val;
	this->ID = Kontoverwaltung::get_new_Id();
	this->offen = true;
}
//copy constr-->offen is set to true
Konto::Konto(Konto& k) :Kontoinhaber{ k.Kontoinhaber }, Kontostand{ 0 }, ID{ Kontoverwaltung::get_new_Id() }, offen{ true }{
	this->Historie = k.Historie;
}

Konto::~Konto()
{
	cout << "Konto: " << this->ID << " Inhaber: " << this->Kontoinhaber << " wurde zum Zeitpunkt: " << get_time() << " geloescht" << endl;
}

int Konto::Einzahlen(double val) {

	if (this == nullptr) return -1;
	if (!offen) {
		cerr << "Das Konto ist geschlossen!" << endl;
		return -1;
	}
	if (val >= 0) {
		Kontostand += val;
		this->addTransaktion(make_shared<Transaktion>(Transaktion{ val, this->getKontoinhaber(), "Einzahlung", get_time() }));
		return 0;
	}
	else {
		cerr << "Es kann nicht negativ eingezahlt werden!" << endl;
		return -1;
	}
		//return Kontoverwaltung::Ueberweisen(val, , to_string(val) + " Euro");

	}

	int Konto::Abheben(double val)
	{
		if (this == nullptr) return -1;
		if (!offen) {
			cerr << "Das Konto ist geschlossen!" << endl;
			return -1;
		}
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
			this->addTransaktion(make_shared<Transaktion>(Transaktion{ val, "", "Abhebung", get_time() }));
			return 0;
		}
		//return Konto::Ueberweisen(val, nullptr, to_string(val) + " Euro");
		
	}

	void Konto::Kontoauszug() {
		if (this == nullptr) return;

		double sum = 0.0;
		int x = 0;
		cout << "Kontostand am " << get_time() << endl;
		for (auto& i : this->Historie) {
			if (x % 10 == 0) {
				cout << "|---------------------------|" << endl;
				if (x != 0)cout << "\t Summe:" << sum << " Euro" << endl;
			}
			//if (i > 0) {
			//	cout << "Es wurden " << i << " Euro eingezahlt." << endl;
			//}
			//else {
			//	cout << "Es wurden " << i * -1 << " Euro abgehoben." << endl;
			//}
			cout << (*i).getFancyTransString();
			sum += (*i).Betrag;
			x++;
		}
		cout << "|---------------------------|" << endl;
		if (x != 0)cout << "\t Summe:" << sum << " Euro" << endl;

	}


