//Custom Includes
#include "processor.hpp"
#include "utility\logging\logger.hpp"

Processor::Processor()
{

}


// _____  ______  _____ ______ _______ 
//|  __ \|  ____|/ ____|  ____|__   __|
//| |__) | |__  | (___ | |__     | |   
//|  _  /|  __|  \___ \|  __|    | |   
//| | \ \| |____ ____) | |____   | |   
//|_|  \_\______|_____/|______|  |_|   

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
	errorState = false;

	//Write Memory
	memory.writeByte(0xFF05, 0x00);
	memory.writeByte(0xFF06, 0x00);
	memory.writeByte(0xFF07, 0x00);
	memory.writeByte(0xFF10, 0x80);
	memory.writeByte(0xFF11, 0xBF);
	memory.writeByte(0xFF12, 0xF3);
	memory.writeByte(0xFF14, 0xBF);
	memory.writeByte(0xFF16, 0x3F);
	memory.writeByte(0xFF17, 0x00);
	memory.writeByte(0xFF19, 0xBF);
	memory.writeByte(0xFF1A, 0x7A);
	memory.writeByte(0xFF1B, 0xFF);
	memory.writeByte(0xFF1C, 0x9F);
	memory.writeByte(0xFF1E, 0xBF);
	memory.writeByte(0xFF20, 0xFF);
	memory.writeByte(0xFF21, 0x00);
	memory.writeByte(0xFF22, 0x00);
	memory.writeByte(0xFF23, 0xBF);
	memory.writeByte(0xFF24, 0x77);
	memory.writeByte(0xFF25, 0xF3);
	memory.writeByte(0xFF26, 0xF1);
	memory.writeByte(0xFF40, 0x91);
	memory.writeByte(0xFF42, 0x00);
	memory.writeByte(0xFF43, 0x00);
	memory.writeByte(0xFF45, 0x00);
	memory.writeByte(0xFF47, 0xFC);
	memory.writeByte(0xFF48, 0xFF);
	memory.writeByte(0xFF49, 0xFF);
	memory.writeByte(0xFF4A, 0x00);
	memory.writeByte(0xFF4B, 0x00);
	memory.writeByte(0xFFFF, 0x00);

}

bool Processor::inErrorState()
{
	return errorState;
}


// __  __ ______ __  __  ____  _______     __   ____  _____  ______ _____         _______ _____ ____  _   _  _____ 
//|  \/  |  ____|  \/  |/ __ \|  __ \ \   / /  / __ \|  __ \|  ____|  __ \     /\|__   __|_   _/ __ \| \ | |/ ____|
//| \  / | |__  | \  / | |  | | |__) \ \_/ /  | |  | | |__) | |__  | |__) |   /  \  | |    | || |  | |  \| | (___  
//| |\/| |  __| | |\/| | |  | |  _  / \   /   | |  | |  ___/|  __| |  _  /   / /\ \ | |    | || |  | | . ` |\___ \ 
//| |  | | |____| |  | | |__| | | \ \  | |    | |__| | |    | |____| | \ \  / ____ \| |   _| || |__| | |\  |____) |
//|_|  |_|______|_|  |_|\____/|_|  \_\ |_|     \____/|_|    |______|_|  \_\/_/    \_\_|  |_____\____/|_| \_|_____/ 

unsigned short Processor::getImmediate16()
{
	//Get 16 Bit Immediate Value			
	gameboyRegister temp;
	temp.lo = memory.readByte(programCounter + 1);
	temp.hi = memory.readByte(programCounter + 2);

	return temp.both;
}

unsigned char Processor::getImmediate8()
{
	return memory.readByte(programCounter + 1);
}

void Processor::writeData16(int address, gameboyRegister data)
{
	memory.writeByte(address, data.lo);
	memory.writeByte(address + 1, data.hi);
}

void Processor::writeData8(int address, char data)
{
	memory.writeByte(address, data);
}

unsigned short Processor::readData16(int address)
{
	gameboyRegister temp;

	temp.lo = memory.readByte(address);
	temp.hi = memory.readByte(address + 1);

	return temp.both;
}

unsigned char Processor::readData8(int address)
{
	return memory.readByte(address);
}

// _      ____   _____ _____ _____          _         ____  _____  ______ _____         _______ _____ ____  _   _  _____ 
//| |    / __ \ / ____|_   _/ ____|   /\   | |       / __ \|  __ \|  ____|  __ \     /\|__   __|_   _/ __ \| \ | |/ ____|
//| |   | |  | | |  __  | || |       /  \  | |      | |  | | |__) | |__  | |__) |   /  \  | |    | || |  | |  \| | (___  
//| |   | |  | | | |_ | | || |      / /\ \ | |      | |  | |  ___/|  __| |  _  /   / /\ \ | |    | || |  | | . ` |\___ \ 
//| |___| |__| | |__| |_| || |____ / ____ \| |____  | |__| | |    | |____| | \ \  / ____ \| |   _| || |__| | |\  |____) |
//|______\____/ \_____|_____\_____/_/    \_\______|  \____/|_|    |______|_|  \_\/_/    \_\_|  |_____\____/|_| \_|_____/ 

void Processor::advanceCounter(int value)
{
	programCounter = programCounter + value;
}

void Processor::handleCycles(int value)
{
	//DO NOTHING
}

// _____ _   _  _____ _______ _____  _    _  _____ _______ _____ ____  _   _   _    _          _   _ _____  _      _____ _   _  _____ 
//|_   _| \ | |/ ____|__   __|  __ \| |  | |/ ____|__   __|_   _/ __ \| \ | | | |  | |   /\   | \ | |  __ \| |    |_   _| \ | |/ ____|
//  | | |  \| | (___    | |  | |__) | |  | | |       | |    | || |  | |  \| | | |__| |  /  \  |  \| | |  | | |      | | |  \| | |  __ 
//  | | | . ` |\___ \   | |  |  _  /| |  | | |       | |    | || |  | | . ` | |  __  | / /\ \ | . ` | |  | | |      | | | . ` | | |_ |
// _| |_| |\  |____) |  | |  | | \ \| |__| | |____   | |   _| || |__| | |\  | | |  | |/ ____ \| |\  | |__| | |____ _| |_| |\  | |__| |
//|_____|_| \_|_____/   |_|  |_|  \_\\____/ \_____|  |_|  |_____\____/|_| \_| |_|  |_/_/    \_\_| \_|_____/|______|_____|_| \_|\_____|


void Processor::emulateCycle(MemoryManager memory)
{

	//Reassign Memory
	this->memory = memory;

	//Get Instruction
	opcode = memory.readByte(programCounter);

	//Handle Instruction
	processOpCode();

	if (!errorState)
	{
		//programCounter += 1;
		Logger::log(Logger::DEBUG, "Processed Code: ", opcode);
	}
	else
	{
		Logger::log(Logger::DEBUG, "Unknown Opcode: ", opcode);
	}
}

//This function processes regular OP Codes in the Gameboy CPU
void Processor::processOpCode()
{
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
			//NOP
			//1  4
			//- - - -

			//Wait Time for Four Cycles
			Logger::log(Logger::DEBUG, "NOP");

			//Update Program Counter
			advanceCounter(1);

			//Blow this popsicle stand
			break;
		}

		case 0x01:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x02:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x03:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x04:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x05:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x06:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x07:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x08:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x09:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x0A:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x0B:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x0C:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x0D:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x0E:
		{
			//LD C, d8
			//2 8
			//- - - -

			BCRegister.lo = getImmediate8();
			advanceCounter(2);

			break;
		}

		case 0x0F:
		{
			//Unimplemented
			errorState = true;
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
			//STOP 0
			//2  4
			//----

			//Stops Gameboy until a Button proess

			//Unimplemented
			errorState = true;
			break;
		}

		case 0x11:
		{
			//LD DE, d16
			//3 12
			//- - - -

			DERegister.both = getImmediate16();
			advanceCounter(3);
			break;
		}

		case 0x12:
		{
			//LD(DE), A
			//1  8
			//- - - -

			writeData8(DERegister.both, AFRegister.hi);
			advanceCounter(1);

			break;
		}

		case 0x13:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x14:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x15:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x16:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x17:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x18:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x19:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x1A:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x1B:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x1C:
		{
			//INC E
			//1 4
			//Z 0 H -

			

			DERegister.lo++;

			//Copy Flag Register
			flagRegister temp; 
			temp.flags = AFRegister.lo;
			temp.z7 = 0;
			temp.n6 = 0;
			temp.h5;

			//Reset Flags Register
			AFRegister.lo = temp.flags;

			//advanceCounter(1);

			//Unimplemented
			errorState = true;
			break;
		}

		case 0x1D:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x1E:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x1F:
		{
			//Unimplemented
			errorState = true;
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
			errorState = true;
			break;
		}

		case 0x21:
		{
			//LD HL, d16
			//3 12
			//- - - -

			HLRegister.both = getImmediate16();

			advanceCounter(3);

			break;
		}

		case 0x22:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x23:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x24:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x25:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x26:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x27:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x28:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x29:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x2A:
		{
			//LD A, (HL + )
			//1  8
			//- - - -

			AFRegister.hi = readData8(HLRegister.both);
			HLRegister.both++;
			advanceCounter(1);

			break;
		}

		case 0x2B:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x2C:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x2D:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x2E:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x2F:
		{
			//Unimplemented
			errorState = true;
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
			errorState = true;
			break;
		}

		case 0x31:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x32:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x33:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x34:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x35:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x36:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x37:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x38:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x39:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x3A:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x3B:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x3C:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x3D:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x3E:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x3F:
		{
			//Unimplemented
			errorState = true;
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
			errorState = true;
			break;
		}

		case 0x41:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x42:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x43:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x44:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x45:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x46:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x47:
		{
			//LD B, A
			//1 4
			//- - - -

			BCRegister.hi = AFRegister.hi;

			advanceCounter(1);
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
			errorState = true;
			break;
		}

		case 0x4C:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x4D:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x4E:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x4F:
		{
			//Unimplemented
			errorState = true;
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
			errorState = true;
			break;
		}

		case 0x51:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x52:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x53:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x54:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x55:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x56:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x57:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x58:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x59:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x5A:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x5B:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x5C:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x5D:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x5E:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x5F:
		{
			//Unimplemented
			errorState = true;
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
			errorState = true;
			break;
		}

		case 0x61:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x62:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x63:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x64:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x65:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x66:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x67:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x68:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x69:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x6A:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x6B:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x6C:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x6D:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x6E:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x6F:
		{
			//Unimplemented
			errorState = true;
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
			errorState = true;
			break;
		}

		case 0x71:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x72:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x73:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x74:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x75:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x76:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x77:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x78:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x79:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x7A:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x7B:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x7C:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x7D:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x7E:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x7F:
		{
			//Unimplemented
			errorState = true;
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
			errorState = true;
			break;
		}

		case 0x81:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x82:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x83:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x84:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x85:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x86:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x87:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x88:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x89:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x8A:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x8B:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x8C:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x8D:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x8E:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x8F:
		{
			//Unimplemented
			errorState = true;
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
			errorState = true;
			break;
		}

		case 0x91:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x92:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x93:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x94:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x95:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x96:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x97:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x98:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x99:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x9A:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x9B:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x9C:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x9D:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x9E:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x9F:
		{
			//Unimplemented
			errorState = true;
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
			errorState = true;
			break;
		}

		case 0xA1:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xA2:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xA3:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xA4:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xA5:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xA6:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xA7:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xA8:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xA9:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xAA:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xAB:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xAC:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xAD:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xAE:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xAF:
		{
			//Unimplemented
			errorState = true;
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
			errorState = true;
			break;
		}

		case 0xB1:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xB2:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xB3:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xB4:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xB5:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xB6:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xB7:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xB8:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xB9:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xBA:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xBB:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xBC:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xBD:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xBE:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xBF:
		{
			//Unimplemented
			errorState = true;
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
			errorState = true;
			break;
		}

		case 0xC1:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xC2:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xC3:
		{
			//JUMP
			Logger::log(Logger::DEBUG, "JPnn");

			//Complete Jump to New Value
			programCounter = getImmediate16();

			break;
		}

		case 0xC4:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xC5:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xC6:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xC7:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xC8:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xC9:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xCA:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xCB:
		{
			this->processExtendedOpCode();
			break;
		}

		case 0xCC:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xCD:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xCE:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xCF:
		{
			//Unimplemented
			errorState = true;
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
			errorState = true;
			break;
		}

		case 0xD1:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xD2:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xD3:
		{
			//Removed from CPU
			errorState = true;
			break;
		}

		case 0xD4:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xD5:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xD6:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xD7:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xD8:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xD9:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xDA:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xDB:
		{
			//Removed from CPU
			errorState = true;
			break;
		}

		case 0xDC:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xDD:
		{
			//Removed from CPU
			errorState = true;
			break;
		}

		case 0xDE:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xDF:
		{
			//Unimplemented
			errorState = true;
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
			//LDH(a8), A
			//2 12
			//- - - -

			int address = 0xFF00 + getImmediate8();
			writeData8(address, AFRegister.hi);

			advanceCounter(2);

			break;
		}

		case 0xE1:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xE2:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xE3:
		{
			//Removed from CPU
			errorState = true;
			break;
		}

		case 0xE4:
		{
			//Removed from CPU
			errorState = true;
			break;
		}

		case 0xE5:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xE6:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xE7:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xE8:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xE9:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xEA:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xEB:
		{
			//Removed from CPU
			errorState = true;
			break;
		}

		case 0xEC:
		{
			//Removed from CPU
			errorState = true;
			break;
		}

		case 0xED:
		{
			//Removed from CPU
			errorState = true;
			break;
		}

		case 0xEE:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xEF:
		{
			//Unimplemented
			errorState = true;
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
			errorState = true;
			break;
		}

		case 0xF1:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xF2:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xF3:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xF4:
		{
			//Removed from CPU
			errorState = true;
			break;
		}

		case 0xF5:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xF6:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xF7:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xF8:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xF9:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xFA:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xFB:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xFC:
		{
			//Removed from CPU
			errorState = true;
			break;
		}

		case 0xFD:
		{
			//Removed from CPU
			errorState = true;
			break;
		}

		case 0xFE:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xFF:
		{
			//Unimplemented
			errorState = true;
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
			errorState = true;
			break;
		}
	}

}


//This function processes the CB Prefixed OP Codes in the Gameboy CPU
void Processor::processExtendedOpCode()
{
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

		case 0x00:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x01:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x02:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x03:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x04:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x05:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x06:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x07:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x08:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x09:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x0A:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x0B:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x0C:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x0D:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x0E:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x0F:
		{
			//Unimplemented
			errorState = true;
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
			errorState = true;
			break;
		}

		case 0x11:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x12:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x13:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x14:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x15:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x16:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x17:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x18:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x19:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x1A:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x1B:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x1C:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x1D:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x1E:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x1F:
		{
			//Unimplemented
			errorState = true;
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
			errorState = true;
			break;
		}

		case 0x21:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x22:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x23:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x24:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x25:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x26:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x27:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x28:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x29:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x2A:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x2B:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x2C:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x2D:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x2E:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x2F:
		{
			//Unimplemented
			errorState = true;
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
			errorState = true;
			break;
		}

		case 0x31:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x32:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x33:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x34:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x35:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x36:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x37:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x38:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x39:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x3A:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x3B:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x3C:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x3D:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x3E:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x3F:
		{
			//Unimplemented
			errorState = true;
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
			errorState = true;
			break;
		}

		case 0x41:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x42:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x43:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x44:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x45:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x46:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x47:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x48:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x49:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x4A:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x4B:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x4C:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x4D:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x4E:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x4F:
		{
			//Unimplemented
			errorState = true;
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
			errorState = true;
			break;
		}

		case 0x51:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x52:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x53:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x54:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x55:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x56:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x57:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x58:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x59:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x5A:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x5B:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x5C:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x5D:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x5E:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x5F:
		{
			//Unimplemented
			errorState = true;
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
			errorState = true;
			break;
		}

		case 0x61:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x62:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x63:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x64:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x65:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x66:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x67:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x68:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x69:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x6A:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x6B:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x6C:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x6D:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x6E:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x6F:
		{
			//Unimplemented
			errorState = true;
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
			errorState = true;
			break;
		}

		case 0x71:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x72:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x73:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x74:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x75:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x76:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x77:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x78:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x79:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x7A:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x7B:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x7C:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x7D:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x7E:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x7F:
		{
			//Unimplemented
			errorState = true;
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
			errorState = true;
			break;
		}

		case 0x81:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x82:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x83:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x84:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x85:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x86:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x87:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x88:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x89:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x8A:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x8B:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x8C:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x8D:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x8E:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x8F:
		{
			//Unimplemented
			errorState = true;
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
			errorState = true;
			break;
		}

		case 0x91:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x92:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x93:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x94:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x95:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x96:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x97:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x98:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x99:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x9A:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x9B:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x9C:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x9D:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x9E:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0x9F:
		{
			//Unimplemented
			errorState = true;
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
			errorState = true;
			break;
		}

		case 0xA1:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xA2:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xA3:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xA4:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xA5:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xA6:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xA7:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xA8:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xA9:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xAA:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xAB:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xAC:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xAD:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xAE:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xAF:
		{
			//Unimplemented
			errorState = true;
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
			errorState = true;
			break;
		}

		case 0xB1:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xB2:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xB3:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xB4:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xB5:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xB6:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xB7:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xB8:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xB9:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xBA:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xBB:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xBC:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xBD:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xBE:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xBF:
		{
			//Unimplemented
			errorState = true;
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
			errorState = true;
			break;
		}

		case 0xC1:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xC2:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xC3:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xC4:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xC5:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xC6:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xC7:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xC8:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xC9:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xCA:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xCB:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xCC:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xCD:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xCE:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xCF:
		{
			//Unimplemented
			errorState = true;
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
			errorState = true;
			break;
		}

		case 0xD1:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xD2:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xD3:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xD4:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xD5:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xD6:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xD7:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xD8:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xD9:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xDA:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xDB:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xDC:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xDD:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xDE:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xDF:
		{
			//Unimplemented
			errorState = true;
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
			errorState = true;
			break;
		}

		case 0xE1:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xE2:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xE3:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xE4:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xE5:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xE6:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xE7:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xE8:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xE9:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xEA:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xEB:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xEC:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xED:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xEE:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xEF:
		{
			//Unimplemented
			errorState = true;
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
			errorState = true;
			break;
		}

		case 0xF1:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xF2:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xF3:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xF4:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xF5:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xF6:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xF7:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xF8:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xF9:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xFA:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xFB:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xFC:
		{
			//Removed from CPU
			errorState = true;
			break;
		}

		case 0xFD:
		{
			//Removed from CPU
			errorState = true;
			break;
		}

		case 0xFE:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		case 0xFF:
		{
			//Unimplemented
			errorState = true;
			break;
		}

		// _____  ______ ______     _    _ _   _______ 
		//|  __ \|  ____|  ____/\  | |  | | | |__   __|
		//| |  | | |__  | |__ /  \ | |  | | |    | |   
		//| |  | |  __| |  __/ /\ \| |  | | |    | |   
		//| |__| | |____| | / ____ \ |__| | |____| |   
		//|_____/|______|_|/_/    \_\____/|______|_|   

		default:
		{
			errorState = true;
			break;
		}
	}
}