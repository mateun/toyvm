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
	printf("argi: %u size: %d\n", argi, size);
	for (int i=0; i<size; ++i) {
		ubyte b = (argi >> (8*i)) & 0xFF;
		printf("multibyte %d=%u\n", i, b);
		args.push_back(b);
	}
	return args;
}

struct Command {
		ubyte cmd = 0;
		ubyte arg_size = 0;
		std::vector<ubyte> args;
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
	}
	else if (cmd == "constb") {
		ci.c.cmd = constb;
		ci.c.arg_size = 1;
		ci.c.args = parse_args(arg, 1);
	}
	else if (cmd == "constw") {
		ci.c.cmd = constw;
		ci.c.arg_size = 2;
		ci.c.args = parse_args(arg, 2);
	}
	else if (cmd == "consti") {
		ci.c.cmd = consti;
		ci.c.arg_size = 4;
		ci.c.args = parse_args(arg, 4);
	}
	else if (cmd == "jmp") {
		ci.c.cmd = jmp;
		ci.c.arg_size = 4;
		ci.c.arg_sym_ref = arg;
	}
	else if (cmd == "addb") {
		ci.c.cmd = addb;
		ci.c.arg_size = 0;
	}
	else if (cmd == "addw") {
		ci.c.cmd = addw;
		ci.c.arg_size = 0;
	}
	else if (cmd == "addi") {
		ci.c.cmd = addi;
		ci.c.arg_size = 0;
	}
	else if (cmd.compare(cmd.length()-1, 1, ":") == 0) {
		ci.is_label = true;
		ci.l.name = cmd;
	}

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
		/*for (auto& b : assembleLine(line)) {
			// instead of directly pushing the bytecode into our
			// vector, we would do separate passes with the command infos here. 
			// see above!
			assembly.push_back(b);	
		}*/	
	}	

	// Go through the commandInfos and resolve symbols etc.
	// First, lets collect symbols
	std::map<std::string, int> sym_tab;
	for (auto& ci : cis) {
		if (ci.c.arg_sym_ref != "") {
			printf("found referenced symbol: %s\n", ci.c.arg_sym_ref.c_str());
			sym_tab[ci.c.arg_sym_ref+":"] = -1;
		}
		// print the arguments
		for (auto a : ci.c.args) {
			printf("------Arg: %u\n", a);
		}
	}	
	// Next, resolve symbols
	int pos = 0;
	for (auto& ci : cis) {
		if (ci.c.cmd == 0 && ci.is_label == false) continue;		
		printf("cmd: %u @pos: %d\n", ci.c.cmd, pos);
		if (ci.is_label) {
			printf("found label in resolution pass: %s at position: %d\n\n", ci.l.name.c_str(), pos);
			sym_tab[ci.l.name] = pos;
		} 
		else {
			pos++; // add 1 for the command itself
			pos += ci.c.arg_size; // add the arg size
		}
		
	}

	// Dump the sym_tab
	for(std::map<std::string, int>::iterator itty = sym_tab.begin(); itty != sym_tab.end(); ++itty) {
		printf("key: %s: %d\n", itty->first.c_str(), itty->second);
	}

	// Next, set the correct symbols
	pos = 0;
	for (auto& ci : cis) {
		if (ci.c.cmd == 0) continue;
		
		if (ci.c.arg_sym_ref != "") {
			printf("looking for value of key: %s\n", ci.c.arg_sym_ref.c_str());
			int jumpTarget = sym_tab[ci.c.arg_sym_ref + ":"];
			printf("jmpTarget: %d\n", jumpTarget);
			ci.c.args = parse_args(std::to_string(jumpTarget), 4);
		}
		printf("cmd: %u @pos: %d\n", ci.c.cmd, pos);		
		for (int i = 0; i<ci.c.arg_size; ++i) {
			printf("\targ: %u\n", ci.c.args.at(i));
		}
	
		pos++;
		pos += ci.c.arg_size;
	}
		
	// Finally, write out the correct bytecode
	for (auto& ci : cis) {
		if (ci.c.cmd == 0) continue;
		
		assembly.push_back(ci.c.cmd);
		for (auto a : ci.c.args) {
			assembly.push_back(a);
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
		assembly = a_cmd(0, addb, "", assembly);
	else if (cmd == "addw")
		assembly = a_cmd(0, addw, "", assembly);
	else if (cmd == "addi")
		assembly = a_cmd(0, addi, "", assembly);
	else if (cmd == "jmp")
		assembly = a_cmd(4, jmp, "0", assembly);

	return assembly;
}
