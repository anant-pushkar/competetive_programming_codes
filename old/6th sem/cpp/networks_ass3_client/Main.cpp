/*
Project name : networks_assignment #3
Created on : Sat Mar  1 15:51:50 2014
Author : Anant Pushkar
Computer Networks Assignment 3
Client 
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<deque>
#include<utility>
#include<unistd.h>
#include <pthread.h>
#include<sys/socket.h>
#include<netdb.h>
#include<sstream>
#include<signal.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <X11/Xatom.h>
#include <sys/sendfile.h>
#include <sys/stat.h>
#define BASEPORT 5000
using namespace std;
bool debug=false;
string communicate(int p,string str){
	int status;
	struct addrinfo host_info;       
	struct addrinfo *host_info_list; 

	memset(&host_info, 0, sizeof host_info);

	host_info.ai_family = AF_UNSPEC;     
	host_info.ai_socktype = SOCK_STREAM; 

	char port[6];
	sprintf(port,"%d",p);
	status = getaddrinfo("localhost", port, &host_info, &host_info_list);
	if (status != 0)  std::cout << "getaddrinfo error" << gai_strerror(status) ;
	
	int socketfd ; 
	socketfd = socket(host_info_list->ai_family, host_info_list->ai_socktype, 
	host_info_list->ai_protocol);
	if (socketfd == -1)  std::cout << "socket error " ;
	
	status = connect(socketfd, host_info_list->ai_addr, host_info_list->ai_addrlen);
	if (status == -1)  std::cout << "connect error" ;
	
	ssize_t bytes_sent;
	bytes_sent = send(socketfd, str.c_str() , str.size(), 0);
	
	ssize_t bytes_recieved;
	char incoming_data_buffer[1000];
	memset(incoming_data_buffer,0,sizeof(incoming_data_buffer));
	bytes_recieved = recv(socketfd, incoming_data_buffer,1000, 0);
	if (bytes_recieved == 0) std::cout << "host shut down." << std::endl ;
	if (bytes_recieved == -1)std::cout << "recieve error!" << std::endl ;
	
	if(str=="open"){
		stringstream ss;
		ss<<p<<".pdf";
		remove(ss.str().c_str());
		
		FILE* fptr=fopen(ss.str().c_str(),"w+");
		
		int FileSize=atoi(incoming_data_buffer) , SizeCheck=0;
		cout<<"File SIze : "<<FileSize<<endl;
		char* mfcc=(char*)calloc(1500,sizeof(char));
		while(SizeCheck < FileSize){
			cout<<"size : "<<SizeCheck<<endl;
			int Received = recv(socketfd, mfcc, 1499, 0);
			fwrite(mfcc, 1, Received, fptr);
			SizeCheck += Received;
			if(Received==0)break;
		}
		
		fclose(fptr);
		return ss.str();
	}
	
	freeaddrinfo(host_info_list);
	close(socketfd);
	
	return string(incoming_data_buffer);
}
class Session{
	string name;
	string file;
	XWindowAttributes attr;
	Display *display;
	Window focus,toplevel_parent_of_focus;
	int revert;
	int zoom,page;
	Window get_toplevel_parent(Display * display, Window window){
		Window parent;
		Window root;
		Window * children;
		unsigned int num_children;

		while (1) {
			if (0 == XQueryTree(display, window, &root,
					&parent, &children, &num_children)) {
				fprintf(stderr, "XQueryTree error\n");
				abort(); //change to whatever error handling you prefer
			}
			if (children) { //must test for null
				XFree(children);
			}
			if (window == root || parent == root) {
				return window;
			}
			else {
				window = parent;
			}
		}
	}
public:
	~Session(){
		remove(file.c_str());
	}
	Session(string name):
	file(name),
	zoom(0),
	page(0){
		string arg="evince -p 0 "+name+"&";
		system(arg.c_str());
		sleep(1);
		display= XOpenDisplay(NULL);
		XGetInputFocus(display,&focus,&revert);
		toplevel_parent_of_focus = get_toplevel_parent(display, focus);
		XGetWindowAttributes(display, toplevel_parent_of_focus, &attr);
		printf("%d %d %d %d \n", attr.x , attr.y, attr.width, attr.height);
	}
	void adjust(string response){
		stringstream ss(response);
		string name;
		int x1,y1,w1,h1,z,p;
		ss>>name>>x1>>y1>>h1>>w1>>z>>p;
		
		XGetWindowAttributes(display, toplevel_parent_of_focus, &attr);
		cout<<"wid : "<<focus-1<<endl<<attr.x<<" "<<attr.y<<" "<<attr.width<<" "<<attr.height<<" "<<zoom<<" "<<page<<endl;
		
		stringstream ss1("");
		ss1<<"xdotool windowactivate "<<focus-1;
		cout<<"running : "<<ss1.str()<<endl;
		system(ss1.str().c_str());
		stringstream ss2("");
		ss2<<"xdotool windowmove "<<focus-1<<" "<<x1<<" "<<y1;
		cout<<"running : "<<ss2.str()<<endl;
		system(ss2.str().c_str());
		
		cout<<"running : "<<ss1.str()<<endl;
		system(ss1.str().c_str());
		stringstream ss3("");
		ss3<<"xdotool windowsize "<<focus-1<<" "<<w1<<" "<<h1;
		cout<<"Executing : "<<ss3.str()<<endl;
		system(ss3.str().c_str());
		
		while(z!=zoom){
			cout<<"running : "<<ss1.str()<<endl;
			system(ss1.str().c_str());
			string str="xdotool key ctrl+";
			str=str+(z<zoom?"minus":"plus");
			//str=str+" --sync";
			cout<<"Execiting : "<<str<<endl;
			system(str.c_str());
			zoom+=z<zoom?-1:+1;
		}

		while(p!=page){
			string str="xdotool key ctrl+";
			str=str+(p<page?"Page_Down":"Page_Up");
			//str=str+" --sync";
			cout<<"Execiting : "<<str<<endl;
			system(str.c_str());
			page+=p<page?-1:+1;
		}
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	
	string response=communicate(BASEPORT,"show");
	cout<<response<<endl;
	
	cout<<"Welcome. Use the following commands to control sessions."<<endl;
	cout<<"open xyz : open session number xyz"<<endl;
	cout<<"exit     : exit from process"<<endl;
	
	string cmd;
	int arg;
	cin>>cmd;
	if(cmd=="open"){
		cin>>arg;
		if(arg<=BASEPORT){
			cout<<"Invalid session id"<<endl;
		}
		response=communicate(arg,"open");
		cout<<response<<endl;
		stringstream ss(response);
		string name;
		ss>>name;
		Session s(name);
		while(true){
			response=communicate(arg,"show");
			cout<<response<<endl;
			s.adjust(response);
			sleep(12);
		}
	}else if(cmd=="exit"){
		return 0;
	}else{
		cout<<"Invalid command. Exiting"<<endl;
		return 0;
	}
	
	return 0;
}

