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

void Processor::emulateCycle(MemoryManager memory)
{

	//Hit a Road Block. Not sure how to decode the Z80 Codes

	opcode = memory.readByte(programCounter);

	//Do Magic
	switch (opcode)
	{

		
		//00 Series
		case 0x00:
		{	
			//Wate Time for Four Cycles
			Logger::log(Logger::DEBUG, "NOP");
			break;
		}

		//10

		//20

		//30

		//40

		//50

		//60

		//70

		//80

		//90

		//A0

		//B0

		//C0

		case 0xC3:
		{
			//JUMP
			Logger::log(Logger::DEBUG, "JPnn");
			break;
		}


		//Situation Normal, All fucked up. 
		default:
		{
			halted = true;
		}
	}

	//Increment memory position provided we are not halted.
	if (!halted)
	{
		programCounter += 1;
		Logger::log(Logger::DEBUG, "Processed Code: ", opcode);
	}
	else
	{
		Logger::log(Logger::DEBUG, "Unknown Opcode: ", opcode);
	}

}

bool Processor::isHalted()
{
	return halted;
}

