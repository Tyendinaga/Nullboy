//STANDARD LIBRARIES
//------------------

//EXTERNAL LIBRARIES
//------------------
#include <glad\glad.h>
#include <GLFW\glfw3.h>

//PROJECT LIBRARIES
//-----------------
#include "emulator.hpp"
#include "cartridge\cartridge.hpp"
#include "utility\logging\logger.hpp"
#include "emulator\display\display.hpp"


void Emulator::run()
{
	display window;

	window.initialize();


	//We're Live
	emulatorRunning = true;
	processor.initialize();

	//Emulator Loop
	while (emulatorRunning && !window.shouldClose())
	{
		//While things aren't burning down we will process things
		//-------------------------------------------------------
		if (!processor.inErrorState())
		{
			processor.emulateCycle(memory);
			//window.drawGraphics();
		}



		//Base GLFW Stuff to keep the window happy till I get things working
		glfwPollEvents();
	}

	glfwTerminate();
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
