#ifndef SERVER_H_
#define SERVER_H_

#include <stdio.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>

int generate_random_int(int);
float generate_random_float(int);
int create_data(char*, int);
int send_data();

#endif
