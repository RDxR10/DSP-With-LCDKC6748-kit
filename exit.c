#include <stdlib.h>
#include <pprof.h>

#if defined(__TI_RECURSIVE_RESOURCE_MUTEXES)
void  _DATA_ACCESS 	(*_delete_mutexes_ptr)(void) = NULL;
#endif
void  _DATA_ACCESS	(*_cleanup_ptr)(void) = NULL;
void  _DATA_ACCESS	(*_dtors_ptr)(int)    = NULL;

typedef void (*PTRFUNC)();
far int __TI_enable_exit_profile_output = 1;

_CODE_ACCESS void exit(int status)
{
	if (__TI_enable_exit_profile_output && _symval(&__TI_pprof_out_hndl) !=(unsigned)-1)
	{
	PTRFUNC ppfunc = (PTRFUNC)(_symval(&__TI_pprof_out_hndl));
	(ppfunc)();
	}

	if (_dtors_ptr) (*_dtors_ptr)(status);

#if defined(_C_IN_NS)
	closeall();
#else
	if(_cleanup_ptr) (*_cleanup_ptr)();
#endif
#if defined(__TI_RECURSIVE_RESOURCE_MUTEXES)
	if (_delete_mutexes_ptr) (*_delete_mutexes_ptr)();
#endif

	abort();
}

_CODE_ACCESS void abort(void)
{
#pragma diag_suppress 1119
#ifndef __VIRTUAL_ENCODING__

	__asm("		.global C$$EXIT");
	__asm("C$$EXIT: nop");
#else
	
	__asm("		.vinstr C$$EXIT");
	__asm("C$$EXIT: .encode \"C$$EXIT\", $ENC_OPNDS, 0");
#endif
#pragma diag_default 1119

	for (; ;);
}
