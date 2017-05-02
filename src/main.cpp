#include <iostream>
#include "vm.h"
#include <stdio.h>
#include <fstream>
#include <assembler.h>
#include <string.h>


/***
	MAIN
	Starts up a virtual machine by reading in either
	- an assembly file
	- a binary file
	from the command line. 
	The first argument indicates the type of file, 
	the second argument is the name of the file.
*/
int main(int argc, char** args)  {

	ubyte* code = (ubyte*) malloc(255);
	memset(code, 0, 255);
	
	if (argc == 3) {
		if (strcmp(args[1], "b") == 0) {
			const char* infile = args[2];
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
		else if (strcmp(args[1], "a")==0) {
			const char* infile = args[2];
			std::vector<ubyte> assembly = assembleFile(infile);
			for (int i=0; i<assembly.size();++i) {
				code[i] = assembly.at(i);
			}

			
		}
	} 
	else {
		printf("usage: vm [fileType] [fileName] \n");
		exit(0);
	}

	ubyte heap[512];
	ubyte stack[256];
	
	VM vm(code, 13, heap, 512, stack, 256);		
	std::string regs = vm.regdump();
	std::string sd = vm.stackdump();
	std::cout << "regs before: " << regs << std::endl;
	std::cout << "stack before: " << sd << std::endl;
	ubyte cmd;
	while ((cmd = vm.fetch()) != 0) {
		vm.execute(cmd);
		
		// probably call Video update function here!

	}
	regs = vm.regdump();
	sd = vm.stackdump();
	std::cout << "regs after: " << regs << std::endl;
	std::cout << "stack after: " << sd << std::endl;
	return 0;
}
