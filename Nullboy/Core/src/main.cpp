//Standard Crap
#include <cstdlib>
#include <iostream>

//External Shit

//Custom Shit
#include "utility\commands\commands.hpp";

int main(int argc, char* argv[])
{
	//Let this asshole take care of it. 
	Commands command(argc, argv);


	//Hold the Execution
	std::cin.get();

	return EXIT_SUCCESS;
}