/*
	8051 FrontEnd created by Dedo in Nov 2015
 *==========================================================================*/

#include <assert.h>
#include <iomanip>			// For setfill etc
#include <sstream>
#if defined(_MSC_VER) && _MSC_VER <= 1200
#pragma warning(disable:4786)
#endif

#include "exp.h"
#include "register.h"
#include "rtl.h"
#include "cfg.h"
#include "proc.h"
#include "prog.h"
#include "decoder.h"
#include "_8051decoder.h"
#include "BinaryFile.h"
#include "frontend.h"
#include "_8051frontend.h"
#include "BinaryFile.h"		// E.g. IsDynamicallyLinkedProc
#include "boomerang.h"
#include "signature.h"

_8051FrontEnd::_8051FrontEnd(BinaryFile *pBF, Prog* prog, BinaryFileFactory* pbff) : FrontEnd(pBF, prog, pbff)
{
	decoder = new _8051Decoder(prog);
}


// destructor
_8051FrontEnd::~_8051FrontEnd()
{
}


std::vector<Exp*> &_8051FrontEnd::getDefaultParams()
{
	static std::vector<Exp*> params;
	if (params.size() == 0) {
		for (int r=31; r>=0; r--) {
			params.push_back(Location::regOf(r));
		}
	}
	return params;
}

std::vector<Exp*> &_8051FrontEnd::getDefaultReturns()
{
	static std::vector<Exp*> returns;
	if (returns.size() == 0) {
		for (int r=31; r>=0; r--) {
			returns.push_back(Location::regOf(r));
		}

	}
	return returns;
}

ADDRESS _8051FrontEnd::getMainEntryPoint( bool &gotMain ) 
{
	gotMain = true;
	ADDRESS start = pBF->GetMainEntryPoint();
	if( start != NO_ADDRESS ) return start;

	start = pBF->GetEntryPoint();
	gotMain = false;
	if( start == NO_ADDRESS ) return NO_ADDRESS;

	gotMain = true;
	return start;
}


bool _8051FrontEnd::processProc(ADDRESS uAddr, UserProc* pProc, std::ofstream &os, bool frag /* = false */,
		bool spec /* = false */) {

	// Call the base class to do most of the work
	if (!FrontEnd::processProc(uAddr, pProc, os, frag, spec))
		return false;
	// This will get done twice; no harm
	pProc->setEntryBB();

	return true;
}
