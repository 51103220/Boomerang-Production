#define sign_extend(N,SIZE) (((int)((N) << (sizeof(unsigned)*8-(SIZE)))) >> (sizeof(unsigned)*8-(SIZE)))
#include <assert.h>

#line 1 "machine/sparc/decoder.m"
/*
 * Copyright (C) 1996-2001, The University of Queensland
 *
 * See the file "LICENSE.TERMS" for information on usage and
 * redistribution of this file, and for a DISCLAIMER OF ALL
 * WARRANTIES.
 *
 */

/*==============================================================================
 * FILE:	   decoder.m
 * OVERVIEW:   Implementation of the SPARC specific parts of the
 *			   SparcDecoder class.
 *============================================================================*/

/* $Revision: 1.24 $	// 1.20.2.2
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
#include "exp.h"
#include "prog.h"
#include "proc.h"
#include "sparcdecoder.h"
#include "rtl.h"
#include "BinaryFile.h"		// For SymbolByAddress()
#include "boomerang.h"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iterator>
#include <vector>
#include <sstream>
 //#include <boost/lexical_cast.hpp>
#include <string>

#define DIS_ROI		(dis_RegImm(roi))
#define DIS_ADDR	(dis_Eaddr(addr))
#define DIS_RD		(dis_RegLhs(rd))
#define DIS_RDR		(dis_RegRhs(rd))
#define DIS_RS1		(dis_RegRhs(rs1))
#define DIS_FS1S	(dis_RegRhs(fs1s+32))
#define DIS_FS2S	(dis_RegRhs(fs2s+32))
// Note: Sparc V9 has a second set of double precision registers that have an
// odd index. So far we only support V8
#define DIS_FDS		(dis_RegLhs(fds+32))
#define DIS_FS1D	(dis_RegRhs((fs1d>>1)+64))
#define DIS_FS2D	(dis_RegRhs((fs2d>>1)+64))
#define DIS_FDD		(dis_RegLhs((fdd>>1)+64))
#define DIS_FDQ		(dis_RegLhs((fdq>>2)+80))
#define DIS_FS1Q	(dis_RegRhs((fs1q>>2)+80))
#define DIS_FS2Q	(dis_RegRhs((fs2q>>2)+80))


/////////////////////////////////// MY CODE HERE ///////////////////////////////////////////////////////////
Exp* SparcDecoder::dis_Register(std::string str){
  if(str=="%SP") return Location::regOf(14);
  if(str=="%FP") return Location::regOf(30);
  if(str=="%G0") return Location::regOf(0);
  if(str=="%G1") return Location::regOf(1);
  if(str=="%G2") return Location::regOf(2);
  if(str=="%G3") return Location::regOf(3);
  if(str=="%G4") return Location::regOf(4);
  if(str=="%G5") return Location::regOf(5);
  if(str=="%G6") return Location::regOf(6);
  if(str=="%G7") return Location::regOf(7);

  if(str=="%O0") return Location::regOf(8);
  if(str=="%O1") return Location::regOf(9);
  if(str=="%O2") return Location::regOf(10);
  if(str=="%O3") return Location::regOf(11);
  if(str=="%O4") return Location::regOf(12);
  if(str=="%O5") return Location::regOf(13);
  if(str=="%O6") return Location::regOf(14);
  if(str=="%O7") return Location::regOf(15);
  if(str=="%L0") return Location::regOf(16);
  if(str=="%L1") return Location::regOf(17);
  if(str=="%L2") return Location::regOf(18);
  if(str=="%L3") return Location::regOf(19);
  if(str=="%L4") return Location::regOf(20);
  if(str=="%L5") return Location::regOf(21);
  if(str=="%L6") return Location::regOf(22);
  if(str=="%L7") return Location::regOf(23);
  if(str=="%I0") return Location::regOf(24);
  if(str=="%I1") return Location::regOf(25);
  if(str=="%I2") return Location::regOf(26);
  if(str=="%I3") return Location::regOf(27);
  if(str=="%I4") return Location::regOf(28);
  if(str=="%I5") return Location::regOf(29);
  if(str=="%I6") return Location::regOf(30);
  if(str=="%I7") return Location::regOf(31);
  return NULL;
}
Exp* SparcDecoder::dis_Number(int i){
  Exp* expr = new Const(i);

    return expr;

}

/////////////////////////////////// END MY CODE HERE ///////////////////////////////////////////////////////////



/////////////////////////////////// MY CODE HERE ///////////////////////////////////////////////////////////
DecodeResult& SparcDecoder::decodeAssembly (ADDRESS pc, std::string line)
{
  using namespace std;
  static DecodeResult result;
  //print "for "
  result.reset();
  std::list<Statement*>* stmts = NULL;
  std::string sentence = line;
  std::transform(sentence.begin(), sentence.end(),sentence.begin(), ::toupper);
    sentence.erase(std::remove(sentence.begin(), sentence.end(), ','), sentence.end());
    std::istringstream iss(sentence);
    vector<std::string> tokens;
    copy(istream_iterator<std::string>(iss),
         istream_iterator<std::string>(),
       back_inserter(tokens));


  if(tokens.at(0) == "SAVE"){
      Exp* op1 = dis_Register(tokens.at(1));
      Exp* op3 =  dis_Register(tokens.at(3));
      Exp* op2 =  dis_Number(std::atoi((tokens.at(2)).c_str()));
      
     stmts = instantiate(pc, "SAVE", op1, op2, op3);
      
              
    }
    else if(tokens.at(0)=="ST"){
      //std::cout<<tokens.at(1)<<"\n"<<tokens.at(2).substr(1,3)<<"\n"<<tokens.at(2).substr(4,tokens.at(2).length()-5)<<"\n";
      Exp* op1 = dis_Register(tokens.at(1));
     Exp* expr = new Binary(opPlus,dis_Register(tokens.at(2).substr(1,3)),new Const(std::atoi((tokens.at(2).substr(4,tokens.at(2).length()-5)).c_str())));
  
      stmts = instantiate(pc, "ST", op1, expr);
    }
    else if(tokens.at(0)=="NOP")
      {
        result.type = NOP;
          stmts = instantiate(pc, "NOP");
  }
    else if(tokens.at(0)=="LD"){
    //  std::cout<<tokens.at(2)<<"\n"<<tokens.at(1).substr(1,3)<<"\n"<<tokens.at(1).substr(4,tokens.at(1).length()-5)<<"\n";
      Exp* expr = new Binary(opPlus,dis_Register(tokens.at(1).substr(1,3)),new Const(std::atoi((tokens.at(1).substr(4,tokens.at(2).length()-5)).c_str())));
      Exp* op2 = dis_Register(tokens.at(2));
      
      stmts = instantiate(pc, "LD", expr,op2);
     
    }
        else if(tokens.at(0)=="RESTORE"){
          std::cout<<"restore h1ere\n";
    //  std::cout<<tokens.at(2)<<"\n"<<tokens.at(1).substr(1,3)<<"\n"<<tokens.at(1).substr(4,tokens.at(1).length()-5)<<"\n";
     // Exp* expr = new Binary(opPlus,dis_Register(tokens.at(1).substr(1,3)),new Const(std::atoi((tokens.at(1).substr(4,tokens.at(2).length()-5)).c_str())));
     // Exp* op2 = dis_Register(tokens.at(2));
      
      stmts = instantiate(pc, "RESTORE", new Const(0), new Const(0), Location::regOf(0));

    }
    else if (tokens.at(0)=="ADD")
    {
      Exp* op1 = dis_Register(tokens.at(1));
      Exp* op3 =  dis_Register(tokens.at(3));
      Exp* op2 =  dis_Number(std::atoi((tokens.at(2)).c_str()));
      stmts = instantiate(pc, "ADD", op1, op2, op3);
    }
    else if (tokens.at(0)=="OR")
    {
      Exp* op2 = dis_Register(tokens.at(2));
      Exp* op3 =  dis_Register(tokens.at(3));
      Exp* op1 =  dis_Number(std::atoi((tokens.at(1)).c_str()));
      stmts = instantiate(pc, "OR", op1, op2, op3);
    }
    else if (tokens.at(0)=="MOV")

    {
      Exp* op2=NULL;
     // std::cout<<(tokens.at(1)).substr(1,1);
      if((tokens.at(1)).substr(1,1)=="G")
          op2 = dis_Register(tokens.at(1));
      else
       op2 =  dis_Number(std::atoi((tokens.at(1)).c_str()));
      Exp* op3 =  dis_Register(tokens.at(2));
      Exp* op1 =  dis_Number(0);
      stmts = instantiate(pc, "OR", op1, op2, op3);
     }
     else if(tokens.at(0) == "JMP"){
       /*Exp* op1 = dis_Register(tokens.at(1));
      Exp* op2 =  dis_Number(8);

      stmts = instantiate(pc, "JMPL",op1, op2);*/
     
      result.rtl = new RTL(pc, stmts);

      result.rtl->appendStmt(new ReturnStatement);

      result.type = DD;
      SHOW_ASM("retl_");

     }


    //result.numBytes = nextPC - hostPC;
      if (result.valid && result.rtl == 0)  // Don't override higher level res
      result.rtl = new RTL(pc, stmts);
 
  return result;
}
std::string SparcDecoder::stripstr(std::string str){
  bool rem;
  while(true) {
    rem = false;
    if(str[0]==' ' )
      {str = str.substr(1, str.length()-1);
        rem = true;}
    if(str[str.length()-1]==' ')
    {
      str = str.substr(0, str.length()-1);
      rem =true;
    }
     if(str[0]==',')
      {str = str.substr(1, str.length()-1);
        rem = true;}
    if(str[str.length()-1]==',')
    {
      str = str.substr(0, str.length()-1);
      rem =true;
    }
    if(!rem) break;
    
    }

  return str;
}
/////////////////////////////////// END MY CODE HERE ///////////////////////////////////////////////////////////
