#include <assembler.h>
#include <string>
#include <sstream>
#include <fstream>
#include <map>

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

static std::vector<ubyte> parse_args(const std::string& arg, int size) {
	std::vector<ubyte> args;
	ui32 argi = atoi(arg.c_str());
	for (int i=0; i<size; i++) {
		ubyte b = (argi >> (8*i)) & 0xFF;
		args.push_back(b);
	}
	return args;
}

struct Command {
		ubyte cmd = 0;
		ubyte arg_size = 0;
		ubyte* args;
		// Does the argument reference a symbol?
		// If yes, name it here.
		std::string arg_sym_ref;
	};

struct LabelInfo {
		std::string name;
};

struct CommandInfo {
	bool is_label=false;
	bool comment = false;
	Command c;
	LabelInfo l;	
	
};


CommandInfo parseLine(const std::string& line) {
	CommandInfo ci;
	std::string cmd, arg;
	std::istringstream iss(line);
	iss >> cmd >> arg >> std::ws;

	// handle the command
	// Comment
	if (cmd == "#") {
		ci.c.cmd = 0;
		ci.comment = true;
		return ci;
	}
	else if (cmd == "constb") {
		ci.c.cmd = constb;
		ci.c.arg_size = 1;
		std::vector<ubyte> args = parse_args(arg, 1);
		ci.c.args = args.data();
		return ci;
	}
	else if (cmd == "constw") {
		ci.c.cmd = constw;
		ci.c.arg_size = 2;
		std::vector<ubyte> args = parse_args(arg, 2);
		ci.c.args = args.data();
		return ci;
	}
	else if (cmd == "jmp") {
		ci.c.cmd = jmp;
		ci.c.arg_size = 4;
		ci.c.arg_sym_ref = arg;
		return ci;
	}
	else if (cmd == "addb") {
		ci.c.cmd = addb;
		ci.c.arg_size = 0;
		return ci;
	}
	else if (cmd.compare(cmd.length()-1, 1, ":") == 0) {
		ci.is_label = true;
		ci.l.name = cmd;
		
		
	}
//		assembly = a_cmd(1, addb, "", assembly);
	//else if (cmd == "addw")
//		assembly = a_cmd(2, addw, "", assembly);
	//else if (cmd == "addi")
//		assembly = a_cmd(4, addi, "", assembly);
	return ci;

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
	std::vector<CommandInfo> cis;
	while (std::getline(iss, line)) {
		if (line == "") continue;

		cis.push_back(parseLine(line));	
		for (auto& b : assembleLine(line)) {
			// instead of directly pushing the bytecode into our
			// vector, we would do separate passes with the command infos here. 
			// see above!
			assembly.push_back(b);	
		}	
	}	

	// Go through the commandInfos and resolve symbols etc.
	// First, lets collect symbols
	std::map<std::string, int> sym_tab;
	for (auto& ci : cis) {
		if (ci.c.arg_sym_ref != "") {
			printf("found referenced symbol: %s\n", ci.c.arg_sym_ref.c_str());
			sym_tab[ci.c.arg_sym_ref] = -1;
		}
	}	


	return assembly;
}

std::vector<ubyte> assembleLine(const std::string& line) {

	// temp test
	CommandInfo ci = parseLine(line);
	printf("ci: %u arg_sym_ref: %s", ci.c.cmd, ci.c.arg_sym_ref.c_str());
	if (ci.is_label) printf("label: %s", ci.l.name.c_str());
	printf("\n");

	// end test

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
