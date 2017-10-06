#pragma once

//Standard Shit
#include <string>

class Commands {

	private:
		std::string fileName;

	public:
		Commands(int argc, char* argv[]);

		std::string getFile();

};