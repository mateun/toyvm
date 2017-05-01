#include "globaltypes.h"
#include <string>


/***
 * A virtual machine which has 
 * a heap, a stack and registers pointing to 
 * the current instruction pointer etc.
 * 
 * The memory is byte addressable, the stack is 
 * is always moved in 4-byte steps with 4-byte alignment 
 * kept all times.
 * 
 * Multi byte values are store in Little-Endian (INTEL)
 * format to allow for easy and direct consumption of
 * data from Intel based machines.

 * Data sizes:
		- byte: 8bit
		- word: 16bit
		- dword: 32bit
		- qword: 64bit
 *
**/
class VM {

public:
	VM(ubyte* code, ui32 csize, ubyte* heapmem, ui32 hmemsize, ubyte* stack, ui32 smemsize) 
		: _code(code), _heapmem(heapmem), _stack(stack) {}
	~VM() {}

public:
	virtual void run();
	virtual std::string regdump(); 
	virtual std::string heapdump();
	virtual std::string stackdump();

private:
	ubyte* _code;
	ubyte* _heapmem;
	ubyte* _stack;
	
	ui32 _cp;
	ui32 _sp;
	ui32 _fp;
	ui32 _hp;

	
	

private:
	void e_consti();
	void e_addi();
	void e_addb();
	void e_addw();
	void e_subi();
	void e_constb();
	void e_constw();
	void e_jmp();
	
};


