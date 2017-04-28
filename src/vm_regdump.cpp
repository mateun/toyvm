#include "vm.h"

std::string VM::regdump() {
	std::string dump = "\n";
	dump += "cp: " + std::to_string(_cp) + "\n";
	dump += "sp: " + std::to_string(_sp) + "\n";
	dump += "fp: " + std::to_string(_fp) + "\n";
	dump += "hp: " + std::to_string(_hp) + "\n";
	
	return dump;
}

std::string VM::heapdump() {
	return "";
}

std::string VM::stackdump() {
	std::string d = "\n";
	for (int i=0; i < 20; ++i) {
		d += std::to_string(i) + ":\t" + std::to_string(_stack[i]) + "\n";
	}
	return d;
}
