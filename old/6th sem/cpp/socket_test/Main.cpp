/*
Project name : socket_test
Created on : Sat Mar  1 14:09:52 2014
Author : Anant Pushkar
test project on socket programming 
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<sys/socket.h>
#include<netdb.h>
#include <unistd.h>
using namespace std;
bool debug=false;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int status;
	struct addrinfo host_info;
	struct addrinfo *host_info_list;
	memset(&host_info, 0, sizeof(host_info));
	
	cout<<"Setting up sockets"<<endl;
	host_info.ai_family = AF_UNSPEC;
	host_info.ai_socktype = SOCK_STREAM; 
	host_info.ai_flags = AI_PASSIVE;  
	
	status = getaddrinfo(NULL, "5556", &host_info, &host_info_list);
	if (status != 0)  cout << "getaddrinfo error" << gai_strerror(status) << endl;
	
	cout<<"Creating a socket"<<endl;
	int socketfd ;
	socketfd = socket(host_info_list->ai_family, host_info_list->ai_socktype,host_info_list->ai_protocol);
	if (socketfd == -1)  cout << "socket error " << endl;
	
	cout<<"Binding socket"<<endl;
	int yes = 1;
	status = setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));
	status = bind(socketfd, host_info_list->ai_addr, host_info_list->ai_addrlen);
	if (status == -1)  cout << "bind error" << endl ;
	
	cout<<"Listening for connections"<<endl;
	status =  listen(socketfd, 5);
	if (status == -1)  cout << "listen error" << endl ;
	
	int new_sd;
	struct sockaddr_storage their_addr;
	socklen_t addr_size = sizeof(their_addr);
	new_sd = accept(socketfd, (struct sockaddr *)&their_addr, &addr_size);
	if (new_sd == -1){
		cout << "listen error" << endl ;
	    }else{
			cout << "Connection accepted. Using new socketfd : "  <<  new_sd << endl;
	    }
	
	cout << "Waiting to receive data" << endl;
	ssize_t bytes_recieved;
	char incoming_data_buffer[1000];
	bytes_recieved = recv(new_sd, incoming_data_buffer,1000, 0);
	if (bytes_recieved == 0) cout << "host shut down." << endl ;
	if (bytes_recieved == -1) cout << "recieve error!" << endl ;
	cout << bytes_recieved << " bytes recieved :" << endl ;
	incoming_data_buffer[bytes_recieved] = '\0';
	cout << incoming_data_buffer << endl;
	
	cout << "send()ing back a message..."  << endl;
	char msg[100] = "msg received\n";
	int len;
	ssize_t bytes_sent;
	len = strlen(msg);
	bytes_sent = send(new_sd, msg, len, 0);
	
	cout << "Stopping server..." << endl;
	freeaddrinfo(host_info_list);
	close(new_sd);
	close(socketfd);
	
	return 0;
}

