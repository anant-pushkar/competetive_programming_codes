'''
Project name : functor_magic
Created on : Thu Jul 24 18:42:43 2014
Author : Anant Pushkar
overiding __call__ method to induce functor like behaviour
'''
import sys
debug_mode = len(sys.argv)>1 and sys.argv[1]=="DEBUG"
def debug(msg):
	if debug_mode:
		print msg

class Foo:
	def bar(self):
		def __call__(self, *args, **kwargs):
		print "This is inside Foo.bar()"
		
	def put_starter(self,fn):
		self.bar.__call__ = fn
	
f = Foo()
def starter():
	print "This is from starter"
f.put_starter(starter)