#pragma once

//Standard Crap
#include <string>

class Logger 
{

	private:

	public:

		
		enum LogLevel {
			DEBUG = 0x00,
			INFO = 0x01,
			WARNING = 0x02,
			ERROR = 0x03,
			SEVERE = 0x04,
		};

		//Logging Functions
		static void log(int logLevel, std::string message);
		static void log(int logLevel, std::string message, unsigned char data);
		static void log(int logLevel, std::string message, std::string data);
};