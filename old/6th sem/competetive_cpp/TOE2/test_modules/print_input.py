import testCases
tests=testCases.getTests()
for i in range(len(tests)):
	print "creating files for "+tests[i].description
	inputStr=""
	#inputStr=inputStr+str(len(tests[i].instances))+"\n"
	for j in range(len(tests[i].instances)):
		inputStr=inputStr+tests[i].instances[j].inputStr+"\n"
	inputStr=inputStr+"end\n"
	f=open("test_suite_"+str(i+1)+".txt","w+")
	f.write(inputStr)
	f.close()
	
	
