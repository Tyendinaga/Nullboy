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

struct flagRegister
{
	union
	{
		struct
		{
			bool z;
			bool n;
			bool h;
			bool c;
		};
		char flags;
	};
};

//Something



class Processor
{

	private:
		
		//
		bool halted;
	
		//
		unsigned char opcode;

		//Registers
		gameboyRegister AFRegister;
		gameboyRegister BCRegister;
		gameboyRegister DERegister;
		gameboyRegister HLRegister;
		unsigned short stackPointer;
		unsigned short programCounter;

		//Memory Reference
		MemoryManager memory;



		//Memory Reads and Writes
		unsigned short getImmediate16();
		unsigned char getImmediate8();
		void writeData16(int address, gameboyRegister data);
		void writeData8(int address, char data);
		unsigned short readData16(int address);
		unsigned char readData8(int address);

		void processOpCode();
		void processExtendedOpCode();

		//Handles Program Counter
		void advanceCounter(int value);

	public:
		Processor();

		
		void initialize();
		void emulateCycle(MemoryManager memory);
		bool isHalted();

};

