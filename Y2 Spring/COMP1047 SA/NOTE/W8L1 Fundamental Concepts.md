## W8L1 Fundamental Concepts

>   ### Outline
>
>   -   Networks Classification
>       -   WANs, MANs, LANs, CANs, HANs, PANs
>       -   PSTN, PSDN, ISDN
>   -   Networking Standards
>       -   standards bodies
>       -   two phase
>   -   Protocol
>       -   specifications
>       -   key features
>       -   possible functions
>       -   multiple protocol layers



#### 1. Fibre To The x - FTTx

-   The FTTx covers a number of technologies and protocols
-   The most common architectures are
    -   FTTHome (FTTH)
    -   FTTBuilding (FTTB)
    -   FTTCurb (FTTC)
    -   FTTNode (FTTN)
    -   成本递增，速度递减

<img src="assets/Screenshot 2023-04-10 at 14.24.26.png" alt="Screenshot 2023-04-10 at 14.24.26" style="zoom:40%;" />



#### 2. Networks Classification

1.   Wide Area Networks (WANs): 
     -   The subscribers are geographically wide apart and are interconnected across metropolitan, regional, and international boundaries.

2.   Metropolitan Area Networks (MANs): 
     -   A data network designed for a town or city.

3.   Local Area Networks (LANs): 
     -   The subscribers are geographically close together (in the same building) or in the same area.

4.   Campus Area Networks (CANs): 
     -   The subscribers are within a limited geographic area, such as a university campus or business area.

5.   Home Area Networks (HANs): 
     -   A network contained within a user's home connects a person's digital devices.

6.   Personal Area Networks (PANs): 
     -   A network for interconnecting electronic devices within an individual person’s workspace.

<img src="assets/Screenshot 2023-04-11 at 20.27.16.png" alt="Screenshot 2023-04-11 at 20.27.16" style="zoom:50%;" />



#### 3. Networks Model

-   General network model for voice and data

<img src="assets/Screenshot 2023-04-11 at 20.32.53.png" alt="Screenshot 2023-04-11 at 20.32.53" style="zoom:40%;" />

-   Simple computer networks are illustrated below



-   PSTN:  Public Switched Telephone Network
    -   公共交换电话网，传统电话系统的一种
    -   由一系列电路交换设备和电话线路组成，由多家电话公司维护
    -   PSTN主要提供==语音通信服务==

<img src="assets/Screenshot 2023-04-11 at 20.34.09.png" alt="Screenshot 2023-04-11 at 20.34.09" style="zoom:50%;" />



-   PSDN: Public Switched Data Network
    -   分组交换数据网，是一种基于分组交换技术的公共数据通信网络
    -   通常用于企业和政府机构等组织之间的远程数据传输
    -   PSDN主要提供==数据通信服务==

<img src="assets/Screenshot 2023-04-11 at 20.42.50.png" alt="Screenshot 2023-04-11 at 20.42.50" style="zoom:50%;" />



-   ISDN: Integrated Services Digital Network
    -   数字式综合业务数字网，是一种基于数字化技术的电话通信系统
    -   与PSTN相比，ISDN提供更高的通信质量和更多的数据传输功能
    -   ISDN则既提供==语音通信服务==，也提供==高速数据传输==和==复杂通信服务==

<img src="assets/Screenshot 2023-04-11 at 20.43.28.png" alt="Screenshot 2023-04-11 at 20.43.28" style="zoom:50%;" />



#### 4. Broadband Multiservice Networks

-   Broadband Multiservice Networks
    
    -   `Broadband`: high transmission rates
    -   Video, Voice and Data services over wired and wireless networks
    -   a new approach for transmission and switching
        -   ATM: Asynchronous Transfer Mode
    
    
    
    -   一种综合了多种服务的宽带网络，能够提供高速数据、音频、视频等多种通信服务
    -   使用了各种传输技术，如ATM、IP、SDH等，使得不同种类的数据和服务都可以在同一个网络上传输
    -   采用了分层的结构，可以在网络上实现多种协议和服务，因此非常适合于各种不同的应用场景，如企业、家庭、学校、医院等
    -   有多种应用，如语音通信、视频会议、实时流媒体、在线游戏、云计算等

<img src="assets/Screenshot 2023-04-11 at 20.59.19.png" alt="Screenshot 2023-04-11 at 20.59.19" style="zoom:50%;" />



#### 5. Networking Standards

-   Standards bodies
    -   ECMA: 
        -   European Computer Manufacturers Association 
    -   EIA: 
        -   Electrical Industries  Association 
    -   IEEE 
        -   Institution of Electrical and Electronic Engineers
    -   ISO 
        -    International Standards Organisation
    -   ITU – T
        -    International Telecommunication Union – Telecommunication Sector
    -   CEPT 
        -    Conference European of Post and Telecommunications
    -   ANSI
        -    American National Standards Institute



-   Two phases - The evolution of networking standards

    1.   Reflected the political, financial and manufacturing issues

    2.   Continuous evolution of standards for interoperability

    

-   Phase 1-a: Computers

    -   <u>the multiplicity of standards</u> and <u>the availability of ==closed systems without inoperability==</u> led to <u>high prices</u> for services and the <u>limited availability</u> of services to the society.


<img src="assets/Screenshot 2023-04-11 at 21.04.08.png" alt="Screenshot 2023-04-11 at 21.04.08" style="zoom:50%;" />



-   Phase 1-b: Computers
    -   The telecommunication industry had the time to organise its affairs around standards that led to ==inoperability== and a world market, leading to low prices and relative high use of services.


<img src="assets/Screenshot 2023-04-11 at 21.04.20.png" alt="Screenshot 2023-04-11 at 21.04.20" style="zoom:50%;" />



-   Phase 2:
    -   the computer and telecommunications industries are working together to deliver ==international standards== for greater ==interoperability==.


<img src="assets/Screenshot 2023-04-11 at 21.04.31.png" alt="Screenshot 2023-04-11 at 21.04.31" style="zoom:50%;" />



#### 6. Services

-   In transferring data from computer A to computer B the users request a service



-   **Services** between adjacent layers are defined by a set of **Primitives** (operations) and **Parameters**
    -   The primitives specify the functions to be performed
    -   The parameters communicate data and control information



-   The service defines **what operations** the layer should perform for the users 
-   But it **does not** prescribe **how these operations** will be implemented

| Service Primitive | Meaning                                    |
| ----------------- | ------------------------------------------ |
| LISTEN            | Waiting for an incoming connection         |
| CONNECT           | Establish a connection with a waiting peer |
| RECEIVE           | Waiting for an incoming message            |
| SEND              | Send a message to the peer                 |
| DISCONNECT        | Terminate the connection                   |



#### 7. Protocol

-   The operation of modern communication systems is based on the concept of ==protocol==.

-   The internal **structure of a protocol** is based on a layer model



-   A protocol is a set of rules

    -   controlling the format, the meaning of the frames, the meaning of packets and messages exchanged by the peer entities within a layer

    

-   <u>The protocol specifications</u>

    -   must be precise
    -   may involve different operating systems
    -   operate between the same layer between two systems



-   <u>Key features of the protocols</u>
    -   **<u>syntax</u>**: data formats, signal levels
    -   **<u>semantics</u>**: control information, error handling
    -   **<u>timing</u>**: speed matching, sequencing



-   <u>Possible functions of a protocol</u>
    -   addressing
    -   connection control
    -   flow control
    -   encapsulation
    -   segmentation and concatenation
    -   transmission of data
    -   error detection and control
    -   routing



-   The complexity of the communication task in each protocol level is reduced by using **multiple protocol layers**

-   <u>Key features of the multiple protocol layers**</u>
    -   Each protocol is implemented independently
    -   Each protocol is responsible for a specific subtask
    -   Protocols are grouped in a hierachy



-   The most important protocols in general use are
    -   TCP / IP protocol suite
    -   OSI reference model



-   Relationship between a Service and a Protocol

<img src="assets/Screenshot 2023-04-11 at 21.58.27.png" alt="Screenshot 2023-04-11 at 21.58.27" style="zoom:50%;" />















