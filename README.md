# Work-23-Do-Not-Put-Forks-in-Sockets

## Compilation
`make`

## Execution
`./server`
`./client`

### Bugs
- When the server is closed before the client, `strerror(errno)` returns `Success`. Otherwise, the server would echo two more messages from the client, and allow the client to send a third, but would not echo the third. There would be no error message. This can be toggled by changing `basic_client.c` line 33 from `if (err2 != err1){` to `if (err2 == -1){`.
