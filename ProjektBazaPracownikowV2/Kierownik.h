#pragma once
#include "Czlowiek.h"
#include "VectorOperator.h"

class Kierownik : public Czlowiek
{
private:
	int liczba_podpracownikow_;
	std::vector<std::shared_ptr<Czlowiek>> lista_podpracownikow_;
public:
	Kierownik() : liczba_podpracownikow_(0) {};
	~Kierownik() {};

	virtual bool dodajDanePracownika()
	{
		this->dodajDaneCzlowieka();

		std::cout << "Liczba podpracownikow domyslnie ustawiona na 0." << std::endl;

		return 1;
	}

	virtual bool usuwaniePracownika() { return 0; };
	virtual void wyswietlJednegoPracownika() 
	{
		this->wyswietlJednegoCzlowieka();
		std::cout << "liczba podpracownikow:" << this->liczba_podpracownikow_ << "\n";
	}

};