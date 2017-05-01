#include <stdio.h>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <commands.h>
#include <globaltypes.h>
#include <vector>
#include <assembler.h>


int main(int argc, char** args) {

	const char* fileName = args[1];
	std::ofstream outfile("out.bin");
	std::vector<ubyte> assembly = assembleFile(fileName);

	for (auto& b : assembly) {
		outfile << b;
	}	
	outfile.close();

	return 0;
}
