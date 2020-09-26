/**
* TCP Client Program
* This program creates a socket, connects to a server, and recieves a message.
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
	
	// create socket
	int netSock = socket(AF_INET, SOCK_STREAM, 0);
	
	// assign socket address and port #
	struct sockaddr_in servAddr;
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons(40000);
	servAddr.sin_addr.s_addr = INADDR_ANY;
	
	// connect to remote socket
	int connStat = connect(netSock, (struct sockaddr *) &servAddr, sizeof(servAddr));
	
	// test connection
	if (connStat == -1){
		printf("Connection to server failed.");
	}
	
	// recieve data from remote socket
	char response[256];
	recv(netSock, &response, sizeof(response), 0);
	
	// print out server response
	printf("The server sent the response: %s\n", response);
	
	return 0;
}