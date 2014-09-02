import project_interpreter as jarvis

class Interpreter(jarvis.JarvisProjectInterpreter):
	
	def __init__(self , prj):
		jarvis.JarvisProjectInterpreter.__init__(self , prj)
		
		def deploy(args):
			import os
			os.system("bash scripts/updatefile")
		self.add_trigger("deploy" , deploy , help_text="deploy app to google app engine")