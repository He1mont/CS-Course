## W9L1: Network Topologies

>   ### Outline
>
>   -   Physical Topologies
>   -   Point to Point
>       -   Permanent
>       -   Switched
>   -   Bus
>       -   Linear bus
>       -   Distributed bus
>   -   Star
>       -   Simple star
>       -   Extended star
>       -   Distributed star
>   -   Ring
>       -   Simple ring
>       -   Dual ring
>   -   Mesh
>       -   Fully connected mesh
>       -   Partially connected mesh
>   -   Tree (Hierarchical Network)
>   -   Hybrid



#### 1. Physical Topologies

-   The ==mapping== of the nodes of a network
-   The ==physical connections== between them
-   examples:
    -   The layour of wiring, calbing the locations of nodes
    -   The interconnections between the node and the cabling or wiring system



#### 2. Point to Point

-   The simplest topology is a permanent link between two endpoints
-   Switch point-point topology is the basic model of conventional telephony
-   The point-to-point topology is divided into two variants



1.   **Permanent (dedicated)**
     -   easiest to understand
     -   a point-to-point communication channel to be permanently associated with the two endpoints

<img src="assets/Screenshot 2023-04-18 at 16.13.40.png" alt="Screenshot 2023-04-18 at 16.13.40" style="zoom:50%;" />

2.   **Switched**
     -   using circuit switching or packet switching technologies

<img src="assets/Screenshot 2023-04-18 at 16.14.34.png" alt="Screenshot 2023-04-18 at 16.14.34" style="zoom:50%;" />



#### 3. Bus

-   Consist of a single cable, called the bus, that connects all nodes on a network
-   Supports only one channel for communication
-   The bus topology is divided into two variants



1.   **Linear bus**
     -   All nodes are connected to a common transmission medium which has **exactly two endpoints**
     -   All data are transmitted over this common transmission medium
     -   All data can be received by all nodes

<img src="assets/Screenshot 2023-04-18 at 16.19.05.png" alt="Screenshot 2023-04-18 at 16.19.05" style="zoom:60%;" />

2.   **Distributed bus**
     -   All nodes are connected to a common transmission medium which has **more than two endpoints**
     -   created by **adding branches** to the main section
     -   All nodes share a common transmission medium

<img src="assets/Screenshot 2023-04-18 at 16.20.55.png" alt="Screenshot 2023-04-18 at 16.20.55" style="zoom:60%;" />

-   Evaluation

| pros                                                 | cons                                                         |
| ---------------------------------------------------- | ------------------------------------------------------------ |
| Cheap and easy to implement                          | **Network disruption** when computers are added or removed   |
| Require **less cable**                               | A break in the cable will prevent all systems from accessing the network |
| Does not use any specialized network to troubleshoot | Difficult to troubleshoot                                    |



#### 4. Star

-   Every node is connected through a central device
-   The star topology is divided into three variants



1.   **Simple Star**
     -   Each of the nodes is connected to a central node with a point-to-point link
     -   The central node is the **'hub'**
     -   The nodes attached to the central node are the **'spokes'**
     -   All transmitted data **must pass through the 'hub' node**

<img src="assets/Screenshot 2023-04-18 at 16.24.24.png" alt="Screenshot 2023-04-18 at 16.24.24" style="zoom:50%;" />

2.   **Extended Star**
     -   Has one or more **repeaters** between the central node
     -   The repeater is used to **extend the maximum transmission** of the simple star network

<img src="assets/Screenshot 2023-04-18 at 16.25.40.png" alt="Screenshot 2023-04-18 at 16.25.40" style="zoom:45%;" />

3.   Distributed Star
     -   Connects multiple star networks with a **daisy chain** in a linear fashion
     -   Has no hierarchy and no central connection from which a set of stacked hubs emerge

<img src="assets/Screenshot 2023-04-18 at 16.26.29.png" alt="Screenshot 2023-04-18 at 16.26.29" style="zoom:50%;" />

-   Evaluation

| pros                                      | cons                                                         |
| ----------------------------------------- | ------------------------------------------------------------ |
| Easily expanded **without disruption**    | Requires **more cable**                                      |
| Cable failure affects only a single user  | A break in the cable of the central node will prevent all systems from accessing the network |
| Easy to troubleshoot and isolate problems | More difficult to implement                                  |



#### 5. Ring

-   Every node is connected to the **two nearest nodes** so that the entire network **forms a circle**
-   The ring topology is divided into two variants



1.   **Simple Ring**
     -   Each node of the network is connected to two other nodes in the network
     -   The data generally flow in **a single direction only**

<img src="assets/Screenshot 2023-04-18 at 16.30.43.png" alt="Screenshot 2023-04-18 at 16.30.43" style="zoom:50%;" />



2.   **Dual Ring**
     -   The dual ring has **twice the capacity** of the single ring as data can travel in **both directions** simultaneously
     -   **provides protection** in the case of a link failure between two nodes

<img src="assets/Screenshot 2023-04-18 at 16.31.43.png" alt="Screenshot 2023-04-18 at 16.31.43" style="zoom:50%;" />

-   Evaluation

| pros                                                         | cons                                                       |
| ------------------------------------------------------------ | ---------------------------------------------------------- |
| Cable faults are easily located, making troubleshooting easier | Expansion to the network can cause network disruption      |
| Ring networks are moderately easy to install                 | A single break in the cable can disrupt the entire network |



#### 6. Mesh

-   Nodes in the network are **connected to other nodes with a point-to-point link**
-   The mesh topology is divided into two variants



1.   **Fully connected mesh**
     -   Each node is connected to other nodes with a point-to-point link
     -   This is generally too expensive for large networks

<img src="assets/Screenshot 2023-04-18 at 16.35.43.png" alt="Screenshot 2023-04-18 at 16.35.43" style="zoom:50%;" />

2.   **Partially connected mesh**
     -   Some of the nodes are connected to more than one other node
     -   Without the expense and complexity required for a connection

<img src="assets/Screenshot 2023-04-18 at 16.37.00.png" alt="Screenshot 2023-04-18 at 16.37.00" style="zoom:50%;" />

-   Evaluation

| pros                                                         | cons                                                  |
| ------------------------------------------------------------ | ----------------------------------------------------- |
| Provide redundant paths between devices                      | Requires **more cable** than the other LAN topologies |
| The network can be expanded without disruption to current users | Complicated implementation                            |



#### 7. Tree (Hierarchical Network)

-   A central 'root' node is connected to one or more other nodes of lower levels
-   The network can consist of multiple levels or layers.
-   Each node in the network has a specific fixed number of nodes connected to it, the number, being referred to as the **'branching factor'**.

<img src="assets/Screenshot 2023-04-18 at 16.39.19.png" alt="Screenshot 2023-04-18 at 16.39.19" style="zoom:50%;" />



#### 8. Hybrid

-   a combination of any two or more topologies
-   Two common examples of hybrid network topology
    -   star bus and star ring

<img src="assets/Screenshot 2023-04-18 at 16.40.07.png" alt="Screenshot 2023-04-18 at 16.40.07" style="zoom:50%;" />



#### 9. Evaluation for Wireless Networking

| pros                                                         | cons                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| Allows for wireless **remote access**                        | Potential **security issues** associated with wireless transmissions |
| The network can be expanded **without disruption** to current users | **Limited speed** in comparison to other network topologies  |























