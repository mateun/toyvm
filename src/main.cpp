#include <iostream>
#include "vm.h"


ubyte code[255] = {
	8, // constb
	77, 
	10,
	9,
	0, 
	0,
	0,
	8,
	255,
	8,
	99,
	0
		
};


int main(int argc, char** args)  {

	ubyte heap[512];
	ubyte stack[256];
	
	VM vm(code, 2, heap, 512, stack, 256);		
	std::string regs = vm.regdump();
	std::string sd = vm.stackdump();
	std::cout << "regs before: " << regs << std::endl;
	std::cout << "stack before: " << sd << std::endl;
	vm.run();
	regs = vm.regdump();
	sd = vm.stackdump();
	std::cout << "regs after: " << regs << std::endl;
	std::cout << "stack after: " << sd << std::endl;
	return 0;
}
