#pragma once

//Standard Stuff
#include <string>

enum cartridgeIndex
{
	entryPointStart = 0x0100,
	entryPointEnd = 0x0103,

	logoStart = 0x0104,
	logoEnd = 0x0133,

	titleStart = 0x0134,
	titleEnd = 0x0143,

	manCodeStart = 0x013F,
	manCodeEnd = 0x0142,

	CGBFlag = 0x0143,
	
	licenseeStart = 0x0144,
	licenseeEnd = 0x0145,

	SGBFlag = 0x0146,

	CartridgeType = 0x0147,

	ROMSize = 0x0148,

	RAMSize = 0x0149,

	DestinationCode = 0x014A,

	oldLicensee = 0x014B,

	MaskRomVersion = 0x014C,

	HeaderChecksum = 0x014D,

	GlobalChecksumStart = 0x014E,
	GlobalChecksumEnd = 0x014F,
};