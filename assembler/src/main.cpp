#include <stdio.h>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <commands.h>
#include <globaltypes.h>
#include <vector>

std::vector<ubyte> a_constb(const std::string& arg, std::vector<ubyte> assembly) {
	ubyte argb = atoi(arg.c_str());
	assembly.push_back(constb);
	assembly.push_back(argb);
	return assembly;
}


std::vector<ubyte> a_constw(const std::string& arg, std::vector<ubyte> assembly) {
	ui32 argi = atoi(arg.c_str());
	
	// need to split the value into two bytes
	ubyte b1 = (argi) & 0xFF;
	ubyte b2 = (argi >> (8)) & 0xFF;
	
	assembly.push_back(constw);
	assembly.push_back(b1);
	assembly.push_back(b2);
	return assembly;

}

std::vector<ubyte> a_consti(const std::string& arg, std::vector<ubyte> assembly) {
	ui32 argi = atoi(arg.c_str());
	
	// need to split the value into two bytes
	ubyte b1 = (argi) & 0xFF;
	ubyte b2 = (argi >> (8)) & 0xFF;
	ubyte b3 = (argi >> (16)) & 0xFF;
	ubyte b4 = (argi >> (24)) & 0xFF;
	
	assembly.push_back(constw);
	assembly.push_back(b1);
	assembly.push_back(b2);
	assembly.push_back(b3);
	assembly.push_back(b4);
	return assembly;

}

std::vector<ubyte> a_addb(const std::string& arg, std::vector<ubyte> assembly) {
	ubyte argb = atoi(arg.c_str());
	assembly.push_back(addi);
	assembly.push_back(argb);
	return assembly;
}

std::vector<ubyte> a_cmd(int size, int cmd, const std::string& arg, std::vector<ubyte> assembly) {
	assembly.push_back(cmd);
	
	if (arg == "") return assembly;	
	ui32 argi = atoi(arg.c_str());
	for (int i=0; i<size; i++) {
		ubyte b = (argi >> (8*i)) & 0xFF;
		assembly.push_back(b);
	}
	
	return assembly;

}




int main(int argc, char** args) {

	std::vector<ubyte> assembly;
	
	const char* fileName = args[1];
	std::cout << "input source: " << std::string(fileName) << std::endl;
	// read the file line by line
	// create machine code for each line
	std::ifstream assfile(fileName);		
	std::string line;
	std::ofstream outfile("out.bin");
	if (assfile.is_open()) {
		std::cout << "file opened!" << std::endl;
		std::string cmd, arg;
		while (std::getline(assfile, line)) {
			if (line == "") continue;

			std::istringstream iss(line);
		  iss >> cmd >> arg >> std::ws;
			
			//std::cout << "cmd: " << cmd << " arg: " << arg << std::endl;

			// handle the command
			if (cmd == "#") continue;
			else if (cmd == "constb") 
				assembly = a_cmd(1, constb, arg, assembly);
			else if (cmd == "constw")
				assembly = a_cmd(2, constw, arg, assembly);
			else if (cmd == "addb")
				assembly = a_cmd(1, addb, "", assembly);
			else if (cmd == "addw")
				assembly = a_cmd(2, addw, "", assembly);
			else if (cmd == "addi")
				assembly = a_cmd(4, addi, "", assembly);
		}

		for (auto& b : assembly) {
			outfile << b;
		}
		outfile.close();
	}



	return 0;
}
