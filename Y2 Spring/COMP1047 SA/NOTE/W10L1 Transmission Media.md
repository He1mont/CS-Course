## W10L1: Transmission Media

>   ### Outline
>
>   -   Concept of a Channel
>   -   Twisted Pair Cables
>       -   UTP and STP
>       -   Features
>       -   Cat-5
>       -   Crosstalk
>       -   Evaluation
>   -   Coaxial Cables
>   -   FTTx
>       -   Common architectures
>       -   OAN, OLT, ONU
>       -   Features
>       -   Benefits
>
>   -   Copper vs. Fibre



#### 1. Concept of a Channel

-   In terms of the physics underlining propagation, channels are divided into two categories:

    -   ==Unguided wave channels==
        -   propagation through **wave diffraction**
        -   e.g.: audio channel, atmospheric channel, free space channel
        -   通过空气自由传播电磁波来传输数据，传输距离、速度不稳定
    -   ==Guided wave channels==
        -   propagation through **wave guidance**
        -   e.g.: twisted wire pairs, coaxial cables, optical fibre cables
        -   通过物理媒介来传输电流或光信号，传输距离、速度更加稳定

    

#### 2. Twisted Pair Cables

-   ==most wide spread medium in the world==
-   A thin-diameter wire (22 to 26 gauge) commonly used for telephone and network cabling.

<img src="assets/Screenshot 2023-04-25 at 09.40.02.png" alt="Screenshot 2023-04-25 at 09.40.02" style="zoom:50%;" />

-   **Twisted Pair Cables**
    -   Unshielded Twisted Pair
    -   Shielded Twisted Pair

-   **Unshielded Twisted Pair**
    -   used for networking applications, such as Ethernet and telephone connections.
    -   less expensive and more flexible
    -   more susceptible to interference 
-   **Shielded Twisted Pair**
    -   have an extra layer of shielding
    -   used in environments **with high levels of electromagnetic interference**, such as industrial settings or hospitals
    -   more expensive and less flexible

<img src="assets/Screenshot 2023-04-25 at 09.45.33.png" alt="Screenshot 2023-04-25 at 09.45.33" style="zoom:40%;" />

-   A view of shielded and screened twisted pair

<img src="assets/Screenshot 2023-04-25 at 09.45.55.png" alt="Screenshot 2023-04-25 at 09.45.55" style="zoom:60%;" />



#### 3. The features of channels

-   From the transmission view point, the parameters that will influence the performance are
    -   DC resistance
        -    the resistance of the flow of direct current
        -   电线或电缆材料的特性，与频率无关
        -   useful for identifying faults and maintaining the connection
        -   known as `Loop Resistance`
    -   Impedance
        -   the total opposition to the flow of an alternating current (AC)
        -   complex resistance provided by the twisted pair over a range of frequencies.
        -   取决于电缆的特性和频率
        -   较低的阻抗可以提供更好的信号传输和降低噪声干扰



#### 4. Cat-5 Cable

<img src="assets/Screenshot 2023-04-25 at 10.13.28.png" alt="Screenshot 2023-04-25 at 10.13.28" style="zoom:50%;" />

-   One of ==the most common== types of twisted pair cable is **category 5**
    -   typically used in structured cabling for computer networks such as ==Ethernet==
    -   suitable for Fast Ethernet (100Mb/s) and Gigabit Ethernet (1Gb/s) [4 pairs]



#### 5. Crosstalk

-   There are two classes if interference
    -   Near End Crosstalk
    -   Far End Crosstalk

-   **Near End Crosstalk (NEXT)**
    -   occurs between two wires in the same cable ==at the same end== (near-end)
-   **Far End Crosstalk (FEXT)**
    -    occurs between two wires in the same cable ==at opposite ends== (far-end)

<img src="assets/Screenshot 2023-04-25 at 10.31.32.png" alt="Screenshot 2023-04-25 at 10.31.32" style="zoom:50%;" />



#### 5*. Evaluation for Twisted Pair Cables

-   **Advantages**
    1.   <u>Cost-effective</u>
    2.   <u>Flexible and Easy to install</u>
    3.   <u>Compatibility</u>: Twisted pair cables are widely used and are compatible with a variety of network equipment.
    4.   <u>Resistant to interference</u>: Twisted pair cables are less prone to electromagnetic and radio frequency interference, which can cause network disruptions and data loss
-   **Disadvantages**
    1.   <u>Limited bandwidth</u> 
    2.   <u>Distance limitations</u>
    3.   <u>Fragility</u>
    4.   <u>Susceptible to crosstalk</u>: Twisted pair cables can suffer from crosstalk interference, which occurs when signals from adjacent cables interfere with each other.
    5.   <u>Limited power delivery</u>: Twisted pair cables are not suitable for high power applications and cannot deliver power over long distances.



#### 6. Coaxial Cables

<img src="assets/Screenshot 2023-04-25 at 10.46.50.png" alt="Screenshot 2023-04-25 at 10.46.50" style="zoom:40%;" />

-   由内部导体、绝缘层、外部导体和外部绝缘层组成
-   **Advantage:**
    -   Resistive loss
    -   Dielectric loss
    -   Radiated loss (least important)



#### 7. Fibre To The x - FTTx

-   Optical Fibres
    -   ultimate at the moment in terms of **broad bandwidth** and **low loss**
    -   extensively used in long distance transmission systems
    -   main application: **Fibre To The x**

-   Fibre To The x
    -   covers a number of technologies and protocols
    -   most common architectures
        -   FTTH
        -   FTTB
        -   FTTC
        -   FTTN

-   Size
    -   A single copper pair is capable of carrying 6 phone calls
    -   A single fibre pair is capable of carrying over 2.5 million phone calls



<img src="assets/Screenshot 2023-04-25 at 10.59.19.png" alt="Screenshot 2023-04-25 at 10.59.19" style="zoom:50%;" />



-   **OAN (Optical Access Network)**
    -   代表的是“光接入网”
    -   a type of broadband network that uses optical fibers to transmit data
    -   connects the service provider's Central Office (CO) to the subscriber's premises
    -   consists of
        -   OLT (Optical Line Terminal)
        -   ONU (Optical Network Unit)
-   **OLT (Optical Line Terminal)**
    -   代表的是“光线路终端”
    -   serves as a ==central point== in a Passive Optical Network (PON)
    -   transmit and receive optical signals to and from ONUs or ONTs
-   **ONU (Optical Network Unit)**
    -   代表的是“光网络单元”
    -   a device used in fiber-optic communication networks
    -   connect the customer's premises to the OLT at the service provider's end
    

<img src="assets/Screenshot 2023-04-25 at 11.05.25.png" alt="Screenshot 2023-04-25 at 11.05.25" style="zoom:50%;" />



-   **Features** of optical fibre
    -   enormous information carrying capacity
    -   easily upgradeable
    -   easily installation
    -   allows fully symmetric services
    -   reduced operations and maintenance costs
-   **Benefits** of optical fibre
    -   very long distance
    -   very less signal attenuation
    -   strong, flexible, reliable
    -   allows small diameter and light weight cables
    -   secure
    -   immune to EMI (electromagnetic interference)



#### 8. Copper pair cables vs. Fibre pair cables

| Aspect              | Copper             | Fibre         |
| ------------------- | ------------------ | ------------- |
| Transmission medium | electrical signals | light         |
| Distance            | limited            | much longer   |
| Bandwidth           | lower              | higher        |
| Cost                | less expensive     | more reliable |

<img src="assets/Screenshot 2023-04-25 at 11.10.30.png" alt="Screenshot 2023-04-25 at 11.10.30" style="zoom:50%;" />



