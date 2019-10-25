/*
 ============================================================================
 Name        : TCP_client.c
 Author      : romedal
 Version     :
 Copyright   : Your copyright notice
 Description : tcp-client in C, Ansi-style
 ============================================================================
 */


#include "../inc/tcp_client.h"

int main(int argc, char **argv)
{
	int sock;
	char send_data[1024];
	struct hostent *host;
	struct sockaddr_in server_addr;
	int  packets = 3, max_value=10;

	packets = atoi(argv[3]);
	max_value = atoi(argv[4]);
	host = gethostbyname(argv[1]);

	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("Socket error");
		exit(EXIT_FAILURE);
	}

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(atoi(argv[2]));
	server_addr.sin_addr = *((struct in_addr *)host->h_addr);
	bzero(&(server_addr.sin_zero),8);

	if (connect(sock, (struct sockaddr *)&server_addr,
			sizeof(struct sockaddr)) == -1)
	{
		perror("Connect error");
		exit(EXIT_FAILURE);
	}
	while(packets) {
		create_data(send_data, max_value);
		send(sock,send_data,strlen(send_data), 0);
		memset(send_data, 0x00, 1024);
		--packets;
		sleep(1);
	}
	close(sock);
	return 0;
}

int generate_random_int(int max){
	struct timeval currentTime;
	gettimeofday(&currentTime, NULL);
	srand(currentTime.tv_sec * (int)1e6 + currentTime.tv_usec);
	return rand() % max;
}

float generate_random_float(int max){
	struct timeval currentTime;
	gettimeofday(&currentTime, NULL);
	srand(currentTime.tv_sec * (int)1e6 + currentTime.tv_usec);
	return (float)rand()/((float)RAND_MAX/max);
}

int create_data(char* buf, int max){
	int c1 = generate_random_int(max);
	float c2 = generate_random_float(max);
	int c3 = generate_random_int(max);
	snprintf (buf, 100, "%d %f %d", c1, c2, c3);

	return 0;

}
