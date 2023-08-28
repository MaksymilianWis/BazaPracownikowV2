#pragma once
#include "VectorOperator.h"
#include <string>
#include <iostream>

class Czlowiek
{
	friend class VectorOperator;
private:
	int id_;
	std::string imie_;
	std::string nazwisko_;
	int data_urodzenia_;
	float wynagrodzenie_;

public:
	Czlowiek() : id_(0), imie_("0"), nazwisko_("0"), data_urodzenia_(00000000), wynagrodzenie_(0) {};
	Czlowiek(int id, int data) : id_(id), imie_("0"), nazwisko_("0"), data_urodzenia_(data), wynagrodzenie_(0) {};
	~Czlowiek() = default;

	virtual bool debugDodajDanePracownika(int id) = 0;
	virtual bool debugDodajDanePracownika(int id, int data) = 0;
	bool debugDodajDaneCzlowieka(int id)
	{
		std::cout << "Podaj id: AUTO";
		this->id_ = id;

		std::cout << "\nPodaj imie: AUTO";
		this->imie_ = "imie";
		std::cout << "\nPodaj nazwisko: AUTO";
		this->nazwisko_ = "nazwisko";
		std::cout << "\nPodaj date (yyyymmdd): AUTO";
		this->data_urodzenia_ = 00000000;
		std::cout << "\nPodaj wysokosc wynagrodzenia: AUTO";
		this->wynagrodzenie_ = 0;

		return 1;
	}
	bool debug2DodajDaneCzlowieka(int id, int data)
	{
		std::cout << "Podaj id: AUTO";
		this->id_ = id;

		std::cout << "\nPodaj imie: AUTO";
		this->imie_ = "imie";
		std::cout << "\nPodaj nazwisko: AUTO";
		this->nazwisko_ = "nazwisko";
		std::cout << "\nPodaj date (yyyymmdd): AUTO";
		this->data_urodzenia_ = data;
		std::cout << "\nPodaj wysokosc wynagrodzenia: AUTO";
		this->wynagrodzenie_ = 0;

		return 1;
	}

	bool dodajDaneCzlowieka()
	{
		std::cout << "Podaj id: ";
		std::cin >> this->id_;

		std::cout << "\nPodaj imie: ";
		std::cin >> this->imie_;
		std::cout << "\nPodaj nazwisko: ";
		std::cin >> this->nazwisko_;
		std::cout << "\nPodaj date (yyyymmdd): ";
		std::cin >> this->data_urodzenia_;
		std::cout << "\nPodaj wysokosc wynagrodzenia: ";
		std::cin >> this->wynagrodzenie_;

		return 1;
	}
	void wyswietlJednegoCzlowieka()
	{
		std::cout << "numer id: " << this->id_ << "\n";
		std::cout << "imie i nazwisko: " << this->imie_ << " " << this->nazwisko_ << "\n";
		std::cout << "data urodzenia : " << this->data_urodzenia_ << "\n";
		std::cout << "wynagrodzenie: " << this->wynagrodzenie_ << "\n";
	}

	virtual bool dodajDanePracownika() = 0;
	virtual void wyswietlJednegoPracownika() = 0;
	virtual void skopiujWszystkichPodpracownikow() = 0;
	virtual void dodajPodpracownika(std::shared_ptr<Czlowiek> Czlowiek) = 0;

	
};

/*
debugDodawanie X
USUWANIE X
DODAWANIE X
WYSZUKIWANIE X
ZMIANA DANYCH X
SORTOWANIE PO WIEKU X
DRUKOWANIE NA EKRAN X
DRUKOWANIE DO PLIKU
*/