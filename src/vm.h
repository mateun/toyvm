#include "globaltypes.h"
#include <string>


/***

 * A virtual machine which has 
 * a heap, a stack and registers pointing to 
 * the current instruction pointer etc.
**/
class VM {

public:
	VM(int* code, ui32 csize, int* heapmem, ui32 hmemsize, int* stack, ui32 smemsize) 
		: _code(code), _heapmem(heapmem), _stack(stack) {}
	~VM() {}

public:
	virtual void run();
	virtual std::string regdump(); 
	virtual std::string heapdump();
	virtual std::string stackdump();

private:
	int* _code;
	int* _heapmem;
	int* _stack;
	
	ui32 _cp;
	ui32 _sp;
	ui32 _fp;
	ui32 _hp;

	
	

private:
	void e_consti();
	void e_addi();
	void e_subi();
	
};


