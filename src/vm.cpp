#include "vm.h"
#include "commands.h"
#include <iostream>
#include <stdio.h>


void VM::run() {
	
	ubyte cmd=_code[_cp];

	while (cmd != 0) {
		cmd = _code[_cp];	
		printf("curr. command: %u\n", cmd);
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
	
}
