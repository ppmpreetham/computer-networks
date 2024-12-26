# TCP Chat-Based Communication
## Aim: 
Establish a simple chat-based communication using TCP, where both client and server can send and receive messages.

## Algorithm:

### Server:

1. Create and bind a TCP socket.
2. Listen for incoming connections.
3. Accept a client connection.
4. Enter a loop where the server receives and sends messages to the client.
5. Close the connection when finished.

### Client:

1. Create a TCP socket.
2. Connect to the server.
3. Enter a loop to send and receive messages to/from the server.
4. Close the connection.

## Output: 
Bidirectional communication where both client and server can exchange messages interactively.