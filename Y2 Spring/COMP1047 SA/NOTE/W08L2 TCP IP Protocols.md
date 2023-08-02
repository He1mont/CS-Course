## W8L2: TCP/IP Protocols

>   ### Outline
>
>   -   TCP/IP Protocols
>   -   OSI Layer Model
>   -   TCP vs UDP
>   -   TCP Protocol
>       -   Connection Management
>       -   Retransmission
>       -   Performance
>
>   -   IP
>       -   IPv4
>       -   IPv6
>
>   -   TCP/IP Protocol Suite
>   -   IP Routing



#### 1. TCP/IP Protocols

[**Here is a tutorial from Youtube for TCP/IP model.**](https://www.youtube.com/watch?v=2QGgEk20RXM)

-   **definition**
    -   TCP: Transmission Control Protocol

    -   IP: Internet Protocol

    -   Not one protocol but a suite of protocols
    -   Layered type of protocols divide the tasks into modules


<img src="assets/Screenshot 2023-04-11 at 22.17.36.png" alt="Screenshot 2023-04-11 at 22.17.36" style="zoom:60%;" />

<img src="assets/Screenshot 2023-05-09 at 23.10.28.png" alt="Screenshot 2023-05-09 at 23.10.28" style="zoom:20%;" />

<img src="assets/Screenshot 2023-05-09 at 23.12.55.png" alt="Screenshot 2023-05-09 at 23.12.55" style="zoom:20%;" />



1.   **Physical Layer**
     -   convert ==binary sequence== into ==signals== and transmits them over local media
         -   signals may have electrical, light and radio
         -   depends on the type of devices
         -   determine the type of cables to be used
     -   one example is ==ethernet==



2.   **Data Link Layer**
     -   The data unit in Data Link Layer is called an ==Ethernet frame==
     -   <u>two sub-layers</u>
         -   Medium Access Control (MAC sub-layer)
         -   Logical Link Control (LLC sub-layer)
     -   <u>MAC sub-layer</u>
         -   Data Encapsulation: 
             add a ==header==(MAC address) and a ==trailer== (Error Checking Data)
         -   Accessing the media
     -   <u>LLC sub-layer</u>
         -   <u>Flow Control</u>: restricts the amount of data
         -   <u>Error Control</u>
             -   Error Detection: done by ==Error Checking bytes==
             -   Frame Retransmission: done by using ==Automatic Repeat Request==
                 When the frame is not received, the sender sends the frame again
         -   <u>Re-size IP packets</u>



3.   **Network Layer**
     -   <u>Logical Addresing</u>
         -   ==IP addresses== of senders and receivers are assigned to each segment to form a ==IP packet==
     -   <u>Routing</u>
         -   move data packets from source to destination
         -   not needed if source and destination are in the same network
     -   <u>Path determination</u>
         -   choosing the best path for data delivery



4.   **Transport Layer**

     -   TCP supports segmentations
         -   divide into smaller pieces, adds a header to form a ==TCP segment==
         -   reliable, Connection-Oriented Protocol
     -   UDP **does not** support segmentation
         -   send messages short enough to fit into one ==UDP diagram==
         -   unreliable, lack error checking
     
     
     
     -   Three phases of data transmission via TCP
         1.   <u>Connection establishment</u>: three-way TCP Connection Handshake
     
         2.   <u>Data transfer</u>
     
              -   Error-free data transfer
     
              -   Ordered-data transfer
     
              -   Retransmission of lost data
     
              -   Discarding duplicate packets
     
              -   Congestion throttling
     
         3.   Connection termination: four-way Handshake Process



5.   **Application Layer**
     -   Network Appliciations use HTTP/s to do the serving
     
     -   forms the basis for various network services
         -   File Transfer: FTP
         -   Web Surfing: HTTP/s
         -   Emails: SMTP

<img src="assets/Screenshot 2023-04-12 at 00.36.45.png" alt="Screenshot 2023-04-12 at 00.36.45" style="zoom:60%;" />



#### 2. OSI Layer Model 

[**Here is a tutorial from Youtube for OSI model.**](https://www.youtube.com/watch?v=vv4y_uOneC0)



-   OSI Layer Model
    -   Open System Interconnection Model 
    -   robust but also slow and expensive



-   Each layer has a specific ==Protocol Data Unit (PDU)==
    -   PDUs are used for peer-to-peer contact between corresponding layers
    -   ==Data== are handled by the top three layers
    -   ==Segments== by the Transport layer
    -   ==Packets== by the Network layer
    -   ==Frames== by the Data Link Layer
    -   ==Bits== or ==Symbols== by the Physical layer

<img src="assets/Screenshot 2023-04-11 at 22.18.38.png" alt="Screenshot 2023-04-11 at 22.18.38" style="zoom:50%;" />




-   The protocols associated with each layer encapsulate
    -   The header
    -   The data of the preceding layer 



<img src="assets/Screenshot 2023-04-11 at 22.25.34.png" alt="Screenshot 2023-04-11 at 22.25.34" style="zoom:45%;" />

<img src="assets/Screenshot 2023-04-12 at 00.34.32.png" alt="Screenshot 2023-04-12 at 00.34.32" style="zoom:60%;" />



1.   **Application Layer:**

     -   It provide services for ==Network Appliciations== like Chrome, Outlook, Skype
     -   forms the basis for various network services
         -   File Transfer: FTP
         -   Web Surfing: HTTP/s
         -   Emails: SMTP

     

2.   **Presentation Layer**

     -   <u>Translation</u>: convert ASCII Code into Machine Language
     -   <u>Data Compression</u>: it can be lossy or lossless
     -   <u>Encryption and Decryption</u>

<img src="assets/Screenshot 2023-05-09 at 21.39.20.png" alt="Screenshot 2023-05-09 at 21.39.20" style="zoom: 25%;" />




3.   **Session Layer**

     -   It enables ==sending and receiving data==

     -   API: Application Programming Interfaces

     -   <u>Authentication</u>: to verify who you are

     -   <u>Authorization</u>: to determine if you have permissions to access file

     -   <u>Session Management</u>: keep a track of which ==data packet== belong to which file

         

4.   **Transport Layer**
-   <u>Segmentation</u>
    -   The received data is divided into ==data units called segments==
    -   Each segment contains ==Sequence number== and ==Port number==
    -   ==Port Number== directs to the correct application
    -   ==Sequence Number== helps to form the correct order

-   <u>Flow Control</u>: Control the ==amount of data== being trasnmitted
     -   <u>Error Control</u>: if some data is missing, it use a scheme to re-transmit the data
-   <u>Connection-Oriented (TCP) and Connectionless Transmission (UDP)</u>



5.   **Network Layer**

     -   Data units in the Network Layer are called ==Packets==
     -   <u>Logical Addresing</u>:
         -   ==IP addresses== of senders and receivers are assigned to each segment to ==form a data packet==
     -   <u>Routing</u>
         -   move data packets from source to destination
     -   <u>Path determination</u>
         -   choosing the best path for data delivery

     

6.   **Data Link Layer**

     -   Data units in Data Link Layer are called ==Frame==
     -   <u>Physical addressing</u>
         
         -   ==MAC addresses== of senders and receivers are assigned to each data packet to ==form a frame==
         -   MAC Address: 12 digit alpha-numeric number embedded in network interface card of a computer by the manufacturer
     -   <u>Access the media</u>: 
         -   Framing
     -   <u>Controls how data is placed and received from the media</u>
         -   Media Access Control
         -   Error Detection
     

<img src="assets/Screenshot 2023-05-09 at 22.52.53.png" alt="Screenshot 2023-05-09 at 22.52.53" style="zoom: 20%;" />



7.   **Physical Layer**
-   Convert binary sequence into signals and transmit over local media

<img src="assets/Screenshot 2023-05-09 at 23.02.11.png" alt="Screenshot 2023-05-09 at 23.02.11" style="zoom:50%;" />



#### 3. TCP and UDP Protocols

-   TCP (Transmission Control Protocol)
    -   Provide Feedback, more reliable
    -   Slower
    -   ==Connection-Oriented==: guarantees the delivery of data over a network
    -   Lost data could be re-transmitted by TCP
    -   Used for ==full data delivery==
    -   Examples: web: HTTP, e-mail: SMTP, IMAP
-   UDP (User Datagram Protocol)
    -   Lack error checking
    -   Faster
    -   ==Connectionless==: doesn't require that data has been received correctly
    -   Used when 
        -   delay are unacceptable
        -   TCP congestion avoidance and flow controls are unsuitable
        -   Highly delay sensitive 
    -   Examples: various types of streaming media



#### 4. TCP Protocol

-   TCP Connection Management
-   TCP Retransmission
-   TCP Performance



#### 4.1 TCP Connection Management

-   The objective of **connection management** is to provide higher layers with the illusion of an end-to-end connection especially in connectionless packet networks
-   two functions required
    -   Connection set-up
    -   Connection tear-down
-   ==Connection set-up==
    -   **three-way handshake**
    -   The sending computer sends a `SYN packet` to the receiving computer
        This packet includes a random `sequence number`, used to track the packet
        -   the phone rings
    -   The receiving computer responds with a `SYN-ACK packet`
        This packet includes an `acknowledgement number` that is `seq = x+1`
        The receiving device also sends ito own `SYN packet` with a sequence number
        -   Hello?
    -   The sending computer responds with an ACK packet
        This packet includes an `acknowledgement number` that is `seq = y+1`
        -   Hi!
    -   After ==the three-way handshake== is complete, both devices have synchronized their `sequence` and `acknowledgement numbers` and can begin exchanging data packets using TCP
    -   where
        -   SYN: Synchronize
        -   ACK: Acknowledge

<img src="assets/Screenshot 2023-04-12 at 01.46.52.png" alt="Screenshot 2023-04-12 at 01.46.52" style="zoom:40%;" />

-   ==Connection tear-down==

    -   two types
        -   Asymmetric release
        -   Symmetric release
    -   Asymmetric release
        -   ==Either== end may terminate the connection
        -   Data and requests ==may be lost== and some solutions are available

    <img src="assets/Screenshot 2023-04-12 at 01.50.09.png" alt="Screenshot 2023-04-12 at 01.50.09" style="zoom:40%;" />

    -   Symmetric release (==Two double handshakes==)
        -   Both ends keep a unidirectional connection to the other
        -   For each connection the source tears it down when no more data will be sent
    
    <img src="assets/Screenshot 2023-04-12 at 01.50.30.png" alt="Screenshot 2023-04-12 at 01.50.30" style="zoom:45%;" />



#### 4.2 TCP - Retransmission

-   The objective is good transmission of data
-   The basic techniques for reliable transmission in the context of a packet network
    -   Use `sequence numbers` to identify each data packet and establish the correspondence between it and its reply
    -   Retransmit the same data packet if its reply is not received within a period
        this is called a `retransmission time-out` (RTO)
-   Procedures
    -   When a sender transmits a packet, it waits for an `ACK` from the receiver before sending the next packet
    -   If the sender doesn't receive an `ACK` within a period, TCP assumes it is `lost` and `retransmits` it
    -   TCP calculate the time of waiting before retransission, that is 
         `round trip time` (RTT) for a packet and its acknowledgement


<img src="assets/Screenshot 2023-04-12 at 01.54.57.png" alt="Screenshot 2023-04-12 at 01.54.57" style="zoom:50%;" />



#### 4.3 TCP - Performance

-   Network performance depends on the nature of an application
-   A good understanding of the requirements of the application
    -   high throughput
    -   low latency
    -   low jitter
-   File Transfer
    -   needs high throughput
    -   intolerant of packet loss
    -   maybe more tolerant of delay
-   Interactive Video Conferencing application
    -   Tolerant of some loss
    -   more intolerant of delay and jitter



-   `Quality of Service` (QoS) is very important in selecting the channel characteristics of the link
-   A method of allocating network resources so that
    -   a mechanism exists to offer varying degrees of service to varying classes of traffic
    -   the features of the service are used
        -   delay, jitter, the proportion of link bandwidth, etc



#### 5. Internet Protocol (IP)

-   Encapsulation
    -   the layer N `Protocol data unit` (PDU) is called the layer N-1 `service data unit` (SDU).
-   In order to achieve encapsulation, the protocols should provide:
    -   Network services
    -   Addressing
    -   Routing
    -   Quality of service
    -   Maximum packet size
    -   Flow and congestion control
    -   Error reporting



-   IP addresses are either statically assigned, or dynamically via the DHCP server
-   Each IP address consists of two parts:
    -   one identifying the **network**: N = Network
    -   one identifying the **node**: n = node

#### 5.1 IPv4:

-   The 32-bit binary number is usually represented as 4 decimal values, each representing 8 bits (0-255)

-   Subnet mask
    -   used to divide the IP address into the network address and the node address

-   IPv4 Network Classes

<img src="assets/Screenshot 2023-05-11 at 23.26.37.png" alt="Screenshot 2023-05-11 at 23.26.37" style="zoom:40%;" />

<img src="assets/Screenshot 2023-04-17 at 15.13.25.png" alt="Screenshot 2023-04-17 at 15.13.25" style="zoom:50%;" />

-   IPv4 addresses reserved for private use
    -   10.0.0.0 to 10.255.255.255
    -   172.16.0.0 to 172.31.255.255
    -   192.168.0.0 to 192.168.255.255
    -   169.254.0.0 to 169.254.255.255
    -   **127.0.0.1 is reserved for localhost** 



-   IP Packets

    -   The message is divided into several packets of reduced length

    -   Each packet has a header and the payload that now carries only a fragment of the message

    -   Protocol number
        -   1 = ICMP (Internet Control Message Protocol)
        -   6 = TCP (Transmission Control Protocol)
        -   17 = UDP (User Datagram Protocol)

-   IPv4 datagram 

    -   [**Here is a tutorial from Youtube for IPv4 datagram.**](https://www.youtube.com/watch?v=3Y70y6dM7Cs)

<img src="assets/Screenshot 2023-04-18 at 15.37.57.png" alt="Screenshot 2023-04-18 at 15.37.57" style="zoom:50%;" />

#### 5.2 IPv6

-   -   IPv4 with 2^32 addresses
    -   IPv6 with 2^128 addresses
-   Features
    -   better and more compact header format
    -   larger address space
    -   support for resource allocation
    -   built-in security
    -   better support for quality of service (QoS)
    -   new protocol for neighboring node interaction
    -   extensibility
-   The Architecture of IPv6

<img src="assets/Screenshot 2023-04-18 at 15.40.35.png" alt="Screenshot 2023-04-18 at 15.40.35" style="zoom:50%;" />

-   IPv6 datagram

<img src="assets/Screenshot 2023-04-18 at 15.50.45.png" alt="Screenshot 2023-04-18 at 15.50.45" style="zoom:50%;" />



#### 6. TCP/IP Protocol Suite

-   HTTP (Hypertext Transfer Protocol)
-   Telnet
-   FTP (File Transfer Protocol)
-   SMTP (Simple Mail Transfer Protocol)
-   DNS (Domain Name Server)
-   RIP (Routing Information Protocol)
-   SNMP (Simple Network Management Protocol)



#### 7. IP Routing

-   All devices need to know what IP addresses are on directly attached networks
    -   if the destination is on a ==local network==, send it directly there
    -   if the destination address isn't local
        -   send to a single local router
        -   routers need to know which network corresponds to each possible IP address
-   Routing Table
    -   Destination IP address
    -   The IP address of a next-hop router
    -   Flags
    -   Network interface specification

<img src="assets/Screenshot 2023-04-18 at 15.55.03.png" alt="Screenshot 2023-04-18 at 15.55.03" style="zoom:50%;" />





 
