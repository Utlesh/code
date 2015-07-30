/**
 * File Name: ServerUtility.c
 * Author:    Trevor Hodde
 * This file sets up various types of sockets for the server.
 * I probably could have done it more efficiently, but I was
 * short on time...
 */

#include "Server.h"

// This function sets up the server and initializes all the
// variables it needs to run
void initServer(int port) {
	//Initialize protocol type
	memset(protocol_type, 0, NAME_SIZE);
	//Initialize protocol method
	memset(protocol_method, 0, NAME_SIZE);
	//Initialize client address buffer
	memset(rtp_address, 0, INET6_ADDRSTRLEN);

	//Initialize server status
	status = INIT;
	//Initialize server session id
	session_id = 0;
	//Initialize the range number (range_end = -1 means infinite)
	range_start = 0;
	range_end = -1;

	//Initialize client rtp port and rtcp port number
	client_rtp_port = 0;
	client_rtcp_port = 0;
	//Initialize server rtp port number
	server_rtp_port = port;

	return;
}

int setupServerTCPSocket(const char *service) {
	struct addrinfo address_criteria;
	struct addrinfo *server_address;
	struct addrinfo *address;
	struct sockaddr_storage local_address;
	socklen_t address_size;	
	int server_socket = -1;
	int return_value;
	
	//Construct the server address structure
	memset(&address_criteria, 0, sizeof(address_criteria));	//zero the address_criteria
	address_criteria.ai_family = AF_UNSPEC;		//any address family
	address_criteria.ai_flags = AI_PASSIVE;		//accept on any address/port
	address_criteria.ai_socktype = SOCK_STREAM;	//only stream sockets
	address_criteria.ai_protocol = IPPROTO_TCP;	//only tcp protocol
	
	//Get IP address information
	return_value = getaddrinfo(NULL, service, &address_criteria, &server_address);
	//Success returns zero
	if (return_value != 0) {
		perror("getaddrinfo() failed");
	}
	
	//Create socket for incoming connections
	for (address = server_address; address != NULL; address = address->ai_next) {
		//Initialize the server socket
		server_socket = -1;
		//Create socket for incoming connections
		server_socket = socket(server_address->ai_family, server_address->ai_socktype, server_address->ai_protocol);
		//if socket creation failed, try next address in the list
		if (server_socket < 0) {
			continue;
		}
		
		//Bind to the server local address and set socket to the list
		if ((bind(server_socket, server_address->ai_addr, server_address->ai_addrlen) == 0) && 
				(listen(server_socket, MAX_PENDING) == 0)) {
			//Get address size
			address_size = sizeof(local_address);
			//Get socket name
			if (getsockname(server_socket, (struct sockaddr*)&local_address, &address_size) < 0) {
				perror("getsockname() failed");
			}

			fputs("Binding to ", stdout);
			printSocketAddress((struct sockaddr*)&local_address, stdout, false);
			fputc('\n', stdout);
			//Bind and list successful
			break;
		}
		//Close and try again
		close(server_socket);
	}
	//Free address list allocated by getaddrinfo()
	freeaddrinfo(server_address);
	
	return server_socket;
}

UDP_SOCKET_INFO *setupServerUDPSocket(const char *host, const char *service) {
	UDP_SOCKET_INFO	*udp_server;	
	struct addrinfo	address_criteria;
	struct addrinfo	*server_address;
	int return_value;

	//Initialize _udp_socket_info structure node
	udp_server = (UDP_SOCKET_INFO*)malloc(sizeof(UDP_SOCKET_INFO));
	//Tell the system what kind of address info we want
	memset(&address_criteria, 0, sizeof(address_criteria));	//zero the address_criteria
	address_criteria.ai_family = AF_UNSPEC;		//any address family
	address_criteria.ai_socktype = SOCK_DGRAM;	//only datagram sockets
	address_criteria.ai_protocol = IPPROTO_UDP;	//only UDP protocol

	//Get address
	return_value = getaddrinfo(host, service, &address_criteria, &server_address);
	//Success returns zero
	if (return_value != 0) {
		perror("getaddrinfo() failed");
	}

	//Create socket for connecting the server
	for (udp_server->address = server_address; udp_server->address != NULL; udp_server->address = udp_server->address->ai_next){
		//Initialize the server socket
		udp_server->socket = -1;
		//Create a unreliable, datagram socket using UDP
		udp_server->socket = socket(udp_server->address->ai_family,
					udp_server->address->ai_socktype,
					udp_server->address->ai_protocol);

		//Socket creation failed
		if (udp_server->socket < 0) {
			continue;
		}
		else {
			break;
		}

		//Socket creation failed and close socket
		close(udp_server->socket);
	}

	//Free addrinfo allocated in getaddrinfo()
	freeaddrinfo(server_address);

	return udp_server;
}

int acceptTCPConnection(int server_socket){
	struct sockaddr_storage client_address;			//client address
	socklen_t client_address_length;
	int client_socket;
	
	//Set length of client address structure
	client_address_length = sizeof(client_address);
	//Wait for a client to connect
	client_socket = accept(server_socket, (struct sockaddr*)&client_address, &client_address_length);
	if (client_socket < 0) {
		perror("accept() failed");
	}
	
	//print the socket address and port
	fputs("Handling client ", stdout);
	printSocketAddress((struct sockaddr*)&client_address, stdout, true);
	fputc('\n', stdout);
	
	return client_socket;
}
