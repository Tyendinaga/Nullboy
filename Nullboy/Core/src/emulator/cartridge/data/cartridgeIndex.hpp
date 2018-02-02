#pragma once

//Standard Stuff
#include <string>

const struct cartridgeIndex
{
	const int entryPointStart = 0x0100;
	const int entryPointEnd = 0x0103;

	const int logoStart = 0x0104;
	const int logoEnd = 0x0133;

	const int titleStart = 0x0134;
	const int titleEnd = 0x0143;

	const int manCodeStart = 0x013F;
	const int manCodeEnd = 0x0142;

	const int CGBFlag = 0x0143;
	
	const int licenseeStart = 0x0144;
	const int licenseeEnd = 0x0145;

	const int SGBFlag = 0x0146;

	const int CartridgeType = 0x0147;

	const int ROMSize = 0x0148;

	const int RAMSize = 0x0149;

	const int DestinationCode = 0x014A;

	const int oldLicensee = 0x014B;

	const int MaskRomVersion = 0x014C;

	const int HeaderChecksum = 0x014D;

	const int GlobalChecksumStart = 0x014E;
	const int GlobalChecksumEnd = 0x014F;
};