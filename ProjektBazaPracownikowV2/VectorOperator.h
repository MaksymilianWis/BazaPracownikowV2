#pragma once
#include <vector>
#include "Czlowiek.h"
#include "Kierownik.h"
#include "Szeregowy.h"
#include <iostream>

class VectorOperator
{
private:
	std::vector<std::shared_ptr<Czlowiek>> lista_kierownikow_;

public:
	VectorOperator() {};
	~VectorOperator() {};

	std::shared_ptr<Czlowiek> wyszukiwaniePracownika(int id)//1 = znaleziony zwraca wskaznik na pracownika
	{
		for (auto i : this->lista_kierownikow_)
		{
			if (i->id_ == id) return i;
		}
		//std::cout << "Nieznaleziono istniejacego juz pracownika w bazie: " << id << std::endl;
		return 0;
	}

	bool debugDodajPracownika(char x, int id) //1 = dodano kierownika pomyslnie x = 'k' Kierownik, x = 's' szeregowy
	{
		switch (x)
		{
		case 'k':
		{
			//TWORZENIE KIEROWNIKA
			std::shared_ptr<Czlowiek> c1 = std::make_shared<Kierownik>();
			do {
				c1->debugDodajDanePracownika(id);
			} while (this->wyszukiwaniePracownika(c1->id_));

			lista_kierownikow_.push_back(c1);
		}
		break;

		case 's':
		{
			//std::shared_ptr<Czlowiek> s1 = std::make_shared<Szeregowy>();
		}
		break;
		default:
			break;
		}
		return 1;
	}
	
	bool dodajPracownika(char x) //1 = dodano kierownika pomyslnie x = 'k' Kierownik, x = 's' szeregowy
	{
		switch(x)
		{
		case 'k':
		{
			//TWORZENIE KIEROWNIKA
			std::shared_ptr<Czlowiek> c1 = std::make_shared<Kierownik>();
			do {
				c1->dodajDanePracownika();
			} while (this->wyszukiwaniePracownika(c1->id_));
			
			lista_kierownikow_.push_back(c1);
		}
			break;

		case 's':
		{
			//std::shared_ptr<Czlowiek> s1 = std::make_shared<Szeregowy>();
		}
			break;
		default:
			break;
		}
		return 1;
	}

	virtual void wyswietlWszystkichPracownikow()
	{
		for (auto i : lista_kierownikow_)
		{
			i->wyswietlJednegoPracownika();
		}
	}

};