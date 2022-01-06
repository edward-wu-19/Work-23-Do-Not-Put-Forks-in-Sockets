#include "pipe_networking.h"

int main() {

    char * buffer = calloc(BUFFER_SIZE, sizeof(char));

    // Initializing Server Socket
    int socket = server_setup();

    // Persistent Process
    while (1) {
        int client = server_connect(socket);

        // Forking Server
        int frk = fork();

        if (frk == 0) { // Child Process
            // Constantly Runs
            while (1) {
                // Reading From User To Worker Pipe
                int err1 = read(client, buffer, BUFFER_SIZE);

                // String Manipulation (Upper Case)
                int i;
                for (i = 0; i < BUFFER_SIZE; i++) {
                    if (buffer[i] != '\0'){
                        buffer[i] = toupper(buffer[i]);
                    }
                }

                // Writing To Worker To User Pipe
                int err2 = write(client, buffer, BUFFER_SIZE);
            }
        }
    }

    return 0;
}