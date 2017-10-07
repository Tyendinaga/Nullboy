//Standard Crap
#include <cstdlib>
#include <iostream>

//External Shit

//Custom Shit
#include "utility\commands\commands.hpp";
#include "utility\logging\logger.hpp";
#include "emulator\cartridge\cartridge.hpp"

int main(int argc, char* argv[])
{
	//Pre Setup for Emulator Run
	//--------------------------
	try 
	{
		Logger::log("INFO: ","BEGINNING PROGRAM EXECUTION");

		//Parse Commandline Arguments
		//---------------------------
		Logger::log("INFO: ", "PREPARING TO PARSE ARGUMENTS");
		Commands command(argc, argv);

		//Load Cartridge into Memory
		//--------------------------
		Logger::log("INFO: ", "PREPARING TO LOAD CARTRIDGE");
		Cartridge cart(command.getFile());

		//Begin the Emulation
		//-------------------
		Logger::log("INFO: ", "PREPARING TO START EMULATOR");

	}
	catch (const std::invalid_argument& e)
	{
		Logger::log("ERROR: " , e.what());
		return EXIT_FAILURE;
	}
	
	//Hold the Execution
	std::cin.get();

	return EXIT_SUCCESS;
}