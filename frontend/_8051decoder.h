/*
	8051 Decoder Header created by Dedo in Nov 2015
 */

#ifndef _8051DECODER
#define _8051DECODER

class Prog;
class NJMCDecoder;
struct DecodeResult;

class _8051Decoder : public NJMCDecoder
{
public:
	/* Default constructor
	 */
					_8051Decoder(Prog* prog);

	/*
	 * Decodes the machine instruction at pc and returns an RTL instance for
	 * the instruction.
	 */
virtual DecodeResult& decodeInstruction (ADDRESS pc, int delta);
virtual DecodeResult& decodeAssembly (ADDRESS pc, std::string instr,AssemblyLine* line);
	/*
	 * Disassembles the machine instruction at pc and returns the number of
	 * bytes disassembled. Assembler output goes to global _assembly
	 */
virtual int			decodeAssemblyInstruction (ADDRESS pc, int delta);


private:
		unsigned magic_process(std::string name);
		/*
		 * Various functions to decode the operands of an instruction into an Exp* representation.
		 */
		//Exp*		dis_Eaddr(ADDRESS pc, int size = 0);
		//Exp*		dis_RegImm(ADDRESS pc);
		//Exp*		dis_Reg(unsigned r);
		//Exp*		dis_RAmbz(unsigned r);		// Special for rA of certain instructions

		//void		unused(int x);
		//RTL*		createBranchRtl(ADDRESS pc, std::list<Statement*>* stmts, const char* name);
		//bool		isFuncPrologue(ADDRESS hostPC);
		//DWord		getDword(ADDRESS lc);

};

#endif
