//Standard Shit
#include <iostream>
#include <stdexcept>

//Custom Shit
#include "commands.hpp"
#include "utility\logging\logger.hpp"

Commands::Commands(int argc, char* argv[])
{

	//Check if Valid number of Arguments
	//----------------------------------
	if (argc < 3)
	{
		throw std::invalid_argument("Incompatible Number of Arguments, Expected 3");
	}

	for (int i = 0; i < argc; i++)
	{
		
		//Convert Argument to String
		std::string arg = argv[i];
		Logger::log("ARGUMENT: ", arg);

		//Indicates the next argument is a file name
		if (arg == "-f")
		{
			//Keep Filename Around
			fileName = argv[i + 1];
		}

	}
}

std::string Commands::getFile()
{
	return fileName;
}
