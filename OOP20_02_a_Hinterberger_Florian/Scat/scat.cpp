#include <iostream>
#include <array>
#include <random>

#define STAPEL 32

using namespace std;

enum class farbe
{
	eichel,
	schellen,
	herz,
	blatt
};

enum class wertigkeit
{
	sieben,
	acht,
	neun,
	unter,
	ober,
	koenig,
	zehn,
	ass
};

struct karte
{
	farbe f;
	wertigkeit w;
};

class kartendeck
{
private:
	array<shared_ptr<karte>, STAPEL> deck;

	void generate_deck(array<shared_ptr<karte>, STAPEL>& deck_in)
	{
		size_t karten_ind = 0;

		for (size_t farben = 0; farben < 4; ++farben)
		{
			for (size_t werte = 0; werte < 8; ++werte, ++karten_ind)
			{
				auto neue_karte = make_shared<karte>();
				neue_karte->f = (farbe)farben;
				neue_karte->w = (wertigkeit)werte;
				deck_in[karten_ind] = neue_karte;
			}
		}
	}

public:
	kartendeck()
	{
		generate_deck(deck);
	}

	void shuffle()
	{
		default_random_engine generator;
		uniform_int_distribution<int> distribution(0, 31);
		
		int rand_ind = 0;

		for (size_t karten_ind = 0; karten_ind < STAPEL; ++karten_ind)
		{
			rand_ind = distribution(generator);
			swap(deck[karten_ind], deck[rand_ind]);
		}
	}
};

int main(int argc, char* argv[])
{
	kartendeck mein_deck = kartendeck();
	mein_deck.shuffle();
}
