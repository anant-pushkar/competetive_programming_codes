from tkinter import *
def draw(cmd):
	cmd=cmd.split()
	if cmd[0]=="point":
		x=int(cmd[1])
		y=int(cmd[2])
		width=3
		color="black"
		txt=""
		if len(cmd)>3 :
			width=int(cmd[3])
			if len(cmd)>4:
				color=cmd[4]
		canvas.create_oval(int((x+width)*r), 
						int((y+width)*r),
						int((x-width)*r), 
						int((y-width)*r) , 
						fill=color)
	if cmd[0]=="txt":
		x=int(cmd[1])
		y=int(cmd[2])
		txt=cmd[3]
		if len(cmd)>4:
			fill=cmd[4]
		canvas.create_text(int(x*r), 
							int(y*r), 
							text=txt)
	if cmd[0]=="line":
		x1=int(cmd[1])
		y1=int(cmd[2])
		x2=int(cmd[3])
		y2=int(cmd[4])
		color="black"
		if len(cmd)>5:
			color=cmd[5]
		canvas.create_line(int(x1*r),
						int(y1*r),
						int(x2*r),
						int(y2*r),
						fill=color)  
root = Tk()
root.title("Graphical Testing tool");    

canvas = Canvas(width=300, height=300, bg='white')  
canvas.pack(expand=YES, fill=BOTH)

r=0.5
while 2>1:
	draw(input())

