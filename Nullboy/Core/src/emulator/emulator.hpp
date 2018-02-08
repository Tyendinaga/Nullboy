#pragma once

//Standard Includes
#include <string>

//Custom Includes
#include "processor\processor.hpp"
#include "cartridge\cartridge.hpp"

class Emulator 
{

	private:
		void run();

		bool emulatorRunning;

		Processor processor;
		

	public:
		Emulator(Cartridge cart);
};