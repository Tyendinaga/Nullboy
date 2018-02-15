//Standard Includes
#include <iostream>
#include <sstream>

//Custom Includes
#include "logger.hpp"

void Logger::log(int logLevel, std::string message)
{
	log(logLevel, message, "");
}

void Logger::log(int logLevel, std::string message, unsigned short data)
{
	//Convert incoming Byte to HEX
	//----------------------------
	std::stringstream stream;
	stream << "0x" << std::hex << (int)data;
	std::string hexCode = stream.str();

	log(logLevel, message, hexCode);
}

void Logger::log(int logLevel, std::string message, std::string data)
{

	std::string qualifier;

	switch (logLevel)
	{
		case LogLevel::DEBUG :
		{		
			qualifier = "DEBUG: ";
			break;
		}

		case LogLevel::INFO:
		{
			qualifier = "INFO: ";
			break;
		}

		case LogLevel::WARNING:
		{
			qualifier = "WARNING: ";
			break;
		}

		case LogLevel::PROBLEM:
		{
			qualifier = "ERROR: ";
			break;
		}

		case LogLevel::SEVERE : 
		{
			qualifier = "SEVERE: ";
			break;
		}

		default: 
		{
			qualifier = "UNKNOWN: ";
			break;
		}
	}

	//FORWARD EVERYTHING TO THE CONSOLE, FOR NOW
	//------------------------------------------

	std::cout << qualifier << message << " " << data << std::endl;
}
