#include <assembler.h>
#include <string>
#include <sstream>
#include <fstream>


static std::vector<ubyte> a_cmd(int size, int cmd, const std::string& arg, std::vector<ubyte> assembly) {
	assembly.push_back(cmd);
	
	if (arg == "") return assembly;	
	ui32 argi = atoi(arg.c_str());
	for (int i=0; i<size; i++) {
		ubyte b = (argi >> (8*i)) & 0xFF;
		assembly.push_back(b);
	}
	
	return assembly;

}


std::vector<ubyte> assembleFile(const std::string& fileName) {
	std::ifstream file(fileName);
	if (file.is_open()) {
		std::stringstream source;
		source << file.rdbuf();
		return assembleSource(source.str());
	} else {
		return std::vector<ubyte>();
	}	
}

std::vector<ubyte> assembleSource(const std::string& source) {
	std::istringstream iss(source);
	std::string line;
	std::vector<ubyte> assembly;
	while (std::getline(iss, line)) {
		if (line == "") continue;
		for (auto& b : assembleLine(line)) {
			assembly.push_back(b);	
		}	
	}	
	return assembly;
}

std::vector<ubyte> assembleLine(const std::string& line) {
	std::vector<ubyte> assembly;
	std::string cmd, arg;
	std::istringstream iss(line);
	iss >> cmd >> arg >> std::ws;

			// handle the command
			if (cmd == "#") return assembly;
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

			return assembly;
}
