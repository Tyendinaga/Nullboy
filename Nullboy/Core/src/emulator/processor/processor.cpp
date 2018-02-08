//Custom Includes
#include "processor.hpp"
#include "utility\logging\logger.hpp"

Processor::Processor()
{

	

}

void Processor::initialize()
{
	//MAKING EVERYTHING NICE AND GOOD TO START
	//----------------------------------------

	//Default Register Values
	AFRegister = 0x01B0;
	BCRegister = 0x0013;
	DERegister = 0x00D8;
	HLRegister = 0x014D;
	
	//Stack
	stackPointer = 0xFFFE;

	//Program Counter
	programCounter = 0x0100;

	//Debug Flagging
	halted = false;

}

void Processor::emulateCycle()
{
	//Fetch OpCode
	//opcode = memory[programCounter] << 8 | memory[programCounter + 1];

	/*
		Identifying Op Codes
		No Idea, Yet
	*/

	//Do Magic
	switch (opcode & 0xf000)
	{
		//Situation Normal, All fucked up. 
		default:
		{
			halted = true;
		}
	}

	//Increment memory position provided we are not halted.
	if (!halted)
	{
		programCounter += 2;
		Logger::log(Logger::DEBUG, "Processed Code: 0x", opcode);
	}
	else
	{
		Logger::log(Logger::DEBUG, "Unknown Opcode: 0x", opcode);
	}

}

bool Processor::isHalted()
{
	return halted;
}

