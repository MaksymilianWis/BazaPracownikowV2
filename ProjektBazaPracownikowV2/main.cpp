#include "iostream"
#include "VectorOperator.h"
#include "Czlowiek.h"
#include "Kierownik.h"
//#include "Szeregowy.h"

int main()
{
	std::shared_ptr<VectorOperator> c1 = std::make_shared<VectorOperator>();

	/*
	c1->debugDodajPracownika('k', 2);
	c1->debugDodajPracownika('k', 1);
	c1->debugDodajPracownika('k', 5);
	c1->debugDodajPracownika('k', 7);
	*/

	c1->debugDodajPracownika('k', 1, 20000404);
	c1->debugDodajPracownika('k', 2, 19950805);
	c1->debugDodajPracownika('k', 3, 20010505);
	c1->debugDodajPracownika('k', 4, 6);
	c1->debugDodajPracownika('k', 5, 5);
	c1->debugDodajPracownika('k', 6, 4);
	c1->debugDodajPracownika('k', 7, 3);
	c1->debugDodajPracownika('k', 8, 2);
	c1->debugDodajPracownika('k', 9, 1);

	//c1->wyswietlWszystkichPracownikow();
	c1->sortowaniePoWieku();	
	
	std::cout << "-----------------------------------------" << std::endl;
	//c1->wyswietlWszystkichPracownikow();
	c1->drukujWszystkichDoPliku();
}