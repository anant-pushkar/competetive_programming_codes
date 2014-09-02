FILE STRUCTURE AND OVERALL IMPLEMENTATION OVERVIEW:

The current module has been devided into 3 levels of abstraction:
	>>Symbol Table: This includes the set of codes written and implemented
		in files symboltable.h and symboltable.c. These include the symbol
		table implementation using hashtables. The various operations specific 
		to the implementation can be found here.
		
		Files included: 
			symboltable.h
			symboltable.c
	
	>>Instruction: This is where pass1 , pass2 and macro processing algorithms have been implemented
		in the form of various modules like scanner and generator modules (to be 
		explained in detail later).
		
		Files Included:
			Instruction.h
			Instruction.c
			
	>>Main: This includes the main funcion where both  pass1 , pass2 and macro processing algorithms have been 
		implemented using the above stated modules.
		
		Files Included:
			Main.c for pass1 and pass2
			macro_processor.c for macro processing

NOTE:
	>> While writing macros, do not use whitespace between parameters to the macro or while declaring the same. 
		For example , 
			>> SWAP MACRO &I,&J   correct
			   SWAP MACRO &I, &J  incorrect
			>> SWAP I,J 	correct
			   SWAP I ,J 	incorrect
			   SWAP I, J 	incorrect
	>> The assmbler is case sensetive. So, though MUL is perfectly valid, Mul is not.
	>> The assembler allows the use of comments. It identifies two kind of comments as follows:
		1. Explicit comments: Those that start with "/" character and are not more than one line long
		2. Implicit comments: Those strings that follow the operand are implicitly considered as comments
			and removed from the intermediate code.
	>> Each token (label, Instruction or operand) in the input code is expected to be seperated by one 
		whitespace character ( ' ' or '\t' ). Though the assembler is designed to truncated any additional 
		or unwanted whitespaces, but additional whitespaces in between the commands should be avoided. 
		
			
			
			
			
			
			
			
			
			
			
			
			
			
		