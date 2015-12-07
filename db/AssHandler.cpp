#include "AssParser.cpp"
using namespace std;
unsigned int start_address = 66676;
const int jsize = 2;
const int bsize = 2;
const int btsize = 4;
const int rsize = 2;
const char *jmps[jsize] = {
                   "SJMP",
                   "JMP",
 };
const char *brs[bsize] = {
                   "JNB",
                   "JB",
 };
const char *bit[btsize] = {
				"CLR",
                "SETB",
                "JNB",
                "JB"
};
const char *registers[rsize] = {
				"A",
                "C",
};
std::map<char*,int> undefined;
bool if_defined(char* name){
	std::map<char*,int>::iterator it;
	for(it = undefined.begin();it != undefined.end(); ++it ){
		if (strcmp(it->first,name) == 0)
			return true;
	}
	return false;
}
int int_defined(char *name){
	std::map<char*,int>::iterator it;
	for(it = undefined.begin();it != undefined.end(); ++it ){
		if (strcmp(it->first,name) == 0)
			return it->second;
	}
	return 0;
}
bool if_exist(char * name, const char* arr[], int size){
	for(int i = 0 ; i < size; i++){
		if (strcmp(name, arr[i]) == 0) 
			return true;
	}
	return false;
}
void print_arg(AssemblyExpression *expr){
	list<AssemblyArgument*>::iterator ai;
	std::cout << "\t\t\t\t\t "; 
	for(ai = expr->argList.begin(); ai != expr->argList.end(); ai++ ){
			switch ((*ai)->kind){
				case 0:
				case 7:
				case IMMEDIATE_ID:
				case 6:
				case INDIRECT:
					std::cout << (*ai)->value.c << " ";
					break;
				case DIRECT_FLOAT:
					std::cout << (*ai)->value.f << " ";
					break;
				case IMMEDIATE_INT:
				case DIRECT_INT:
					std::cout << (*ai)->value.i << " ";
					break;
				case 8:
					std::cout << (*ai)->value.c  << " "; 
					break;
				default:
					break;
			}
		}
}
void print_ass(AssemblyProgram* ass_program){
	list<AssemblyArgument*>::iterator ai;
	list<AssemblyLine*>::iterator li;
	list<AssemblyExpression*>::iterator ei;
	list<AssemblyLabel*>::iterator lbi;
	if (ass_program){
		std::cout << "***Assembly Name " << ass_program->name << std::endl; 
		std::cout << "***Number of labels " << ass_program->labelList->size() << std::endl;
		for(lbi = ass_program->labelList->begin();lbi != ass_program->labelList->end(); lbi++){
			std::cout << "\t Label name: " << (*lbi)->name << std::endl;
			std::cout << "\t Number of lines: " << (*lbi)->lineList->size() << std::endl;
			for(li = (*lbi)->lineList->begin(); li != (*lbi)->lineList->end(); li++ ){
				std::cout << "\t\t Opcode " << (*li)->name << std::endl;
				std::cout << "\t\t\t Number of Expression: " << (*li)->expList->size() << std::endl;
				for(ei = (*li)->expList->begin(); ei != (*li)->expList->end(); ei++ ){
					std::cout << "\t\t\t\t Number of Arguments:" << (*ei)->argList.size() << std::endl;
					print_arg((*ei));
					std::cout << std::endl; 
				}
			}
		}

	}
}
list<AssemblyLine*>* iterate_label(AssemblyProgram* &ass_program, char* name){
	list<AssemblyArgument*>::iterator ai;
	list<AssemblyLine*>::iterator li;
	list<AssemblyExpression*>::iterator ei;
	list<AssemblyLabel*>::iterator lbi;
	if (ass_program){
		for(lbi = ass_program->labelList->begin();lbi != ass_program->labelList->end(); lbi++){
			if (strcmp((*lbi)->name,name) == 0){
				for(li = (*lbi)->lineList->begin(); li != (*lbi)->lineList->end();){
					if (if_exist((*li)->name, jmps, jsize)){
						char * label_name;
						if((*li)->expList->size() != 0){
							AssemblyExpression * temp_expr = (*li)->expList->front();
							if(temp_expr->argList.size() != 0){
								label_name = temp_expr->argList.front()->value.c;
							}
						} 
						li = (*lbi)->lineList->erase(li);				
						list<AssemblyLine*> *temp_list = iterate_label(ass_program, label_name);
						(*lbi)->lineList->insert(li,temp_list->begin(),temp_list->end());
						advance(li,temp_list->size());
					}
					else if (if_exist((*li)->name, brs, bsize)){
						if (!(*li)->checked){
							(*li)->checked = true;
							char * label_name;
							if((*li)->expList->size() == 2){
								AssemblyExpression * temp_expr = (*li)->expList->back();
								if(temp_expr->argList.size() != 0){
									label_name = temp_expr->argList.front()->value.c;
								}
							} 			
							list<AssemblyLine*> *temp_list = iterate_label(ass_program, label_name);
							(*li)->offset = temp_list->size();
							(*lbi)->lineList->insert(++li,temp_list->begin(),temp_list->end());
							advance(li,temp_list->size()+1);
						}
						else{
							++li;
						}
					}
					else {
						++li;
					}
				}
				return (*lbi)->lineList;
			}
		}

	}
	list<AssemblyLine*>* temp_list = new list<AssemblyLine*>();
	return temp_list;
}
void append_jumps(AssemblyProgram* &ass_program){
	list<AssemblyArgument*>::iterator ai;
	list<AssemblyLine*>::iterator li;
	list<AssemblyExpression*>::iterator ei;
	list<AssemblyLabel*>::iterator lbi;
	if (ass_program){
		for(lbi = ass_program->labelList->begin();lbi != ass_program->labelList->end(); lbi++){
			for(li = (*lbi)->lineList->begin(); li != (*lbi)->lineList->end();){
				if (if_exist((*li)->name, jmps, jsize)){
					char * label_name;
					if((*li)->expList->size() != 0){
						AssemblyExpression * temp_expr = (*li)->expList->front();
						if(temp_expr->argList.size() != 0){
							label_name = temp_expr->argList.front()->value.c;
						}
					} 
					li = (*lbi)->lineList->erase(li);				
					list<AssemblyLine*> *temp_list = iterate_label(ass_program, label_name);
					(*lbi)->lineList->insert(li,temp_list->begin(),temp_list->end());
					advance(li,temp_list->size());
				}
				else if (if_exist((*li)->name, brs, bsize)){
						if (!(*li)->checked){
							char * label_name;
							(*li)->checked = true;
							if((*li)->expList->size() == 2){
								AssemblyExpression * temp_expr = (*li)->expList->back();
								if(temp_expr->argList.size() != 0){
									label_name = temp_expr->argList.front()->value.c;
								}
							} 			
							list<AssemblyLine*> *temp_list = iterate_label(ass_program, label_name);
							(*li)->offset = temp_list->size();
							(*lbi)->lineList->insert(++li,temp_list->begin(),temp_list->end());
							
							advance(li,temp_list->size()+1);
						}
						else{
							++li;
						}
				}
				else{
					++li;
				}

			}
		}

	}
}
void handle_binary(AssemblyProgram* &ass_program){
	list<AssemblyArgument*>::iterator ai;
	list<AssemblyLine*>::iterator li;
	list<AssemblyExpression*>::iterator ei;
	list<AssemblyLabel*>::iterator lbi;
	if (ass_program){
		for(lbi = ass_program->labelList->begin();lbi != ass_program->labelList->end(); lbi++){
			for(li = (*lbi)->lineList->begin(); li != (*lbi)->lineList->end(); li++){
				for(ei = (*li)->expList->begin(); ei != (*li)->expList->end(); ei++ ){
					if((*ei)->kind == 2){
						temp_expr t_e;
						bool LHS = false;
						bool imm = false;
						int rand_value = rand() % 1000 + 100;
						for(ai = (*ei)->argList.begin(); ai != (*ei)->argList.end(); ai++ ){
							switch ((*ai)->kind){
								case 7: //OPERATOR
									t_e.op = (*ai)->value.c;
									break;
								case 5: //IMMEDIATE ID
									imm = true;
									if(!LHS){
										LHS = true;
										if(if_defined((*ai)->value.c)){
											t_e.LHS = int_defined((*ai)->value.c);
										}
										else{
											undefined[(*ai)->value.c] = rand_value;
											t_e.LHS = int_defined((*ai)->value.c);
										}
									}
									else{
										if(if_defined((*ai)->value.c)){
											t_e.RHS = int_defined((*ai)->value.c);
										}
										else{
											undefined[(*ai)->value.c] = rand_value;
											t_e.RHS = int_defined((*ai)->value.c);
										}
									}
									break;
								case 6: // ID
									if(!LHS){
										LHS = true;
										if(if_defined((*ai)->value.c)){
											t_e.LHS = int_defined((*ai)->value.c);											
										}
										else{ 
											undefined[(*ai)->value.c] = rand_value;
											t_e.LHS = int_defined((*ai)->value.c);
										}
									}
									else{
										if(if_defined((*ai)->value.c)){
											t_e.RHS = int_defined((*ai)->value.c);
										}
										else{
											undefined[(*ai)->value.c] = rand_value;
											t_e.RHS = int_defined((*ai)->value.c);
										}
									}
									break;
								case 1: //DIRECT_INT
								case 4: //IMMEDIATE_INT
									if(!LHS)
										t_e.LHS = (*ai)->value.i;
									else
										t_e.RHS = (*ai)->value.i;
									break;
								default:
									break;
							}
						}
						if (strcmp(t_e.op,"+") == 0) {
							t_e.value = t_e.LHS + t_e.RHS;
						}
						else if (strcmp(t_e.op,"-") == 0) {
							t_e.value = t_e.LHS - t_e.RHS;
						}
						else if (strcmp(t_e.op,"*") == 0) {
							t_e.value = t_e.LHS * t_e.RHS;
						}
						else if (strcmp(t_e.op,"/") == 0) {
							t_e.value = t_e.LHS / t_e.RHS;
						}

						(*ei)->argList.clear(); //Remove all elements;
						Arg a;
						a.i = t_e.value;
						if (imm)
							(*ei)->argList.push_back(new AssemblyArgument(4,a));
						else
							(*ei)->argList.push_back(new AssemblyArgument(1,a)); 
					
					}
				}
			}
		}

	}
}
void handle_bit(AssemblyProgram* &ass_program){
	list<AssemblyArgument*>::iterator ai;
	list<AssemblyLine*>::iterator li;
	list<AssemblyExpression*>::iterator ei;
	list<AssemblyLabel*>::iterator lbi;
	if (ass_program){
		for(lbi = ass_program->labelList->begin();lbi != ass_program->labelList->end(); lbi++){
			for(li = (*lbi)->lineList->begin(); li != (*lbi)->lineList->end(); li++){
				if(if_exist((*li)->name, bit, btsize)){
					if ((*li)->expList->size() > 0){
						AssemblyExpression* temp_expr = (*li)->expList->front();
						if(temp_expr->argList.size()>0){
							AssemblyArgument* temp_arg = temp_expr->argList.front();
							int rand_value = rand() % 1000 + 100;
							int result = 1;
							switch(temp_arg->kind){
								case 6: //ID
									if(!if_exist(temp_arg->value.c,registers,rsize)){
										if(!if_defined(temp_arg->value.c)){
											undefined[temp_arg->value.c] = rand_value;
										}	
										result = int_defined(temp_arg->value.c);
									}
									
									break;
								case 8: //BIT
									if(!if_defined(temp_arg->value.c)){
										undefined[temp_arg->value.c] = rand_value;
									}	
										result = int_defined(temp_arg->value.c);
									break;
								default:
									break;
							}
							Arg a;
							a.i = result;
							temp_arg->change(1,a); 
						}
					}
				}
			}
		}

	}
}
void address_label(AssemblyProgram* &ass_program){
	list<AssemblyLabel*>::iterator lbi;
	unsigned int last_address = start_address;
	if (ass_program){
		for(lbi = ass_program->labelList->begin();lbi != ass_program->labelList->end(); lbi++){
			(*lbi)->address = last_address;
			last_address = (*lbi)->address + (*lbi)->lineList->size()*4;
		}
	}
}
AssemblyProgram* AssHandler::process(const char* name) {
	std::cout << "------START PARSING------\n";
	handle(name);
	std::cout << "-----PARSING RESULT------\n";
	//print_ass(ass_program);
	std::cout << "-----HANDLE BINARY EXPRESSION---\n";
	handle_binary(ass_program);
	std::cout << "-----HANDLE BIT ---\n";
	handle_bit(ass_program);
	//print_ass(ass_program);
	std::cout << "-----APPENDING JUMP AND BRANCH STATEMENTS---\n";	
	append_jumps(ass_program);
	print_ass(ass_program);
	std::cout << "---ADDRESSING LABEL---\n";
	address_label(ass_program);
	list<AssemblyLabel*>::iterator lbi;
	if (ass_program){
		for(lbi = ass_program->labelList->begin();lbi != ass_program->labelList->end(); lbi++){
			std::cout << (*lbi)->name << " : " << (*lbi)->address << std::endl;
		}
	}
	return ass_program;	
}