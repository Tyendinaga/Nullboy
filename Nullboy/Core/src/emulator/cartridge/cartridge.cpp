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
		data.read(&MEMa[0], length);
		

	}

	

	//Unlock the file
	data.close();

}
