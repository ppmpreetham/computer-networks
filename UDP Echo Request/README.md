# UDP Echo Request

## Aim
Implement a UDP-based echo server that echoes messages received from the client.

## Algorithm

### Server

1. Create a UDP socket.
2. Bind it to an IP and port.
3. Receive a message from the client.
4. Send the same message back to the client.
5. Repeat the above steps for each new client message.

### Client

1. Create a UDP socket.
2. Send a message to the server.
3. Receive the echoed message from the server.
4. Display the echoed message.

## Output
The client sends a message, e.g., `Hello, UDP Server!` and receives the same message back, confirming the echo functionality.