# TCP Echo Request
## Aim: 
Implement a TCP-based echo server where a client sends a message to the server, and the server sends back the same message.

## Algorithm:

### Server:

1. Create a TCP socket.
2. Bind the socket to an IP and port.
3. Listen for incoming connections.
4. Accept a client connection.
5. Receive a message from the client and send it back (echo).
6. Repeat until the client disconnects.
7. Close the connection.

### Client:

1. Create a TCP socket.
2. Connect to the server.
3. Send a message to the server.
4. Receive the echoed message from the server and display it.
5. Close the connection.

## Output: 
Client sends a message, e.g., `Hello, Server!`, and receives the same message back, confirming that the server echoes correctly.

