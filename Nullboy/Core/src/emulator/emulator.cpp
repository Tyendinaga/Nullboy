//STANDARD LIBRARIES
//------------------

//EXTERNAL LIBRARIES
//------------------

//PROJECT LIBRARIES
//-----------------
#include "emulator.hpp"
#include "cartridge\cartridge.hpp"
#include "utility\logging\logger.hpp"

void Emulator::run()
{
	


	//We're Live
	emulatorRunning = true;
	processor.initialize();

	//Emulator Loop
	while (emulatorRunning)
	{
		//While shit isn't burning down we'll process things
		//--------------------------------------------------
		if (!processor.isHalted())
		{
			processor.emulateCycle(memory);
		}
	}
}

void Emulator::loadMemory()
{
	//Let's start by transferring the first bank over.
	//Doing so will allow us to begin processing OP Codes

	Logger::log(Logger::INFO, "=== LOADING CARTRIDGE INTO MEMORY MANAGER");




	//for (int i = 0x0000; i <= 0x3FFF; i++)
	for (int i = 0x0000; i <= 0x7FFF; i++)
	{
		unsigned char data = cartridge.readByte(i);
		memory.writeByte(i, data);
	}

}

Emulator::Emulator(Cartridge cartridge, Commands commands)
{

	//Get some local copies of variables
	this->cartridge = cartridge;
	this->commands = commands;

	//Let's load up our Memory
	this->loadMemory();

	//Make the Magic Happen
	this->run();
}
