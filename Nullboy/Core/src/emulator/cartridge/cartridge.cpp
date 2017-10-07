//Standard Things
#include<fstream>
#include <stdexcept>

//Custom Things
#include "cartridge.hpp"
#include "utility\logging\logger.hpp"

Cartridge::Cartridge(std::string fileName)
{
	
	//CARTRIDGE LOADING
	//-----------------
	Logger::log("LOADING: ", fileName);

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
		

	}

	//Unlock the file
	data.close();

	//CARTRIDGE VERIFICATION
	//----------------------

	//Each cartridge contains a bitmap of the nintendo logo inside it. 
	//This logo resides at 0104 to 0133
	//The Gameboy actually checks this to confirm the cartridge is good
	//So Shall we. 

	//Bitmap Data
	//CE ED 66 66 CC 0D 00 0B 03 73 00 83 00 0C 00 0D
	//00 08 11 1F 88 89 00 0E DC CC 6E E6 DD DD D9 99
	//BB BB 67 63 6E 0E EC CC DD DC 99 9F BB B9 33 3E

	unsigned char d = 0xCE;

	std::vector<unsigned char> BMPa = {		0xCE, 0xED, 0x66, 0x66, 0xCC, 0x0D, 0x00, 0x0B, 0x03, 0x73, 0x00, 0x83, 0x00, 0x0C, 0x00, 0x0D,
											0x00, 0x08, 0x11, 0x1F, 0x88, 0x89, 0x00, 0x0E, 0xDC, 0xCC, 0x6E, 0xE6, 0xDD, 0xDD, 0xD9, 0x99,
											0xBB, 0xBB, 0x67, 0x63, 0x6E, 0x0E, 0xEC, 0xCC, 0xDD, 0xDC, 0x99, 0x9F, 0xBB, 0xB9, 0x33, 0x3E};

	std::vector<unsigned char>::iterator BMPi;

	//Start location of Bitmap
	int index = 0x0104;

	//Iterate through the BMP

	BMPi = BMPa.begin();
	MEMi = MEMa.begin() + index;
	while (BMPi != BMPa.end())
	{
		
		if (*BMPi != *MEMi)
		{
			//Notify that there's an error mathcing up the bitmap data
			Logger::log("ERROR: ", "Nintendo File Mismatch");
		}
		else
		{
			//Print the Value of the Bitmap
			Logger::log("INFO: Nintendo Bitmap: ", *BMPi);
		}

		//Increment
		BMPi++;
		MEMi++;
	}
}
