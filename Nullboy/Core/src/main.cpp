//STANDARD LIBRARIES
//------------------
#include <cstdlib>
#include <iostream>

//EXTERNAL LIBRARIES
//------------------

//PROJECT LIBRARIES
//-----------------
#include "utility\commands\commands.hpp";
#include "utility\logging\logger.hpp";
#include "emulator\cartridge\cartridge.hpp"
#include "emulator\emulator.hpp"

#include "emulator\memory\MemoryManager.hpp"

//#ifdef _MSC_VER
//#    pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
//#endif

//PROGRAM ENTRY POINT
//-------------------
int main(int argc, char* argv[])
{
	//Pre Setup for Emulator Run
	//--------------------------
	try 
	{ 
		Logger::log(Logger::INFO,"=== BEGINNING PROGRAM EXECUTION");

		//Parse Commandline Arguments
		//---------------------------
		Logger::log(Logger::INFO, "=== PREPARING TO PARSE ARGUMENTS");
		Commands command(argc, argv);

		//Load Cartridge into Memory
		//--------------------------
		Logger::log(Logger::INFO, "=== PREPARING TO LOAD CARTRIDGE");
		Cartridge cart(command.getFile());

		//Begin the Emulation
		//-------------------
		Logger::log(Logger::INFO, "=== PREPARING TO START EMULATOR");
		Emulator emulator(cart, command);

	}
	catch (const std::invalid_argument& e)
	{
		Logger::log(Logger::PROBLEM, e.what());
		return EXIT_FAILURE;
	}
	
	//Pause the Execution
	std::cin.get();

	return EXIT_SUCCESS;
}