#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>	//inet_addr

#include "lapsrv_defs.h" // project definitions

int main(int argc, char** argv)
{
  int srv_socket, cli_socket;
  size_t sin_size = sizeof(struct sockaddr_in);
	struct sockaddr_in srv_addr, cli_addr;

  printf("\n");
  printf("-- LAP Server: Initializing. --\n");
	
	// Create socket
	srv_socket = socket(AF_INET , SOCK_STREAM , 0);
	if (srv_socket == -1)
	{
		perror("Could not create socket");
	}
  printf("[I] Socket created. FD is %d.\n", srv_socket);
	
	// Prepare the sockaddr_in structure  
	srv_addr.sin_family = AF_INET;
	srv_addr.sin_addr.s_addr = INADDR_ANY;
	srv_addr.sin_port = htons(LAPSRV_SERVER_PORT);
	
	// Binds the socket to LAPSRV_SERVER_PORT
  printf("[I] Binding socket to port %d...\n", LAPSRV_SERVER_PORT);
	if (bind(srv_socket, (struct sockaddr *)&srv_addr, sizeof(struct sockaddr)) < 0)
	{
    perror("Could not bind.");
	}
	printf("[I] Socket bound to port %d.\n", LAPSRV_SERVER_PORT);
	
	// Listen
  printf("[I] Start listening on port %d...\n", LAPSRV_SERVER_PORT);
	listen(srv_socket , 3);
  printf("[I] Listening on port %d.\n", LAPSRV_SERVER_PORT);
	
	// Accept and incoming connection
	printf("[I] Waiting for incoming connections...\n");
	cli_socket = accept(srv_socket, (struct sockaddr *)&cli_addr, (socklen_t*)&sin_size);
	if (cli_socket < 0)
	{
		perror("[E] Accept failed.");
	}
	
	printf("[I] Connection accepted. Client FD is %d\n", cli_socket);

  close(cli_socket);
  shutdown(srv_socket, SHUT_RDWR);

	return 0;
}