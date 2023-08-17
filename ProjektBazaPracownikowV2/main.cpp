#include "iostream"
#include "VectorOperator.h"
//#include "Czlowiek.h"
//#include "Kierownik.h"
//#include "Szeregowy.h"

int main()
{
	std::shared_ptr<VectorOperator> c1 = std::make_shared<VectorOperator>();

	c1->DodajPracownika('k');
	c1->wyswietlWszystkichPracownikow();
}