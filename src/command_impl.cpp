#include "vm.h"
#include <iostream>

void VM::e_addi() {
	std::cout << "addi" << std::endl;
	ui32 val1 = _stack[_sp--];
	ui32 val2 = _stack[_sp--];
	std::cout << "val1 und 2: " << std::to_string(val1) << std::endl;
	_stack[++_sp] = val1 + val2;
	_cp++;

}

void VM::e_subi() {}

void VM::e_consti() {
	std::cout << "consti" << std::endl;
	ui32 val = _code[++_cp];
	_stack[++_sp] = val;
	_cp++;
	
}
