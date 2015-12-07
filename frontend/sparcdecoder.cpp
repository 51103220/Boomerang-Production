#include <algorithm>
#include <iostream>
#include <sstream>
#include <iterator>
#include <vector>
#include <sstream>
#include <string>
#include <assert.h>
#include <cstring>
#include <vector>

inline bool isInteger(const std::string & s) {
  if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false ;
  char * p ;
  strtol(s.c_str(), &p, 10) ;
  return (*p == 0) ;
}

bool if_str(std::string name){
  if (name.find("\"") != std::string::npos) {
    return true;
  }
  return false;
}
char* process_str(std::string name){
  name.erase(0,1);
  name.erase(name.size()-1,1);
  char *str =  new char[name.length() + 1];
  strcpy(str, name.c_str());
  return str;
}
/*
 * Copyright (C) 1996-2001, The University of Queensland
 *
 * See the file "LICENSE.TERMS" for information on usage and
 * redistribution of this file, and for a DISCLAIMER OF ALL
 * WARRANTIES.
 *
 */

/*==============================================================================
 * FILE:     decoder.m
 * OVERVIEW:   Implementation of the SPARC specific parts of the
 *         SparcDecoder class.
 *============================================================================*/

/* $Revision: 1.24 $  
 *
 * 26 Apr 02 - Mike: Mods for boomerang
 * 19 May 02 - Mike: Added many (int) casts: variables from toolkit are unsgnd
 * 21 May 02 - Mike: SAVE and RESTORE have full semantics now
 * 30 Oct 02 - Mike: dis_Eaddr mode indirectA had extra memof
 * 22 Nov 02 - Mike: Support 32 bit V9 branches
 * 04 Dec 02 - Mike: r[0] -> 0 automatically (rhs only)
 * 30 May 02 - Mike: Also fixed r[0] -> 0 for store instructions
 * 03 Nov 04 - Mike: DIS_FDS was returning numbers for the double precision registers
*/

/*==============================================================================
 * Dependencies.
 *============================================================================*/

#include <assert.h>
#include <cstring>
#if defined(_MSC_VER) && _MSC_VER <= 1100
#include "signature.h"
#endif


#include "decoder.h"
#include "sparcdecoder.h"
#include "exp.h"
#include "prog.h"
#include "proc.h"
#include "rtl.h"
#include "BinaryFile.h"   
#include "boomerang.h"

#define DIS_ROI   (dis_RegImm(roi))
#define DIS_ADDR  (dis_Eaddr(addr))
#define DIS_RD    (dis_RegLhs(rd))
#define DIS_RDR   (dis_RegRhs(rd))
#define DIS_RS1   (dis_RegRhs(rs1))
#define DIS_FS1S  (dis_RegRhs(fs1s+32))
#define DIS_FS2S  (dis_RegRhs(fs2s+32))


#define DIS_FDS   (dis_RegLhs(fds+32))
#define DIS_FS1D  (dis_RegRhs((fs1d>>1)+64))
#define DIS_FS2D  (dis_RegRhs((fs2d>>1)+64))
#define DIS_FDD   (dis_RegLhs((fdd>>1)+64))
#define DIS_FDQ   (dis_RegLhs((fdq>>2)+80))
#define DIS_FS1Q  (dis_RegRhs((fs1q>>2)+80))
#define DIS_FS2Q  (dis_RegRhs((fs2q>>2)+80))

/*==============================================================================
 * FUNCTION:     unused
 * OVERVIEW:     A dummy function to suppress "unused local variable" messages
 * PARAMETERS:     x: integer variable to be "used"
 * RETURNS:      Nothing
 *============================================================================*/
unsigned SparcDecoder::magic_process(std::string name) {
  std::transform(name.begin(), name.end(),name.begin(), ::tolower);
  std::string str = name;
  if (name == "%g0") return 0;
  else if (name == "%g1") return 1;
  else if (name == "%g2") return 2;
  else if (name == "%g3") return 3;
  else if (name == "%g4") return 4;
  else if (name == "%g5") return 5;
  else if (name == "%g6") return 6;
  else if (name == "%g7") return 7;
  else if (name == "%o0") return 8;
  else if (name == "%o1") return 9;
  else if (name == "%o2") return 10;
  else if (name == "%o3") return 11;
  else if (name == "%o4") return 12;
  else if (name == "%o5") return 13;
  else if (name == "%sp") return 14;
  else if (name == "%o7") return 15;
  else if (name == "%l0") return 16;
  else if (name == "%l1") return 17;
  else if (name == "%l2") return 18;
  else if (name == "%l3") return 19;
  else if (name == "%l4") return 20;
  else if (name == "%l5") return 21;
  else if (name == "%l6") return 22;
  else if (name == "%l7") return 23;
  else if (name == "%i0") return 24;
  else if (name == "%i1") return 25;
  else if (name == "%i2") return 26;
  else if (name == "%i3") return 27;
  else if (name == "%i4") return 28;
  else if (name == "%i5") return 29;
  else if (name == "%fp") return 30;
  else if (name == "%i7") return 31;
  else if (name == "%f0") return 0;
  else if (name == "%f1") return 1;
  else if (name == "%f2") return 2;
  else if (name == "%f3") return 3;
  else if (name == "%f4") return 4;
  else if (name == "%f5") return 5;
  else if (name == "%f6") return 6;
  else if (name == "%f7") return 7;
  else if (name == "%f8") return 8;
  else if (name == "%f9") return 9;
  else if (name == "%f10") return 10;
  else if (name == "%f11") return 11;
  else if (name == "%f12") return 12;
  else if (name == "%f13") return 13;
  else if (name == "%f14") return 14;
  else if (name == "%f15") return 15;
  else if (name == "%f16") return 16;
  else if (name == "%f17") return 17;
  else if (name == "%f18") return 18;
  else if (name == "%f19") return 19;
  else if (name == "%f20") return 20;
  else if (name == "%f21") return 21;
  else if (name == "%f22") return 22;
  else if (name == "%f23") return 23;
  else if (name == "%f24") return 24;
  else if (name == "%f25") return 25;
  else if (name == "%f26") return 26;
  else if (name == "%f27") return 27;
  else if (name == "%f28") return 28;
  else if (name == "%f29") return 29;
  else if (name == "%f30") return 30;
  else if (name == "%f31") return 31;
  else if (name == "%f0to1") return 0;
  else if (name == "a") return 1;
  else if (name == "%f2to3") return 2;
  else if (name == "b") return 3;
  else if (name == "%f4to5") return 4;
  else if (name == "c") return 5;
  else if (name == "%f6to7") return 6;
  else if (name == "d") return 7;
  else if (name == "%f8to9") return 8;
  else if (name == "e") return 9;
  else if (name == "%f10to11") return 10;
  else if (name == "f") return 11;
  else if (name == "%f12to13") return 12;
  else if (name == "g") return 13;
  else if (name == "%f14to15") return 14;
  else if (name == "h") return 15;
  else if (name == "%f16to17") return 16;
  else if (name == "i") return 17;
  else if (name == "%f18to19") return 18;
  else if (name == "j") return 19;
  else if (name == "%f20to21") return 20;
  else if (name == "k") return 21;
  else if (name == "%f22to23") return 22;
  else if (name == "l") return 23;
  else if (name == "%f24to25") return 24;
  else if (name == "m") return 25;
  else if (name == "%f26to27") return 26;
  else if (name == "n") return 27;
  else if (name == "%f28to29") return 28;
  else if (name == "o") return 29;
  else if (name == "%f30to31") return 30;
  else if (name == "p") return 31;
  else if (name == "%f0to3") return 0;
  else if (name == "q") return 1;
  else if (name == "r") return 2;
  else if (name == "s") return 3;
  else if (name == "%f4to7") return 4;
  else if (name == "t") return 5;
  else if (name == "u") return 6;
  else if (name == "v") return 7;
  else if (name == "%f8to11") return 8;
  else if (name == "w") return 9;
  else if (name == "x") return 10;
  else if (name == "y") return 11;
  else if (name == "%f12to15") return 12;
  else if (name == "z") return 13;
  else if (name == "A") return 14;
  else if (name == "B") return 15;
  else if (name == "%f16to19") return 16;
  else if (name == "C") return 17;
  else if (name == "D") return 18;
  else if (name == "E") return 19;
  else if (name == "%f20to23") return 20;
  else if (name == "F") return 21;
  else if (name == "G") return 22;
  else if (name == "H") return 23;
  else if (name == "%f24to27") return 24;
  else if (name == "I") return 25;
  else if (name == "J") return 26;
  else if (name == "K") return 27;
  else if (name == "%f28to31") return 28;
  else if (name == "L") return 29;
  else if (name == "M") return 30;
  else if (name == "N") return 31;
  else if (name == "%c0") return 0;
  else if (name == "%c1") return 1;
  else if (name == "%c2") return 2;
  else if (name == "%c3") return 3;
  else if (name == "%c4") return 4;
  else if (name == "%c5") return 5;
  else if (name == "%c6") return 6;
  else if (name == "%c7") return 7;
  else if (name == "%c8") return 8;
  else if (name == "%c9") return 9;
  else if (name == "%c10") return 10;
  else if (name == "%c11") return 11;
  else if (name == "%c12") return 12;
  else if (name == "%c13") return 13;
  else if (name == "%c14") return 14;
  else if (name == "%c15") return 15;
  else if (name == "%c16") return 16;
  else if (name == "%c17") return 17;
  else if (name == "%c18") return 18;
  else if (name == "%c19") return 19;
  else if (name == "%c20") return 20;
  else if (name == "%c21") return 21;
  else if (name == "%c22") return 22;
  else if (name == "%c23") return 23;
  else if (name == "%c24") return 24;
  else if (name == "%c25") return 25;
  else if (name == "%c26") return 26;
  else if (name == "%c27") return 27;
  else if (name == "%c28") return 28;
  else if (name == "%c29") return 29;
  else if (name == "%c30") return 30;
  else if (name == "%c31") return 31;
  else if (name == "") return 0;
  else if (name == ",a") return 1;
  else if (name == "%hi(.lc0)") return 66560;
  else if (name == "%lo(.lc0)") return 508;
  else if (name == "puts") return 132808;   
  else if (isInteger(str)) {
    int i = std::atoi((str).c_str());
    if (i < 0) return i;
    else return 100 + i;
  }

} 
void SparcDecoder::unused(int x)
{
}
/*==============================================================================
 * FUNCTION:     createBranchRtl
 * OVERVIEW:     Create an RTL for a Bx instruction
 * PARAMETERS:     pc - the location counter
 *           stmts - ptr to list of Statement pointers
 *           name - instruction name (e.g. "BNE,a", or "BPNE")
 * RETURNS:      Pointer to newly created RTL, or NULL if invalid
 *============================================================================*/
static DecodeResult result;
RTL* SparcDecoder::createBranchRtl(ADDRESS pc,std::list<Statement*>* stmts,const char* name)
{
  RTL* res = new RTL(pc, stmts);
  BranchStatement* br = new BranchStatement();
  res->appendStmt(br);
  if(name[0] == 'F')
  {
    if(name[2] == 'U')
    name++;
    switch(name[2])
    {
      case 'E':
      br->setCondType(BRANCH_JE, true);
      break;
      case 'L':
      if(name[3] == 'G')
      br->setCondType(BRANCH_JNE, true);
      else
      if(name[3] == 'E')
      br->setCondType(BRANCH_JSLE, true);
      else
      br->setCondType(BRANCH_JSL, true);
      break;
      case 'G':
      if(name[3] == 'E')
      br->setCondType(BRANCH_JSGE, true);
      else
      br->setCondType(BRANCH_JSG, true);
      break;
      case 'N':
      if(name[3] == 'E')
      br->setCondType(BRANCH_JNE, true);
      break;
      default:
      std::cerr << "unknown float branch " << name << std::endl;
      delete res;
      res = NULL;
    }
    return res;
  }
  switch(name[1])
  {
    case 'E':
    br->setCondType(BRANCH_JE);
    break;
    case 'L':
    if(name[2] == 'E')
    {
      if(name[3] == 'U')
      br->setCondType(BRANCH_JULE);
      else
      br->setCondType(BRANCH_JSLE);
    }
    else
    br->setCondType(BRANCH_JSL);
    break;
    case 'N':
    if(name[3] == 'G')
    br->setCondType(BRANCH_JMI);
    else
    br->setCondType(BRANCH_JNE);
    break;
    case 'C':
    if(name[2] == 'C')
    br->setCondType(BRANCH_JUGE);
    else
    br->setCondType(BRANCH_JUL);
    break;
    case 'V':
    if(name[2] == 'C')
    std::cerr << "Decoded BVC instruction\n";
    else
    std::cerr << "Decoded BVS instruction\n";
    break;
    case 'G':
    if(name[2] == 'E')
    br->setCondType(BRANCH_JSGE);
    else
    if(name[2] == 'U')
    br->setCondType(BRANCH_JUG);
    else
    br->setCondType(BRANCH_JSG);
    break;
    case 'P':
    if(name[2] == 'O')
    {
      br->setCondType(BRANCH_JPOS);
      break;
    }
    char temp[8];
    temp[0] = 'B';
    strcpy(temp+1, name+2);
    delete res;
    return createBranchRtl(pc, stmts, temp);
    default:
    std::cerr << "unknown non-float branch " << name << std::endl;
  }
  return res;
}
/*==============================================================================
 * FUNCTION:     SparcDecoder::decodeInstruction
 * OVERVIEW:     Attempt to decode the high level instruction at a given address and return the corresponding HL type
 *          (e.g. CallStatement, GotoStatement etc). If no high level instruction exists at the given address,
 *          then simply return the RTL for the low level instruction at this address. There is an option to also
 *           include the low level statements for a HL instruction.
 * PARAMETERS:     pc - the native address of the pc
 *           delta - the difference between the above address and the host address of the pc (i.e. the address
 *          that the pc is at in the loaded object file)
 *           proc - the enclosing procedure. This can be NULL for those of us who are using this method in an
 *          interpreter
 * RETURNS:      a DecodeResult structure containing all the information gathered during decoding
 *============================================================================*/
DecodeResult& SparcDecoder::decodeAssembly (ADDRESS pc, std::string line,AssemblyLine* Line)
{
  int delta = 0;
  static DecodeResult result;
  ADDRESS hostPC = pc+delta;
  result.reset();
  std::list<Statement*>* stmts = NULL;
  ADDRESS nextPC = NO_ADDRESS;
  //ADDRESS nextPC = NO_ADDRESS;
  using namespace std;
  std::string sentence = line;
  std::transform(sentence.begin(), sentence.end(),sentence.begin(), ::toupper);
    sentence.erase(std::remove(sentence.begin(), sentence.end(), ','), sentence.end());
    std::istringstream iss(sentence);
    std::vector <std::string> tokens;
    copy(istream_iterator<std::string>(iss),
         istream_iterator<std::string>(),
       back_inserter(tokens));
  dword MATCH_p = hostPC;
  if (tokens.at(0) == "CALL" ) {
    unsigned addr = magic_process(tokens.at(1));
    bool is_lib = false;
    if (tokens.at(1) == "PRINTF" || tokens.at(1) == "PUTS"){
      addr = 132912;
      is_lib = true;
    }
    else {
      addr = 66752;
    }
    CallStatement* newCall = new CallStatement;
    ADDRESS nativeDest = addr - delta;
    newCall->setDest(nativeDest);
    Proc* destProc;
    std::transform(tokens.at(1).begin(), tokens.at(1).end(),tokens.at(1).begin(), ::tolower);
    char *name =  new char[tokens.at(1).length() + 1];
    strcpy(name, tokens.at(1).c_str());
    if (!ASS_FILE){
      destProc = prog->setNewProc(nativeDest);
      if (destProc == (Proc*)-1) destProc = NULL;
    }
    else {
      destProc = prog->newProc(name, nativeDest, is_lib);
    }
    newCall->setDestProc(destProc);

    result.rtl = new RTL(pc, stmts);
    result.rtl->appendStmt(newCall);
    result.type = SD;

    SHOW_ASM("call__ " << std::hex << (nativeDest))

    DEBUG_STMTS

  }
  if (tokens.at(0) == "BN,a" || tokens.at(0) == "BE,a" || tokens.at(0) == "BLE,a" || tokens.at(0) == "BL,a" || tokens.at(0) == "BLEU,a" || tokens.at(0) == "BCS,a" || tokens.at(0) == "BNEG,a" || tokens.at(0) == "BVS,a" || tokens.at(0) == "BA,a" || tokens.at(0) == "BNE,a" || tokens.at(0) == "BG,a" || tokens.at(0) == "BGE,a" || tokens.at(0) == "BGU,a" || tokens.at(0) == "BCC,a" || tokens.at(0) == "BPOS,a" || tokens.at(0) == "BVC,a" || tokens.at(0) == "FBN,a" || tokens.at(0) == "FBNE,a" || tokens.at(0) == "FBLG,a" || tokens.at(0) == "FBUL,a" || tokens.at(0) == "FBL,a" || tokens.at(0) == "FBUG,a" || tokens.at(0) == "FBG,a" || tokens.at(0) == "FBU,a" || tokens.at(0) == "FBA,a" || tokens.at(0) == "FBE,a" || tokens.at(0) == "FBUE,a" || tokens.at(0) == "FBGE,a" || tokens.at(0) == "FBUGE,a" || tokens.at(0) == "FBLE,a" || tokens.at(0) == "FBULE,a" || tokens.at(0) == "FBO,a" || tokens.at(0) == "CBN,a" || tokens.at(0) == "CB123,a" || tokens.at(0) == "CB12,a" || tokens.at(0) == "CB13,a" || tokens.at(0) == "CB1,a" || tokens.at(0) == "CB23,a" || tokens.at(0) == "CB2,a" || tokens.at(0) == "CB3,a" || tokens.at(0) == "CBA,a" || tokens.at(0) == "CB0,a" || tokens.at(0) == "CB03,a" || tokens.at(0) == "CB02,a" || tokens.at(0) == "CB023,a" || tokens.at(0) == "CB01,a" || tokens.at(0) == "CB013,a" || tokens.at(0) == "CB012,a") {
    unsigned tgt = magic_process(tokens.at(1));
    char *name =  new char[tokens.at(0).length() + 1];
    strcpy(name, tokens.at(0).c_str());
    if(name[0] == 'C')
    {
      result.valid = false;
      result.rtl = new RTL;
      result.numBytes = 4;
      return result;
    }
    GotoStatement* jump = 0;
    RTL* rtl = NULL;
    if(strcmp(name,"BA,a") == 0 || strcmp(name,"BN,a") == 0)
    {
      jump = new GotoStatement;
      rtl = new RTL(pc, stmts);
      rtl->appendStmt(jump);
    }
    else
    if(strcmp(name,"BVS,a") == 0 || strcmp(name,"BVC,a") == 0)
    {
      jump = new GotoStatement;
      rtl = new RTL(pc, stmts);
      rtl->appendStmt(jump);
    }
    else
    {
      rtl = createBranchRtl(pc, stmts, name);
      jump = (GotoStatement*) rtl->getList().back();
    }
    result.type = SCDAN;
    if((strcmp(name,"BA,a") == 0) || (strcmp(name, "BVC,a") == 0))
    {
      result.type = SU;
    }
    else
    {
      result.type = SKIP;
    }
    result.rtl = rtl;
    jump->setDest(tgt - delta);
  }
  if (tokens.at(0) == "BPN,a" || tokens.at(0) == "BPE,a" || tokens.at(0) == "BPLE,a" || tokens.at(0) == "BPL,a" || tokens.at(0) == "BPLEU,a" || tokens.at(0) == "BPCS,a" || tokens.at(0) == "BPNEG,a" || tokens.at(0) == "BPVS,a" || tokens.at(0) == "BPA,a" || tokens.at(0) == "BPNE,a" || tokens.at(0) == "BPG,a" || tokens.at(0) == "BPGE,a" || tokens.at(0) == "BPGU,a" || tokens.at(0) == "BPCC,a" || tokens.at(0) == "BPPOS,a" || tokens.at(0) == "BPVC,a") {
    unsigned cc01 = magic_process(tokens.at(1));
    unsigned tgt = magic_process(tokens.at(2));
    char *name =  new char[tokens.at(0).length() + 1];
    strcpy(name, tokens.at(0).c_str());
    if(cc01 != 0)
    {
      result.valid = false;
      result.rtl = new RTL;
      result.numBytes = 4;
      return result;
    }
    GotoStatement* jump = 0;
    RTL* rtl = NULL;
    if(strcmp(name,"BPA,a") == 0 || strcmp(name,"BPN,a") == 0)
    {
      jump = new GotoStatement;
      rtl = new RTL(pc, stmts);
      rtl->appendStmt(jump);
    }
    else
    if(strcmp(name,"BPVS,a") == 0 || strcmp(name,"BPVC,a") == 0)
    {
      jump = new GotoStatement;
      rtl = new RTL(pc, stmts);
      rtl->appendStmt(jump);
    }
    else
    {
      rtl = createBranchRtl(pc, stmts, name);
      jump = (GotoStatement*) rtl->getList().back();
    }
    result.type = SCDAN;
    if((strcmp(name,"BPA,a") == 0) || (strcmp(name, "BPVC,a") == 0))
    {
      result.type = SU;
    }
    else
    {
      result.type = SKIP;
    }
    result.rtl = rtl;
    jump->setDest(tgt - delta);
  }
  if (tokens.at(0) == "BN" || tokens.at(0) == "BE" || tokens.at(0) == "BLE" || tokens.at(0) == "BL" || tokens.at(0) == "BLEU" || tokens.at(0) == "BCS" || tokens.at(0) == "BNEG" || tokens.at(0) == "BVS" || tokens.at(0) == "BA" || tokens.at(0) == "BNE" || tokens.at(0) == "BG" || tokens.at(0) == "BGE" || tokens.at(0) == "BGU" || tokens.at(0) == "BCC" || tokens.at(0) == "BPOS" || tokens.at(0) == "BVC" || tokens.at(0) == "FBN" || tokens.at(0) == "FBNE" || tokens.at(0) == "FBLG" || tokens.at(0) == "FBUL" || tokens.at(0) == "FBL" || tokens.at(0) == "FBUG" || tokens.at(0) == "FBG" || tokens.at(0) == "FBU" || tokens.at(0) == "FBA" || tokens.at(0) == "FBE" || tokens.at(0) == "FBUE" || tokens.at(0) == "FBGE" || tokens.at(0) == "FBUGE" || tokens.at(0) == "FBLE" || tokens.at(0) == "FBULE" || tokens.at(0) == "FBO" || tokens.at(0) == "CBN" || tokens.at(0) == "CB123" || tokens.at(0) == "CB12" || tokens.at(0) == "CB13" || tokens.at(0) == "CB1" || tokens.at(0) == "CB23" || tokens.at(0) == "CB2" || tokens.at(0) == "CB3" || tokens.at(0) == "CBA" || tokens.at(0) == "CB0" || tokens.at(0) == "CB03" || tokens.at(0) == "CB02" || tokens.at(0) == "CB023" || tokens.at(0) == "CB01" || tokens.at(0) == "CB013" || tokens.at(0) == "CB012") {
    unsigned tgt = magic_process(tokens.at(1));
    char *name =  new char[tokens.at(0).length() + 1];
    strcpy(name, tokens.at(0).c_str());
    if(name[0] == 'C')
    {
      result.valid = false;
      result.rtl = new RTL;
      result.numBytes = 4;
      return result;
    }
    GotoStatement* jump = 0;
    RTL* rtl = NULL;
    if(strcmp(name,"BA") == 0 || strcmp(name,"BN") == 0)
    {
      jump = new GotoStatement;
      rtl = new RTL(pc, stmts);
      rtl->appendStmt(jump);
    }
    else
    if(strcmp(name,"BVS") == 0 || strcmp(name,"BVC") == 0)
    {
      jump = new GotoStatement;
      rtl = new RTL(pc, stmts);
      rtl->appendStmt(jump);
    }
    else
    {
      rtl = createBranchRtl(pc, stmts, name);
      jump = (BranchStatement*) rtl->getList().back();
    }
    result.type = SCD;
    if((strcmp(name,"BA") == 0) || (strcmp(name, "BVC") == 0))
    result.type = SD;
    if((strcmp(name,"BN") == 0) || (strcmp(name, "BVS") == 0))
    result.type = NCT;
    result.rtl = rtl;
    jump->setDest(tgt - delta);
  }
  if (tokens.at(0) == "BPA" ) {
    unsigned cc01 = magic_process(tokens.at(1));
    unsigned tgt = magic_process(tokens.at(2));
    unused(cc01);
    GotoStatement* jump = new GotoStatement;
    result.type = SD;
    result.rtl = new RTL(pc, stmts);
    result.rtl->appendStmt(jump);
    jump->setDest(tgt - delta);
  }
  if (tokens.at(0) == "BPN" || tokens.at(0) == "BPE" || tokens.at(0) == "BPLE" || tokens.at(0) == "BPL" || tokens.at(0) == "BPLEU" || tokens.at(0) == "BPCS" || tokens.at(0) == "BPNEG" || tokens.at(0) == "BPVS" || tokens.at(0) == "BPA" || tokens.at(0) == "BPNE" || tokens.at(0) == "BPG" || tokens.at(0) == "BPGE" || tokens.at(0) == "BPGU" || tokens.at(0) == "BPCC" || tokens.at(0) == "BPPOS" || tokens.at(0) == "BPVC") {
    unsigned cc01 = magic_process(tokens.at(1));
    unsigned tgt = magic_process(tokens.at(2));
    char *name =  new char[tokens.at(0).length() + 1];
    strcpy(name, tokens.at(0).c_str());
    if(cc01 != 0)
    {
      result.valid = false;
      result.rtl = new RTL;
      result.numBytes = 4;
      return result;
    }
    GotoStatement* jump = 0;
    RTL* rtl = NULL;
    if(strcmp(name,"BPN") == 0)
    {
      jump = new GotoStatement;
      rtl = new RTL(pc, stmts);
      rtl->appendStmt(jump);
    }
    else
    if(strcmp(name,"BPVS") == 0 || strcmp(name,"BPVC") == 0)
    {
      jump = new GotoStatement;
      rtl = new RTL(pc, stmts);
      rtl->appendStmt(jump);
    }
    else
    {
      rtl = createBranchRtl(pc, stmts, name);
      jump = (GotoStatement*)rtl->getList().back();
    }
    result.type = SCD;
    if(strcmp(name, "BPVC") == 0)
    result.type = SD;
    if((strcmp(name,"BPN") == 0) || (strcmp(name, "BPVS") == 0))
    result.type = NCT;
    result.rtl = rtl;
    jump->setDest(tgt - delta);
  }
  if (tokens.at(0) == "JMPL" || tokens.at(0) == "JMP" ) {
    if (tokens.at(0) == "JMP"){

      result.rtl = new RTL(pc, stmts);

      result.rtl->appendStmt(new ReturnStatement);

      result.type = DD;
      SHOW_ASM("retl_");
      DEBUG_STMTS
    }
    else{
      unsigned addr = magic_process(tokens.at(1));
      unsigned rd = magic_process(tokens.at(2));
      CaseStatement* jump = new CaseStatement;
      jump->setIsComputed();
      result.rtl = new RTL(pc, stmts);
      result.rtl->appendStmt(jump);
      result.type = DD;
      jump->setDest(dis_Eaddr(addr));
      unused(rd);
    }
  }
  if (tokens.at(0) == "SAVE" ) {
    unsigned rs1 = magic_process(tokens.at(1));
    unsigned roi = magic_process(tokens.at(2));
    unsigned rd = magic_process(tokens.at(3));
    stmts = instantiate(pc, "SAVE", DIS_RS1, DIS_ROI, DIS_RD);
  }
  if (tokens.at(0) == "RESTORE" ) {
  
    stmts = instantiate(pc, "RESTORE", new Const(0), new Const(0), Location::regOf(0));
  
  }
  if (tokens.at(0) == "NOP" ) {
    char *name =  new char[tokens.at(0).length() + 1];
    strcpy(name, tokens.at(0).c_str());
    result.type = NOP;
    stmts = instantiate(pc,  name);
  }
  if (tokens.at(0) == "SETHI" ) {
    
    if (if_str(tokens.at(1))){   
      unsigned rd = magic_process(tokens.at(2));
      char *para = process_str(tokens.at(1));
      stmts = instantiate(pc,  "sethi", new Const(para), DIS_RD);
    }
    else
    {
      unsigned imm22 = magic_process(tokens.at(1));
      unsigned rd = magic_process(tokens.at(2));
      stmts = instantiate(pc,  "sethi", dis_Num(imm22), DIS_RD);
    }
    
  }
  if (tokens.at(0) == "LDSB" || tokens.at(0) == "LDSH" || tokens.at(0) == "LDUB" || tokens.at(0) == "LDUH" || tokens.at(0) == "LD" || tokens.at(0) == "LDSTUB" || tokens.at(0) == "SWAP." || tokens.at(0) == "LDD") {
    if (tokens.at(0) == "LD"){
      unsigned rd = magic_process(tokens.at(2));
      char *name =  new char[tokens.at(0).length() + 1];
      Exp* expr = new Binary(opPlus, Location::regOf(magic_process(tokens.at(1).substr(1,3))),new Const(std::atoi((tokens.at(1).substr(4,tokens.at(2).length()-5)).c_str())));
      strcpy(name, tokens.at(0).c_str());
      stmts = instantiate(pc,  name, expr, DIS_RD);
    }
    else {
    unsigned addr = magic_process(tokens.at(1));
    unsigned rd = magic_process(tokens.at(2));
    char *name =  new char[tokens.at(0).length() + 1];
    strcpy(name, tokens.at(0).c_str());
    stmts = instantiate(pc,  name, DIS_ADDR, DIS_RD);
    }
  }
  if (tokens.at(0) == "LDF" ) {
    unsigned addr = magic_process(tokens.at(1));
    unsigned fds = magic_process(tokens.at(2));
    char *name =  new char[tokens.at(0).length() + 1];
    strcpy(name, tokens.at(0).c_str());
    stmts = instantiate(pc,  name, DIS_ADDR, DIS_FDS);
  }
  if (tokens.at(0) == "LDDF" ) {
    unsigned addr = magic_process(tokens.at(1));
    unsigned fdd = magic_process(tokens.at(2));
    char *name =  new char[tokens.at(0).length() + 1];
    strcpy(name, tokens.at(0).c_str());
    stmts = instantiate(pc,  name, DIS_ADDR, DIS_FDD);
  }
  if (tokens.at(0) == "LDSBA" || tokens.at(0) == "LDSHA" || tokens.at(0) == "LDUBA" || tokens.at(0) == "LDUHA" || tokens.at(0) == "LDA" || tokens.at(0) == "LDSTUBA" || tokens.at(0) == "SWAPA" || tokens.at(0) == "LDDA") {
    unsigned addr = magic_process(tokens.at(1));
    unsigned asi = magic_process(tokens.at(2));
    unsigned rd = magic_process(tokens.at(3));
    char *name =  new char[tokens.at(0).length() + 1];
    strcpy(name, tokens.at(0).c_str());
    unused(asi);
    stmts = instantiate(pc,  name, DIS_RD, DIS_ADDR);
  }
  if (tokens.at(0) == "STB" || tokens.at(0) == "STH" || tokens.at(0) == "ST" || tokens.at(0) == "STD") {
    if (tokens.at(0) == "ST"){
      unsigned rd = magic_process(tokens.at(1));
      Exp* expr = new Binary(opPlus, Location::regOf(magic_process(tokens.at(2).substr(1,3))),new Const(std::atoi((tokens.at(2).substr(4,tokens.at(2).length()-5)).c_str())));
    
      char *name =  new char[tokens.at(0).length() + 1];
      strcpy(name, tokens.at(0).c_str());
      stmts = instantiate(pc,  name, DIS_RDR, expr);
    }
    else
    {
    unsigned rd = magic_process(tokens.at(1));
    unsigned addr = magic_process(tokens.at(2));
    char *name =  new char[tokens.at(0).length() + 1];
    strcpy(name, tokens.at(0).c_str());
    stmts = instantiate(pc,  name, DIS_RDR, DIS_ADDR);
    }
  }
  if (tokens.at(0) == "STF" ) {
    unsigned fds = magic_process(tokens.at(1));
    unsigned addr = magic_process(tokens.at(2));
    char *name =  new char[tokens.at(0).length() + 1];
    strcpy(name, tokens.at(0).c_str());
    stmts = instantiate(pc,  name, DIS_FDS, DIS_ADDR);
  }
  if (tokens.at(0) == "STDF" ) {
    unsigned fdd = magic_process(tokens.at(1));
    unsigned addr = magic_process(tokens.at(2));
    char *name =  new char[tokens.at(0).length() + 1];
    strcpy(name, tokens.at(0).c_str());
    stmts = instantiate(pc,  name, DIS_FDD, DIS_ADDR);
  }
  if (tokens.at(0) == "STBA" || tokens.at(0) == "STHA" || tokens.at(0) == "STA" || tokens.at(0) == "STDA") {
    unsigned rd = magic_process(tokens.at(1));
    unsigned addr = magic_process(tokens.at(2));
    unsigned asi = magic_process(tokens.at(3));
    char *name =  new char[tokens.at(0).length() + 1];
    strcpy(name, tokens.at(0).c_str());
    unused(asi);
    stmts = instantiate(pc,  name, DIS_RDR, DIS_ADDR);
  }
  if (tokens.at(0) == "LDFSR" ) {
    unsigned addr = magic_process(tokens.at(1));
    char *name =  new char[tokens.at(0).length() + 1];
    strcpy(name, tokens.at(0).c_str());
    stmts = instantiate(pc,  name, DIS_ADDR);
  }
  if (tokens.at(0) == "LDCSR" ) {
    unsigned addr = magic_process(tokens.at(1));
    char *name =  new char[tokens.at(0).length() + 1];
    strcpy(name, tokens.at(0).c_str());
    stmts = instantiate(pc,  name, DIS_ADDR);
  }
  if (tokens.at(0) == "STFSR" ) {
    unsigned addr = magic_process(tokens.at(1));
    char *name =  new char[tokens.at(0).length() + 1];
    strcpy(name, tokens.at(0).c_str());
    stmts = instantiate(pc,  name, DIS_ADDR);
  }
  if (tokens.at(0) == "STCSR" ) {
    unsigned addr = magic_process(tokens.at(1));
    char *name =  new char[tokens.at(0).length() + 1];
    strcpy(name, tokens.at(0).c_str());
    stmts = instantiate(pc,  name, DIS_ADDR);
  }
  if (tokens.at(0) == "STDFQ" ) {
    unsigned addr = magic_process(tokens.at(1));
    char *name =  new char[tokens.at(0).length() + 1];
    strcpy(name, tokens.at(0).c_str());
    stmts = instantiate(pc,  name, DIS_ADDR);
  }
  if (tokens.at(0) == "STDCQ" ) {
    unsigned addr = magic_process(tokens.at(1));
    char *name =  new char[tokens.at(0).length() + 1];
    strcpy(name, tokens.at(0).c_str());
    stmts = instantiate(pc,  name, DIS_ADDR);
  }
  if (tokens.at(0) == "RDY" ) {
    unsigned rd = magic_process(tokens.at(1));
    char *name =  new char[tokens.at(0).length() + 1];
    strcpy(name, tokens.at(0).c_str());
    stmts = instantiate(pc,  name, DIS_RD);
  }
  if (tokens.at(0) == "RDPSR" ) {
    unsigned rd = magic_process(tokens.at(1));
    char *name =  new char[tokens.at(0).length() + 1];
    strcpy(name, tokens.at(0).c_str());
    stmts = instantiate(pc,  name, DIS_RD);
  }
  if (tokens.at(0) == "RDWIM" ) {
    unsigned rd = magic_process(tokens.at(1));
    char *name =  new char[tokens.at(0).length() + 1];
    strcpy(name, tokens.at(0).c_str());
    stmts = instantiate(pc,  name, DIS_RD);
  }
  if (tokens.at(0) == "RDTBR" ) {
    unsigned rd = magic_process(tokens.at(1));
    char *name =  new char[tokens.at(0).length() + 1];
    strcpy(name, tokens.at(0).c_str());
    stmts = instantiate(pc,  name, DIS_RD);
  }
  if (tokens.at(0) == "WRY" ) {
    unsigned rs1 = magic_process(tokens.at(1));
    unsigned roi = magic_process(tokens.at(2));
    char *name =  new char[tokens.at(0).length() + 1];
    strcpy(name, tokens.at(0).c_str());
    stmts = instantiate(pc,  name, DIS_RS1, DIS_ROI);
  }
  if (tokens.at(0) == "WRPSR" ) {
    unsigned rs1 = magic_process(tokens.at(1));
    unsigned roi = magic_process(tokens.at(2));
    char *name =  new char[tokens.at(0).length() + 1];
    strcpy(name, tokens.at(0).c_str());
    stmts = instantiate(pc,  name, DIS_RS1, DIS_ROI);
  }
  if (tokens.at(0) == "WRWIM" ) {
    unsigned rs1 = magic_process(tokens.at(1));
    unsigned roi = magic_process(tokens.at(2));
    char *name =  new char[tokens.at(0).length() + 1];
    strcpy(name, tokens.at(0).c_str());
    stmts = instantiate(pc,  name, DIS_RS1, DIS_ROI);
  }
  if (tokens.at(0) == "WRTBR" ) {
    unsigned rs1 = magic_process(tokens.at(1));
    unsigned roi = magic_process(tokens.at(2));
    char *name =  new char[tokens.at(0).length() + 1];
    strcpy(name, tokens.at(0).c_str());
    stmts = instantiate(pc,  name, DIS_RS1, DIS_ROI);
  }
  if (tokens.at(0) == "AND" || tokens.at(0) == "MOV" || tokens.at(0) == "ANDcc" || tokens.at(0) == "ANDN" || tokens.at(0) == "ANDNcc" || tokens.at(0) == "OR" || tokens.at(0) == "ORcc" || tokens.at(0) == "ORN" || tokens.at(0) == "ORNcc" || tokens.at(0) == "XOR" || tokens.at(0) == "XORcc" || tokens.at(0) == "XNOR" || tokens.at(0) == "XNORcc" || tokens.at(0) == "SLL" || tokens.at(0) == "SRL" || tokens.at(0) == "SRA" || tokens.at(0) == "ADD" || tokens.at(0) == "ADDcc" || tokens.at(0) == "ADDX" || tokens.at(0) == "ADDXcc" || tokens.at(0) == "TADDcc" || tokens.at(0) == "TADDccTV" || tokens.at(0) == "SUB" || tokens.at(0) == "SUBcc" || tokens.at(0) == "SUBX" || tokens.at(0) == "SUBXcc" || tokens.at(0) == "TSUBcc" || tokens.at(0) == "TSUBccTV" || tokens.at(0) == "MULScc" || tokens.at(0) == "UMUL" || tokens.at(0) == "SMUL" || tokens.at(0) == "UMULcc" || tokens.at(0) == "SMULcc" || tokens.at(0) == "UDIV" || tokens.at(0) == "SDIV" || tokens.at(0) == "UDIVcc" || tokens.at(0) == "SDIVcc") {
    if (tokens.at(0) == "MOV"){
      unsigned roi = magic_process(tokens.at(1));
      unsigned rd = magic_process(tokens.at(2));
      char *name =  new char[tokens.at(0).length() + 1];
      strcpy(name, tokens.at(0).c_str());
      stmts = instantiate(pc,  "OR", new Const(0), DIS_ROI, DIS_RD);
    } 
    else{
      unsigned rs1 = magic_process(tokens.at(1));
      unsigned roi = magic_process(tokens.at(2));
      unsigned rd = magic_process(tokens.at(3));
      char *name =  new char[tokens.at(0).length() + 1];
      strcpy(name, tokens.at(0).c_str());
      stmts = instantiate(pc,  name, DIS_RS1, DIS_ROI, DIS_RD);
    }
  }
  if (tokens.at(0) == "FMOVs" || tokens.at(0) == "FNEGs" || tokens.at(0) == "FABSs" || tokens.at(0) == "FSQRTs") {
    unsigned fs2s = magic_process(tokens.at(1));
    unsigned fds = magic_process(tokens.at(2));
    char *name =  new char[tokens.at(0).length() + 1];
    strcpy(name, tokens.at(0).c_str());
    stmts = instantiate(pc,  name, DIS_FS2S, DIS_FDS);
  }
  if (tokens.at(0) == "FADDs" || tokens.at(0) == "FSUBs" || tokens.at(0) == "FMULs" || tokens.at(0) == "FDIVs") {
    unsigned fs1s = magic_process(tokens.at(1));
    unsigned fs2s = magic_process(tokens.at(2));
    unsigned fds = magic_process(tokens.at(3));
    char *name =  new char[tokens.at(0).length() + 1];
    strcpy(name, tokens.at(0).c_str());
    stmts = instantiate(pc,  name, DIS_FS1S, DIS_FS2S, DIS_FDS);
  }
  if (tokens.at(0) == "FADDd" || tokens.at(0) == "FSUBd" || tokens.at(0) == "FMULd" || tokens.at(0) == "FDIVd") {
    unsigned fs1d = magic_process(tokens.at(1));
    unsigned fs2d = magic_process(tokens.at(2));
    unsigned fdd = magic_process(tokens.at(3));
    char *name =  new char[tokens.at(0).length() + 1];
    strcpy(name, tokens.at(0).c_str());
    stmts = instantiate(pc,  name, DIS_FS1D, DIS_FS2D, DIS_FDD);
  }
  if (tokens.at(0) == "FADDq" || tokens.at(0) == "FSUBq" || tokens.at(0) == "FMULq" || tokens.at(0) == "FDIVq") {
    unsigned fs1q = magic_process(tokens.at(1));
    unsigned fs2q = magic_process(tokens.at(2));
    unsigned fdq = magic_process(tokens.at(3));
    char *name =  new char[tokens.at(0).length() + 1];
    strcpy(name, tokens.at(0).c_str());
    stmts = instantiate(pc,  name, DIS_FS1Q, DIS_FS2Q, DIS_FDQ);
  }
  if (tokens.at(0) == "FCMPs" || tokens.at(0) == "FCMPEs") {
    unsigned fs1s = magic_process(tokens.at(1));
    unsigned fs2s = magic_process(tokens.at(2));
    char *name =  new char[tokens.at(0).length() + 1];
    strcpy(name, tokens.at(0).c_str());
    stmts = instantiate(pc,  name, DIS_FS1S, DIS_FS2S);
  }
  if (tokens.at(0) == "FCMPd" || tokens.at(0) == "FCMPEd") {
    unsigned fs1d = magic_process(tokens.at(1));
    unsigned fs2d = magic_process(tokens.at(2));
    char *name =  new char[tokens.at(0).length() + 1];
    strcpy(name, tokens.at(0).c_str());
    stmts = instantiate(pc,  name, DIS_FS1D, DIS_FS2D);
  }
  if (tokens.at(0) == "FCMPq" || tokens.at(0) == "FCMPEq") {
    unsigned fs1q = magic_process(tokens.at(1));
    unsigned fs2q = magic_process(tokens.at(2));
    char *name =  new char[tokens.at(0).length() + 1];
    strcpy(name, tokens.at(0).c_str());
    stmts = instantiate(pc,  name, DIS_FS1Q, DIS_FS2Q);
  }
  if (tokens.at(0) == "FiTOs" || tokens.at(0) == "FsTOi") {
    unsigned fs2s = magic_process(tokens.at(1));
    unsigned fds = magic_process(tokens.at(2));
    char *name =  new char[tokens.at(0).length() + 1];
    strcpy(name, tokens.at(0).c_str());
    stmts = instantiate(pc, name, DIS_FS2S, DIS_FDS);
  }
  if (tokens.at(0) == "FiTOd" ) {
    unsigned fs2s = magic_process(tokens.at(1));
    unsigned fdd = magic_process(tokens.at(2));
    char *name =  new char[tokens.at(0).length() + 1];
    strcpy(name, tokens.at(0).c_str());
    stmts = instantiate(pc, name, DIS_FS2S, DIS_FDD);
  }
  if (tokens.at(0) == "FdTOi" ) {
    unsigned fs2d = magic_process(tokens.at(1));
    unsigned fds = magic_process(tokens.at(2));
    char *name =  new char[tokens.at(0).length() + 1];
    strcpy(name, tokens.at(0).c_str());
    stmts = instantiate(pc, name, DIS_FS2D, DIS_FDS);
  }
  if (tokens.at(0) == "FiTOq" ) {
    unsigned fs2s = magic_process(tokens.at(1));
    unsigned fdq = magic_process(tokens.at(2));
    char *name =  new char[tokens.at(0).length() + 1];
    strcpy(name, tokens.at(0).c_str());
    stmts = instantiate(pc, name, DIS_FS2S, DIS_FDQ);
  }
  if (tokens.at(0) == "FqTOi" ) {
    unsigned fs2q = magic_process(tokens.at(1));
    unsigned fds = magic_process(tokens.at(2));
    char *name =  new char[tokens.at(0).length() + 1];
    strcpy(name, tokens.at(0).c_str());
    stmts = instantiate(pc, name, DIS_FS2Q, DIS_FDS);
  }
  if (tokens.at(0) == "FsTOd" ) {
    unsigned fs2s = magic_process(tokens.at(1));
    unsigned fdd = magic_process(tokens.at(2));
    char *name =  new char[tokens.at(0).length() + 1];
    strcpy(name, tokens.at(0).c_str());
    stmts = instantiate(pc, name, DIS_FS2S, DIS_FDD);
  }
  if (tokens.at(0) == "FdTOs" ) {
    unsigned fs2d = magic_process(tokens.at(1));
    unsigned fds = magic_process(tokens.at(2));
    char *name =  new char[tokens.at(0).length() + 1];
    strcpy(name, tokens.at(0).c_str());
    stmts = instantiate(pc, name, DIS_FS2D, DIS_FDS);
  }
  if (tokens.at(0) == "FsTOq" ) {
    unsigned fs2s = magic_process(tokens.at(1));
    unsigned fdq = magic_process(tokens.at(2));
    char *name =  new char[tokens.at(0).length() + 1];
    strcpy(name, tokens.at(0).c_str());
    stmts = instantiate(pc, name, DIS_FS2S, DIS_FDQ);
  }
  if (tokens.at(0) == "FqTOs" ) {
    unsigned fs2q = magic_process(tokens.at(1));
    unsigned fds = magic_process(tokens.at(2));
    char *name =  new char[tokens.at(0).length() + 1];
    strcpy(name, tokens.at(0).c_str());
    stmts = instantiate(pc, name, DIS_FS2Q, DIS_FDS);
  }
  if (tokens.at(0) == "FdTOq" ) {
    unsigned fs2d = magic_process(tokens.at(1));
    unsigned fdq = magic_process(tokens.at(2));
    char *name =  new char[tokens.at(0).length() + 1];
    strcpy(name, tokens.at(0).c_str());
    stmts = instantiate(pc, name, DIS_FS2D, DIS_FDQ);
  }
  if (tokens.at(0) == "FqTOd" ) {
    unsigned fs2q = magic_process(tokens.at(1));
    unsigned fdd = magic_process(tokens.at(2));
    char *name =  new char[tokens.at(0).length() + 1];
    strcpy(name, tokens.at(0).c_str());
    stmts = instantiate(pc, name, DIS_FS2Q, DIS_FDD);
  }
  if (tokens.at(0) == "FSQRTd" ) {
    unsigned fs2d = magic_process(tokens.at(1));
    unsigned fdd = magic_process(tokens.at(2));
    char *name =  new char[tokens.at(0).length() + 1];
    strcpy(name, tokens.at(0).c_str());
    stmts = instantiate(pc, name, DIS_FS2D, DIS_FDD);
  }
  if (tokens.at(0) == "FSQRTq" ) {
    unsigned fs2q = magic_process(tokens.at(1));
    unsigned fdq = magic_process(tokens.at(2));
    char *name =  new char[tokens.at(0).length() + 1];
    strcpy(name, tokens.at(0).c_str());
    stmts = instantiate(pc, name, DIS_FS2Q, DIS_FDQ);
  }
  if (tokens.at(0) == "RETURN" ) {
    unsigned addr = magic_process(tokens.at(1));
    char *name =  new char[tokens.at(0).length() + 1];
    strcpy(name, tokens.at(0).c_str());
    stmts = instantiate(pc, name, DIS_ADDR);
    result.rtl = new RTL(pc, stmts);
    result.rtl->appendStmt(new ReturnStatement);
    result.type = DD;
  }
  if (tokens.at(0) == "TN" || tokens.at(0) == "TE" || tokens.at(0) == "TLE" || tokens.at(0) == "TL" || tokens.at(0) == "TLEU" || tokens.at(0) == "TCS" || tokens.at(0) == "TNEG" || tokens.at(0) == "TVS" || tokens.at(0) == "TA" || tokens.at(0) == "TNE" || tokens.at(0) == "TG" || tokens.at(0) == "TGE" || tokens.at(0) == "TGU" || tokens.at(0) == "TCC" || tokens.at(0) == "TPOS" || tokens.at(0) == "TVC") {
    unsigned addr = magic_process(tokens.at(1));
    char *name =  new char[tokens.at(0).length() + 1];
    strcpy(name, tokens.at(0).c_str());
    stmts = instantiate(pc,  name, DIS_ADDR);
  }
  if (tokens.at(0) == "UNIMP" ) {
    unsigned n = magic_process(tokens.at(1));
    unused(n);
    stmts = NULL;
    result.valid = false;
  }
  result.numBytes = nextPC - hostPC;
  if(result.valid && result.rtl == 0)
    result.rtl = new RTL(pc, stmts);
  return result;
}
/***********************************************************************
 * These are functions used to decode instruction operands into
 * expressions (Exp*s).
 **********************************************************************/

/*==============================================================================
 * FUNCTION:    SparcDecoder::dis_RegLhs
 * OVERVIEW:    Decode the register on the LHS
 * PARAMETERS:    r - register (0-31)
 * RETURNS:     the expression representing the register
 *============================================================================*/
Exp* SparcDecoder::dis_RegLhs(unsigned r)
{
  return Location::regOf(r);
}
/*==============================================================================
 * FUNCTION:    SparcDecoder::dis_RegRhs
 * OVERVIEW:    Decode the register on the RHS
 * NOTE:      Replaces r[0] with const 0
 * NOTE:      Not used by DIS_RD since don't want 0 on LHS
 * PARAMETERS:    r - register (0-31)
 * RETURNS:     the expression representing the register
 *============================================================================*/
Exp* SparcDecoder::dis_RegRhs(unsigned r)
{
  if(r == 0)
  return new Const(0);
  return Location::regOf(r);
}
/*==============================================================================
 * FUNCTION:    SparcDecoder::dis_RegImm
 * OVERVIEW:    Decode the register or immediate at the given address.
 * NOTE:      Used via macro DIS_ROI
 * PARAMETERS:    pc - an address in the instruction stream
 * RETURNS:     the register or immediate at the given address
 *============================================================================*/
Exp* SparcDecoder::dis_RegImm(unsigned pc)
{
  if(pc >=100)
  { 
    int i = 0;
    if (pc < 4196)
      i = pc-100;
    if(pc >= (4294967296 - 4096))
      i = pc - 4294967296;
    Exp* expr = new Const(i);
    return expr;
  }
  else return dis_RegRhs(pc);
}
/*==============================================================================
 * FUNCTION:    SparcDecoder::dis_Eaddr
 * OVERVIEW:    Converts a dynamic address to a Exp* expression.
 *          E.g. %o7 --> r[ 15 ]
 * PARAMETERS:    pc - the instruction stream address of the dynamic address
 *          ignore - redundant parameter on SPARC
 * RETURNS:     the Exp* representation of the given address
 *============================================================================*/
Exp* SparcDecoder::dis_Eaddr(ADDRESS pc,int ignore)
{
  Exp* expr = NULL;
  return expr;
}
/*==============================================================================
 * FUNCTION:    isFuncPrologue()
 * OVERVIEW:    Check to see if the instructions at the given offset match any callee prologue, i.e. does it look
 *          like this offset is a pointer to a function?
 * PARAMETERS:    hostPC - pointer to the code in question (host address)
 * RETURNS:     True if a match found
 *============================================================================*/
bool SparcDecoder::isFuncPrologue(ADDRESS hostPC)
{
  return false;
}
/*==============================================================================
 * FUNCTION:    isRestore()
 * OVERVIEW:    Check to see if the instruction at the given offset is a restore instruction
 * PARAMETERS:    hostPC - pointer to the code in question (host address)
 * RETURNS:     True if a match found
 *============================================================================*/
bool SparcDecoder::isRestore(ADDRESS hostPC)
{
  return false;
}
/**********************************
 * These are the fetch routines.
 **********************************/

/*==============================================================================
 * FUNCTION:    getDword
 * OVERVIEW:    Returns the double starting at the given address.
 * PARAMETERS:    lc - address at which to decode the double
 * RETURNS:     the decoded double
 *============================================================================*/
DWord SparcDecoder::getDword(ADDRESS lc)
{
  Byte* p = (Byte*)lc;
  return (p[0] << 24) + (p[1] << 16) + (p[2] << 8) + p[3];
}
/*==============================================================================
 * FUNCTION:     SparcDecoder::SparcDecoder
 * OVERVIEW:     
 * PARAMETERS:     None
 * RETURNS:      N/A
 *============================================================================*/
SparcDecoder::SparcDecoder(Prog* prog): NJMCDecoder(prog)
{
  std::string file = Boomerang::get()->getProgPath() + "frontend/machine/sparc/sparc.ssl";
  RTLDict.readSSLFile(file.c_str());
}
int SparcDecoder::decodeAssemblyInstruction(unsigned,int)
{
  return 0;
}
DecodeResult&  SparcDecoder::decodeInstruction (ADDRESS pc, int delta){
  return result;
}