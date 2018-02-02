#pragma once



class MemoryController
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

	private:

		//0000-3FFF
		unsigned char bank00[0x4000];

		//4000-7FFF
		unsigned char bank01[0x4000];

		//8000-9FFF
		unsigned char vRAM[0x2000];

		//A000-BFFF
		unsigned char eRAM[0x2000];

		//C000-CFFF
		unsigned char wRAM0[0x1000];

		//D000 - DFFF
		unsigned char wRAM1[0x1000];

		//E000-FDFF
		unsigned char wRAMe[0x2000];

		//FE00 - FE9F
		unsigned char SpriteAtributeTable[0x2000];

		//FEA0 - FEFF
		unsigned char uRam[0x1000];

		//FF00 - FF7F
		unsigned char ioRegisters[0x1000];

		//FF80 - FFFE
		unsigned char hRam[0x1000];

		//FFFF - FFFF
		unsigned char interruptsRegister;



	public:
		MemoryController();

		void writeByte(int address, char data);



};