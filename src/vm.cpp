#include "vm.h"
#include "commands.h"
#include <iostream>
#include <stdio.h>


ubyte VM::fetch() {
	return _code[_cp];

}

void VM::execute(ubyte cmd) {
	switch (cmd) {
				case (consti): e_consti(); break;
				case (constw): e_constw(); break;
				case (constb): e_constb(); break;
				case (jmp): e_jmp(); break;
				case (addi): e_addi(); break;
				case (addb): e_addb(); break;
				case (addw): e_addw(); break;
				case (subi): e_subi(); break;
				default: break;
		}
}

void VM::run() {
	
	ubyte cmd=fetch();
	printf("code dump (20bytes):\n");
	for (int i=0; i<20; ++i) {
		printf("code %u at %d\n", _code[i], i);
	}

	while (cmd != 0) {
		cmd = fetch();
		printf("curr. command: %u _cp: %d\n", cmd, _cp);
		execute(cmd);
	}
	
}
