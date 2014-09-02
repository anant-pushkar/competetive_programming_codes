/*
Project name : networks_assignment #3
Created on : Sat Mar  1 15:51:50 2014
Author : Anant Pushkar
Computer Networks Assignment 3
Server 
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
#define MAXPID 1000
using namespace std;
bool debug=false;
int idx;
class Session{
	string file;
	XWindowAttributes attr;
	Display *display;
	int revert;
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
	Window focus,toplevel_parent_of_focus;
	int zoom,page;
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
		printf("%d %d %d %d\n", attr.x , attr.y, attr.width, attr.height);
	}
	
	string get_name(){
		return file;
	}
	
	char* get_info(){
		//display= XOpenDisplay(NULL);
		//XGetInputFocus(display,&focus,&revert);
		XGetWindowAttributes(display, toplevel_parent_of_focus, &attr);
		
		char*msg=(char*)calloc(1000,sizeof(char));
		printf("%d %d %d %d \n", attr.x , attr.y, attr.width, attr.height);
		sprintf(msg,"%s %d %d %d %d %d %d",file.c_str(),attr.x,attr.y,attr.height,attr.width,zoom,page);
		return msg;
	}
};
deque< pair<int,Session> > sessions;
void zoomin(int ){
	cout<<"Zooming "<<idx<<" in"<<endl;
	sessions[idx].second.zoom--;
}
void zoomout(int){
	cout<<"Zooming "<<idx<<" out"<<endl;
	sessions[idx].second.zoom++;
}
void pageup(int){
	sessions[idx].second.page++;
}
void pagedown(int){
	sessions[idx].second.page--;
}
string show_all(){
	int nSessions=sessions.size();
	if(nSessions==0){
		return "0 sessions active\n";
	}
	stringstream stream;
	stream<<nSessions<<" session"<<(nSessions==1?"":"s")<<" active"<<endl;
	for(int i=0;i<nSessions;++i){
		stream<<sessions[i].first<<"\t"<<sessions[i].second.get_name()<<endl;
	}
	return stream.str();
}
char* get_msg(int type){
	if(type==0){
		char *msg =(char*)calloc(1000,sizeof(char));
		strcpy(msg , show_all().c_str());
		return msg;
	}else{
		return sessions[type-1].second.get_info();
	}
}
void receive(int type , int socketfd){
	int new_sd;
	struct sockaddr_storage their_addr;
	socklen_t addr_size = sizeof(their_addr);
	new_sd = accept(socketfd, (struct sockaddr *)&their_addr, &addr_size);
	if (new_sd == -1){
		cout << "listen error" << endl ;
	}

	ssize_t bytes_recieved;
	char incoming_data_buffer[1000];
	bytes_recieved = recv(new_sd, incoming_data_buffer,1000, 0);
	if (bytes_recieved == 0) cout << "host shut down." << endl ;
	if (bytes_recieved == -1) cout << "recieve error!" << endl ;
	cout << ">>"<<bytes_recieved << " bytes recieved :" << endl ;
	incoming_data_buffer[bytes_recieved] = '\0';
	cout << incoming_data_buffer << endl;
	if(strcmp(incoming_data_buffer,"open")==0){
		FILE *fptr = fopen(sessions[type-1].second.get_name().c_str(),"r");
		struct stat stat_buf ;
		fstat(fileno(fptr),&stat_buf);
		//ssize_t size = sendfile(new_sd,fd,0,stat_buf.st_size);
		
		int FileSize=stat_buf.st_size , SizeCheck=0;
		cout<<"Sending filesize : "<<FileSize<<endl;
		stringstream ss;
		ss<<FileSize;
		
		ssize_t bytes_sent;
		bytes_sent = send(new_sd, ss.str().c_str(), ss.str().size(), 0);
		
		char* mfcc=(char*)calloc(1500,sizeof(char));
		while(SizeCheck < FileSize){
			int Read = fread(mfcc, sizeof(char), 1499, fptr);
			send(new_sd, mfcc, Read, 0);
			SizeCheck += Read;
		}
		
	}else{
		int len;
		ssize_t bytes_sent;
		char*msg= get_msg(type);
		len = strlen(msg);
		bytes_sent = send(new_sd, msg, len, 0);
		free(msg);
	}
	close(new_sd);
}
void communicate(int type,int p){
	int status;
	struct addrinfo host_info;
	struct addrinfo *host_info_list;
	
	memset(&host_info, 0, sizeof(host_info));
	
	host_info.ai_family = AF_UNSPEC;
	host_info.ai_socktype = SOCK_STREAM; 
	host_info.ai_flags = AI_PASSIVE;  
	
	char port[6];
	sprintf(port,"%d",p);
	status = getaddrinfo(NULL, port, &host_info, &host_info_list);
	if (status != 0)  cout << "getaddrinfo error" << gai_strerror(status) << endl;

	int socketfd ;
	socketfd = socket(host_info_list->ai_family, host_info_list->ai_socktype,host_info_list->ai_protocol);
	if (socketfd == -1)  cout << "socket error " << endl;

	int yes = 1;
	status = setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));
	status = bind(socketfd, host_info_list->ai_addr, host_info_list->ai_addrlen);
	if (status == -1)  cout << "bind error" << endl ;

	while(1){
		status =  listen(socketfd, 5);
		if (status == -1)  cout << "listen error" << endl ;
		receive(type,socketfd);
	}
	
	freeaddrinfo(host_info_list);
	close(socketfd);
}
void *listen(void *threadid){
	communicate(0,BASEPORT);
}
void broadcast(int port){
	communicate(port-BASEPORT,port);
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	pthread_t thread;
	cout<<"Welcome. Use the following commands to control sessions."<<endl;
	cout<<"open xyz    : open a new session on file xyz"<<endl;
	cout<<"show        : show all active sessions"<<endl;
	cout<<"exit        : exit from process"<<endl;
	cout<<"zoom in xyz : zoom in display associated with session id xyz"<<endl;
	cout<<"zoom out xyz: zoom out display associated with session id xyz"<<endl;
	cout<<"page up xyz      : scroll up display associated with session id xyz"<<endl;
	cout<<"page down xyz    : scroll down display associated with session id xyz"<<endl;
	int rc = pthread_create(&thread, NULL, listen, (void *)0);
	string cmd,arg;
	int nSessions,base=BASEPORT+1,pid[MAXPID],index=0;
	int id;
	char sys[1000];
	while(true){
		cin>>cmd;
		if(cmd=="show"){
			cout<<">>"<<show_all();
		}
		else if(cmd=="exit")break;
		else if(cmd=="open"){
			cin>>arg;
			sessions.push_back(make_pair(base++,arg));
			if(index==MAXPID){
				cout<<"cannot open more files"<<endl;
				continue;
			}
			pid[index++]=fork();
			if(pid[index-1]==0){
				idx=base-BASEPORT-2;
				signal(SIGHUP , zoomin);
				signal(SIGINT , zoomout);
				signal(SIGUSR1 , pageup);
				signal(SIGUSR2 , pagedown);
				broadcast(base-1);
			}
		}
		else if(cmd=="zoom"){
			cin>>arg>>id;
			if(id<=BASEPORT || id>base){
				cout<<"Invalid session id"<<endl;
				continue;
			}
			stringstream ss;
			ss<<"xdotool windowactivate "<<sessions[id-BASEPORT-1].second.focus-1;
			cout<<"running : "<<ss.str();
			system(ss.str().c_str());
			ss.clear();
			if(arg=="in" || arg=="out"){
				stringstream ss2;
				ss2<<"xdotool key ctrl+"<<(arg=="out"?"plus":"minus");
				cout<<"running : "<<ss2.str();
				system(ss2.str().c_str());
				if(arg=="out")kill(pid[id-BASEPORT-1],SIGINT);
				else kill(pid[id-BASEPORT-1],SIGHUP);
			}else cout<<">>Invalid command"<<endl;
			
		}else if(cmd=="page"){
			cin>>arg>>id;
			if(id<=BASEPORT || id>base){
				cout<<"Invalid session id"<<endl;
				continue;
			}
			stringstream ss;
			ss<<"xdotool windowactivate "<<sessions[id-BASEPORT-1].second.focus-1;
			cout<<"running : "<<ss.str()<<endl;
			system(ss.str().c_str());
			ss.clear();
			if(arg=="up" || arg=="down"){
				stringstream ss2;
				ss2<<"xdotool key ctrl+"<<(arg=="up"?"Page_Up":"Page_Down");
				cout<<"running : "<<ss2.str()<<endl;
				system(ss2.str().c_str());
				if(arg=="up")kill(pid[id-BASEPORT-1],SIGUSR1);
				else kill(pid[id-BASEPORT-1],SIGUSR2);
			}else cout<<">>Invalid command"<<endl;
		}
		else cout<<">>Invalid command"<<endl;
	}
	for(int i=0;i<index;++i)kill(pid[i],SIGKILL);
	return 0;
}

