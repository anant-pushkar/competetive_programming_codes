import sys
import testCases
#print 'Number of arguments:', len(sys.argv), 'arguments.'
#print 'Argument List:', str(sys.argv)
id=int(sys.argv[1])
#print "got id "+str(id) 
tests=testCases.getTests()
check=1
for i in range(len(tests[id].instances)):
	lines=tests[id].instances[i].outputStr.split("\n")
	for j in range(len(lines)):
		if lines[j]=="":
			break
		try:
			actual=str(raw_input())
			if lines[j]=='?':
				print '\033[34m'+'Showing output for '+tests[id].description+" at "+tests[id].instances[i].description
				print "Input : \n"+tests[id].instances[i].inputStr
				print "line #"+str(j+1)
				print "Got :"+actual
				print '\033[0m'
				continue
			if actual!=lines[j]:
				print '\033[91m'+tests[id].description+" failed at "+tests[id].instances[i].description
				print "Input : \n"+tests[id].instances[i].inputStr
				print "Expected : \n"+tests[id].instances[i].outputStr
				print "Mismatch in line #"+str(j+1)
				print "Got :"+actual
				print '\033[0m'
				check=0
				break
		except (EOFError) :
			check=-1
			print '\033[91m'
			print "unexpected end of output stream in "+tests[id].description+" at "+tests[id].instances[i].description
			print "Input : \n"+tests[id].instances[i].inputStr
			print "Expected : \n"+tests[id].instances[i].outputStr
			print '\033[0m'
			break
if check==1 :
	print '\033[92m'
	print tests[id].description + " passed"

