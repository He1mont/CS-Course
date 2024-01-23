# lec13: Concurrency 6: Beyond Locks

>   **Overview**
>
>   -   Trouble with locks
>
>   -    Alternative Concurrency Approaches

## **The trouble with locks**

-   **Deadlocks.**
-   **Starvation.**
-   **Priority inversion.**
-   **Lack of compositionality**
    -   you cannot compose small correct concurrent programs to form large correct concurrent programs.
-   **Livelock**
    -   We could try to grab locks and back-off if we cannot acquire them all we risk another problem

-   **Access to shared state is implicit**
    -   it can be hard to tell who’s modifying what, and if suitable locks are held at the time.
-   **Lock convoying** 
    -   threads end up queuing up behind a thread holding a lock - linearizes behaviour and can take a long time to clear.

## Alternative Concurrency Approaches

**Two alternatives**

-   Message passing
    -   **synchronous**
    -   **asynchronous**

-   Transactional memory

### **Synchronous Message Passing**

>   **Phone Calls**

-   We **avoid sharing memory**, instead we have channles `c`, `d`
-   There are two opeations on channle `c``
    -   `c(x)` sends message x over the channel.
    -   `-c(x)` receives a value over the channel into x .
-   Communication is **synchronous** 
    -   a send must wait for a corresponding receive and vice-versa. 

    -   **Think phone calls.**


<img src="assets/Screenshot 2024-01-18 at 02.13.31.png" alt="Screenshot 2024-01-18 at 02.13.31" style="zoom:50%;" />

**Pros and Cons**

-   Flow of data is **explicit**
    -   no exposure to **race conditions** and other difficult debugging.
-   Synchronizing senders and receivers can **slow performance.**
-   Concurrency problems casued by using mutexes and semaphores using synchronous message passing
    -   **deadlocks, starvation etc. all still possible**.



### **Asynchronous Message Passing**

>   **Sending Emails**

**Pros and Cons**

-   Flow of data is **explicit**
    -   no exposure to **race conditions** and other difficult debugging.
-   May be **less efficient** than shared memory.
-   **Less explicit** coupling between senders and receivers.
-   Concurrency problems casued by using mutexes and semaphores using synchronous message passing
    -   **deadlocks, starvation etc. all still possible**.



### **Transactional Memory** (A Database Analogy)

>   Consider the following situation

<img src="assets/Screenshot 2024-01-18 at 02.20.35.png" alt="Screenshot 2024-01-18 at 02.20.35" style="zoom:50%;" />

-   Transferring the money to Geert requires two steps:
    -   Deduct £10 from the Dan account. 
    -   Add £10 to the Geert account.

>   Similar to **Git**

```C
do { 
    begin_transaction(); 
    modify_shared_data(); 
    commit(); 
} while(!transaction_succeeds());
```

-   No **locks**, and no risk of **deadlock.**
-   A form of **livelock** still possible
    -   as we back-off and try again after rollbacks.
-   **Starvation** still possible
    -   smaller transactions may cause repeated rollbacks of longer ones.





