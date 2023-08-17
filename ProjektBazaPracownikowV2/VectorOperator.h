#pragma once
#include <vector>
#include "Czlowiek.h"
#include "Kierownik.h"
#include <iostream>

class VectorOperator
{
private:
	std::vector<Czlowiek*> lista_kierownikow_;

public:
	VectorOperator() {};
	~VectorOperator() {};

	bool wyszukiwaniePracownika(int id)//1 = znaleziony zwraca wskaznik na pracownika
	{
		for (auto i : this->lista_kierownikow_)
		{
			if (i->id_ == id) return i;
		}
		std::cout << "Nieznaleziono pracownika: " << id;
		return 0;
	}

	
	bool dodajDoListyKierownikow() //1 = dodano kierownika pomyslnie
	{
		Czlowiek* kierownik = new Kierownik;

		lista_kierownikow_.push_back(kierownik);
		if (!this->wyszukiwaniePracownika(kierownik->id_))
		{
			std::cout << "Nie udalo sie dodac kierownika." << std::endl;
			return 0;
		}
		std::cout << "Pomyslnie dodano kierownika";
		return 1;
	}

};