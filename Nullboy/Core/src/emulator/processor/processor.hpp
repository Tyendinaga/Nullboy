#pragma once

#include "emulator\memory\MemoryManager.hpp"

class Processor
{

	private:
		bool halted; //Debug use Only

		//1 Byte?
		unsigned char opcode;

		//Registers
		unsigned short AFRegister;
		unsigned short BCRegister;
		unsigned short DERegister;
		unsigned short HLRegister;

		//Stack & Stack Pointer
		unsigned short stackPointer;

		//Program Counter 
		unsigned short programCounter;





	public:
		Processor();

		void initialize();
		void emulateCycle(MemoryManager memory);

		bool isHalted();

};