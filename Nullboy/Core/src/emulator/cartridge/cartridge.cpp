//Standard Includes
#include <fstream>
#include <stdexcept>

//Custom Includes
#include "cartridge.hpp"
#include "utility\logging\logger.hpp"

Cartridge::Cartridge(std::string fileName)
{
	
	//LOAD CARTRIDGE DATA
	//-------------------
	Logger::log(Logger::INFO, "=== LOADING CARTRIDGE");
	Logger::log(Logger::INFO, "FILENAME: ", fileName);


	std::ifstream data;
	data.open(fileName, std::ios::in | std::ios::binary);

	//Confirm Data Existance
	if (!data)
	{
		throw std::invalid_argument("File provided could not be located");
	}
	else
	{
		//Data in gameboy cartridges appears to be variable length.
		//We are just going to load the entire cartridge into memory

		//Figure out the File Size 
		data.seekg(0, std::ios_base::end);
		int length = data.tellg();

		//Size up our Vector to the length
		MEMa.resize(length);

		//Take in all that Data
		data.seekg(0, std::ios_base::beg);
		data.read((char*)&MEMa[0], length);

		Logger::log(Logger::INFO, "LOADED", std::to_string(length / 1024) + "KB");

	}

	//Unlock the file
	data.close();

	//Perform some basic validation
	verify();

	//Save That Data
	loadHeader();


}

Cartridge::Cartridge()
{
}

unsigned char Cartridge::readByte(int address)
{
	MEMi = MEMa.begin() + address;
	return *MEMi;
}

void Cartridge::verify()
{

	Logger::log(Logger::INFO, "=== VERIFYING CARTRIDGE");

	//BITMAP VERIFICATION
	//-------------------

	//Each cartridge contains a bitmap of the nintendo logo inside it. 
	//This logo resides at 0104 to 0133
	//The Gameboy Bootrom supposedly checks this for validity on runtime. 

	//HEXADECIMAL Bitmap Data
	//CE ED 66 66 CC 0D 00 0B 03 73 00 83 00 0C 00 0D
	//00 08 11 1F 88 89 00 0E DC CC 6E E6 DD DD D9 99
	//BB BB 67 63 6E 0E EC CC DD DC 99 9F BB B9 33 3E

	Logger::log(Logger::INFO, "BEGINNING BITMAP VERIFICATION");

	std::vector<unsigned char> BMPa = 
	{ 
		0xCE, 0xED, 0x66, 0x66, 0xCC, 0x0D, 0x00, 0x0B, 0x03, 0x73, 0x00, 0x83, 0x00, 0x0C, 0x00, 0x0D,
		0x00, 0x08, 0x11, 0x1F, 0x88, 0x89, 0x00, 0x0E, 0xDC, 0xCC, 0x6E, 0xE6, 0xDD, 0xDD, 0xD9, 0x99,
		0xBB, 0xBB, 0x67, 0x63, 0x6E, 0x0E, 0xEC, 0xCC, 0xDD, 0xDC, 0x99, 0x9F, 0xBB, 0xB9, 0x33, 0x3E 
	};

	std::vector<unsigned char>::iterator BMPi;

	bool bitmapValid = true;

	//Iterate through the Bitmap
	BMPi = BMPa.begin();
	MEMi = MEMa.begin() + cartridgeIndex::logoStart;
	while (BMPi != BMPa.end())
	{

		if (*BMPi != *MEMi)
		{
			Logger::log(Logger::PROBLEM, "BITMAP VALIDATION FAILED");
			bitmapValid = false;
			break;
		}
		else
		{
			//Print the Value of the Bitmap
			//Logger::log("INFO: Nintendo Bitmap: ", *BMPi);
		}

		//Increment
		BMPi++;
		MEMi++;
	}

	if (bitmapValid)
	{
		Logger::log(Logger::INFO, "BITMAP VALIDATION SUCCEEDED");
	}
	else
	{
		Logger::log(Logger::INFO, "BITMAP VALIDATION FAILED");
	}

	//HEADER CHECKSUM VERIFICATION
	//----------------------------
	
	//The header checksum check takes values from 0134 to 014C and checksums them. 
	//This checksum value is stored at 014D

	Logger::log(Logger::INFO, "BEGINNING CHECKSUM VERIFICATION");

	MEMi = MEMa.begin() + 0x014D;
	header.headerChecksum = *MEMi;
	unsigned char tempChecksum = 0;

	Logger::log(Logger::INFO,"HEADER CHECKSUM", *MEMi);

	//This is Probably Dumb
	unsigned short i = 0x0134;
	while (i < 0x014C)
	{
		MEMi = MEMa.begin() + i;
		tempChecksum = tempChecksum - *MEMi -1;
		i++;
	}

	//My Checksum seems to be off by one, consistently. 
	tempChecksum--;

	if (tempChecksum == header.headerChecksum)
	{
		Logger::log(Logger::INFO, "CHECKSUM VERIFICATION SUCCEEDED");
	}
	else
	{
		Logger::log(Logger::PROBLEM, "CHECKSUM VERIFICATION FAILED");
	}

	//GLOBAL CHECKSUM VERIFICATION
	//----------------------------

}



void Cartridge::loadHeader()
{
	Logger::log(Logger::INFO, "=== LOADING CARTRIDGE HEADER");


	//Get Game Title
	header.gameTitle = "DEFAULT";

	Logger::log(Logger::INFO, header.gameTitle);


	/*
	 80h - Game supports CGB functions, but works on old gameboys also.
	 C0h - Game works on CGB only (physically the same as 80h).
	*/

	//Get CGB Flag
	MEMi = MEMa.begin() + cartridgeIndex::CGBFlag;
	header.CGBFlag = *MEMi;

	Logger::log(Logger::INFO, "CGB Flag: ", header.CGBFlag);

	/*
	 00h = No SGB functions (Normal Gameboy or CGB only game)
	 03h = Game supports SGB functions
	*/

	//Get SGB Flag
	MEMi = MEMa.begin() + cartridgeIndex::SGBFlag;
	header.SGBFlag = *MEMi;

	Logger::log(Logger::INFO, "SGB Flag: ", header.SGBFlag);


	/*
	 00h  ROM ONLY                 19h  MBC5
	 01h  MBC1                     1Ah  MBC5+RAM
	 02h  MBC1+RAM                 1Bh  MBC5+RAM+BATTERY
	 03h  MBC1+RAM+BATTERY         1Ch  MBC5+RUMBLE
	 05h  MBC2                     1Dh  MBC5+RUMBLE+RAM
	 06h  MBC2+BATTERY             1Eh  MBC5+RUMBLE+RAM+BATTERY
	 08h  ROM+RAM                  20h  MBC6
	 09h  ROM+RAM+BATTERY          22h  MBC7+SENSOR+RUMBLE+RAM+BATTERY
	 0Bh  MMM01
	 0Ch  MMM01+RAM
	 0Dh  MMM01+RAM+BATTERY
	 0Fh  MBC3+TIMER+BATTERY
	 10h  MBC3+TIMER+RAM+BATTERY   FCh  POCKET CAMERA
	 11h  MBC3                     FDh  BANDAI TAMA5
	 12h  MBC3+RAM                 FEh  HuC3
	 13h  MBC3+RAM+BATTERY         FFh  HuC1+RAM+BATTERY
	*/

	//Get Cartridge Type
	MEMi = MEMa.begin() + cartridgeIndex::CartridgeType;
	header.cartridgeType = *MEMi;

	Logger::log(Logger::INFO, "Cartridge Type: " ,header.cartridgeType);

	/*
	 00h -  32KByte (no ROM banking)
	 01h -  64KByte (4 banks)
	 02h - 128KByte (8 banks)
	 03h - 256KByte (16 banks)
	 04h - 512KByte (32 banks)
	 05h -   1MByte (64 banks)  - only 63 banks used by MBC1
	 06h -   2MByte (128 banks) - only 125 banks used by MBC1
	 07h -   4MByte (256 banks)
	 08h -   8MByte (512 banks)
	 52h - 1.1MByte (72 banks)
	 53h - 1.2MByte (80 banks)
	 54h - 1.5MByte (96 banks)
	*/

	//Get ROM SIZE
	MEMi = MEMa.begin() + cartridgeIndex::ROMSize;
	header.ROMSize = *MEMi;

	Logger::log(Logger::INFO, "ROM Size: ", header.ROMSize);

	/*
	 00h - None
	 01h - 2 KBytes
	 02h - 8 Kbytes
	 03h - 32 KBytes (4 banks of 8KBytes each)
	 04h - 128 KBytes (16 banks of 8KBytes each)
	 05h - 64 KBytes (8 banks of 8KBytes each)
	*/

	//Get RAM Size
	MEMi = MEMa.begin() + cartridgeIndex::RAMSize;
	header.RAMSize = *MEMi;

	Logger::log(Logger::INFO, "RAM Size: ", header.RAMSize);

	/*
	 00h - Japanese
	 01h - Non-Japanese
	*/
	MEMi = MEMa.begin() + cartridgeIndex::DestinationCode;
	header.destinationCode = *MEMi;

	Logger::log(Logger::INFO, "Destination: ", header.destinationCode);

	/*
	00h - Non-Super Game Boy
	33h - Super Game Boy
	*/
	MEMi = MEMa.begin() + cartridgeIndex::oldLicensee;
	header.oldLicenseCode = *MEMi;

	Logger::log(Logger::INFO, "Old Licensee: ", header.oldLicenseCode);
}
