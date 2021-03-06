#pragma once

//Standard Stuff
#include <string>

class Logger 
{

	private:

	public:

		enum LogLevel {
			DEBUG = 0x00,
			INFO = 0x01,
			WARNING = 0x02,
			PROBLEM = 0x03,
			SEVERE = 0x04,
		};

		//Logging Functions
		static void log(int logLevel, std::string message);
		static void log(int logLevel, std::string message, unsigned short data);
		static void log(int logLevel, std::string message, std::string data);
};