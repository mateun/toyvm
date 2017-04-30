#include <iostream>
#include "vm.h"
#include <stdio.h>


int main(int argc, char** args)  {


	ubyte code[255];
	if (argc == 2) {
		const char* infile = args[1];
		FILE* binfile = fopen(infile, "rb");				
		if (binfile == NULL) {
			printf("file not opened!\n");
			exit(1);
		}
		int nr = fread(code, 1, 255, binfile);

		// this is of course unsafe but lets do it now for quick testing, 
		// adding a trailing 0 to end our code:
		code[nr] = 0;

		for (int i = 0; i<=nr; ++i) {
			printf("code: %d: %u\n",i, (unsigned)code[i]);
		}
		fclose(binfile);
	}

	ubyte heap[512];
	ubyte stack[256];
	
	VM vm(code, 13, heap, 512, stack, 256);		
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
