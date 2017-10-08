#pragma once

//Standard Shit
#include<string>
#include<vector>

class Cartridge 
{

	private:

		//ROM Data
		std::vector<unsigned char> MEMa;
		std::vector<unsigned char>::iterator MEMi;

		//Cartridge Header
		std::string gameTitle;
		std::string manufacturerCode;
		unsigned char CGBFlag;
		std::string newLicenseCode;
		unsigned char SGBFlag;
		unsigned char cartridgeType;
		unsigned char ROMSize;
		unsigned char RAMSize;
		unsigned char destinationCode;
		unsigned char oldLicenseCode;
		unsigned char ROMversion;
		unsigned char headerChecksum;
		unsigned short globalChesksum;


		//Cartridge Data Index
		int entryPoint = 0x0100;
		int logoLocation = 0x0104;
		int titleLocation = 0x0134;
		int manufacturerLocation = 0x013F;
		int cgbFlagLocation = 0x0143;


		//Functions
		void verify();

	public:
		Cartridge(std::string fileName);



};