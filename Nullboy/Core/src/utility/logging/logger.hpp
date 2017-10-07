#pragma once

//Standard Crap
#include <string>

class Logger 
{

	private:

	public:
		static void log(std::string message);
		static void log(std::string qualifier, std::string message);
		static void log(std::string qualifier, unsigned char message);
};