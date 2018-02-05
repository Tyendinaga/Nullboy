#include "MemoryController.hpp"
#include "utility\logging\logger.hpp"


MemoryController::MemoryController()
{

}

//Write Information to somewhere on the memory map
void MemoryController::writeByte(int address, char data)
{
	/*
	//MEMORY MAP
	0000-3FFF	16KB ROM bank 00	From cartridge, fixed bank
	4000-7FFF	16KB ROM Bank 01~NN	From cartridge, switchable bank via MBC (if any)
	8000-9FFF	8KB Video RAM (VRAM)	Only bank 0 in Non-CGB mode Switchable bank 0/1 in CGB mode

	A000-BFFF	8KB External RAM	In cartridge, switchable bank if any
	C000-CFFF	4KB Work RAM (WRAM) bank 0
	D000-DFFF	4KB Work RAM (WRAM) bank 1~N	Only bank 1 in Non-CGB mode Switchable bank 1~7 in CGB mode

	E000-FDFF	Mirror of C000~DDFF (ECHO RAM)	Typically not used
	FE00-FE9F	Sprite attribute table (OAM)
	FEA0-FEFF	Not Usable
	FF00-FF7F	I/O Registers
	FF80-FFFE	High RAM (HRAM)
	FFFF-FFFF	Interrupts Enable Register (IE)

	//KB to Hex Conversions
	16KB = 0x4000
	8KB = 0x2000
	4KB = 0X1000
	*/

	//Get the string of the address (For Debugging)
	std::string location = std::to_string(address);

	//DETEMINE WRITEABLE MEMORY BANK
	//------------------------------

	//0000 - 3FFF	16KB ROM bank 00	From cartridge, fixed bank
	if (address <= 0x3FFF)
	{
		//Logger::log(Logger::DEBUG, "Bank 00: " + location);

		bank00[address] = data;
	}

	//4000 - 7FFF	16KB ROM Bank 01~NN	From cartridge, switchable bank via MBC(if any)
	if (address >= 0x4000 && address <= 0x7FFF)
	{
		Logger::log(Logger::DEBUG, "Bank XX: " + location);
	}

	//8000 - 9FFF	8KB Video RAM(VRAM)	Only bank 0 in Non - CGB mode Switchable bank 0 / 1 in CGB mode
	if (address >= 0x8000 && address <= 0x9FFF)
	{
		Logger::log(Logger::DEBUG, "Video Ram: "+ location);
	}

	//A000 - BFFF	8KB External RAM	In cartridge, switchable bank if any
	if (address >= 0xA000 && address <= 0xBFFF)
	{
		Logger::log(Logger::DEBUG, "External Ram: " + location);
	}

	//C000 - CFFF	4KB Work RAM(WRAM) bank 0
	if (address >= 0xC000 && address <= 0xCFFF)
	{
		Logger::log(Logger::DEBUG, "WRam Bank 0: " + location);
	}

	//D000 - DFFF	4KB Work RAM(WRAM) bank 1~N	Only bank 1 in Non - CGB mode Switchable bank 1~7 in CGB mode
	if (address >= 0xD000 && address <= 0xDFFF)
	{
		Logger::log(Logger::DEBUG, "WRam Bank X: " + location);
	}


	//E000 - FDFF	Mirror of C000~DDFF(ECHO RAM)	Typically not used
	if (address >= 0xE000 && address <= 0xFDFF)
	{
		Logger::log(Logger::DEBUG, "Echo Ram: " + location);
	}

	//FE00 - FE9F	Sprite attribute table(OAM)
	if (address >= 0xFE00 && address <= 0xFE9F)
	{
		Logger::log(Logger::DEBUG, "OAM: " + location);
	}


	//FEA0 - FEFF	Not Usable
	if (address >= 0xFEA0 && address <= 0xFEFF)
	{
		Logger::log(Logger::DEBUG, "Not Useable: " + location);
	}

	//FF00 - FF7F	I / O Registers
	if (address >= 0xFF00 && address <= 0xFF7F)
	{
		Logger::log(Logger::DEBUG, "IO Registers: " + location);
	}

	//FF80 - FFFE	High RAM(HRAM)
	if (address >= 0xFF80 && address <= 0xFFFE)
	{ 
		//Logger::log(Logger::DEBUG, "High Ram: " + location);

		//Get Relative Offset so we can work
		int relativeOffset = address - 0xFF80;

	}

	//FFFF - FFFF	Interrupts Enable Register(IE)
	if (address == 0xFFFF)
	{
		//Logger::log(Logger::DEBUG, "Interrupts Register: " + location);
		interruptsRegister = data;
	}
}
