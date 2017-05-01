#include "vm.h"
#include <iostream>
#include <stdio.h>

void VM::e_addi() {
	ui32 val1 = _stack[_sp--];
	ui32 val2 = _stack[_sp--];
	_stack[++_sp] = val1 + val2;
	_cp++;

}


void VM::e_addb() {
	ubyte v1 = _stack[_sp--];
	ubyte v2 = _stack[_sp--];
	_stack[++_sp] = v1 + v2;
	_cp++;	
}

void VM::e_subi() {}



void VM::e_constb() {
	ubyte val = _code[++_cp];
	_stack[++_sp] = val;
	_cp++;
}

void VM::e_constw() {
	
}

// store a 32bit integer on the stack.
void VM::e_consti() {
	ui32 val1 = _code[++_cp];
	ui32 val2 = _code[++_cp];
	ui32 val3 = _code[++_cp];
	ui32 val4 = _code[++_cp];
	_stack[++_sp] = val1;
	_stack[++_sp] = val2;
	_stack[++_sp] = val3;
	_stack[++_sp] = val4;

	_cp++;
	
}


// jumps to an address in the code
// section.
void VM::e_jmp() {
	ui32 val1 = _code[++_cp];
	ui32 val2 = _code[++_cp];
	ui32 val3 = _code[++_cp];
	ui32 val4 = _code[++_cp];
	
	ui32 address = val1 | (val2 << 8) | (val3 << 16) | (val4 << 24);
	_cp = address;	

}
