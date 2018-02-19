#pragma once

#include "emulator\memory\MemoryManager.hpp"


//Registers
struct gameboyRegister
{
	union
	{
		struct
		{
			char lo;
			char hi;
		};
		unsigned short both;
	};
};

//Something



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


		//Memory Reference
		MemoryManager memory;

		//Stack & Stack Pointer
		unsigned short stackPointer;

		//Program Counter 
		unsigned short programCounter;

		unsigned short getImmediate16();
		void advanceCounter(int value);

	public:
		Processor();

		void initialize();
		void emulateCycle(MemoryManager memory);

		bool isHalted();

};

