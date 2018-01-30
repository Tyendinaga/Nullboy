#pragma once

class Processor
{

	private:
		bool halted; //Debug use Only



	public:
		Processor();

		void initialize();
		void emulateCycle();


};