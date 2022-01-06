#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#ifndef NETWORKING_H
#define NETWORKING_H

#define BUFFER_SIZE 256
#define PORT "9845"
#define TEST_IP "127.0.0.1" // 127.0.0.1:9001, 127.0.0.1 is the local host's IP
// ./a.out localhost

void error_check(int i, char *s);
int server_setup();
int server_connect(int sd);
int client_setup(char * server);

#endif