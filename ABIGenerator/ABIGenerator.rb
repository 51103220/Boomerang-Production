require 'roo'

CallSpec = Struct.new(:platform, :return,:param,:additionParam,:alias,:scratch,:preserved,:righttoleft) 
def transform_reg str
	temp = str.scan(/r(\d+)/)
	code =""
	code <<"Location::regOf(#{temp[0][0]})"
	#print code 
	return code
end
def transform_const str
	temp = str.scan(/(\d+)/)
	code = ""
	code << "new Const((int)#{temp[0][0]})"
	return code
end
def transform_reg_op str
	temp = str.scan(/(r\d+)\s*(\+|\-)\s*(\d+)/)
	#print temp
	code = ""
	code<<"(new Binary("
	code<< (temp[0][1]=='+' ? "opPlus, " : "opMinus, ")
	code<< transform_reg(temp[0][0])
	code << ", "
	code <<transform_const(temp[0][2])
	code<<")"
	code<<")"
	return code
end
def transform_mem_op str
	temp = str.scan(/m\[(r\d+\s*[+-]\s*\d+)\]/)
	#print temp
	code = ""
	code <<"Location::memOf("
	code << transform_reg_op(temp[0][0])
	code <<")"
	return code
end
#transform_mem_op "m[r3+ 10]"
def read_CallSpec
content = File.read('CallSpec')
	 
 	 machines = content.scan(/^\s*\#([^\#\{}]+)\{([^\#]+)\}/m )
 	 callSpecs = []
 	 for machine in machines
 	 	p1 = nil
 	 	p2 = []
 	 	p3 = []
 	 	p4 = nil
 	 	p5 = []
 	 	p6 = nil
 	 	p7 = nil
 	 	p8 = nil
 	 	p1 = machine[0]
 	 	assignments=machine[1].scan(/[\n\r]*([a-zA-Z_]+)[ ]*=[ ]*([a-zA-Z0-9,\[\]\+\- ]+)[\n\r]+/m)
 	 	
 	 	for assignment in assignments
 	 		#print assignment[0]  + "123"
			if assignment[0]=~/parameters/
				p3 = assignment[1].gsub(/\s+/, "").split(',') 	
			end
			if assignment[0]=~/add_params/
				p4 = assignment[1]#.gsub(/\s+/, "").split(',') 	
			end
			if assignment[0]=~/alias/
				p5 = assignment[1].gsub(/\s*,\s*/, ",").split(',')	
			end
			if assignment[0]=~/return/
				p2 = assignment[1].gsub(/\s+/, "").split(',') 	
			end	
			if assignment[0]=~/righttoleft/
				p8 = assignment[1]#.gsub(/\s+/, "").split(',')
			end
 	 	end
 	 	temp = CallSpec.new(p1, p2, p3, p4, p5, p6, p7, p8)
		#print temp
		#print "\n"
		callSpecs<<temp
 	 end
 	return callSpecs
end
#def restructure_data
#	file = Roo::Spreadsheet.open('./CallSpec.ods')
#	f = file.sheet(0) 
#	callSpecs = []
#	count = 0 
#	f.each(platforms: 'Platform', returns:'Return Value', parameters:'Parameters', addparams:'Additional Parameters',align:'Stack Alignment',scratchs:'Scratch Registers',preserveds:'Preserved Registers',calls:'Call List') do |hash|
#		if count != 0
#			p1 = hash[:platforms]
#			if hash[:returns].nil?
#				hash[:returns] = ""
#			end	
#			p2 = hash[:returns].gsub(/\s+/, "").split(',')
#			if hash[:parameters].nil?
#				hash[:parameters]=""
#			end
#			p3 = hash[:parameters].gsub(/\s+/, "").split(',')
#			#if hash[:addparams].nil?
#			#	hash[:addparams]=""
#			#end
#			#p4 = hash[:addparams].gsub(/r\d+/,"").split(' ')
#			p4 = hash[:addparams]
#			p5 = hash[:alias]
#			p6 = hash[:scratchs]
#			p7 = hash[:preserveds]
#			p8 = hash[:calls]
#			#temp = CallSpec.new(hash[:platforms],hash[:returns],hash[:parameters],hash[:addparams],hash[:align],hash[:scratchs],hash[:preserveds],hash[:calls])
#			#
#			temp = CallSpec.new(p1, p2, p3, p4, p5, p6, p7, p8)
#			callSpecs<<temp
#			
#		end
#		count=count +1
#	end
#	return callSpecs	
#end
def code_generation (specification)
	#print specification 
	#print "\n"
	#indent = 0
	code = ""
	##WRITING CODE HERE
	
	code<<"switch (prog->getFrontEndId()){\n" ##switch machine architecture
	index=0
	for machine in specification
		index=index+1
		code<<"\tcase #{machine[:platform]}:{\n"
		for i in 1..machine[:param].length
			code<<"\tbool param#{index}#{i} = false;\n"
		end
		code<<"\tbool ispara#{index} = false;\n";
		code<<"\tbool addparam#{index} = false;\n"
		i=1
		code<<"\tfor (stit = stmts.begin(); stit != stmts.end(); ++stit) {\n" #check each STMT
		code<<"\t\tStatement* s = *stit;\n"
		code<<"\t\tispara#{index}=false;\n"
		code<<"\t\tif(!s->isAssignment())\n"# Break if not an assignment
		code<<"\t\t\tcontinue;\n"
		code<<"\t\tExp *lhs = ((Assignment*)s)->getLeft();\n"
		code<<"\t\tExp* temp2;\n"
		for reg in machine[:param] ## process parameter
			temp = transform_reg(reg)
			code<<"\t\tif(((std::string)lhs->prints())==(std::string)#{temp}->prints()){\n"## process parameter using switch case
			code<<"\t\t\tispara#{index} = true;\n"
			code<<"\t\t\tparam#{index}#{i} = true;\n"
			code<<"\t\t\ttemp2 = lhs->clone();\n"
			code<<"\t\t}\n"
			i=i+1;
		end       ##end process parameter
		i=1;
		for aliasreg in machine[:alias]
			temp = transform_mem_op(aliasreg)
			code<<"\t\tif(((std::string)lhs->prints())==(std::string)#{temp}->prints()){\n"
			code<<"\t\t\tispara#{index} = true;\n"
			code<<"\t\t\tparam#{index}#{i} = true;\n"
			aliascode = transform_reg(machine[:param][i-1])
			code<<"\t\t\ttemp2 = #{aliascode};\n"
			code<<"\t\t}\n"
			i=i+1;
		end
		if !machine[:additionParam].nil?## Handle addition paramater on register x
			code<<"\t\tif("
			#check for all official params first
			for i in 1..machine[:param].length
				code<<"param#{index}#{i} && "
			end
			code<<"!addparam#{index}){\n"
			code<<"\t\t\tstit = stmts.begin();\n"
			code<<"\t\t\tc->ABIparameters.clear();\n"
			code<<"\t\t\taddparam#{index} = true;\n"
			code<<"\t\t}\n"
			code<<"\t\tif(addparam#{index} &&"
			code<<"(((std::string)lhs->prints()).find(\"#{machine[:additionParam]}\")!=std::string::npos)"
			code<<"){\n"
			#if machine[:param].length >0
			code<<"\t\t\tif(lhs->isMemOf()){\n"
			#end
			code<<"\t\t\tispara#{index} = true;\n"
			if machine[:platform] == "PLAT_PENTIUM"
				code<<"\t\t\tint offset= 0;\n"
				code<<"\t\t\tint regis = 0;\n"
				code<<"\t\t\tif(!lhs->getSubExp1()->isRegOf()){\n"
				code<<"\t\t\t\toffset= ((Const*)lhs->getSubExp1()->getSubExp2())->getInt();\n"
				code<<"\t\t\t\tregis = ((Const*)(lhs->getSubExp1()->getSubExp1()->getSubExp1()))->getInt();\n"
				code<<"\t\t\t}\n"
				code<<"\t\t\telse\n"
				code<<"\t\t\t\tregis = ((Const*)(lhs->getSubExp1()->getSubExp1()))->getInt();\n"
				code<<"\t\t\toffset = offset + 4;\n"
				code<<"\t\t\ttemp2=Location::memOf((new Binary(opPlus, Location::regOf(regis), new Const(offset))));\n"


			else
				code<<"\t\t\ttemp2 = lhs->clone();\n"
			end
			code<<"\t\t\t}\n"
			code<<"\t\t}\n"
		end
		code<<"\t\tif (ispara#{index}){\n" ##Add to paralist if this check is true
		#code<<"\tcount ++;\n"
		#code<<"\t\t\tExp* temp2 = lhs->clone();"
		code<<"\t\t\tstd::list<Exp*>::iterator eit;\n"
		code<<"\t\t\teit=c->ABIparameters.begin();\n"
		code<<"\t\t\tc->ABIparameters.insert(eit,temp2);\n"
		code<<"\t\t}\n"## finish adding to paralist
		code<<"\t}\n"#END check each STMT
		
		code<<"\tbreak;}\n"##break after each type of machine
	end
	code<<"}\n" ##Finish machine architecture
	###FINISH WRITING CODE AND PUSH TO FILE
	@content = code
	write_to_output "test.cpp"
end

@content
def write_cpp_file 
	 mfile=""
	 indent = 0;
	File.open("procABI.m").each do |line|
		mfile<<line
		if line =~ /.*{.*/
			indent=indent+1
			#print line
		end
		if line =~ /.*}.*/
			indent=indent-1
		end
		if line =~ /\/\/##@@.+/
			indentstr="";
			#print indent
			for temp in 1..indent
				indentstr<<"\t"
			end
			@content.each_line do |linecode|
				mfile<<indentstr
				mfile<<linecode	
			end
		end
	end
	@content=mfile
	write_to_output "test.cpp"
end

def write_to_output file
	File.open(file, "w") do |f|
		f.puts @content
	end
end

 spec = read_CallSpec				
 #spec2 = restructure_data #read calling convention specification from spec file
 #print spec
 #print "\n"
 #print spec2
 code_generation spec # generate code from calling spec
 write_cpp_file #detect and push code into cpp file
