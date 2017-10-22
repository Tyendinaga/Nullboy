#pragma once

//Standard includes
#include <string>

struct cartridgeHeader
{
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
};