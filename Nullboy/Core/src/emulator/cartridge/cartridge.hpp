#pragma once

//Standard Shit
#include<string>
#include<vector>

class Cartridge 
{

	private:

		//Readable Data
		std::vector<unsigned char> MEMa;
		std::vector<unsigned char>::iterator MEMi;

		//


	public:
		Cartridge(std::string fileName);



};