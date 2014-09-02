import os
import testCases
import subprocess

print '\033[95m'
print "Creating input files "
cmd="python test_modules/print_input.py"
os.system(cmd)

tests=testCases.getTests()
for i in range(len(tests)):
	print '\033[94m'
	print "\nrunning "+tests[i].description
	cmd="./main < test_suite_"+str(i+1)+".txt | python test_modules/filter.py | python test_modules/examiner.py "+str(i)
	print '\033[97m'
	exit_code=subprocess.Popen(['python','-c','import os; os.system("'+cmd+'")']).wait()
	print '\033[94m'
	print "Exit code : "+str(exit_code)
