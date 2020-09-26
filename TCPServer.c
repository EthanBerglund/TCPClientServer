/**
* TCP Server Program
* This program creates a socket, listens for clients, and sends them a message upon connection.
* 
* @author Ethan H. M. Berglund
* @version 1.0
* @since 9-25-2020
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(){
	
	char message[256] = "You have reached the server!";
	
	// create socket
	int serSock = socket(AF_INET, SOCK_STREAM, 0);
	
	// assign socket address and port #
	struct sockaddr_in servAddr;
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons(40000);
	servAddr.sin_addr.s_addr = INADDR_ANY;
	
	// bind socket to specified IP and Port
	bind(serSock, (struct sockaddr *) &servAddr, sizeof(servAddr));
	
	// listen for connections
	listen(serSock, 4);
	
	// accept client socket to write message to
	int cliSock = accept(serSock, NULL, NULL);
	
	// send message to client
	send(cliSock, message, sizeof(message), 0);
	
	return 0;
}