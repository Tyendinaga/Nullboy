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

		//  ___   ___     _____ ______ _____  _____ ______  _____ 
		// / _ \ / _ \   / ____|  ____|  __ \|_   _|  ____|/ ____|
		//| | | | | | | | (___ | |__  | |__) | | | | |__  | (___  
		//| | | | | | |  \___ \|  __| |  _  /  | | |  __|  \___ \ 
		//| |_| | |_| |  ____) | |____| | \ \ _| |_| |____ ____) |
		// \___/ \___/  |_____/|______|_|  \_\_____|______|_____/
		//
                                                        
		case 0x00: //NOP
		{	
			//Wait Time for Four Cycles
			Logger::log(Logger::DEBUG, "NOP");
			
			//Update Program Counter
			programCounter += 1;

			//Blow this popsicle stand
			break;
		}

		case 0x01:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x02:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x03:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x04:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x05:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x06:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x07:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x08:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x09:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x0A:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x0B:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x0C:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x0D:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x0E:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x0F:
		{
			//Unimplemented
			halted = true;
			break;
		}

		// __  ___     _____ ______ _____  _____ ______  _____ 
		///_ |/ _ \   / ____|  ____|  __ \|_   _|  ____|/ ____|
		// | | | | | | (___ | |__  | |__) | | | | |__  | (___  
		// | | | | |  \___ \|  __| |  _  /  | | |  __|  \___ \ 
		// | | |_| |  ____) | |____| | \ \ _| |_| |____ ____) |
		// |_|\___/  |_____/|______|_|  \_\_____|______|_____/ 
                                                     
		case 0x10: //NOP
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x11:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x12:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x13:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x14:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x15:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x16:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x17:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x18:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x19:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x1A:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x1B:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x1C:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x1D:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x1E:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x1F:
		{
			//Unimplemented
			halted = true;
			break;
		}

		// ___   ___     _____ ______ _____  _____ ______  _____ 
		//|__ \ / _ \   / ____|  ____|  __ \|_   _|  ____|/ ____|
		//   ) | | | | | (___ | |__  | |__) | | | | |__  | (___  
		//  / /| | | |  \___ \|  __| |  _  /  | | |  __|  \___ \ 
		// / /_| |_| |  ____) | |____| | \ \ _| |_| |____ ____) |
		//|____|\___/  |_____/|______|_|  \_\_____|______|_____/ 

		case 0x20: //NOP
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x21:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x22:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x23:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x24:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x25:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x26:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x27:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x28:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x29:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x2A:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x2B:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x2C:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x2D:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x2E:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x2F:
		{
			//Unimplemented
			halted = true;
			break;
		}

		// ____   ___     _____ ______ _____  _____ ______  _____ 
		//|___ \ / _ \   / ____|  ____|  __ \|_   _|  ____|/ ____|
		//  __) | | | | | (___ | |__  | |__) | | | | |__  | (___  
		// |__ <| | | |  \___ \|  __| |  _  /  | | |  __|  \___ \ 
		// ___) | |_| |  ____) | |____| | \ \ _| |_| |____ ____) |
		//|____/ \___/  |_____/|______|_|  \_\_____|______|_____/ 

		// _  _    ___     _____ ______ _____  _____ ______  _____ 
		//| || |  / _ \   / ____|  ____|  __ \|_   _|  ____|/ ____|
		//| || |_| | | | | (___ | |__  | |__) | | | | |__  | (___  
		//|__   _| | | |  \___ \|  __| |  _  /  | | |  __|  \___ \ 
		//   | | | |_| |  ____) | |____| | \ \ _| |_| |____ ____) |
		//   |_|  \___/  |_____/|______|_|  \_\_____|______|_____/ 

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

		// _____  ___     _____ ______ _____  _____ ______  _____ 
		//| ____|/ _ \   / ____|  ____|  __ \|_   _|  ____|/ ____|
		//| |__ | | | | | (___ | |__  | |__) | | | | |__  | (___  
		//|___ \| | | |  \___ \|  __| |  _  /  | | |  __|  \___ \ 
		// ___) | |_| |  ____) | |____| | \ \ _| |_| |____ ____) |
		//|____/ \___/  |_____/|______|_|  \_\_____|______|_____/ 

		//   __   ___     _____ ______ _____  _____ ______  _____ 
		//  / /  / _ \   / ____|  ____|  __ \|_   _|  ____|/ ____|
		// / /_ | | | | | (___ | |__  | |__) | | | | |__  | (___  
		//| '_ \| | | |  \___ \|  __| |  _  /  | | |  __|  \___ \ 
		//| (_) | |_| |  ____) | |____| | \ \ _| |_| |____ ____) |
		// \___/ \___/  |_____/|______|_|  \_\_____|______|_____/ 

		// ______ ___     _____ ______ _____  _____ ______  _____ 
		//|____  / _ \   / ____|  ____|  __ \|_   _|  ____|/ ____|
		//    / / | | | | (___ | |__  | |__) | | | | |__  | (___  
		//   / /| | | |  \___ \|  __| |  _  /  | | |  __|  \___ \ 
		//  / / | |_| |  ____) | |____| | \ \ _| |_| |____ ____) |
		// /_/   \___/  |_____/|______|_|  \_\_____|______|_____/ 

		//  ___   ___     _____ ______ _____  _____ ______  _____ 
		// / _ \ / _ \   / ____|  ____|  __ \|_   _|  ____|/ ____|
		//| (_) | | | | | (___ | |__  | |__) | | | | |__  | (___  
		// > _ <| | | |  \___ \|  __| |  _  /  | | |  __|  \___ \ 
		//| (_) | |_| |  ____) | |____| | \ \ _| |_| |____ ____) |
		// \___/ \___/  |_____/|______|_|  \_\_____|______|_____/ 

		//  ___   ___     _____ ______ _____  _____ ______  _____ 
		// / _ \ / _ \   / ____|  ____|  __ \|_   _|  ____|/ ____|
		//| (_) | | | | | (___ | |__  | |__) | | | | |__  | (___  
		// \__, | | | |  \___ \|  __| |  _  /  | | |  __|  \___ \ 
		//   / /| |_| |  ____) | |____| | \ \ _| |_| |____ ____) |
		//  /_/  \___/  |_____/|______|_|  \_\_____|______|_____/ 
                                                        
		//          ___     _____ ______ _____  _____ ______  _____ 
		//    /\   / _ \   / ____|  ____|  __ \|_   _|  ____|/ ____|
		//   /  \ | | | | | (___ | |__  | |__) | | | | |__  | (___  
		//  / /\ \| | | |  \___ \|  __| |  _  /  | | |  __|  \___ \ 
		// / ____ \ |_| |  ____) | |____| | \ \ _| |_| |____ ____) |
		///_/    \_\___/  |_____/|______|_|  \_\_____|______|_____/ 

		// ____   ___     _____ ______ _____  _____ ______  _____ 
		//|  _ \ / _ \   / ____|  ____|  __ \|_   _|  ____|/ ____|
		//| |_) | | | | | (___ | |__  | |__) | | | | |__  | (___  
		//|  _ <| | | |  \___ \|  __| |  _  /  | | |  __|  \___ \ 
		//| |_) | |_| |  ____) | |____| | \ \ _| |_| |____ ____) |
		//|____/ \___/  |_____/|______|_|  \_\_____|______|_____/ 
                                                        
		//  _____ ___     _____ ______ _____  _____ ______  _____ 
		// / ____/ _ \   / ____|  ____|  __ \|_   _|  ____|/ ____|
		//| |   | | | | | (___ | |__  | |__) | | | | |__  | (___  
		//| |   | | | |  \___ \|  __| |  _  /  | | |  __|  \___ \ 
		//| |___| |_| |  ____) | |____| | \ \ _| |_| |____ ____) |
		// \_____\___/  |_____/|______|_|  \_\_____|______|_____/ 

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


		// _____   ___     _____ ______ _____  _____ ______  _____ 
		//|  __ \ / _ \   / ____|  ____|  __ \|_   _|  ____|/ ____|
		//| |  | | | | | | (___ | |__  | |__) | | | | |__  | (___  
		//| |  | | | | |  \___ \|  __| |  _  /  | | |  __|  \___ \ 
		//| |__| | |_| |  ____) | |____| | \ \ _| |_| |____ ____) |
		//|_____/ \___/  |_____/|______|_|  \_\_____|______|_____/ 

		// ______ ___     _____ ______ _____  _____ ______  _____ 
		//|  ____/ _ \   / ____|  ____|  __ \|_   _|  ____|/ ____|
		//| |__ | | | | | (___ | |__  | |__) | | | | |__  | (___  
		//|  __|| | | |  \___ \|  __| |  _  /  | | |  __|  \___ \ 
		//| |___| |_| |  ____) | |____| | \ \ _| |_| |____ ____) |
		//|______\___/  |_____/|______|_|  \_\_____|______|_____/ 

		// ______ ___     _____ ______ _____  _____ ______  _____ 
		//|  ____/ _ \   / ____|  ____|  __ \|_   _|  ____|/ ____|
		//| |__ | | | | | (___ | |__  | |__) | | | | |__  | (___  
		//|  __|| | | |  \___ \|  __| |  _  /  | | |  __|  \___ \ 
		//| |   | |_| |  ____) | |____| | \ \ _| |_| |____ ____) |
		//|_|    \___/  |_____/|______|_|  \_\_____|______|_____/ 

		//Situation Normal, All fucked up. 
		default:
		{
			halted = true;
			break;
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

