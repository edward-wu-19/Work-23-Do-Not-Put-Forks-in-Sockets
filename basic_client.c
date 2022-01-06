#include "pipe_networking.h"

int main(int argc, char* argv[]) {
    char ipaddr[100];

    if (argc > 1){
        strcpy(ipaddr, argv[1]);
    }

  int server = client_setup(ipaddr);

  char* buffer = calloc(BUFFER_SIZE, sizeof(char));

    // Constantly Runs
    while (1) {
        // Asking For User Input
        printf("> ");
        fgets(buffer, BUFFER_SIZE, stdin);
        *strchr(buffer, '\n') = '\0';

        // Writing To User To Worker Pipe
        int err1 = write(server, buffer, BUFFER_SIZE);

        // Reading From Worker To User Pipe
        int err2 = read(server, buffer, BUFFER_SIZE);

        printf("The server says: %s\n", buffer);
    }
  
  return 0;
}