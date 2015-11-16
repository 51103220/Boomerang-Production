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
			std::cout<<"Get user call "<<c->getName()<<"from"<< getName()<<"\n";
			
			std::cout<<" current bb test remake";
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
					if(((std::string)lhs->prints())=="r8"){
						ispara1 = true;
						param11 = true;
					}
					if(((std::string)lhs->prints())=="r9"){
						ispara1 = true;
						param12 = true;
					}
					if(((std::string)lhs->prints())=="r10"){
						ispara1 = true;
						param13 = true;
					}
					if(((std::string)lhs->prints())=="r11"){
						ispara1 = true;
						param14 = true;
					}
					if(((std::string)lhs->prints())=="r12"){
						ispara1 = true;
						param15 = true;
					}
					if(((std::string)lhs->prints())=="r13"){
						ispara1 = true;
						param16 = true;
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
						c->ABIparameters.insert(eit,lhs);
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
					if(!addparam2){
						stit = stmts.begin();
						c->ABIparameters.clear();
						addparam2 = true;
					}
					if(addparam2 &&(((std::string)lhs->prints()).find("r28")!=std::string::npos)){
						if(lhs->isMemOf())
						ispara2 = true;
					}
					if (ispara2){
						std::list<Exp*>::iterator eit;
						eit=c->ABIparameters.begin();
						c->ABIparameters.insert(eit,lhs);
					}
				}
				break;}
				case PLAT_PARISC:{
				bool ispara3 = false;
				bool addparam3 = false;
				for (stit = stmts.begin(); stit != stmts.end(); ++stit) {
					Statement* s = *stit;
					ispara3=false;
					if(!s->isAssignment())
						continue;
					Exp *lhs = ((Assignment*)s)->getLeft();
					if (ispara3){
						std::list<Exp*>::iterator eit;
						eit=c->ABIparameters.begin();
						c->ABIparameters.insert(eit,lhs);
					}
				}
				break;}
				case PLAT_M68K:{
				bool ispara4 = false;
				bool addparam4 = false;
				for (stit = stmts.begin(); stit != stmts.end(); ++stit) {
					Statement* s = *stit;
					ispara4=false;
					if(!s->isAssignment())
						continue;
					Exp *lhs = ((Assignment*)s)->getLeft();
					if (ispara4){
						std::list<Exp*>::iterator eit;
						eit=c->ABIparameters.begin();
						c->ABIparameters.insert(eit,lhs);
					}
				}
				break;}
				case PLAT_PPC:{
				bool ispara5 = false;
				bool addparam5 = false;
				for (stit = stmts.begin(); stit != stmts.end(); ++stit) {
					Statement* s = *stit;
					ispara5=false;
					if(!s->isAssignment())
						continue;
					Exp *lhs = ((Assignment*)s)->getLeft();
					if (ispara5){
						std::list<Exp*>::iterator eit;
						eit=c->ABIparameters.begin();
						c->ABIparameters.insert(eit,lhs);
					}
				}
				break;}
				case PLAT_MIPS:{
				bool ispara6 = false;
				bool addparam6 = false;
				for (stit = stmts.begin(); stit != stmts.end(); ++stit) {
					Statement* s = *stit;
					ispara6=false;
					if(!s->isAssignment())
						continue;
					Exp *lhs = ((Assignment*)s)->getLeft();
					if (ispara6){
						std::list<Exp*>::iterator eit;
						eit=c->ABIparameters.begin();
						c->ABIparameters.insert(eit,lhs);
					}
				}
				break;}
				case PLAT_ST20:{
				bool ispara7 = false;
				bool addparam7 = false;
				for (stit = stmts.begin(); stit != stmts.end(); ++stit) {
					Statement* s = *stit;
					ispara7=false;
					if(!s->isAssignment())
						continue;
					Exp *lhs = ((Assignment*)s)->getLeft();
					if (ispara7){
						std::list<Exp*>::iterator eit;
						eit=c->ABIparameters.begin();
						c->ABIparameters.insert(eit,lhs);
					}
				}
				break;}
				case PLAT_GENERIC:{
				bool param81 = false;
				bool param82 = false;
				bool param83 = false;
				bool param84 = false;
				bool ispara8 = false;
				bool addparam8 = false;
				for (stit = stmts.begin(); stit != stmts.end(); ++stit) {
					Statement* s = *stit;
					ispara8=false;
					if(!s->isAssignment())
						continue;
					Exp *lhs = ((Assignment*)s)->getLeft();
					if(((std::string)lhs->prints())=="r0"){
						ispara8 = true;
						param81 = true;
					}
					if(((std::string)lhs->prints())=="r1"){
						ispara8 = true;
						param82 = true;
					}
					if(((std::string)lhs->prints())=="r2"){
						ispara8 = true;
						param83 = true;
					}
					if(((std::string)lhs->prints())=="r3"){
						ispara8 = true;
						param84 = true;
					}
					if(param81 && param82 && param83 && param84 && !addparam8){
						stit = stmts.begin();
						c->ABIparameters.clear();
						addparam8 = true;
					}
					if(addparam8 &&(((std::string)lhs->prints()).find("r13")!=std::string::npos)){
						if(lhs->isMemOf())
						ispara8 = true;
					}
					if (ispara8){
						std::list<Exp*>::iterator eit;
						eit=c->ABIparameters.begin();
						c->ABIparameters.insert(eit,lhs);
					}
				}
				break;}
			}
						//FINISH PROCESSED 

					
				
			}
		}

}
