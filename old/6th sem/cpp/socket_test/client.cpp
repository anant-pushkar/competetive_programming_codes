#include <iostream>
#include <cstring>     
#include <sys/socket.h> 
#include <netdb.h>      
#include <unistd.h>
int main()
{

	int status;
	struct addrinfo host_info;       
	struct addrinfo *host_info_list; 

	memset(&host_info, 0, sizeof host_info);

	std::cout << "Setting up the structs..."  << std::endl;

	host_info.ai_family = AF_UNSPEC;     
	host_info.ai_socktype = SOCK_STREAM; 

	status = getaddrinfo("localhost", "5556", &host_info, &host_info_list);
	if (status != 0)  std::cout << "getaddrinfo error" << gai_strerror(status) ;
	
	std::cout << "Creating a socket..."  << std::endl;
	int socketfd ; 
	socketfd = socket(host_info_list->ai_family, host_info_list->ai_socktype, 
	host_info_list->ai_protocol);
	if (socketfd == -1)  std::cout << "socket error " ;
	
	std::cout << "Connect()ing..."  << std::endl;
	status = connect(socketfd, host_info_list->ai_addr, host_info_list->ai_addrlen);
	if (status == -1)  std::cout << "connect error" ;
	
	std::cout << "send()ing message..."  << std::endl;
	char msg[100] = "hello there!";
	int len;
	ssize_t bytes_sent;
	len = strlen(msg);
	bytes_sent = send(socketfd, "hey there", len, 0);
	
	std::cout << "Waiting to recieve data..."  << std::endl;
	ssize_t bytes_recieved;
	char incoming_data_buffer[1000];
	bytes_recieved = recv(socketfd, incoming_data_buffer,1000, 0);
	if (bytes_recieved == 0) std::cout << "host shut down." << std::endl ;
	if (bytes_recieved == -1)std::cout << "recieve error!" << std::endl ;
	std::cout << bytes_recieved << " bytes recieved :" << std::endl ;
	std::cout << incoming_data_buffer << std::endl;
	
	std::cout << "Receiving complete. Closing socket..." << std::endl;
	freeaddrinfo(host_info_list);
	close(socketfd);
    
}    