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
	std::string data_urodzenia_;
	float wynagrodzenie_;

public:
	Czlowiek() : id_(0), imie_("0"), nazwisko_("0"), data_urodzenia_("00;00;0000"), wynagrodzenie_(0) {};
	~Czlowiek() = default;

	bool dodajDaneCzlowieka()
	{
		std::cout << "Podaj id: ";
		std::cin >> this->id_;

		std::cout << "\nPodaj imie: ";
		std::cin >> this->imie_;
		std::cout << "\nPodaj nazwisko: ";
		std::cin >> this->nazwisko_;
		std::cout << "\nPodaj date (dd;mm;yyyy): ";
		std::cin >> this->data_urodzenia_;
		std::cout << "\nPodaj wysokosc wynagrodzenia: ";
		std::cin >> this->wynagrodzenie_;

		return 1;
	}
	void wyswietlJednegoCzlowieka()
	{
		std::cout << "numer id: " << this->id_ << "\n";
		std::cout << "imie i nazwisko: " << this->imie_ << " " << this->nazwisko_ << "\n";
		std::cout << "wynagrodzenie: " << this->wynagrodzenie_ << "\n";
	}

	virtual bool dodajDanePracownika() = 0;
	virtual bool usuwaniePracownika() = 0;
	virtual void wyswietlJednegoPracownika() = 0;

	
};

/*
USUWANIE
DODAWANIE
WYSZUKIWANIE X
ZMIANA DANYCH
SORTOWANIE PO WIEKU
DRUKOWANIE NA EKRAN
DRUKOWANIE DO PLIKU
*/