#include "iostream"
#include "VectorOperator.h"
#include "Czlowiek.h"
#include "Kierownik.h"
#include "Szeregowy.h"

int main()
{
	Czlowiek* c1 = new Kierownik;

	if (dynamic_cast<Kierownik*>(c1))
	{
		std::cout << "jest to kierownik" << std::endl;
	}
	else if(dynamic_cast<Czlowiek*>(c1))
	{
		std::cout << "jest to czlowiek" << std::endl;
	}
	else if (dynamic_cast<Szeregowy*>(c1))
	{
		std::cout << "jest to szeregowy" << std::endl;
	}
}