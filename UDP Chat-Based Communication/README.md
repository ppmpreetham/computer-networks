# UDP Chat-Based Communication

## Aim
Establish a simple chat application using UDP where the client and server can exchange messages.

## Algorithm

### Server

1. Create and bind a UDP socket.
2. Enter a loop where it receives a message from the client and sends a reply.
3. Continue the loop to enable bidirectional communication.

### Client

1. Create a UDP socket.
2. Enter a loop where it sends a message to the server and waits for a reply.
3. Display the reply and repeat the loop to continue communication.

## Output
Bidirectional communication, allowing both client and server to send and receive chat messages over UDP.