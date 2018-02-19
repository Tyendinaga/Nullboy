#include "MemoryManager.hpp"
#include "utility\logging\logger.hpp"


MemoryManager::MemoryManager()
{

}

//Write Information to somewhere on the memory map
void MemoryManager::writeByte(int address, char data)
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
		bank00[address] = data;
	}

	//4000 - 7FFF	16KB ROM Bank 01~NN	From cartridge, switchable bank via MBC(if any)
	if (address >= 0x4000 && address <= 0x7FFF)
	{
		int localAddress = address - 0x4000;
		bank01[localAddress] = data;
	}

	//8000 - 9FFF	8KB Video RAM(VRAM)	Only bank 0 in Non - CGB mode Switchable bank 0 / 1 in CGB mode
	if (address >= 0x8000 && address <= 0x9FFF)
	{
		int localAddress = address - 0x8000;
		vRAM[localAddress] = data;
	}

	//A000 - BFFF	8KB External RAM	In cartridge, switchable bank if any
	if (address >= 0xA000 && address <= 0xBFFF)
	{
		int localAddress = address - 0xA000;
		eRAM[localAddress] = data;
	}

	//C000 - CFFF	4KB Work RAM(WRAM) bank 0
	if (address >= 0xC000 && address <= 0xCFFF)
	{
		int localAddress = address - 0xC000;
		wRAM0[localAddress] = data;
	}

	//D000 - DFFF	4KB Work RAM(WRAM) bank 1~N	Only bank 1 in Non - CGB mode Switchable bank 1~7 in CGB mode
	if (address >= 0xD000 && address <= 0xDFFF)
	{
		int localAddress = address - 0xD000;
		wRAM1[localAddress] = data;
	}


	//E000 - FDFF	Mirror of C000~DDFF(ECHO RAM)	Typically not used
	if (address >= 0xE000 && address <= 0xFDFF)
	{
		//int localAddress = address - 0xD000;
		//wRAM1[localAddress] = data;
	}

	//FE00 - FE9F	Sprite attribute table(OAM)
	if (address >= 0xFE00 && address <= 0xFE9F)
	{
		int localAddress = address - 0xFE00;
		SpriteAtributeTable[localAddress] = data;
	}

	//FEA0 - FEFF	Not Usable
	if (address >= 0xFEA0 && address <= 0xFEFF)
	{
		Logger::log(Logger::DEBUG, "Not Useable: " + location);
	}

	//FF00 - FF7F	I / O Registers
	if (address >= 0xFF00 && address <= 0xFF7F)
	{
		int localAddress = address - 0xFF00;
		ioRegisters[localAddress] = data;
	}

	//FF80 - FFFE	High RAM(HRAM)
	if (address >= 0xFF80 && address <= 0xFFFE)
	{ 
		int localAddress = address - 0xFF80;
		ioRegisters[localAddress] = data;
	}

	//FFFF - FFFF	Interrupts Enable Register(IE)
	if (address == 0xFFFF)
	{
		interruptsRegister = data;
	}
}

char MemoryManager::readByte(int address)
{
	char data;

	//0000 - 3FFF	16KB ROM bank 00	From cartridge, fixed bank
	if (address <= 0x3FFF)
	{
		//Logger::log(Logger::DEBUG, "Bank 00: " + location);
		data = bank00[address];
	}

	//4000 - 7FFF	16KB ROM Bank 01~NN	From cartridge, switchable bank via MBC(if any)
	if (address >= 0x4000 && address <= 0x7FFF)
	{
		//Logger::log(Logger::DEBUG, "Bank XX: " + location);
		int localAddress = address - 0x4000;
		data = bank01[localAddress];
	}

	//8000 - 9FFF	8KB Video RAM(VRAM)	Only bank 0 in Non - CGB mode Switchable bank 0 / 1 in CGB mode
	if (address >= 0x8000 && address <= 0x9FFF)
	{
		int localAddress = address - 0x8000;
		data = vRAM[localAddress];
	}

	//A000 - BFFF	8KB External RAM	In cartridge, switchable bank if any
	if (address >= 0xA000 && address <= 0xBFFF)
	{
		int localAddress = address - 0xA000;
		data = eRAM[localAddress];
	}

	//C000 - CFFF	4KB Work RAM(WRAM) bank 0
	if (address >= 0xC000 && address <= 0xCFFF)
	{
		int localAddress = address - 0xC000;
		data = wRAM0[localAddress];
	}

	//D000 - DFFF	4KB Work RAM(WRAM) bank 1~N	Only bank 1 in Non - CGB mode Switchable bank 1~7 in CGB mode
	if (address >= 0xD000 && address <= 0xDFFF)
	{
		int localAddress = address - 0xD000;
		data = wRAM1[localAddress];
	}


	//E000 - FDFF	Mirror of C000~DDFF(ECHO RAM)	Typically not used
	if (address >= 0xE000 && address <= 0xFDFF)
	{
		//int localAddress = address - 0xD000;
		//wRAM1[localAddress] = data;
	}

	//FE00 - FE9F	Sprite attribute table(OAM)
	if (address >= 0xFE00 && address <= 0xFE9F)
	{
		int localAddress = address - 0xFE00;
		data = SpriteAtributeTable[localAddress];
	}


	//FEA0 - FEFF	Not Usable
	if (address >= 0xFEA0 && address <= 0xFEFF)
	{
		Logger::log(Logger::DEBUG, "Not Useable: " + address);
	}

	//FF00 - FF7F	I / O Registers
	if (address >= 0xFF00 && address <= 0xFF7F)
	{
		int localAddress = address - 0xFF00;
		data = ioRegisters[localAddress];
	}

	//FF80 - FFFE	High RAM(HRAM)
	if (address >= 0xFF80 && address <= 0xFFFE)
	{
		int localAddress = address - 0xFF80;
		data = ioRegisters[localAddress];
	}

	//FFFF - FFFF	Interrupts Enable Register(IE)
	if (address == 0xFFFF)
	{
		data = interruptsRegister;
	}

	return data;
}
