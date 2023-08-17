#pragma once
#include "Czlowiek.h"
#include "VectorOperator.h"

class Kierownik : public Czlowiek
{
private:
	int liczba_podpracownikow_;
	std::vector<Czlowiek*> lista_podpracownikow_;
public:
	Kierownik() : liczba_podpracownikow_(0) {};
	~Kierownik() {};

	virtual bool dodajPracownika(VectorOperator& vOperator)
	{
		this->dodajCzlowieka(vOperator);

		std::cout << "Liczba podpracownikow domyslnie ustawiona 0." << std::endl;

		if (!vOperator.dodajDoListyKierownikow())
		{
			return 0;
		}
		return 1;
	}

	virtual bool usuwaniePracownika() { return 0; };

};