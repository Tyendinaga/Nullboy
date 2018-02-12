#pragma once

//Standard includes
#include<string>
#include<vector>

//custom includes
#include "emulator\cartridge\data\cartridgeHeader.hpp"
#include "emulator\cartridge\data\cartridgeIndex.hpp"

class Cartridge 
{

	private:

		//ROM Data
		std::vector<unsigned char> MEMa;
		std::vector<unsigned char>::iterator MEMi;

		//Data Stored in Cartridge Header
		struct cartridgeHeader header;

		//Functions
		void verify();
		void loadHeader();

	public:
		Cartridge(std::string fileName);
		Cartridge();

		unsigned char readByte(int address);


};