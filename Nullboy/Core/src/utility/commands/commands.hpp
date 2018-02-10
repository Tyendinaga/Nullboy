#pragma once

//Standard Includes
#include <string>

class Commands {

	private:
		std::string fileName;

	public:
		Commands(int argc, char* argv[]);
		Commands();

		std::string getFile();

};