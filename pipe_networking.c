#include "pipe_networking.h"

void error_check(int i, char *s){

}

int server_setup(){
    //use getaddrinfo
    struct addrinfo * hints, * results;
    hints = calloc(1,sizeof(struct addrinfo));
    hints->ai_family = AF_INET;
    hints->ai_socktype = SOCK_STREAM; //TCP socket
    hints->ai_flags = AI_PASSIVE; //only needed on server
    getaddrinfo(NULL, PORT, hints, &results);  //Server sets node to NULL

    //create socket
    int sd = socket(results->ai_family, results->ai_socktype, results->ai_protocol);
    if (socket == -1){
        printf("Error: %s\n\n", strerror(errno));
    }

    int foo = bind(sd, results->ai_addr, results->ai_addrlen);
    if (foo == -1){
        printf("Error: %s\n\n", strerror(errno));
    }

    //DO STUFF

    free(hints);
    freeaddrinfo(results);

    return sd;
}


int server_connect(int sd) {
    //use getaddrinfo (not shown)
    struct addrinfo * hints, * results;
    hints = calloc(1,sizeof(struct addrinfo));
    hints->ai_family = AF_INET;
    hints->ai_socktype = SOCK_STREAM; //TCP socket
    hints->ai_flags = AI_PASSIVE; //only needed on server
    getaddrinfo(NULL, PORT, hints, &results);  //Server sets node to NULL
    
    listen(sd, 10);
    int client_socket;
    socklen_t sock_size;
    struct sockaddr_storage client_address;
    sock_size = sizeof(client_address);
    client_socket = accept(sd,(struct sockaddr *)&client_address, &sock_size);
    if (client_socket == -1){
        printf("Error: %s\n\n", strerror(errno));
    }

    return client_socket;
}



int client_setup(char * server) {
    //use getaddrinfo (not shown)
    struct addrinfo * hints, * results;
    hints = calloc(1,sizeof(struct addrinfo));
    hints->ai_family = AF_INET;
    hints->ai_socktype = SOCK_STREAM; //TCP socket
    hints->ai_flags = AI_PASSIVE; //only needed on server
    int goo = getaddrinfo(NULL, PORT, hints, &results);  //Server sets node to NULL
    if (goo == -1){
        printf("Error: %s\n\n", strerror(errno));
    }

    //create socket
    int sd = socket(results->ai_family, results->ai_socktype, results->ai_protocol);
    if (sd == -1){
        printf("Error: %s\n\n", strerror(errno));
    }

    int foo = connect(sd, results->ai_addr, results->ai_addrlen);
    if (foo == -1){
        printf("Error: %s\n\n", strerror(errno));
    }

    return sd;
}