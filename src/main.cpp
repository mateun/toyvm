#include <iostream>
#include "vm.h"


int code[6] = {
	1, // consti
	9, // 99
	1,  // consti
	-12,
	2,	// addi
	0
		
};


int main(int argc, char** args)  {

	int heap[512];
	int stack[256];
	
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
