#include <algorithm>
#include <iostream>
#include <sstream>
#include <iterator>
#include <vector>
#include <sstream>
#include <string>
#include <assert.h>
#include <cstring>
using namespace std;

inline bool isInteger(const std::string & s) {
    if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false ;
    char * p ;
    strtol(s.c_str(), &p, 10) ;
    return (*p == 0) ;
}

/*
    Intel 8051 decoder
    Created in 09/11/2015 at HCMUT by Dedo

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
#include "_8051decoder.h"
#include "rtl.h"
#include "BinaryFile.h"     
#include "boomerang.h"

unsigned _8051Decoder::magic_process(std::string name) {

    if (name == "R0") return 0;
    else if (name == "R1") return 1;
    else if (name == "R2") return 2;
    else if (name == "R3") return 3;
    else if (name == "R4") return 4;
    else if (name == "R5") return 5;
    else if (name == "R6") return 6;
    else if (name == "R7") return 7;
    else if (name == "A") return 8;
    else if (name == "B") return 9;
    else if (name == "C") return 10;
    else if (name == "DPTR") return 11;
    else if (name == "AB") return 12;
    else if (name == "P0") return 13;
    else if (name == "P1") return 14;
    else if (name == "P2") return 15;
    else if (name == "P3") return 16;
    else if (name == "SP") return 88;
    else if (name == "DPL") return 17;
    else if (name == "DPH") return 18;
    else if (name == "PCON") return 19;
    else if (name == "TCON") return 20;
    else if (name == "TMOD") return 21;
    else if (name == "TL0") return 22;
    else if (name == "TL1") return 23;
    else if (name == "TH0") return 24;
    else if (name == "TH1") return 25;
    else if (name == "SCON") return 26;
    else if (name == "SBUF") return 27;
    else if (name == "IE") return 28;
    else if (name == "IP") return 29;
    else if (name == "PSW") return 30;
    else 
        return 999;
}

unsigned map_sfr(std::string name){
    if (name == "R0") return 0;
    else if (name == "R1") return 1;
    else if (name == "R2") return 2;
    else if (name == "R3") return 3;
    else if (name == "R4") return 4;
    else if (name == "R5") return 5;
    else if (name == "R6") return 6;
    else if (name == "R7") return 7;
    else if (name == "A") return 8;
    else if (name == "B") return 9;
    else if (name == "C") return 10;
    else if (name == "DPTR") return 11;
    else if (name == "AB") return 12;
    else if (name == "P0") return 13;
    else if (name == "P1") return 14;
    else if (name == "P2") return 15;
    else if (name == "P3") return 16;
    else if (name == "SP") return 88;
    else if (name == "DPL") return 17;
    else if (name == "DPH") return 18;
    else if (name == "PCON") return 19;
    else if (name == "TCON") return 20;
    else if (name == "TMOD") return 21;
    else if (name == "TL0") return 22;
    else if (name == "TL1") return 23;
    else if (name == "TH0") return 24;
    else if (name == "TH1") return 25;
    else if (name == "SCON") return 26;
    else if (name == "SBUF") return 27;
    else if (name == "IE") return 28;
    else if (name == "IP") return 29;
    else if (name == "PSW") return 30;
    else 
        return 999;
}
static DecodeResult result;


/*==============================================================================
 * FUNCTION:       _8051Decoder::decodeInstruction
 * OVERVIEW:       Attempt to decode the high level instruction at a given address and return the corresponding HL type
 *                  (e.g. CallStatement, GotoStatement etc). If no high level instruction exists at the given address,
 *                  then simply return the RTL for the low level instruction at this address. There is an option to also
 *                 include the low level statements for a HL instruction.
 * PARAMETERS:     pc - the native address of the pc
 *                 delta - the difference between the above address and the host address of the pc (i.e. the address
 *                  that the pc is at in the loaded object file)
 *                 proc - the enclosing procedure. This can be NULL for those of us who are using this method in an
 *                  interpreter
 * RETURNS:        a DecodeResult structure containing all the information gathered during decoding
 *============================================================================*/
DecodeResult&  _8051Decoder::decodeInstruction (ADDRESS pc, int delta){
  return result;
}
bool if_a_byte(char * reg){
    std::list<char*>::iterator br;
    std::cout << reg;
    for(br = bitReg.begin(); br != bitReg.end(); ++ br ){
        if(strcmp(reg,(*br)) == 0)
            return true;
    }  
    return false;
}
list<Statement*>* initial_bit_regs(){
    std::list<Statement*>* stmts = new list<Statement*>();

    // Build a Union

    CompoundType* ct = new CompoundType();
      
    ct->addType(new SizeType(8), "bit1:1");
    ct->addType(new SizeType(8), "bit2:1");
    ct->addType(new SizeType(8), "bit3:1");
    ct->addType(new SizeType(8), "bit4:1");
    ct->addType(new SizeType(8), "bit5:1");
    ct->addType(new SizeType(8), "bit6:1");
    ct->addType(new SizeType(8), "bit7:1");
    ct->addType(new SizeType(8), "bit8:1");
    UnionType * ut = new UnionType();
    ut->addType(new SizeType(8), "x");
    ut->addType(ct,"m");

    // A Register will represent a Union variable, i choose Reg31

    
    // Now check in bitReg to match all Register that represents a byte
    std::list<char*>::iterator br;
    for(br = bitReg.begin(); br != bitReg.end(); ++ br ){
        unsigned num = map_sfr(std::string(*br));
        ImpRefStatement * i_s = new ImpRefStatement((Type*) ut, Location::regOf(num));
        stmts->push_back(i_s);
        Assign * a_ss = new Assign((Type *) ut,(Exp *) Location::regOf(30),(Exp *) new TypedExp((Type*) ut, (Exp*) Location::regOf(num)), NULL);
        std::cout << "REPRESENT A BYTE " << a_ss->prints() << std::endl;
        stmts->push_back(a_ss);
    }
    
    return stmts;
}

extern bool first_line;

Exp* byte_present(char * reg){
    Exp* exp = NULL;
    unsigned num = map_sfr(reg);
    exp = new Binary(opMemberAccess,Location::regOf(num), new Const("x"));
    return exp;
}
Exp* access_bit(char * reg, unsigned pos){
    Exp* exp = NULL;
    unsigned num = map_sfr(reg);

    std::stringstream sstm;
    sstm << "bit" << pos;
    std::string name = sstm.str();
    char *bit =  new char[name.length() + 1];
    strcpy(bit, name.c_str());
 
    Exp * exp1 = Location::regOf(num);
    Exp * exp2 = new Binary(opMemberAccess,exp1, new Const("m"));
    exp = new Binary(opMemberAccess,exp2, new Const(bit));
    
   
    //exp = new Ternary(opAt, Location::regOf(num), new Const(pos), new Const(pos));
    return exp;
}
Exp* binary_expr(AssemblyExpression* expr){
    Exp* exp;
    Exp* exp1;
    Exp* exp2;
    list<AssemblyArgument*>::iterator ai;
    bool imm = false;
    bool lhs = true;
    OPER op;
    unsigned op1;
    for (ai = expr->argList.begin(); ai != expr->argList.end(); ++ ai){
        switch((*ai)->kind){
            case 7 : //OPERATOR
            {  
                if (strcmp((*ai)->value.c,"+") == 0 )
                    op = opPlus;
                if (strcmp((*ai)->value.c,"-") == 0 )
                    op = opMinus;
                if (strcmp((*ai)->value.c,"*") == 0 )
                    op = opMult;
                if (strcmp((*ai)->value.c,"/") == 0 )
                    op = opDiv;
                break;
            }
            case 6: // ID , handle as memOf
            {   
                op1 = map_sfr(std::string((*ai)->value.c));
                if(lhs){
                    
                    if (op1 <= 8)
                        exp1 = Location::regOf(op1);
                    else 
                        exp1 = Location::memOf(Location::regOf(op1));
                    lhs = false;
                }
                else{
                    if (op1 <= 8)
                        exp2 = Location::regOf(op1);
                    else 
                        exp2 = Location::memOf(Location::regOf(op1));
                  
                }
                break;
            }
            case 5: // IMMEDIATE ID , handle as regOf
            {   imm = true;
                op1 = map_sfr(std::string((*ai)->value.c));
                if(lhs){
                    if (op1 <= 8)
                        exp1 = Location::regOf(op1);
                    else 
                        exp1 = Location::memOf(Location::regOf(op1));
                    lhs = false;
                }
                else{
                    if (op1 <= 8)
                        exp2 = Location::regOf(op1);
                    else 
                        exp2 = Location::memOf(Location::regOf(op1));
                }
                break;
            }
            case 1:
            {
                if(lhs){
                    exp1 = new Const((*ai)->value.i);
                    lhs = false;
                }
                else{
                    
                    exp2 = new Const((*ai)->value.i);
                }
                
                break;
            }
            case 4: //IMMEDIATE INT
            {   
                imm = true;
                if(lhs){
                    exp1 = new Const((*ai)->value.i);
                    lhs = false;
                }
                else{
                    
                    exp2 = new Const((*ai)->value.i);
                }
                
                break;
            }
            default:
                break;
        }

    }
    PointerType *t = new PointerType(new SizeType(8));
    if (imm)
        exp = new Binary(op, exp1, exp2);
    else
        exp = Location::memOf(new TypedExp((Type*) t,new Binary(op, exp1, exp2)));
    return exp;
}

DecodeResult& _8051Decoder::decodeAssembly(ADDRESS pc,std::string line, AssemblyLine* Line)
{
    static DecodeResult result;
    int delta = 0;
    ADDRESS hostPC = pc+delta;

    result.reset();
    std::list<Statement*>* stmts = NULL;
    // For Direct Int
    PointerType *direct_type = new PointerType(new SizeType(8));
    //-------USELESS-----------
    ADDRESS nextPC = NO_ADDRESS;
    //ADDRESS nextPC = NO_ADDRESS;
    dword MATCH_p = hostPC;
    //-------------------------
    std::string opcode(Line->name);
    list<AssemblyExpression*>::iterator ei;
    if (opcode == "MOV" || opcode == "MOVC" || opcode == "MOVX") {
        Exp* exp1;
        Exp* exp2;
        //-----EXPRESSION1, ALWAYS AN ID----------------------------
        ei = Line->expList->begin();
        AssemblyArgument* arg1 = (*ei)->argList.front();
        if(arg1->kind != 1){
            exp1 = Location::regOf(map_sfr(std::string(arg1->value.c)));
            if (if_a_byte(arg1->value.c)){
                exp1 = byte_present(arg1->value.c);
            }
        }
        //-----EXPRESSION2, FIRST TEST THE BINARY
        ++ei;
        
        AssemblyArgument* arg2 = (*ei)->argList.front();
        //---------------------------------------------------------
        unsigned op1;
        unsigned op2;
        if(opcode == "MOV"){
            switch (arg1->kind){
                case 3: /* MOV INDIRECT */
                {   
                    op1 = magic_process(std::string(arg1->value.c));
                    switch (op1){
                        case 0: /* @R0 */
                        {   
                            if((*ei)->kind == 2){
                                exp2 = binary_expr((*ei));
                                stmts = instantiate(pc, "MOV_RI0_EXP", exp2);
                            } 
                            else {
                                switch (arg2->kind){
                                    case 6: /* @R0, ID */
                                    {   op2 = magic_process(arg2->value.c);
                                        exp2 = Location::regOf(op2);
                                        if(if_a_byte(arg2->value.c))
                                            exp2 = byte_present(arg2->value.c);
                                        
                                        if((op2 >= 9 &&  op2 <= 10) ||  op2 >= 12){/* DIRECT ID */
                                            Ternary* e2 = new Ternary(opZfill, new Const(16), new Const(31), Location::regOf(0));
                                            exp1 = Location::memOf(e2);
                                            stmts = instantiate(pc, "MOV_RI0_DIR",exp1, Location::memOf(exp2));
                                        }
                                        else if(op2 == 8) /* A */
                                            stmts = instantiate(pc, "MOV_RI0_A", exp2);
                                        break;
                                    }
                                    case 4: /* @R0, IMMEDIATE INT */
                                    {    stmts = instantiate(pc, "MOV_RI0_IMM" , new Const(arg2->value.i));
                                        break;
                                    }
                                    case 1: /* @R0, DIRECT INT */
                                    {   
                                        
                                        Ternary* e2 = new Ternary(opZfill, new Const(16), new Const(31), Location::regOf(0));
                                        exp1 = Location::memOf(e2);  
                                        stmts = instantiate(pc, "MOV_RI0_DIR", exp1, Location::memOf(new TypedExp((Type *) direct_type, new Const(arg2->value.i))));
                                        break;
                                    }
                                    default:break; 
                                }
                            }
                            break;
                        }
                        case 1: /* @R1 */
                        {   
                            if((*ei)->kind == 2){
                                exp2 = binary_expr((*ei));
                                stmts = instantiate(pc, "MOV_RI1_EXP", exp2);
                            } 
                            else { 
                                switch (arg2->kind){
                                    case 6: /* ID */
                                    {
                                        op2 = magic_process(arg2->value.c);
                                        exp2 = Location::regOf(op2);
                                        if(if_a_byte(arg2->value.c))
                                            exp2 = byte_present(arg2->value.c);

                                        if((op2 >= 9 &&  op2 <= 10) ||  op2 >= 12){/* DIRECT ID */
                                            Ternary* e2 = new Ternary(opZfill, new Const(16), new Const(31), Location::regOf(1));
                                            exp1 = Location::memOf(e2);                                        
                                            stmts = instantiate(pc, "MOV_RI1_DIR",exp1,Location::memOf(exp2));
                                        }
                                        else if(op2 == 8) /* A */
                                            stmts = instantiate(pc, "MOV_RI1_A",exp2);
                                        break;
                                    }
                                    case 4: /* IMMEDIATE INT */
                                    {    stmts = instantiate(pc, "MOV_RI1_IMM" , new Const(arg2->value.i));
                                        break;
                                    }
                                    case 1: /* DIRECT INT */
                                    {   
                                        Ternary* e2 = new Ternary(opZfill, new Const(16), new Const(31), Location::regOf(1));
                                        exp1 = Location::memOf(e2);  
                                        stmts = instantiate(pc, "MOV_RI1_DIR", exp1, Location::memOf(new TypedExp((Type *) direct_type, new Const(arg2->value.i))));
                                        break;
                                    }
                                    default:
                                        break; 
                                }
                            }
                            break;
                        }
                        case 11: /* @DPTR */
                            break;
                        default:
                            break;
                    }

                    break;
                }
                case 6: /* MOV Rn | A | DPTR | DIRECT */
                {       
                        op1 = magic_process(std::string(arg1->value.c));
                        if (op1 < 8){ /* MOV Rn */
                            if((*ei)->kind == 2){
                                exp2 = binary_expr((*ei));
                            }
                            else {
                                switch(arg2->kind){
                                    case 6: 
                                    { /* Rn, ID */
                                        op2 = magic_process(std::string(arg2->value.c));
                                        Exp* temp = Location::regOf(op2);
                                        if(if_a_byte(arg2->value.c))
                                            temp = byte_present(arg2->value.c);
                                        if ((op2 >= 9 && op2 <= 10) || op2 >= 12){ /* RN, DIRECT */

                                            exp2 = Location::memOf(temp);
                                        }
                                        else if (op2 == 8 ){ /* RN, A */
                                            exp2 = temp;
                                        }
                                        break;
                                    }
                                    case 4: /* RN, IMM */
                                    {   exp2  =  new Const(arg2->value.i);  
                                        break;
                                    }
                                    case 1: /* Rn, Direct int */
                                    {
                                        exp2  =  Location::memOf(new TypedExp((Type *) direct_type, new Const(arg2->value.i))); 
                                        break;
                                    }
                                    default:
                                        break;
                                }
                            }
                            stmts = instantiate(pc, "MOV_EXP", exp1, exp2);
                        }
                        else if (op1 == 8){ /* MOV A */
                            if ((*ei)->kind == 2){
                                exp2 = binary_expr((*ei));
                                stmts = instantiate(pc, "MOV_EXP", exp1, exp2);
                            }
                            else{
                                switch(arg2->kind){
                                    case 3: /* A, INDIRECT */
                                    {   
                                        op2 = magic_process(std::string(arg2->value.c));
                                        Ternary* e2 = new Ternary(opZfill, new Const(16), new Const(31), Location::regOf(op2));
                                        exp2 = Location::memOf(new TypedExp((Type *) direct_type, e2));
                                        if (op2 == 0)
                                            stmts = instantiate(pc, "MOV_A_RI0", exp1, exp2);
                                        else if (op2 == 1)
                                            stmts = instantiate(pc, "MOV_A_RI1", exp1, exp2);
                                        break;
                                    }
                                    case 6: /* A, Rn | DIRECT ID */
                                    {
                                        op2 = magic_process(std::string(arg2->value.c));
                                        if(op2 < 8){ /* A, Rn*/
                                            exp2 = Location::regOf(op2);
                                            if (if_a_byte(arg2->value.c))
                                                exp2 = byte_present(arg2->value.c);
                                        }
                                        else if ((op2 >= 9 && op2 <= 10) || op2 >= 12){ /* A, DIRECT */
                                            Exp * temp = Location::regOf(op2);
                                            if (if_a_byte(arg2->value.c))
                                                temp = byte_present(arg2->value.c);
                                            exp2 = Location::memOf(temp);
                                        }
                                        stmts = instantiate(pc, "MOV_EXP", exp1, exp2);
                                        break;
                                    }
                                    case 4: /* A, IMM */
                                    {   exp2 = new  Const(arg2->value.i);
                                        stmts = instantiate(pc, "MOV_EXP", exp1, exp2);
                                        break;
                                    }
                                    case 1: /* A, DIRECT INT  */
                                    {   exp2 = Location::memOf(new TypedExp((Type *) direct_type, new Const(arg2->value.i)));
                                        stmts = instantiate(pc, "MOV_EXP", exp1, exp2);
                                        break;
                                    }
                                    default:
                                        break;
                                }
                            }

                        }
                        else if (op1 == 11 ){ /* MOV DPTR */
                            if ((*ei)->kind == 2){
                                exp2 = binary_expr((*ei));
                                stmts = instantiate(pc,"MOV_DPTR_ADDR16", exp1, exp2); 
                            }
                            else
                                stmts = instantiate(pc,"MOV_DPTR_ADDR16", exp1, new Const(arg2->value.i)); 
                        }
                        else if ((op1 >= 9 && op1 <= 10) || op1 >= 12){ /* MOV DIRECT */
                            Exp * new_exp1 = Location::memOf(exp1);
                            if((*ei)->kind == 2){
                                exp2 = binary_expr((*ei));
                                stmts = instantiate(pc, "MOV_EXP", new_exp1, exp2);
                            }
                            else {
                                switch(arg2->kind){
                                    case 3: /* DIRECT, INDIRECT*/
                                    {   
                                        op2 = magic_process(std::string(arg2->value.c));
                                        Ternary* e2 = new Ternary(opZfill, new Const(16), new Const(31), Location::regOf(op2));
                                        exp2 = Location::memOf(new TypedExp((Type *) direct_type, e2));
                                        if (op2 == 0)
                                            stmts = instantiate(pc, "MOV_DIR_RI0", new_exp1, exp2); 
                                        else if(op2 == 1)
                                            stmts = instantiate(pc, "MOV_DIR_RI1", new_exp1, exp2); 
                                        break;
                                    }
                                    case 6: /* DIRECT, Rn | DIRECT ID*/
                                    {   
                                        op2 = magic_process(std::string(arg2->value.c));
                                        if (op2 <= 8 ){ /* DIRECT, Rn | A */
                                            exp2 = Location::regOf(op2);
                                            if(if_a_byte(arg2->value.c))
                                                exp2 = byte_present(arg2->value.c);
                                        }
                                        else if ((op2 >= 9 && op2 <= 10) || op2 >= 12){ /* DIRECT, DIRECT */
                                            Exp* temp = Location::regOf(op2);
                                            if(if_a_byte(arg2->value.c))
                                                temp = byte_present(arg2->value.c);
                                            exp2 = Location::memOf(temp);
                                        }
                                        stmts = instantiate(pc, "MOV_EXP", new_exp1, exp2);
                                        break;
                                    }
                                    case 1: /* DIRECT, DIRECT INT */
                                    {   
                                        exp2 = Location::memOf(new TypedExp((Type *) direct_type, new Const(arg2->value.i)));
                                        stmts = instantiate(pc, "MOV_EXP", new_exp1, exp2);
                                        break;
                                    }
                                    case 4: /* DIRECT, IMM */
                                    {   
                                        exp2 = new Const(arg2->value.i);
                                        stmts = instantiate(pc, "MOV_EXP", new_exp1, exp2);
                                        break;
                                    }
                                    default:
                                        break;   
                                }
                            }
                        }   
                    break;
                }
                case 1: /* DIRECT INT*/
                {   
                    Exp * new_exp1 = Location::memOf(new Const(arg1->value.i));
                    exp2 = Location::memOf(Location::regOf(map_sfr(std::string(arg2->value.c))));
                    stmts = instantiate(pc, "MOV_EXP", new_exp1, exp2);
                    break;
                }
                default:
                    break;
            }
        }
        /*else if(tokens.at(0) == "MOVC"){
            if(tokens.at(4) == "DPTR")
            {
                stmts = instantiate(pc, "MOVC_A_AADDDPTR");
            }
            else
            if(tokens.at(4) == "PC")
            {
                stmts = instantiate(pc, "MOVC_A_AADDPC");
            }
        }*/
        else if(opcode == "MOVX"){
            switch(arg1->kind){
                case 3: /* MOVX INDIRECT, A*/
                {   op1 = magic_process(std::string(arg1->value.c));
                    exp2 = Location::regOf(map_sfr(std::string(arg2->value.c)));
                    if(if_a_byte(arg2->value.c))
                        exp2 = byte_present(arg2->value.c);
                    if (op1 == 0)
                        stmts = instantiate(pc, "MOVX_RI0_A",exp2);
                    else if (op1 == 1 )
                        stmts = instantiate(pc, "MOVX_RI1_A", exp2);
                    else if (op1 == 11)
                         stmts = instantiate(pc, "MOVX_DPTRA_A",exp2);
                    break;
                }
                case 6: /*MOVX A, INDIRECT*/
                {   op2 = magic_process(std::string(arg2->value.c));
                    Ternary* e2 = new Ternary(opZfill, new Const(16), new Const(31), Location::regOf(op2));
                    exp2 = Location::memOf(new TypedExp((Type *) direct_type, e2));
                    if (op2 == 0){
                        stmts = instantiate(pc, "MOVX_A_RI0",exp1, exp2);
                    }
                    else if (op2 == 1 ){
                        stmts = instantiate(pc, "MOVX_A_RI1",exp1, exp2);
                    }
                    else if (op2 == 11){
                        stmts = instantiate(pc, "MOVX_A_DPTRA",exp1, exp2);
                    }
                    break;
                }
                case 0:
                case 1:
                case 2:
                case 5:
                case 4:
                case 7:
                case 8:
                    break;
                default:
                    break;
            }
        }
    }
    else if (opcode == "RET" || opcode == "RETI") {
        result.rtl = new RTL(pc, stmts);
        Assign * return_s;
        std::list<char*>::iterator br;
        for (br = bitReg.begin(); br != bitReg.end(); ++ br ){
            if (strcmp("A",(*br)) == 0){
                return_s = new Assign(new SizeType(8),(Exp *) Location::regOf(8),new Binary(opMemberAccess,Location::regOf(8), new Const("x")), NULL);
                result.rtl->appendStmt(return_s);
                break;
            }
        }
        result.rtl->appendStmt(new ReturnStatement); 
        result.type = DD;
    }
    else if (opcode == "JNB" || opcode == "JB" || opcode == "JBC") {
        ei = Line->expList->begin();
        AssemblyArgument* arg1 = (*ei)->argList.front();      
        if (opcode == "JB")
            stmts = instantiate(pc, "JB_DIR_IMM", access_bit(arg1->value.bit.reg,arg1->value.bit.pos), new Const(100));
        else if (opcode == "JNB")
            stmts = instantiate(pc, "JNB_DIR_IMM", access_bit(arg1->value.bit.reg,arg1->value.bit.pos), new Const(100));
        else if (opcode == "JBC"){} //TODO: 
            //stmts = instantiate(pc, "JBC_DIR_IMM", new Const(arg1->value.i), new Const(100));
 
        result.rtl = new RTL(pc, stmts); 
        BranchStatement* jump = new BranchStatement; 
        result.rtl->appendStmt(jump); 
        result.numBytes = 4; 
        jump->setDest(pc + (Line->offset+1)*4);
        jump->setCondType(BRANCH_JE);
    }
    else if (opcode == "SETB"){
        ei = Line->expList->begin();
        AssemblyArgument* arg1 = (*ei)->argList.front();
        stmts = instantiate(pc, "SETB_DIR", access_bit(arg1->value.bit.reg,arg1->value.bit.pos));        
    }
    else if (opcode == "ORL" || opcode == "ANL" || opcode == "XRL") {
        stringstream ss;
        ss << opcode << "_EXP";
        string str(ss.str());
        char *name =  new char[str.length() + 1];
        strcpy(name, str.c_str());
        Exp* exp1;
        Exp* exp2;

        ei = Line->expList->begin();
        AssemblyArgument* arg1 = (*ei)->argList.front();
        exp1 = Location::regOf(map_sfr(std::string(arg1->value.c)));
        if (if_a_byte(arg1->value.c)){
            exp1 = byte_present(arg1->value.c);
        }

        ei++;
        AssemblyArgument* arg2 = (*ei)->argList.front();
        unsigned op1, op2;

        switch(arg1->kind){
            case 6: /* A, C, DIRECT */
            {   op1 = magic_process(std::string(arg1->value.c));
                if (op1 == 8){ /*A*/
                    switch(arg2->kind){
                        case 3: /*A, INDIRECT*/
                        {   op2 = magic_process(arg2->value.c);
                            Ternary* e2 = new Ternary(opZfill, new Const(16), new Const(31), Location::regOf(op2));
                            exp2 = Location::memOf(new TypedExp((Type *) direct_type, e2));
                            if (op2 == 0){
                                if (opcode == "ORL")
                                    stmts = instantiate(pc,"ORL_EXP", exp1, exp2);
                                else if(opcode == "ANL")
                                    stmts = instantiate(pc,"ANL_EXP", exp1, exp2);
                                else
                                    stmts = instantiate(pc,"XRL_EXP", exp1, exp2);
                            }
                            else if (op2 == 1){
                                if (opcode == "ORL")
                                    stmts = instantiate(pc,"ORL_EXP", exp1, exp2);
                                else if(opcode == "ANL")
                                    stmts = instantiate(pc,"ANL_EXP", exp1, exp2);
                                else
                                    stmts = instantiate(pc,"XRL_EXP", exp1, exp2);
                            }
                            break;
                        }
                        case 6: /*A, Rn | DIRECT ID*/
                        {   
                            op2 = magic_process(arg2->value.c);
                            if (op2 < 8){
                                exp2 = Location::regOf(op2);
                                if(if_a_byte(arg2->value.c))
                                    exp2 = byte_present(arg2->value.c);
                            }
                            else if (op2 >= 9){
                                Exp * temp = Location::regOf(op2);
                                if(if_a_byte(arg2->value.c))
                                    temp = byte_present(arg2->value.c);
                                exp2 = Location::memOf(temp);
                            }
                            stmts = instantiate(pc,name, exp1,exp2);
                            break;
                        }
                        case 1: /* A, DIRECT INT */
                        {   
                            exp2 = Location::memOf(new TypedExp((Type *) direct_type, new Const(arg2->value.i)));
                            stmts = instantiate(pc,name, exp1,exp2);
                            break;
                        }
                        case 4: /*A, IMM */
                        {
                            exp2 = new Const(arg2->value.i);
                            stmts = instantiate(pc,name, exp1,exp2);
                            break;
                        }
                        default:
                            break;
                    }
                }
                else if (op1 >= 9){ /*DIRECT*/
                    Exp* new_exp1 = Location::memOf(exp1);
                    switch(arg2->kind){
                        case 6: /*JUST DIRECT, A*/
                        {   
                            exp2 = Location::regOf(map_sfr(std::string(arg2->value.c)));
                            if (if_a_byte(arg2->value.c))
                                exp2 = byte_present(arg2->value.c);
                            stmts = instantiate(pc,name, new_exp1,exp2);
                            break;
                        }
                        case 4: /*DIRECT, IMM*/
                        {
                            exp2  = new Const(arg2->value.i);
                            stmts = instantiate(pc,name, new_exp1 ,exp2);
                            break;
                        }
                        default:
                            break;
                    }
                }    
                break;
            }
          
            default:
                break;
        }
    }
    else if (opcode == "CLR") {
        ei = Line->expList->begin();
        AssemblyArgument* arg1 = (*ei)->argList.front();
        unsigned op1;
        switch(arg1->kind){
            case 6: /* A, C*/
            {   op1 = magic_process(std::string(arg1->value.c));
                if(op1 == 8)
                    stmts = instantiate(pc, "CLR_A");
                else if(op1 == 10)
                    stmts = instantiate(pc, "CLR_C");
                break;
            }
            case 8: /* BIT */
            {   stmts = instantiate(pc, "CLR_DIR", access_bit(arg1->value.bit.reg,arg1->value.bit.pos));  
                break;
            }
            default:
                break;
        }
    }
    else if (opcode == "NOP") {
    }
    else if (opcode == "ACALL" || opcode == "LCALL") {
        ei = Line->expList->begin();
        AssemblyArgument* arg1 = (*ei)->argList.front();
        bool is_lib = false;
        ADDRESS address;
        std::map<ADDRESS, const char*>::iterator it;
       
        for(it = namesList.begin();it != namesList.end(); ++it ){
            if (strcmp(it->second,arg1->value.c) == 0){
                address = it->first;
                break;
            }
        }
        CallStatement* newCall = new CallStatement;
        ADDRESS nativeDest = address - delta;
        newCall->setDest(nativeDest);
        Proc* destProc;
        funcsType[address] = is_lib;
        destProc = prog->newProc(arg1->value.c, nativeDest, is_lib);
        newCall->setDestProc(destProc);
        result.rtl = new RTL(pc, stmts);
        result.rtl->appendStmt(newCall);
        result.type = SD;
    }
    else if (opcode == "ADD" || opcode == "ADDC" || opcode == "SUBB") {
        stringstream ss;
        ss << opcode << "_A_EXP";
        string str(ss.str());
        char *name =  new char[str.length() + 1];
        strcpy(name, str.c_str());

        Exp* exp1;
        Exp* exp2;

        ei = Line->expList->begin();
        AssemblyArgument* arg1 = (*ei)->argList.front();
        exp1 = Location::regOf(map_sfr(std::string(arg1->value.c)));
        if (if_a_byte(arg1->value.c)){
            exp1 = byte_present(arg1->value.c);
        }

        ei++;
        AssemblyArgument* arg2 = (*ei)->argList.front();
        unsigned op1, op2;

        switch(arg2->kind){
            case 3: /* A, INDIRECT */
            {   
                op2 = map_sfr(std::string(arg2->value.c));
                Ternary* e2 = new Ternary(opZfill, new Const(16), new Const(31), Location::regOf(op2));
                exp2 = Location::memOf(new TypedExp((Type *) direct_type, e2));
                if (op2 == 0){
                    if (opcode == "ADD")
                        stmts = instantiate(pc,"ADD_A_EXP", exp1, exp2);
                    else if (opcode == "SUBB")
                        stmts = instantiate(pc,"SUBB_A_EXP", exp1, exp2);
                    else{ 
                        Exp * temp = Location::regOf(10);
                        if(if_a_byte("C"))
                            temp = byte_present("C");
                        stmts = instantiate(pc,"ADDC_A_EXP", exp1, Location::memOf(temp), exp2);
                    } 
                }
                else if (op2 == 1){
                    if (opcode == "ADD")
                        stmts = instantiate(pc,"ADD_A_EXP", exp1, exp2);
                    else if (opcode == "SUBB")
                        stmts = instantiate(pc,"SUBB_A_EXP", exp1, exp2);
                    else{ 
                        Exp * temp = Location::regOf(10);
                        if(if_a_byte("C"))
                            temp = byte_present("C");
                        stmts = instantiate(pc,"ADDC_A_EXP", exp1, Location::memOf(temp), exp2);
                    } 
                }
                     
                break;
            }
            case 6: /* A, Rn | Direct ID */
            {
                op2 = map_sfr(std::string(arg2->value.c));
                if (op2 < 8){ //Rn
                    exp2 = Location::regOf(op2);
                    if (if_a_byte(arg2->value.c))
                        exp2 = byte_present(arg2->value.c);
                }
                else if (op2 >= 9){ //Direct
                    exp2 = Location::regOf(op2);
                    if (if_a_byte(arg2->value.c))
                        exp2 = byte_present(arg2->value.c);
                    exp2 = Location::memOf(exp2);
                }
                if (opcode == "ADDC"){
                    Exp * temp = Location::regOf(10);
                        if(if_a_byte("C"))
                            temp = byte_present("C");
                    stmts = instantiate(pc,name, exp1, Location::memOf(temp), exp2);
                }
                else 
                    stmts = instantiate(pc,name, exp1, exp2);

                break;
            }
            case 1: /*A, Direct Int */
            {   
                exp2 = Location::memOf(new TypedExp((Type *) direct_type, new Const(arg2->value.i)));
                if (opcode == "ADDC"){
                    Exp * temp = Location::regOf(10);
                        if(if_a_byte("C"))
                            temp = byte_present("C");
                    stmts = instantiate(pc,name, exp1, Location::memOf(temp), exp2);
                }
                else 
                    stmts = instantiate(pc,name, exp1, exp2);
                break;
            }
            case 4: /* A, IMM */
            {
                exp2 = new Const(arg2->value.i);
                if (opcode == "ADDC"){
                    Exp * temp = Location::regOf(10);
                        if(if_a_byte("C"))
                            temp = byte_present("C");
                    stmts = instantiate(pc,name, exp1, Location::memOf(temp), exp2);
                }
                else 
                    stmts = instantiate(pc,name, exp1, exp2);
                break;
            }
            default:
                break;
        }
        
    }
    else if (opcode == "RR" || opcode == "RRC" || opcode == "RLC") {
        Exp* exp1;
        ei = Line->expList->begin();
        AssemblyArgument* arg1 = (*ei)->argList.front();
        if(arg1->kind != 1){
            exp1 = Location::regOf(map_sfr(std::string(arg1->value.c)));
            if (if_a_byte(arg1->value.c)){
                exp1 = byte_present(arg1->value.c);
            }
        }
        if(opcode == "RR")
            stmts = instantiate(pc,"RR_A", exp1);
        else if(opcode == "RRC")
            stmts = instantiate(pc,"RRC_A", exp1);
        else 
            stmts = instantiate(pc,"RLC_A", exp1);
    }
    else if (opcode == "DEC" || opcode == "INC") {
        stringstream ss;
        ss << opcode << "_EXP";
        string str(ss.str());
        char *name =  new char[str.length() + 1];
        strcpy(name, str.c_str());

        Exp* exp1;
        Exp* exp2;

        ei = Line->expList->begin();
        AssemblyArgument* arg1 = (*ei)->argList.front();
        exp1 = Location::regOf(map_sfr(std::string(arg1->value.c)));
        if (if_a_byte(arg1->value.c)){
            exp1 = byte_present(arg1->value.c);
        }
        unsigned op1, op2;
        op1 =  map_sfr(std::string(arg1->value.c));
        switch(arg1->kind){
            case 3: /*INDIRECT*/
            {   
                Ternary* e2 = new Ternary(opZfill, new Const(16), new Const(31), Location::regOf(op1));
                exp1 = Location::memOf(Location::regOf(op1));
                exp2 = Location::memOf(new TypedExp((Type *) direct_type, e2));
                if (op1 == 0){
                    if(opcode == "INC"){
                        stmts = instantiate(pc,"INC_EXP_EXP",exp1,exp2);
                    }
                    else{
                        stmts = instantiate(pc,"DEC_EXP_EXP",exp1,exp2);
                    }
                }
                else{
                    if(opcode == "INC"){
                        stmts = instantiate(pc,"INC_EXP_EXP",exp1,exp2);
                    }
                    else{
                        stmts = instantiate(pc,"DEC_EXP_EXP",exp1,exp2);
                    }
                }
                break;
            }
            case 6: /*A, DPTR, DIRECT*/
            {   if (!(op1 >=0 && op1 <=8 ||  op1 == 11))
                    exp1 = Location::memOf(exp1);

                stmts = instantiate(pc,name,exp1);
                break;
            }
            default:
                break;
        }
    }
    else if (opcode == "JC" || opcode == "JNC") {
        ei = Line->expList->begin();
        AssemblyArgument* arg1 = (*ei)->argList.front();
        Exp * exp1;
        exp1 = Location::regOf(10);
        if(if_a_byte("C"))
            exp1 = byte_present("C");
        exp1 =  Location::memOf(exp1);      
        if (opcode == "JC")
            stmts = instantiate(pc, "JC_IMM", exp1);
        else if (opcode == "JNC")
            stmts = instantiate(pc, "JNC_IMM", exp1);
 
        result.rtl = new RTL(pc, stmts); 
        BranchStatement* jump = new BranchStatement; 
        result.rtl->appendStmt(jump); 
        result.numBytes = 4; 
        jump->setDest(pc + (Line->offset+1)*4);
        jump->setCondType(BRANCH_JE);
    }
    else if (opcode == "DIV" || opcode == "MUL") {
        Exp * exp1;
        Exp * exp2;
        exp1 = Location::regOf(8);
        exp2 = Location::regOf(9);
        if (if_a_byte("A"))
            exp1 = byte_present("A");
        if (if_a_byte("B"))
            exp1 = byte_present("B");
        if (opcode == "DIV")
            stmts = instantiate(pc, "DIV_AB", exp1, Location::memOf(exp2));
        if (opcode == "MUL")
            stmts = instantiate(pc, "MUL_AB", exp1, Location::memOf(exp2));
    }
    else if (opcode == "CPL") {
        Exp * exp1;
        ei = Line->expList->begin();
        AssemblyArgument* arg1 = (*ei)->argList.front();
        if(arg1->kind == 1){
            stmts = instantiate(pc,"CPL_BIT", Location::memOf(new Const(arg1->value.i)));
        }
        else {
            unsigned op1 = map_sfr(std::string(arg1->value.c));
            exp1 = Location::regOf(op1);
            if(if_a_byte(arg1->value.c))
                exp1 = byte_present(arg1->value.c);

            if (op1 == 8){
                stmts = instantiate(pc,"CPL_A", exp1);
            }
            else{
                exp1 = Location::memOf(exp1);
                stmts = instantiate(pc,"CPL_DIR", exp1);
            }
        }
        
    }
    else if (opcode == "JZ" || opcode == "JNZ") {
        ei = Line->expList->begin();
        AssemblyArgument* arg1 = (*ei)->argList.front();
        Exp * exp1;
        exp1 = Location::regOf(8);
        if(if_a_byte("A"))
            exp1 = byte_present("A");      
        if (opcode == "JZ")
            stmts = instantiate(pc, "JZ_IMM", exp1);
        else if (opcode == "JNZ")
            stmts = instantiate(pc, "JNZ_IMM", exp1);
 
        result.rtl = new RTL(pc, stmts); 
        BranchStatement* jump = new BranchStatement; 
        result.rtl->appendStmt(jump); 
        result.numBytes = 4; 
        jump->setDest(pc + (Line->offset+1)*4);
        jump->setCondType(BRANCH_JE);
    }
    else if (opcode == "CJNE"){
        Exp* exp1;
        Exp* exp2;
        //-----EXPRESSION1, ALWAYS AN ID----------------------------
        ei = Line->expList->begin();
        AssemblyArgument* arg1 = (*ei)->argList.front();
        exp1 = Location::regOf(map_sfr(std::string(arg1->value.c)));
        if (if_a_byte(arg1->value.c)){
            exp1 = byte_present(arg1->value.c);
        }
        ++ei;
        AssemblyArgument* arg2 = (*ei)->argList.front();
        unsigned op1, op2;
        switch(arg1->kind){
            case 3: /*INDIRECT , IMM*/
            {   
                op1 = map_sfr(std::string(arg1->value.c));
                if (op1 == 0)
                    stmts = instantiate(pc,"CJNE_RI0", new Const(arg2->value.i));
                if (op1 == 1)
                    stmts = instantiate(pc,"CJNE_RI1", new Const(arg2->value.i));
                break;
            }
            case 6: /*A, Rn*/
            {   
                op1 = map_sfr(std::string(arg1->value.c));
                if (op1 <= 7){ //Rn
                    stmts = instantiate(pc,"CJNE_EXP", exp1, new Const(arg2->value.i));
                }   
                else { //A
                    switch(arg2->kind){
                        case 1: // A, Direct int
                        {   stmts = instantiate(pc,"CJNE_EXP", exp1, Location::memOf(new Const(arg2->value.i)));
                            break;
                        }
                        case 6: //A, Direct ID
                        {   op2 = map_sfr(std::string(arg2->value.c));
                            exp2 = Location::regOf(op2);
                            if(if_a_byte(arg2->value.c))
                                exp2 = byte_present(arg2->value.c);
                            exp2 = Location::memOf(exp2);
                            stmts = instantiate(pc,"CJNE_EXP", exp1, exp2);
                            break;
                        }
                        case 4: //A, Immediate
                        {   stmts = instantiate(pc,"CJNE_EXP", exp1, new Const(arg2->value.i));
                            break;
                        }
                        default:
                            break;
                    }
                }
                break;
            }
            default:
                break;
        }
        result.rtl = new RTL(pc, stmts); 
        BranchStatement* jump = new BranchStatement; 
        result.rtl->appendStmt(jump); 
        result.numBytes = 4; 
        jump->setDest(pc + (Line->offset+1)*4);
        jump->setCondType(BRANCH_JE);
    }
    else if (opcode == "DJNZ"){
        Exp* exp1;
        Exp* exp2;
        //-----EXPRESSION1, ALWAYS AN ID----------------------------
        ei = Line->expList->begin();
        AssemblyArgument* arg1 = (*ei)->argList.front();
        exp1 = Location::regOf(map_sfr(std::string(arg1->value.c)));
        if (if_a_byte(arg1->value.c)){
            exp1 = byte_present(arg1->value.c);
        }
        ++ei;
        AssemblyArgument* arg2 = (*ei)->argList.front();
        unsigned op1, op2;

        bool loop = false;
        if(Line->offset < 0)
            loop = true;
        switch(arg1->kind){
            case 6: /*Rn, Direct*/
            {   
                op1 = map_sfr(std::string(arg1->value.c));
                if (op1 <= 7){ //Rn
                    if (!loop)
                        stmts = instantiate(pc,"DJNZ_EXP", exp1);
                    else
                        stmts = instantiate(pc,"DJNZ_EXP_LOOP", exp1);
                }   
                else {// Direct
                    exp1 = Location::memOf(exp1);
                    if (!loop)
                        stmts = instantiate(pc,"DJNZ_EXP", exp1);
                    else 
                        stmts = instantiate(pc,"DJNZ_EXP_LOOP", exp1);
                }
                break;
            }
            default:
                break;
        }
        result.rtl = new RTL(pc, stmts); 
        BranchStatement* jump = new BranchStatement; 
        result.rtl->appendStmt(jump); 
        result.numBytes = 4; 
        jump->setDest(pc + (Line->offset+1)*4);
        jump->setCondType(BRANCH_JNE);
    }
    else if (opcode == "PUSH" || opcode == "POP"){
        ei = Line->expList->begin();
        AssemblyArgument* arg1 = (*ei)->argList.front();

        if (opcode == "PUSH")
            stmts = instantiate(pc,"PUSH_DIR", new Const(arg1->value.i) );
        else
            stmts = instantiate(pc,"POP_DIR", new Const(arg1->value.i) );
    }
    else if (opcode == "SWAP"){
        Exp* exp1 = Location::regOf(8);
        if(if_a_byte("A"))
            exp1 = byte_present("A");
        stmts = instantiate(pc,"SWAP_A", exp1);
    }
    else if (opcode == "XCH"){
        Exp* exp1;
        Exp* exp2;
        //-----EXPRESSION1, ALWAYS AN ID----------------------------
        ei = Line->expList->begin();
        AssemblyArgument* arg1 = (*ei)->argList.front();
        exp1 = Location::regOf(map_sfr(std::string(arg1->value.c)));
        if (if_a_byte(arg1->value.c)){
            exp1 = byte_present(arg1->value.c);
        }
        //-----EXPRESSION2, FIRST TEST THE BINARY
        ++ei;
        
        AssemblyArgument* arg2 = (*ei)->argList.front();
        //---------------------------------------------------------
        unsigned op1;
        unsigned op2;
        switch(arg2->kind){
            case 3: //A, INDIRECT
            {   op2 = map_sfr(std::string(arg2->value.c));
                Ternary* e2 = new Ternary(opZfill, new Const(16), new Const(31), Location::regOf(op2));
                exp2 = Location::memOf(new TypedExp((Type *) direct_type, e2));
                if (op2 == 0){
                    stmts = instantiate(pc,"XCH_EXP_EXP", exp1, exp2, Location::memOf(Location::regOf(op2)));
                }
                else{
                    stmts = instantiate(pc,"XCH_EXP_EXP", exp1, exp2, Location::memOf(Location::regOf(op2)));   
                }
                break;
            }
            case 6: //A, Rn|DIRECT ID
            {   
                op2 = map_sfr(string(arg2->value.c));
                exp2 = Location::regOf(op2);
                if (if_a_byte(arg2->value.c))
                    exp2 = byte_present(arg2->value.c);
                if(op2 > 7)
                    exp2 = Location::memOf(exp2);
                stmts = instantiate(pc,"XCH_EXP", exp1, exp2);
                break;
            }
            case 1: //A, Direct INT
            {   exp2 = Location::memOf(new TypedExp((Type *) direct_type, new Const(arg2->value.i)));
                stmts = instantiate(pc,"XCH_EXP_EXP", exp1, exp2,Location::memOf(new Const(arg2->value.i)));
                break;
            }
            default:
                break;
        }
    }
    else if (opcode == "RL"){
        Exp* exp1 = Location::regOf(8);
        if(if_a_byte("A"))
            exp1 = byte_present("A");
        stmts = instantiate(pc,"RL_A", exp1);
    }
    else
    {
        std::cout << "ELSE " << opcode << std::endl;
        stmts = NULL;
        result.valid = false;
        result.numBytes = 4;
    }
    result.numBytes = 4;

    if(result.valid && result.rtl == 0)
        result.rtl = new RTL(pc, stmts);

    //ADDED ONE-BYTE REGISTER at the first time
    if(first_line){ 
        std::list<Statement*>* temp = initial_bit_regs();
        std::list<Statement*>::iterator li;
        for(li = temp->begin(); li != temp->end(); ++li){
            result.rtl->appendStmt((*li));
        }

        first_line = false;
    }

    return result;
}

_8051Decoder::_8051Decoder(Prog* prog) : NJMCDecoder(prog)
{
    std::string file = Boomerang::get()->getProgPath() + "frontend/machine/_8051/_8051.ssl";
    RTLDict.readSSLFile(file.c_str());
}
int _8051Decoder::decodeAssemblyInstruction(unsigned,int)
{
    return 0;
}
