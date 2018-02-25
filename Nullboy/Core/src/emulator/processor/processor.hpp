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
			unsigned z7:1;
			unsigned n6:1;
			unsigned h5:1;
			unsigned c4:1;
			unsigned x3:1;
			unsigned x2:1;
			unsigned x1:1;
			unsigned x0:1;
		};
		unsigned char flags;
	};
};

//Something



class Processor
{

	private:
		
		//Unimplemented Instruction
		bool errorState;
	
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
		void handleCycles(int value);

		

	public:
		Processor();

		
		void initialize();
		void emulateCycle(MemoryManager memory);
		bool inErrorState();

};

