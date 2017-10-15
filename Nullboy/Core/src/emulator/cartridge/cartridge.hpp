#pragma once

//custom stuff
#include "emulator\cartridge\data\cartridgeHeader.hpp"
#include "emulator\cartridge\data\cartridgeIndex.hpp"

//Standard Stuff
#include<string>
#include<vector>

class Cartridge 
{

	private:

		//ROM Data
		std::vector<unsigned char> MEMa;
		std::vector<unsigned char>::iterator MEMi;

		//Data Stored in Cartridge Header
		struct cartridgeHeader header;
		struct cartridgeIndex index;

		/*
		//Cartridge Data Index
		int entryPoint = 0x0100;
		int logoLocation = 0x0104;
		int titleLocation = 0x0134;
		int manufacturerLocation = 0x013F;
		int cgbFlagLocation = 0x0143;
		*/

		//Functions
		void verify();
		void loadHeader();

	public:
		Cartridge(std::string fileName);



};