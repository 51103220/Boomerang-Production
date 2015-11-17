#include "proc.h"
void UserProc::findABIParameters(){
	BB_IT it;
	for (PBB bb = cfg->getFirstBB(it); bb; bb = cfg->getNextBB(it)) {
		if (bb->getType() == CALL) {
			CallStatement* call = (CallStatement*)bb->getRTLs()->back()->getHlStmt();
			if (!call->isCall()) {
				LOG << "bb at " << bb->getLowAddr() << " is a CALL but last stmt is not a call: " << call << "\n";
			}
			assert(call->isCall());
			UserProc* c = (UserProc*)call->getDestProc();
			if (c == NULL || c->isLib()) continue;
			BB_IT previous=it;
			previous--;
			std::cout<<"Get user call "<<c->getName()<<" from "<< getName()<<"\n";
			
			std::cout<<" current bb test remake\n";
			StatementList stmts;
			bb->getStatements(stmts);
			StatementList::iterator stit;


						/*if (!(lhs->isRegOf() || isLocalOrParamPattern(lhs)))*/
				
						//##@@EACH TYPE OF MACHINE WILL BE PROCESSED HERE //DONT DELETE THIS LINE
			switch (prog->getFrontEndId()){
				case PLAT_SPARC:{
				bool param11 = false;
				bool param12 = false;
				bool param13 = false;
				bool param14 = false;
				bool param15 = false;
				bool param16 = false;
				bool ispara1 = false;
				bool addparam1 = false;
				for (stit = stmts.begin(); stit != stmts.end(); ++stit) {
					Statement* s = *stit;
					ispara1=false;
					if(!s->isAssignment())
						continue;
					Exp *lhs = ((Assignment*)s)->getLeft();
					Exp* temp2;
					if(((std::string)lhs->prints())=="r8"){
						ispara1 = true;
						param11 = true;
						temp2 = lhs->clone();
					}
					if(((std::string)lhs->prints())=="r9"){
						ispara1 = true;
						param12 = true;
						temp2 = lhs->clone();
					}
					if(((std::string)lhs->prints())=="r10"){
						ispara1 = true;
						param13 = true;
						temp2 = lhs->clone();
					}
					if(((std::string)lhs->prints())=="r11"){
						ispara1 = true;
						param14 = true;
						temp2 = lhs->clone();
					}
					if(((std::string)lhs->prints())=="r12"){
						ispara1 = true;
						param15 = true;
						temp2 = lhs->clone();
					}
					if(((std::string)lhs->prints())=="r13"){
						ispara1 = true;
						param16 = true;
						temp2 = lhs->clone();
					}
					if(param11 && param12 && param13 && param14 && param15 && param16 && !addparam1){
						stit = stmts.begin();
						c->ABIparameters.clear();
						addparam1 = true;
					}
					if(addparam1 &&(((std::string)lhs->prints()).find("r14")!=std::string::npos)){
						if(lhs->isMemOf())
						ispara1 = true;
					}
					if (ispara1){
						std::list<Exp*>::iterator eit;
						eit=c->ABIparameters.begin();
						c->ABIparameters.insert(eit,temp2);
					}
				}
				break;}
				case PLAT_PENTIUM:{
				bool ispara2 = false;
				bool addparam2 = false;
				for (stit = stmts.begin(); stit != stmts.end(); ++stit) {
					Statement* s = *stit;
					ispara2=false;
					if(!s->isAssignment())
						continue;
					Exp *lhs = ((Assignment*)s)->getLeft();
					Exp* temp2;
					if (ispara2){
						std::list<Exp*>::iterator eit;
						eit=c->ABIparameters.begin();
						c->ABIparameters.insert(eit,temp2);
					}
				}
				break;}
				case PLAT_PPC:{
				bool param31 = false;
				bool param32 = false;
				bool param33 = false;
				bool param34 = false;
				bool param35 = false;
				bool param36 = false;
				bool param37 = false;
				bool param38 = false;
				bool ispara3 = false;
				bool addparam3 = false;
				for (stit = stmts.begin(); stit != stmts.end(); ++stit) {
					Statement* s = *stit;
					ispara3=false;
					if(!s->isAssignment())
						continue;
					Exp *lhs = ((Assignment*)s)->getLeft();
					Exp* temp2;
					if(((std::string)lhs->prints())=="r3"){
						ispara3 = true;
						param31 = true;
						temp2 = lhs->clone();
					}
					if(((std::string)lhs->prints())=="r4"){
						ispara3 = true;
						param32 = true;
						temp2 = lhs->clone();
					}
					if(((std::string)lhs->prints())=="r5"){
						ispara3 = true;
						param33 = true;
						temp2 = lhs->clone();
					}
					if(((std::string)lhs->prints())=="r6"){
						ispara3 = true;
						param34 = true;
						temp2 = lhs->clone();
					}
					if(((std::string)lhs->prints())=="r7"){
						ispara3 = true;
						param35 = true;
						temp2 = lhs->clone();
					}
					if(((std::string)lhs->prints())=="r8"){
						ispara3 = true;
						param36 = true;
						temp2 = lhs->clone();
					}
					if(((std::string)lhs->prints())=="r9"){
						ispara3 = true;
						param37 = true;
						temp2 = lhs->clone();
					}
					if(((std::string)lhs->prints())=="r10"){
						ispara3 = true;
						param38 = true;
						temp2 = lhs->clone();
					}
					if(((std::string)lhs->prints())=="m[r1 + 24]"){
						ispara3 = true;
						param31 = true;
						temp2 = Location::regOf(3);
					}
					if(((std::string)lhs->prints())=="m[r1 + 28]"){
						ispara3 = true;
						param32 = true;
						temp2 = Location::regOf(4);
					}
					if(((std::string)lhs->prints())=="m[r1 + 32]"){
						ispara3 = true;
						param33 = true;
						temp2 = Location::regOf(5);
					}
					if(((std::string)lhs->prints())=="m[r1 + 36]"){
						ispara3 = true;
						param34 = true;
						temp2 = Location::regOf(6);
					}
					if(((std::string)lhs->prints())=="m[r1 + 40]"){
						ispara3 = true;
						param35 = true;
						temp2 = Location::regOf(7);
					}
					if(((std::string)lhs->prints())=="m[r1 + 44]"){
						ispara3 = true;
						param36 = true;
						temp2 = Location::regOf(8);
					}
					if(((std::string)lhs->prints())=="m[r1 + 48]"){
						ispara3 = true;
						param37 = true;
						temp2 = Location::regOf(9);
					}
					if(((std::string)lhs->prints())=="m[r1 + 52]"){
						ispara3 = true;
						param38 = true;
						temp2 = Location::regOf(10);
					}
					if(param31 && param32 && param33 && param34 && param35 && param36 && param37 && param38 && !addparam3){
						stit = stmts.begin();
						c->ABIparameters.clear();
						addparam3 = true;
					}
					if(addparam3 &&(((std::string)lhs->prints()).find("r1")!=std::string::npos)){
						if(lhs->isMemOf())
						ispara3 = true;
					}
					if (ispara3){
						std::list<Exp*>::iterator eit;
						eit=c->ABIparameters.begin();
						c->ABIparameters.insert(eit,temp2);
					}
				}
				break;}
				case PLAT_MIPS:{
				bool ispara4 = false;
				bool addparam4 = false;
				for (stit = stmts.begin(); stit != stmts.end(); ++stit) {
					Statement* s = *stit;
					ispara4=false;
					if(!s->isAssignment())
						continue;
					Exp *lhs = ((Assignment*)s)->getLeft();
					Exp* temp2;
					if (ispara4){
						std::list<Exp*>::iterator eit;
						eit=c->ABIparameters.begin();
						c->ABIparameters.insert(eit,temp2);
					}
				}
				break;}
				case PLAT_ST20:{
				bool ispara5 = false;
				bool addparam5 = false;
				for (stit = stmts.begin(); stit != stmts.end(); ++stit) {
					Statement* s = *stit;
					ispara5=false;
					if(!s->isAssignment())
						continue;
					Exp *lhs = ((Assignment*)s)->getLeft();
					Exp* temp2;
					if (ispara5){
						std::list<Exp*>::iterator eit;
						eit=c->ABIparameters.begin();
						c->ABIparameters.insert(eit,temp2);
					}
				}
				break;}
			}
						//FINISH PROCESSED 

					
				
			}
		}

}
