#include "pipe_networking.h"

int main() {

    char * buffer = calloc(BUFFER_SIZE, sizeof(char));

    // Initializing Server Socket
    int socket = server_setup();
    if (socket == -1){
            printf("Error: %s\n\n", strerror(errno));
        }

    // Persistent Process
    while (1) {
        int client = server_connect(socket);
        if (client == -1){
            printf("Error: %s\n\n", strerror(errno));
        }

        // Forking Server
        int frk = fork();

        if (frk == 0) { // Child Process
            // Constantly Runs
            while (1) {
                // Reading From User To Worker Pipe
                int err1 = read(client, buffer, BUFFER_SIZE);

                if (err1 == -1){
                    printf("Error: %s\n\n", strerror(errno));
                }

                // String Manipulation (Upper Case)
                int i;
                for (i = 0; i < BUFFER_SIZE; i++) {
                    if (buffer[i] != '\0'){
                        buffer[i] = toupper(buffer[i]);
                    }
                }

                // Writing To Worker To User Pipe
                int err2 = write(client, buffer, BUFFER_SIZE);
                if (err2 == -1){
                    printf("Error: %s\n\n", strerror(errno));
                }
            }
        }
    }

    return 0;
}