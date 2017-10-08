//Standard Shit
#include <iostream>

//Custom Shit
#include "logger.hpp"

void Logger::log(std::string message)
{
	//Forward everything to the Console for Now
	//-----------------------------------------

	std::cout << "DEBUG: " << message << std::endl;

}

void Logger::log(std::string qualifier, std::string message)
{
	//Forward everything to the Console for Now
	//-----------------------------------------

	std::cout << qualifier << message << std::endl;

}

void Logger::log(std::string qualifier, unsigned char message)
{
	//Forward everything to the Console for Now
	//-----------------------------------------

	std::cout << qualifier << std::hex << (int)message << std::endl;
}

void Logger::log(int Level, std::string message)
{
	switch (Level)
	{
		case LogLevel::DBUG :
		{			
			break;
		}

		case LogLevel::SEVR : 
		{
			std::cout << "SEVR: " << message << std::endl;
			break;
		}
	}
}
