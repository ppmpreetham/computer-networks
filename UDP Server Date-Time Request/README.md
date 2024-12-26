# UDP Server Date-Time Request

## Aim
Create a UDP server that responds with the current date and time whenever it receives a request.

## Algorithm

### Server

1. Create and bind a UDP socket.
2. Wait for a request from the client.
3. Retrieve the current date and time.
4. Send the date-time information back to the client.

### Client

1. Create a UDP socket.
2. Send a date-time request to the server.
3. Receive the date-time information from the server.
4. Display the received date-time information.

## Output
The client receives the current date and time from the server, e.g., `Wed Nov 13 10:00:00 2024`.