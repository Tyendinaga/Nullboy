#pragma once

#include "emulator\memory\MemoryManager.hpp"


//Registers
struct gameboyRegister
{
	union
	{
		unsigned short both;
		struct
		{
			char hi;
			char lo;
		};
	};
};

class Processor
{

	private:
		bool halted; //Debug use Only

		//1 Byte?
		unsigned char opcode;

		gameboyRegister AFRegister;
		gameboyRegister BCRegister;
		gameboyRegister DERegister;
		gameboyRegister HLRegister;

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

