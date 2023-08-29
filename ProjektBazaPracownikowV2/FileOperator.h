#pragma once
#include <iostream>
#include <fstream>

class FileOperator
{
private:
	std::ofstream myfile;

public:
	FileOperator()
	{
		myfile.open("lista pracownikow.csv");
		if (myfile.is_open())
		{
			std::cout << "plik zostal otwarty" << std::endl;
		}
	}
	~FileOperator()
	{
		myfile.close();
		if (!myfile.is_open())
		{
			std::cout << "plik zostal zamkniety" << std::endl;
		}
	}
	void drukujJednegoDoPliku(std::string data_line)
	{
		

		if (myfile.is_open())
		{
			myfile << data_line;
		}
		else { std::cout << "plik nie zosta³ otwarty" << std::endl; }
		
	}

};