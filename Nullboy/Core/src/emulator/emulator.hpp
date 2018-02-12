#pragma once

//Standard Includes
#include <string>

//Custom Includes
#include "processor\processor.hpp"
#include "cartridge\cartridge.hpp"
#include "utility\commands\commands.hpp"
#include "memory\MemoryManager.hpp"

class Emulator 
{

	private:
		
		//Methods
		void run();
		void loadMemory();

		//Variables
		Processor processor;
		Cartridge cartridge;
		Commands commands;
		MemoryManager memory;



		bool emulatorRunning;

	public:
		Emulator(Cartridge cartridge, Commands commands);
};

