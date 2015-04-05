/****************************************************************
*
* FILENAME
*
*   \file mipsfrontend.h
*
* PURPOSE 
*
*   Skeleton for MIPS disassembly.
*
* AUTHOR 
*
*   \author Markus Gothe, nietzsche@lysator.liu.se
*
* REVISION 
*
*   $Id: mipsfrontend.h,v 1.2 2011/03/20 13:37:37 emmerik Exp $
*
*****************************************************************/

#ifndef MIPSFRONTEND_H
#define MIPSFRONTEND_H

// Class MIPSFrontEnd: derived from FrontEnd, with source machine specific
// behaviour

#include <set>
#include "decoder.h"
#include "exp.h"			// Ugh... just for enum OPER
#include "frontend.h"		// In case included bare, e.g. ProcTest.cpp

class FrontEnd;
class MIPSDecoder;
struct DecodeResult;
class CallStatement;

class MIPSFrontEnd : public FrontEnd
{
public:
	MIPSFrontEnd(BinaryFile *pBF, Prog* prog, BinaryFileFactory* pbff);
	/**
	 * Virtual destructor.
	 */
virtual ~MIPSFrontEnd();

virtual platform getFrontEndId() { return PLAT_MIPS; }

virtual bool processProc(ADDRESS uAddr, UserProc* pProc, std::ofstream &os, bool frag = false, bool spec = false);

virtual std::vector<Exp*> &getDefaultParams();
virtual std::vector<Exp*> &getDefaultReturns();

virtual ADDRESS getMainEntryPoint( bool &gotMain );
	
};

#endif
