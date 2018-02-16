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

	AFRegister.both = 0x01B0;
	BCRegister.both = 0x0013;
	DERegister.both = 0x00D8;
	HLRegister.both = 0x014D;
	
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
	//Turns out I have to read them as 8bits instead of 16bits. 
	//This means a lot of bitwise operations in my future. 
	opcode = memory.readByte(programCounter);
	

	//Do Magic
	switch (opcode)
	{

		
		//00 Series
		case 0x00:
		{	
			//Wait Time for Four Cycles
			Logger::log(Logger::DEBUG, "NOP");
			
			//Update Program Counter
			programCounter += 1;

			//Blow this popsicle stand
			break;
		}

		//10

		//20

		//30

		//40
		case 0x48:
		{
			//LD C, B

			//Copy B to C
			BCRegister.lo = BCRegister.hi;

			//Update Program Counter
			programCounter += 1;

			break;
		}

		case 0x49:
		{
			//LD C, C

			//Copy C to C
			BCRegister.lo = BCRegister.lo;

			//Update Program Counter
			programCounter += 1;

			break;
		}

		case 0x4A:
		{
			//LD C, D

			//Copy D to C
			BCRegister.lo = DERegister.hi;

			//Update Program Counter
			programCounter += 1;

			break;
		}

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

			//Combine the Next two data values into a new Program Counter Value
			//TODO Shorten this into a single line. 
			unsigned short target = memory.readByte(programCounter + 1);
			target <<=CHAR_BIT;
			target += memory.readByte(programCounter + 2);

			//Complete Jump to New Value
			programCounter = target;

			break;
		}


		//Situation Normal, All fucked up. 
		default:
		{
			halted = true;
		}
	}

	//Increment memory position provided we are not halted.
	//This logic I pulled from my CHIP8 Emulator isn't going to cut it here.
	//The variable length instructions will see to that. 
	if (!halted)
	{
		//programCounter += 1;
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

