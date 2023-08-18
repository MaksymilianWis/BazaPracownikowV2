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
	bool usuwaniePracownika(int id_kierownika_do_usuniecia) 
	{
		int id_nowy_kierownik;
		std::shared_ptr<Czlowiek> it_kierownik_do_usuniecia = this->wyszukiwaniePracownika(id_kierownika_do_usuniecia);

		do
		{
			std::cout << "Podaj id kierownia do przepisania listy podpracownikow: ";
			std::cin >> id_nowy_kierownik;
		} while (!this->wyszukiwaniePracownika(id_nowy_kierownik) or id_nowy_kierownik == id_kierownika_do_usuniecia);
		std::shared_ptr<Czlowiek> it_nowy_kierownik = this->wyszukiwaniePracownika(id_nowy_kierownik);

		it_nowy_kierownik->skopiujWszystkichPodpracownikow();
		
		auto it = std::remove(lista_kierownikow_.begin(), lista_kierownikow_.end(), it_kierownik_do_usuniecia);
		lista_kierownikow_.erase(it, lista_kierownikow_.end());
		std::cout << "usunieto pracownika o id: " << id_kierownika_do_usuniecia << std::endl;
		
		if (!this->wyszukiwaniePracownika(id_kierownika_do_usuniecia))
		{
			return 0;
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