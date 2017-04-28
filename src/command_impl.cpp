#include "vm.h"
#include <iostream>

void VM::e_addi() {
	ui32 val1 = _stack[_sp--];
	ui32 val2 = _stack[_sp--];
	_stack[++_sp] = val1 + val2;
	_cp++;

}

void VM::e_subi() {}

void VM::e_consti() {
	ui32 val = _code[++_cp];
	_stack[++_sp] = val;
	_cp++;
	
}
