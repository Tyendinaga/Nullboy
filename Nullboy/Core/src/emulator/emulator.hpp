#pragma once

//Standard Includes
#include <string>

//Custom Includes
#include "processor\processor.hpp"
#include "cartridge\cartridge.hpp"
#include "utility\commands\commands.hpp"

class Emulator 
{

	private:
		
		//Methods
		void run();

		//Variables
		
		Processor processor;
		Cartridge cartridge;
		Commands commands;

		bool emulatorRunning;

	public:
		Emulator(Cartridge cartridge, Commands commands);
};