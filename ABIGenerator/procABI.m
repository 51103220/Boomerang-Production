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
				
						//##@@EACH TYPE OF MACHINE WILL BE PROCESSED HERE //DONT DELETE THIS LINE
						//FINISH PROCESSED 

					
				
			}
		}

}