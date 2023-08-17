#include "iostream"
#include "VectorOperator.h"
//#include "Czlowiek.h"
//#include "Kierownik.h"
//#include "Szeregowy.h"

int main()
{
	std::shared_ptr<VectorOperator> c1 = std::make_shared<VectorOperator>();

	c1->debugDodajPracownika('k', 1);
	c1->debugDodajPracownika('k', 2);
	c1->debugDodajPracownika('k', 3);
	c1->debugDodajPracownika('k', 4);
	c1->wyswietlWszystkichPracownikow();
}