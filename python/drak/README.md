drak
======
NLP term project

**This is designed to run only on Linux machines. Results on other Environments are unpredictable**

To install Dependencies : 

	sudo su
	pip install beautifulsoup4 google py-stackexchange 
	exit


To Run:

	python main.py

Input format :

	#number of test cases
	name of log file (located in logs/ folder) for each test case
	
Sample Input : 

	7
	programming error
	igraph-python
	stackexchange
	igraph_import failed
	import failed 2
	java_dependency_error2
	programming error 2

This will run DRAK in verbose mode printing each intermediate results to the terminal

