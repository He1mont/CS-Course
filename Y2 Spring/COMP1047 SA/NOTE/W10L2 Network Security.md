## W10L2: Network Security

>   ### Outline
>
>   -   The 3 'A's of Security
>   -   Authentication
>       -   two factor authentication
>
>   -   Authorisation
>       -   Firesystem Access Control
>       -   DMZ
>       -   Firewall and its evolution
>
>   -   Auditing
>       -   IDS: HIDS, NIDS




### ==We are Hackers, not Crackers==



#### 1. The 3 "A"s of Security

-   **Authentication**
    -   verify the user's identity, i.e. use of passwords
-   **Authorisation**
    -   check users' ==level of access==
    -   Which computers are they allowed to access
    -   Which actions are they allowed to perform
-   **Auditing**
    -   track and record a user's access to data



#### 2. Two Factor Authentication

-   one of the best defences against `brute forcing` and `poor crentials` is ==Two Factor Authentication==
-   require two elements:
    -   `A 'known' portion`: a password, PIN or other credential
    -   `A 'physical' portion`: a token or device with a temporally unique code

-   Examples:
    -   Google 2-step verification
    -   Location Aware Login
    -   One Time Password (OTP) Security Device



-   **Google 2-step verification**
    -   User signs in with normal credentials 
    -   User enters the code shown on their device or received via SMS

<img src="assets/Screenshot 2023-04-25 at 15.29.01.png" alt="Screenshot 2023-04-25 at 15.29.01" style="zoom:50%;" />



#### 3*: Authorisation

#### 3. Filesystem Access Control

-   Filesystem Access Control
    -   Filesystem implements its own access control system
    -   Only the filesystem implements user groups
-   Filesystem Groups
    -   every file has ==owner and a group==
    -   owner set permissions
    -   can decide what owner, group owners and other can do with files

-   **Permission bits**: rwx
    -   r: read privilege
    -   w: write privilege
    -   x: execution privilege

<img src="assets/Screenshot 2023-04-25 at 15.33.01.png" alt="Screenshot 2023-04-25 at 15.33.01" style="zoom:50%;" />



#### 4. DMZ (De-Militarized Zone)

-   **usage**
    
    -   used to create a ==buffer zone== between the internet and an organization's internal network
    -   A physical or logical subnetwork within which all servers hosting publicly accessible services are placed
    -   Contains and exposes an organization’s external services to a larger, untrusted network, usually the Internet
    
-   **purpose**
    
    -   To add an ==additional layer== of security to an organization's LAN
    -   An external attacker ==only has access to equipment in the DMZ==, rather than the whole of the network
    



#### 4*. Firewall

-   designed to ==block unauthorised access== while permitting authorised communications
-   all messages entering or leaving the intranet pass through the firewall
-   Here is an image of `Single Firewall Architecture`

<img src="assets/Screenshot 2023-04-25 at 18.11.08.png" alt="Screenshot 2023-04-25 at 18.11.08" style="zoom:30%;" />



-   **The evolution of the firewall**
    -   1st Generation: Packet Filter
    -   2nd Generation: Stateful Filter
    -   3rd Generation: Application Layer

-   **1st Generation: Packet Filter**
    -   intercept network traffic and inspect packets
    -   filter on packet's source and destination address, its protocol, the port number
    -   packets are allow to pass or dropped
    -   has ==no memory of connections==

<img src="assets/Screenshot 2023-05-12 at 17.38.44.png" alt="Screenshot 2023-05-12 at 17.38.44" style="zoom:50%;" />



-   **2nd Generation: Stateful Filter**
    -   keep track of ongoing connections
    -   only allow packet where the connection was established from inside the firewall

<img src="assets/Screenshot 2023-05-12 at 17.39.01.png" alt="Screenshot 2023-05-12 at 17.39.01" style="zoom:50%;" />



-   **3rd Generation: Application Layer**
    -   can tell the difference between HTTP traffic used to access a Web page and HTTP traffic used for file sharing

<img src="assets/Screenshot 2023-05-12 at 17.39.12.png" alt="Screenshot 2023-05-12 at 17.39.12" style="zoom:50%;" />



#### 5*. Auditing

#### 5. IDS (Intrusion Detection System)

-   it monitors

    -   Network traffic
    -   Unauthorised access
    -   Suspicious activities

-   a last line of defence in the network security (**Auditing**)

-   why use an IDS?

    -   **Early detection of security breache**

    -   **Threat intelligence**: 

        IDS solutions can ==analyze network traffic patterns== to provide insights into potential vulnerabilities and emerging threats

    -   **Compliance**:

        Many regulatory requirements mandate the use of IDS as a security control

    -   **Reduced risk**

        By ==detecting and responding to security incidents== quickly, an IDS can reduce the overall risk to an organization's network and data.

    -   **Improved incident response**

        IDS can ==provide valuable data== about an attack, such as the methods used by attackers and the systems affected.



-   Types of IDS
    -   Host-base IDS (HIDS)
    -   Network-base IDS (NIDS)

-   **Host-base IDS (HIDS)**
    -   Get audit data from host audit trails
    -   Detect attacks against a single host
-   **Network-base IDS (NIDS)**
    -   Use network traffic as the audit data source
    -   Relieve the burden on the hosts that usually provide normal computing services
    -   Detect attacks from networks









