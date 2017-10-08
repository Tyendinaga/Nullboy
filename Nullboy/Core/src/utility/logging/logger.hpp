#pragma once

//Standard Crap
#include <string>

class Logger 
{

	private:

	public:

		
		enum LogLevel {
			DBUG = 0x00,
			INFO = 0x01,
			WARN = 0x02,
			ERRO = 0x03,
			SEVR = 0x04,
		};

		//Logging Functions
		static void log(std::string message);
		static void log(std::string qualifier, std::string message);
		static void log(std::string qualifier, unsigned char message);
		static void log(int LogLevel, std::string message);
};