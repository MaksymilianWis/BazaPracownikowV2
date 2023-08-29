#pragma once
#include "Czlowiek.h"
#include "VectorOperator.h"

class Kierownik : public Czlowiek
{
	friend class FileOperator;
private:
	int liczba_podpracownikow_;
	std::vector<std::shared_ptr<Czlowiek>> lista_podpracownikow_;
public:
	Kierownik() : liczba_podpracownikow_(0) {};
	~Kierownik() {};

	virtual bool debugDodajDanePracownika(int id)
	{
		this->debugDodajDaneCzlowieka(id);

		std::cout << "Liczba podpracownikow domyslnie ustawiona na 0." << std::endl;

		return 1;
	}
	virtual bool debugDodajDanePracownika(int id, int data)
	{
		this->debug2DodajDaneCzlowieka(id, data);

		std::cout << "Liczba podpracownikow domyslnie ustawiona na 0." << std::endl;

		return 1;
	}
	virtual bool dodajDanePracownika()
	{
		this->dodajDaneCzlowieka();

		std::cout << "Liczba podpracownikow domyslnie ustawiona na 0." << std::endl;

		return 1;
	}
	virtual void wyswietlJednegoPracownika() 
	{
		this->wyswietlJednegoCzlowieka();
		std::cout << "liczba podpracownikow: " << this->liczba_podpracownikow_ << "\n";
		this->wyswietlWszystkichPodpracownikow();
	}
	virtual void skopiujWszystkichPodpracownikow()
	{
		for (auto i : this->lista_podpracownikow_) //DODAJ OPERATOR VECTOR + VECTOR
		{
			this->dodajPodpracownika(i);
		}
	}
	virtual void dodajPodpracownika(std::shared_ptr<Czlowiek> Czlowiek)
	{
		this->lista_podpracownikow_.push_back(Czlowiek);
	}
	virtual std::string zwrocDanePracownikaString()
	{
		return this->zwrocDaneCzlowiekaString() + ";" + std::to_string(this->liczba_podpracownikow_) + "\n";//dodaj drukowanie listy podpracownikow
	}
	

	void wyswietlWszystkichPodpracownikow()
	{
		for (auto i : lista_podpracownikow_)
		{
			i->wyswietlJednegoCzlowieka();
		}
	}
	
	

};