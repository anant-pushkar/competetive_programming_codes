'''
Project name : dependency_checker
Created on : Thu Jun 26 11:17:39 2014
Author : Anant Pushkar
plugin for jarvis to check and install dependencies
'''
import subprocess
import os
class DependencyChecker:
	def __init__(self,libname):
		self.libname = libname
		try:
			dpkg_output = subprocess.check_output(['dpkg', '-s', self.libname])
			self.is_installed = "Package: "+self.libname+"\nStatus: install ok installed" in dpkg_output
		except:
			self.is_installed = False
	
class DependencySet:
	def __init__(self,dependency_list):
		self.dependency_list = []
		for dependency in dependency_list:
			self.dependency_list.append(DependencyChecker(dependency))
		
	def install_unmet(self):
		unmet = [dependency.libname for dependency in self.dependency_list if not dependency.is_installed]
		print "running","sudo apt-get install "+" ".join(unmet)
		os.system("sudo apt-get install "+" ".join(unmet))

T = int(raw_input())
arr = []
for t in range(T):
	dpnc = str(raw_input())
	arr.append(dpnc)
dSet = DependencySet(arr)
dSet.install_unmet()