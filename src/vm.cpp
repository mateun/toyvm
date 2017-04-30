#include "vm.h"
#include "commands.h"
#include <iostream>


void VM::run() {
	
	ui32 cmd=_code[_cp];
	while (cmd != 0) {
		cmd = _code[_cp];	
		switch (cmd) {
				case (consti): e_consti(); break;
				case (addi): e_addi(); break;
				case (subi): e_subi(); break;
				default: break;
		}
	}
	
}
