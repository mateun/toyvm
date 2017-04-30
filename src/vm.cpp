#include "vm.h"
#include "commands.h"
#include <iostream>
#include <stdio.h>


void VM::run() {
	
	ubyte cmd=_code[_cp];
	printf("cmd: %u\n", cmd);	

	while (cmd != 0) {
		cmd = _code[_cp];	
		switch (cmd) {
				case (consti): e_consti(); break;
				case (constb): e_constb(); break;
				case (jmp): e_jmp(); break;
				case (addi): e_addi(); break;
				case (addb): e_addb(); break;
				case (subi): e_subi(); break;
				default: break;
		}
	}
	
}
