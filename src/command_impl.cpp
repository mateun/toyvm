#include "vm.h"
#include <iostream>
#include <stdio.h>

void VM::e_addw() {
	//printf("in addw...\n\n");
	ubyte val1_0 = _stack[_sp--];
	ubyte val1_1 = _stack[_sp--];
	ui32 val1 = val1_0 | (val1_1 << 8); 

	ubyte val2_0 = _stack[_sp--];
	ubyte val2_1 = _stack[_sp--];
	ui32 val2 = val2_0 | (val2_1 << 8);
 	ui32 res = val1 + val2;

	for (int i = 0; i<2; ++i) {
		ubyte b = (res >> (8*i)) & 0xFF;
		_stack[++_sp] = b;	
	}	
	_cp++;

}

void VM::e_addi() {
	ubyte val1_0 = _stack[_sp--];
	ubyte val1_1 = _stack[_sp--];
	ubyte val1_2 = _stack[_sp--];
	ubyte val1_3 = _stack[_sp--];
	ui32 val1 = val1_0 | (val1_1 << 8) | (val1_2 << 16) | (val1_3 << 24);

	ubyte val2_0 = _stack[_sp--];
	ubyte val2_1 = _stack[_sp--];
	ubyte val2_2 = _stack[_sp--];
	ubyte val2_3 = _stack[_sp--];
	ui32 val2 = val2_0 | (val2_1 << 8) | (val2_2 << 16) | (val2_3 << 24);
	ui32 res = val1 + val2;

	for (int i = 0; i<4; ++i) {
		ubyte b = (res >> (8*i)) & 0xFF;
		_stack[++_sp] = b;	
	}	
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
	_sp += 3;
	_cp++;
}

void VM::e_constw() {
	ui32 val1 = _code[++_cp];
	ui32 val2 = _code[++_cp];
	_stack[++_sp] = val1;
	_stack[++_sp] = val2;

	_cp++;
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
