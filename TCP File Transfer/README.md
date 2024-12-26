# TCP File Transfer

## Aim
Transfer a file from a TCP client to a TCP server over a network.

## Algorithm

### Server

1. Create and bind a TCP socket.
2. Listen for incoming connections.
3. Accept a client connection.
4. Receive file data from the client and save it to a file.
5. Close the file and the connection.

### Client

1. Create a TCP socket.
2. Connect to the server.
3. Open a file in read mode.
4. Send the file content to the server in chunks.
5. Close the file and the connection.

## Output
The server receives the file sent by the client and saves it as `received_file.txt`.