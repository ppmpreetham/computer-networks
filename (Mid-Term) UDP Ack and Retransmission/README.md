# UDP Acknowledgment and Retransmission

## Aim
To implement a reliable data transfer over UDP by creating a client-server model where the client sends numbered packets, the server acknowledges each packet, and the client retransmits packets if an acknowledgment is not received within a specified timeout period.

## Algorithm/Procedure

### Server-side (Receiver)

1. Create a UDP socket.
2. Bind the socket to a specified port.
3. Receive data packets from the client.
4. Send an acknowledgment for each received packet.
5. Display the received packet number.

### Client-side (Sender)

1. Create a UDP socket.
2. Send numbered packets to the server.
3. Start a timer after sending each packet.
4. Wait for an acknowledgment from the server within the timeout period.
5. If acknowledgment is not received within the timeout, resend the packet.
6. Repeat until all packets are acknowledged.

## Expected Output

### Server-side Output

```yaml
Server listening on port 8080
Received packet: Packet 1
Received packet: Packet 2
...
Received packet: Packet 10
```

### Client-side Output

```makefile
Sent: Packet 1
Received: ACK: Packet 1
Sent: Packet 2
Received: ACK: Packet 2
...
Sent: Packet 10
Received: ACK: Packet 10
```

## Result
The client and server communicate using UDP. The client sends numbered packets, and the server acknowledges each packet. If the client does not receive an acknowledgment within the timeout period, it resends the packet until acknowledgment is received. This implementation provides a reliable data transfer mechanism over an otherwise unreliable UDP protocol.