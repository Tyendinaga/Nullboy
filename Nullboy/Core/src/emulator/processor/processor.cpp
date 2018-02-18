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
                                                     
		case 0x10: 
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

		case 0x20:
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

		case 0x30:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x31:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x32:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x33:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x34:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x35:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x36:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x37:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x38:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x39:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x3A:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x3B:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x3C:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x3D:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x3E:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x3F:
		{
			//Unimplemented
			halted = true;
			break;
		}

		// _  _    ___     _____ ______ _____  _____ ______  _____ 
		//| || |  / _ \   / ____|  ____|  __ \|_   _|  ____|/ ____|
		//| || |_| | | | | (___ | |__  | |__) | | | | |__  | (___  
		//|__   _| | | |  \___ \|  __| |  _  /  | | |  __|  \___ \ 
		//   | | | |_| |  ____) | |____| | \ \ _| |_| |____ ____) |
		//   |_|  \___/  |_____/|______|_|  \_\_____|______|_____/ 

		case 0x40:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x41:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x42:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x43:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x44:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x45:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x46:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x47:
		{
			//Unimplemented
			halted = true;
			break;
		}

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

		case 0x4B:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x4C:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x4D:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x4E:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x4F:
		{
			//Unimplemented
			halted = true;
			break;
		}

		// _____  ___     _____ ______ _____  _____ ______  _____ 
		//| ____|/ _ \   / ____|  ____|  __ \|_   _|  ____|/ ____|
		//| |__ | | | | | (___ | |__  | |__) | | | | |__  | (___  
		//|___ \| | | |  \___ \|  __| |  _  /  | | |  __|  \___ \ 
		// ___) | |_| |  ____) | |____| | \ \ _| |_| |____ ____) |
		//|____/ \___/  |_____/|______|_|  \_\_____|______|_____/ 

		case 0x50:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x51:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x52:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x53:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x54:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x55:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x56:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x57:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x58:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x59:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x5A:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x5B:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x5C:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x5D:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x5E:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x5F:
		{
			//Unimplemented
			halted = true;
			break;
		}

		//   __   ___     _____ ______ _____  _____ ______  _____ 
		//  / /  / _ \   / ____|  ____|  __ \|_   _|  ____|/ ____|
		// / /_ | | | | | (___ | |__  | |__) | | | | |__  | (___  
		//| '_ \| | | |  \___ \|  __| |  _  /  | | |  __|  \___ \ 
		//| (_) | |_| |  ____) | |____| | \ \ _| |_| |____ ____) |
		// \___/ \___/  |_____/|______|_|  \_\_____|______|_____/ 

		case 0x60:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x61:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x62:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x63:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x64:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x65:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x66:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x67:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x68:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x69:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x6A:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x6B:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x6C:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x6D:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x6E:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x6F:
		{
			//Unimplemented
			halted = true;
			break;
		}

		// ______ ___     _____ ______ _____  _____ ______  _____ 
		//|____  / _ \   / ____|  ____|  __ \|_   _|  ____|/ ____|
		//    / / | | | | (___ | |__  | |__) | | | | |__  | (___  
		//   / /| | | |  \___ \|  __| |  _  /  | | |  __|  \___ \ 
		//  / / | |_| |  ____) | |____| | \ \ _| |_| |____ ____) |
		// /_/   \___/  |_____/|______|_|  \_\_____|______|_____/ 

		case 0x70:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x71:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x72:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x73:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x74:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x75:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x76:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x77:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x78:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x79:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x7A:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x7B:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x7C:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x7D:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x7E:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x7F:
		{
			//Unimplemented
			halted = true;
			break;
		}

		//  ___   ___     _____ ______ _____  _____ ______  _____ 
		// / _ \ / _ \   / ____|  ____|  __ \|_   _|  ____|/ ____|
		//| (_) | | | | | (___ | |__  | |__) | | | | |__  | (___  
		// > _ <| | | |  \___ \|  __| |  _  /  | | |  __|  \___ \ 
		//| (_) | |_| |  ____) | |____| | \ \ _| |_| |____ ____) |
		// \___/ \___/  |_____/|______|_|  \_\_____|______|_____/ 

		case 0x80:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x81:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x82:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x83:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x84:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x85:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x86:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x87:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x88:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x89:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x8A:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x8B:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x8C:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x8D:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x8E:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x8F:
		{
			//Unimplemented
			halted = true;
			break;
		}

		//  ___   ___     _____ ______ _____  _____ ______  _____ 
		// / _ \ / _ \   / ____|  ____|  __ \|_   _|  ____|/ ____|
		//| (_) | | | | | (___ | |__  | |__) | | | | |__  | (___  
		// \__, | | | |  \___ \|  __| |  _  /  | | |  __|  \___ \ 
		//   / /| |_| |  ____) | |____| | \ \ _| |_| |____ ____) |
		//  /_/  \___/  |_____/|______|_|  \_\_____|______|_____/ 

		case 0x90:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x91:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x92:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x93:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x94:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x95:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x96:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x97:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x98:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x99:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x9A:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x9B:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x9C:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x9D:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x9E:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0x9F:
		{
			//Unimplemented
			halted = true;
			break;
		}

		//          ___     _____ ______ _____  _____ ______  _____ 
		//    /\   / _ \   / ____|  ____|  __ \|_   _|  ____|/ ____|
		//   /  \ | | | | | (___ | |__  | |__) | | | | |__  | (___  
		//  / /\ \| | | |  \___ \|  __| |  _  /  | | |  __|  \___ \ 
		// / ____ \ |_| |  ____) | |____| | \ \ _| |_| |____ ____) |
		///_/    \_\___/  |_____/|______|_|  \_\_____|______|_____/ 

		case 0xA0:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xA1:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xA2:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xA3:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xA4:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xA5:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xA6:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xA7:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xA8:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xA9:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xAA:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xAB:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xAC:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xAD:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xAE:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xAF:
		{
			//Unimplemented
			halted = true;
			break;
		}

		// ____   ___     _____ ______ _____  _____ ______  _____ 
		//|  _ \ / _ \   / ____|  ____|  __ \|_   _|  ____|/ ____|
		//| |_) | | | | | (___ | |__  | |__) | | | | |__  | (___  
		//|  _ <| | | |  \___ \|  __| |  _  /  | | |  __|  \___ \ 
		//| |_) | |_| |  ____) | |____| | \ \ _| |_| |____ ____) |
		//|____/ \___/  |_____/|______|_|  \_\_____|______|_____/ 

		case 0xB0:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xB1:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xB2:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xB3:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xB4:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xB5:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xB6:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xB7:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xB8:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xB9:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xBA:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xBB:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xBC:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xBD:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xBE:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xBF:
		{
			//Unimplemented
			halted = true;
			break;
		}

		//  _____ ___     _____ ______ _____  _____ ______  _____ 
		// / ____/ _ \   / ____|  ____|  __ \|_   _|  ____|/ ____|
		//| |   | | | | | (___ | |__  | |__) | | | | |__  | (___  
		//| |   | | | |  \___ \|  __| |  _  /  | | |  __|  \___ \ 
		//| |___| |_| |  ____) | |____| | \ \ _| |_| |____ ____) |
		// \_____\___/  |_____/|______|_|  \_\_____|______|_____/ 

		case 0xC0:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xC1:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xC2:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xC3:
		{
			//JUMP
			Logger::log(Logger::DEBUG, "JPnn");

			//Combine the Next two data values into a new Program Counter Value
			//TODO Shorten this into a single line. 
			unsigned short target = memory.readByte(programCounter + 1);
			target <<= CHAR_BIT;
			target += memory.readByte(programCounter + 2);

			//Complete Jump to New Value
			programCounter = target;

			break;
		}

		case 0xC4:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xC5:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xC6:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xC7:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xC8:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xC9:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xCA:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xCB:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xCC:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xCD:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xCE:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xCF:
		{
			//Unimplemented
			halted = true;
			break;
		}


		// _____   ___     _____ ______ _____  _____ ______  _____ 
		//|  __ \ / _ \   / ____|  ____|  __ \|_   _|  ____|/ ____|
		//| |  | | | | | | (___ | |__  | |__) | | | | |__  | (___  
		//| |  | | | | |  \___ \|  __| |  _  /  | | |  __|  \___ \ 
		//| |__| | |_| |  ____) | |____| | \ \ _| |_| |____ ____) |
		//|_____/ \___/  |_____/|______|_|  \_\_____|______|_____/ 

		case 0xD0:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xD1:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xD2:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xD3:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xD4:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xD5:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xD6:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xD7:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xD8:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xD9:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xDA:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xDB:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xDC:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xDD:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xDE:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xDF:
		{
			//Unimplemented
			halted = true;
			break;
		}

		// ______ ___     _____ ______ _____  _____ ______  _____ 
		//|  ____/ _ \   / ____|  ____|  __ \|_   _|  ____|/ ____|
		//| |__ | | | | | (___ | |__  | |__) | | | | |__  | (___  
		//|  __|| | | |  \___ \|  __| |  _  /  | | |  __|  \___ \ 
		//| |___| |_| |  ____) | |____| | \ \ _| |_| |____ ____) |
		//|______\___/  |_____/|______|_|  \_\_____|______|_____/ 

		case 0xE0:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xE1:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xE2:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xE3:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xE4:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xE5:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xE6:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xE7:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xE8:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xE9:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xEA:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xEB:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xEC:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xED:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xEE:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xEF:
		{
			//Unimplemented
			halted = true;
			break;
		}

		// ______ ___     _____ ______ _____  _____ ______  _____ 
		//|  ____/ _ \   / ____|  ____|  __ \|_   _|  ____|/ ____|
		//| |__ | | | | | (___ | |__  | |__) | | | | |__  | (___  
		//|  __|| | | |  \___ \|  __| |  _  /  | | |  __|  \___ \ 
		//| |   | |_| |  ____) | |____| | \ \ _| |_| |____ ____) |
		//|_|    \___/  |_____/|______|_|  \_\_____|______|_____/ 

		case 0xF0:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xF1:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xF2:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xF3:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xF4:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xF5:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xF6:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xF7:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xF8:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xF9:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xFA:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xFB:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xFC:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xFD:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xFE:
		{
			//Unimplemented
			halted = true;
			break;
		}

		case 0xFF:
		{
			//Unimplemented
			halted = true;
			break;
		}

		// _____  ______ ______     _    _ _   _______ 
		//|  __ \|  ____|  ____/\  | |  | | | |__   __|
		//| |  | | |__  | |__ /  \ | |  | | |    | |   
		//| |  | |  __| |  __/ /\ \| |  | | |    | |   
		//| |__| | |____| | / ____ \ |__| | |____| |   
		//|_____/|______|_|/_/    \_\____/|______|_|   
                                             
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

