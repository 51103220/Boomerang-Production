/*
	8051 FrontEnd Header created by Dedo in Nov 2015
 */
#ifndef _8051FRONTEND_H
#define _8051FRONTEND_H

#include <set>
#include "decoder.h"
#include "exp.h"			// Ugh... just for enum OPER
#include "frontend.h"		// In case included bare, e.g. ProcTest.cpp

class FrontEnd;
class _8051Decoder;
struct DecodeResult;
class CallStatement;

class _8051FrontEnd : public FrontEnd
{
public:
	
				_8051FrontEnd(BinaryFile *pBF, Prog* prog, BinaryFileFactory* pbff);
	/**
	 * Virtual destructor.
	 */
virtual ~_8051FrontEnd();

virtual platform getFrontEndId() { return PLAT_SPARC; }

virtual bool		processProc(ADDRESS uAddr, UserProc* pProc, std::ofstream &os, bool frag = false,
						bool spec = false);


virtual std::vector<Exp*> &getDefaultParams();
virtual std::vector<Exp*> &getDefaultReturns();

virtual ADDRESS getMainEntryPoint( bool &gotMain );
	
};

#endif