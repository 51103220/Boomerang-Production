#include "AssParser.cpp"
#include <fstream>
#include <cstddef>         
ofstream myfile;
using namespace std;
unsigned int start_address = 66676;
const int jsize = 2;
const int bsize = 8;
const int btsize = 4;
const int rsize = 32;
const char *jmps[jsize] = {
                   "SJMP",
                   "JMP",
 };
const char *brs[bsize] = {
                   "JNB",
                   "JB",
                   "JNC",
                   "JC",
                   "JZ",
                   "JNZ",
                   "CJNE",
                   "DJNZ"
 };
const char *bit[btsize] = {
				"CLR",
                "SETB",
                "JNB",
                "JB"
};
const char *registers[rsize] = {
				"R0",
				"R1",
				"R2",
				"R3",
				"R4",
				"R5",
				"R6",
				"R7",
				"A",
				"B",
                "C",
                "DPTR",
                "AB",
                "P0",
                "P1",
                "P2",
                "P3",
                "SP",
                "DPL",
                "DPH",
                "PCON",
                "TCON",
                "TMOD",
                "TL0",
                "TL1",
                "TH1",
                "TH0",
                "SCON",
                "SBUF",
                "IE",
                "IP",
                "PSW"
};
std::map<char*,int> undefined;
std::map<char *, char *> defined;
list<const char*> loop_labels;

bool check_loop(const char* name){
	list<const char*>::iterator i;
	for(i = loop_labels.begin(); i!= loop_labels.end(); ++i){
		if(strcmp(name, (*i)) == 0)
			return true;
	}
	return false;
}
void init_defined(const char* name){
	std::string path(name);
	std::size_t found = path.find_last_of("/\\");
	std::string define_path;
	if (found != -1 ){
		define_path.append(path.substr(0,found)).append("/defines"); 
	}
	const char *file = define_path.c_str();
	FILE *myfile = fopen(file, "r");
	if (!myfile) {
		std::cout << "DEFINES file does not exist, create one if needed!" << std::endl;
	}
	else{
		std::cout << "DEFINES exists, start Parsing...\n";
		std::string line;
		std::ifstream input(file);
		std::string l;
		
	    while( std::getline(input, line)) {
	       found = line.find_last_of(":");
	       l = line.substr(0,found);
	       char *key = new char[l.length() + 1];
		   strcpy(key, l.c_str());
		
	       l = line.substr(found+1);
	       char *value = new char[l.length() + 1];
		   strcpy(value, l.c_str());
		   defined[key] = value;
	    }

	}
	fclose(myfile);
	std::map<char *, char *>::iterator i;
	for(i = defined.begin(); i != defined.end(); ++i){
		std::cout << i->first << ":" << i->second << std::endl;
	}
	/*defined["Option"] = "R1";
	defined["someFlag"] = "R2";
	defined["DRAB"] = "ACC.1";
	defined["CARB"] = "ACC.3";
	defined["OPTIONS"] = "R7";
	defined["SMPDUP"] = "ACC.1";
	defined["SLVFLGMAP"] = "R6";
	defined["MASTER"] = "ACC.2";
	defined["XROVLY"] = "R5";
	defined["SIMP"] = "ACC.4";
	defined["SYSFLGMAP"] = "R4";
	defined["BTS"] = "P0";
	defined["whatever"] = "R3";*/
}
char * defined_value(char * name){
	std::map<char *,char *>::iterator it;
	for(it = defined.begin();it != defined.end(); ++it ){
		if (strcmp(it->first,name) == 0)
			return it->second;
	}
	return NULL;
}
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
	myfile << "\t\t\t\t\t ";
	for(ai = expr->argList.begin(); ai != expr->argList.end(); ai++ ){
			switch ((*ai)->kind){
				case 0:
				case 7:
				case IMMEDIATE_ID:
				case 6:
				case INDIRECT:
					std::cout << (*ai)->value.c << " ";
					myfile << (*ai)->value.c << " ";
					break;
				case DIRECT_FLOAT:
					std::cout << (*ai)->value.f << " ";
					myfile << (*ai)->value.f << " ";
					break;
				case IMMEDIATE_INT:
				case DIRECT_INT:
					std::cout << (*ai)->value.i << " ";
					myfile << (*ai)->value.i << " ";
					break;
				case 8:
					std::cout << (*ai)->value.c  << " ";
					myfile << (*ai)->value.c  << " ";
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
			myfile << (*lbi)->name << std::endl;
			std::cout << "\t Number of lines: " << (*lbi)->lineList->size() << std::endl;
			for(li = (*lbi)->lineList->begin(); li != (*lbi)->lineList->end(); li++ ){
				std::cout << "\t\t Offset " << (*li)->offset << std::endl;
				std::cout << "\t\t Opcode " << (*li)->name << std::endl;
				myfile << "\t\t" << (*li)->name << std::endl;
				std::cout << "\t\t\t Number of Expression: " << (*li)->expList->size() << std::endl;
				for(ei = (*li)->expList->begin(); ei != (*li)->expList->end(); ei++ ){
					std::cout << "\t\t\t\t Number of Arguments:" << (*ei)->argList.size() << std::endl;
					print_arg((*ei));
					std::cout << std::endl;
					myfile << std::endl; 
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
							
							if(strcmp(label_name,(*lbi)->name) != 0){ // Check for Loop - NON LOOP			
								list<AssemblyLine*> *temp_list = iterate_label(ass_program, label_name);
								(*li)->offset = temp_list->size();
								(*lbi)->lineList->insert(++li,temp_list->begin(),temp_list->end());
								
								advance(li,temp_list->size()+1);
							}
							else{ // LOOP
								std::cout << "LOOP LABEL: " << (*lbi)->name << std::endl;
								loop_labels.push_back((*lbi)->name);
								(*li)->offset = -1;
								++li;
							}
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
				else if (if_exist((*li)->name, brs, bsize)){ // APPEND CONDITION
						if (!(*li)->checked){
							char * label_name;
							(*li)->checked = true;
							if((*li)->expList->size() >= 1){
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
void loop_offset(AssemblyProgram* &ass_program){
	list<AssemblyArgument*>::iterator ai;
	list<AssemblyLine*>::iterator li;
	list<AssemblyExpression*>::iterator ei;
	list<AssemblyLabel*>::iterator lbi;
	if (ass_program){
		for(lbi = ass_program->labelList->begin();lbi != ass_program->labelList->end(); lbi++){
			if(check_loop((*lbi)->name)){
				int count = 0;
				for(li = (*lbi)->lineList->begin(); li != (*lbi)->lineList->end(); ++li){
					if ((*li)->offset == -1){
						(*li)->offset = (-1)*count;
					}
					++count;
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
					{
						for(ai = (*ei)->argList.begin(); ai != (*ei)->argList.end(); ai++ ){
							switch ((*ai)->kind){
								case 5: //IMMEDIATE ID
								case 6: // ID
									if(!if_exist((*ai)->value.c,registers,rsize)){
										char * n = defined_value((*ai)->value.c);
										if (n)
											(*ai)->value.c = n;
									}
									break;
								default:
									break;
							}
						}
					
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
							bool check = false;
							AssemblyArgument* temp_arg = temp_expr->argList.front();

							switch(temp_arg->kind){
								case 6: //ID
								{	std::string n(temp_arg->value.c);
									if (n != "A" && n != "C" ){
										temp_arg->change(8,temp_arg->value);
										check = true;
									}
									break;
								}
								case 8: //BIT
									check = true;
									break;	
								default:
									break;
							}
							//---WHOLE STUFF FOR BIT HANDLING
							if (check){
								std::string temp(temp_arg->value.c);
								char c =  temp.at(temp.size()-1);
								int num = c - '0';
								temp =  temp.substr(0, temp.size()-1);
								temp =  temp.substr(0, temp.size()-1);
								if (temp == "ACC")
									temp = "A";
								char *cstr = new char[temp.length() + 1];
								strcpy(cstr, temp.c_str());
								Arg a;
								a.bit.reg = cstr;
								a.bit.pos = num;
								temp_arg->change(8,a);

								std::list<char*>::iterator br;
								bool existed = false;
        						for (br = ass_program->bitReg.begin(); br != ass_program->bitReg.end(); ++ br ){
        							if(std::string(cstr) == std::string((*br))){
        								existed = true;
        								break;
        							}
        						}
        						if (!existed)
									ass_program->bitReg.push_back(cstr);
							}
							//-------------------------------
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

	std::cout << "------START PARSING------\n" << name << std::endl;
	handle(name);
	std::cout << "-----HANDLE BINARY EXPRESSION---\n";
	init_defined(name);
	handle_binary(ass_program);

	std::cout << "-----HANDLE BIT ---\n";
	handle_bit(ass_program);

	std::cout << "-----APPENDING JUMP AND BRANCH STATEMENTS---\n";	
	append_jumps(ass_program);

	std::cout << "-----CHECK FOR LOOPS------\n";
	loop_offset(ass_program);

	myfile.open("FinalResult");
	print_ass(ass_program);
	myfile.close();

	std::cout << "---ADDRESSING LABEL---\n";
	address_label(ass_program);

	list<AssemblyLabel*>::iterator lbi;
	if (ass_program){
		for(lbi = ass_program->labelList->begin();lbi != ass_program->labelList->end(); lbi++){
			std::cout << (*lbi)->name << " : " << (*lbi)->address << std::endl;
		}
	}
	std::list<char*>::iterator br;
	if(ass_program){
		for(br = ass_program->bitReg.begin();br != ass_program->bitReg.end(); ++br){
			std::cout <<  " REGISTER IS BIT PRESENTATOR " << (*br) << std::endl;
		}
	}
	return ass_program;	
}