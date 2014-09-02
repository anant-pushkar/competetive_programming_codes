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
#include<vector>  
#include <sys/socket.h> 
#include <netdb.h>      
#include <unistd.h>
#include<sstream>
#define BASEPORT 4000
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
	
	freeaddrinfo(host_info_list);
	close(socketfd);
	
	return string(incoming_data_buffer);
}
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
		while(true){
			response=communicate(arg,"show");
			cout<<response<<endl;
			sleep(3);
		}
	}else if(cmd=="exit"){
		return 0;
	}else{
		cout<<"Invalid command. Exiting"<<endl;
		return 0;
	}
	
	return 0;
}

