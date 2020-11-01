#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <iomanip>
#include <ctime>



using namespace std;


struct material
{
	unsigned long ID;
	unsigned long artikelnummer;
	string bezeichnung;
};

struct fach
{
	unsigned long fachnr;
	unsigned long artikel;
	shared_ptr<stack<shared_ptr<material>>> speicher;
};

class lagerverwaltung
{
public:
	lagerverwaltung()
	{
		//1 Fach pro artikel (fachnummer und artikelnummer müssen passen)
		//--> jedes fach ist ein Stack (LIFO)
		//--> vektor fasst alle stacks zusammen (artikelfächer)
		//shared pointer gewählt --> automatische destruktion

	}

	~lagerverwaltung()
	{
		for (auto fach : lager)
		{
			while (!fach.speicher->empty()) fach.speicher->pop();
		}
	}

	void einlagern(long id, long artikelnr, string bezeichnung, int fachnr)
	{
		if (lager.empty())
		{
			neues_fach(fachnr, id, artikelnr, bezeichnung);
		}
		else
		{
			bool neues_f = false;

			for (auto& fach : lager)
			{
				//3 Cases
				//fach gibt es und hat richtige artikelnr --> Mat einfügen
				//fach gibt es nicht und kein fach hat die artikel nr --> neues fach anlegen und mat einfügen
				//fachnr stimmt aber artikelnr nicht und umgekehrt --> fehler
				neues_f = false;
				if (fach.fachnr == fachnr && fach.artikel == artikelnr) material_ablegen(fach, id, artikelnr, bezeichnung);
				else if (fach.fachnr != fachnr && fach.artikel != artikelnr) neues_f = true;
				else
				{
					cerr << "Falsches Fach " << fachnr << " fuer den angegebenen Artikel " << artikelnr << " kontrollieren sie bitte die angegebene Artikelnummer oder Fachnummer" << endl;
					break;
				}
			}
			if (neues_f)
			{
				neues_fach(fachnr, id, artikelnr, bezeichnung);
			}
		}
	}

	shared_ptr<material> entnehmen(long artikelnr)
	{
		for (auto& fach : lager)
		{
			if (fach.artikel == artikelnr)
			{
				shared_ptr<material> material = fach.speicher->top();
				cout << "Aus Fach " << fach.fachnr << " Artikel " << fach.artikel << " Bezeichnung: " << fach.speicher->top()->bezeichnung << " entnommen" << endl;
				fach.speicher->pop();
				return material;
			}
		}
		cerr << "Material ist nicht vorhanden" << endl;
		return nullptr;
	}

	void lager_zustand()
	{
		tm tm;
		time_t t = time(nullptr);
		localtime_s(&tm, &t);
		cout << "----------------------------------------" << endl << "Lagerzustand vom: " << put_time(&tm, "%d-%m-%Y %H:%M:%S") << endl << endl;
		for (auto& f : lager) {
			cout << "Fach: " << setw(4) << f.fachnr << "\tArtikel: " << f.artikel << "\tBezeichnung: " << setw(20) << f.speicher->top()->bezeichnung << "\tAnzahl: " << f.speicher->size() << endl;
		}
	}



private:
	vector<fach> lager;

	void material_ablegen(fach & f, long id, long artikelnr, string bezeichnung)
	{
		shared_ptr<material> neues_mat = make_shared<material>();
		neues_mat->ID = id;
		neues_mat->artikelnummer = artikelnr;
		neues_mat->bezeichnung = bezeichnung;
		f.speicher->push(neues_mat);
	}

	void neues_fach(int fachNr, long id, long artikelnr, string bezeichnung)
	{
		fach neues_fach = { fachNr, artikelnr ,make_shared<stack<shared_ptr<material>>>() };
		material_ablegen(neues_fach, id, artikelnr, bezeichnung);
		lager.push_back(neues_fach);
		//cout << "Neues Fach Nr: " << fachNr << "\tArtikel: " << artikelnr << endl;
	}

};

int main(int argc, char * argv[]) 
{
	lagerverwaltung l = lagerverwaltung();
	l.einlagern(3, 2, "Zahnbuerste", 5);
	l.einlagern(4, 2, "Zahnbuerste", 5);
	l.einlagern(5, 3, "Zahnbuerste", 5);
	l.einlagern(6, 2, "Zahnbuerste", 6);
	l.einlagern(1, 5, "Zahnseide", 10);
	l.einlagern(2, 5, "Zahnseide", 10);
	l.einlagern(3, 5, "Zahnseide", 10);
	l.einlagern(4, 5, "Zahnseide", 10);
	l.einlagern(6, 5, "Zahnseide", 10);
	l.einlagern(7, 5, "Zahnseide", 10);
	l.einlagern(1, 33, "Zahnpaste", 15);
	l.einlagern(2, 33, "Zahnpaste", 15);
	l.einlagern(3, 33, "Zahnpaste", 15);
	l.einlagern(4, 33, "Zahnpaste", 15);
	cout << "Ich habe: " << l.entnehmen(5)->bezeichnung << endl;
	l.lager_zustand();

}
