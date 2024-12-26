# TCP Server Date-Time Request

## Aim
Create a TCP server that sends the current date and time to a client upon request.

## Algorithm

### Server

1. Create a TCP socket.
2. Bind the socket to a port and listen for connections.
3. Accept a client connection.
4. Get the current system date and time.
5. Send the date-time information to the client.
6. Close the connection.

### Client

1. Create a TCP socket.
2. Connect to the server.
3. Receive the date-time string from the server.
4. Display the received date-time.
5. Close the connection.

## Output
The client receives and displays the current date and time from the server, e.g., `Wed Nov 13 10:00:00 2024`.