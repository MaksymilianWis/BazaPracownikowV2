#pragma once
#include <vector>
#include "Czlowiek.h"
#include "Kierownik.h"
#include "Szeregowy.h"
#include "FileOperator.h"
#include <iostream>

class VectorOperator
{
private:
	std::vector<std::shared_ptr<Czlowiek>> lista_kierownikow_;

	template<typename T>
	void itQuickSort(T poczatek, T koniec)// od najmlodszego
	{
		auto i = this->lista_kierownikow_.begin();

		//i->swap;

		auto p = poczatek, q = koniec;
		auto pivot = poczatek;
		std::advance(pivot, std::distance(p, q) / 2);

		while (true)
		{
			while (p->get()->data_urodzenia_ < pivot->get()->data_urodzenia_)//szukanie wiekszego od pivot
				p++;
			while (q->get()->data_urodzenia_ > pivot->get()->data_urodzenia_)//szukanie mniejszego od pivot
				q--;
			if (std::distance(p, q)>0)
			{
				p->swap(*q);
				std::cout << "========================================" << std::endl;
				this->wyswietlWszystkichPracownikow();
				std::cout << "========================================" << std::endl;
			}
			else
			{
				break;
			}
		}
		if(std::distance(poczatek, q) > 1) 
			itQuickSort(poczatek, q);

		if (std::distance(p, koniec) > 1)
		{
			itQuickSort(p, koniec);
		}
	}
	
	void quickSort(int poczatek, int koniec)//NIE DZIALA
	{
		
		int pivot = (this->lista_kierownikow_[(poczatek + koniec)/2]->data_urodzenia_);
		int p = --poczatek, q = ++koniec; poczatek++; koniec--;
		while (true)
		{
			

			while (pivot > this->lista_kierownikow_[++p]->data_urodzenia_)
				;
			while (pivot < this->lista_kierownikow_[--q]->data_urodzenia_)
				;
			if (p <= q)
			{
				this->lista_kierownikow_[p].swap(this->lista_kierownikow_[q]);//zamienia miejscami w tablicy funkcja wbudowana w vector
				std::cout << "========================================" << std::endl;
				this->wyswietlWszystkichPracownikow();
				std::cout << "========================================" << std::endl;
			}
			else
			{
				break;
			}
		}

		if (q > poczatek)
			this->quickSort(poczatek, q);
		if (p < koniec)
			this->quickSort(p, koniec);
	}

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
	bool debugDodajPracownika(char x, int id, int data) //1 = dodano kierownika pomyslnie x = 'k' Kierownik, x = 's' szeregowy
	{
		switch (x)
		{
		case 'k':
		{
			//TWORZENIE KIEROWNIKA
			std::shared_ptr<Czlowiek> c1 = std::make_shared<Kierownik>();
			do {
				c1->debugDodajDanePracownika(id, data);
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
	void wyswietlWszystkichPracownikow()
	{
		for (auto i : lista_kierownikow_)
		{
			i->wyswietlJednegoPracownika();
		}
	}
	bool zmienDanePracownika(int id)
	{
		this->wyszukiwaniePracownika(id)->dodajDanePracownika();
		if (!wyszukiwaniePracownika(id))
		{
			std::cout << "Nie udalo sie zmienic danych pracownika o id: " << id << std::endl;
			return 0;
		}
		return 1;
	}
	void sortowaniePoWieku()
	{
		//this->quickSort(0, this->lista_kierownikow_.size());
		this->itQuickSort(std::begin(this->lista_kierownikow_), std::prev(std::end(lista_kierownikow_), 1));
	}
	void drukujWszystkichDoPliku()
	{
		std::unique_ptr<FileOperator> fop = std::make_unique<FileOperator>();
		

		for (auto it : lista_kierownikow_)
		{
			fop->drukujJednegoDoPliku(it->zwrocDanePracownikaString());
		}

	}

	


};