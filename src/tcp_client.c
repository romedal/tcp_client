/*
 ============================================================================
 Name        : TCP_client.c
 Author      : romedal
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include "../inc/tcp_client.h"

int main(int argc, char **argv)
{
	int sockfd, sPort=0;
	char sAddr[20] = "192.169.5.7";
	struct sockaddr_in servaddr;

	if(argc != 3)
	{
		printf("USAGE: <IPaddress> <port>");
		exit(EXIT_FAILURE);
	}
//
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	memset(&servaddr, 0x00, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_family = htons(sPort);
	inet_pton(AF_INET, sAddr, &servaddr);
	if(connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) <0)
	{
		printf("Could not connect");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}
