#pragma once

class Processor
{

	private:
		bool halted; //Debug use Only

		//2 Bytes
		unsigned short opcode;

		//Registers
		unsigned short AFRegister;
		unsigned short BCRegister;
		unsigned short DERegister;
		unsigned short HLRegister;

		//Stack & Stack Pointer
		unsigned short stackPointer;

		//Program Counter 
		unsigned short programCounter;



	public:
		Processor();

		void initialize();
		void emulateCycle();

		bool isHalted();

};