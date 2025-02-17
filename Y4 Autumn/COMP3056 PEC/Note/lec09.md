# lec09: Trust, Safety and Reliability

[toc]

## Trusting Computer Systems

### Scenario 1: Addtion

- You want the sum of 1,000 numbers. You get three different answers from three different sources:
    - a) One person using pencil and paper
    - b) One person using a calculator
    - c) One person using dedicated spreadsheet software

### Scenario 2: Translation

- You need a Russian poem translated. You get three different answers from three different sources:

    - a) You ask a friend, who is a Russian major, for a translation
    - b) You use dedicated translation software to do it yourself
    - c) You search the poem’s title and find a translation on the Internet

## Computer Failure: Causes

### Causes of Computer Failure

- **Hardware errors**
    - Hardware malfunctions causing erroneous results
- **Software errors**
    - Software “bugs” in code or software design
- **Computer solves the wrong problem**
    - Programmers incorrectly understand requirements of clients. Program does as intended (no bugs) but does not do what client wants and expects
- **Misuse**
    - Using system for the wrong purpose, or using system incorrectly for the right purpose. E.g., “Garbage in, garbage out”
- **Communication failure (in human interaction)**
    - User prompted for action misunderstands (e.g., airplane refuel, user assumes amount in gallons rather than litres – plane runs out of fuel!)
- **Malice**
    - Malicious software (virus, trojan, hacking …) for profit, terrorism, warfare, “fun”

### Case: Software Error

- ESA unmanned space flight: Rockets explode

### Case: Hardware Error

- Intel about flaw in P5 chip

## Bugs and Public Safety

### Safety-Critical Software (SCS)

- Software that affect somebody’s safety if fails to work properly
    - Air traffic control, nuclear safety system, medical, etc.
- Standards of creating, testing, and maintaining SCS are much stricter than other software
- Exhaustive testing is the obvious answer, but large number of decision-points in software makes this impossible
- Software also control machinery and equipment, therefore
    - Real-time software systems (e.g., avoid object before crash)
    - Software executes in multi-process environments (e.g., accelerate, brake, avoid)
    - These greatly complicate testing

**Some improvements have been achieved**

- Better education and training of engineers, programmers, analysts
- More sophisticated software testing procedures
    - May include formal verification (like a mathematical proof)
- Better maintenance
- Refocus on prevention rather than detection/correction
- Simulation can be beneficial (e.g., air-disaster)
- Emphasis on ethics and professional education

> **CASE**: THERAC-25, Machine designed for cancer treatments

### Moral Responsibility

**Accountability and Moral Responsibility**

- The following people bear **moral** responsibility
    - The programmer who designed software
    - The company’s quality assurance officer
- Not **legal** responsibility

**Birsch's Moral responsibility**

3 criteria must be met for person to bear moral responsibility

1. The person’s actions **must have caused the harm**, or been a significant causal factor

2. The person must have **intended or willed the harm**, or it must be a result of his/her **negligence, carelessness, or recklessness**

3. The person must be able to have known, or must **know the consequences of the action**, or must have deliberately **remained ignorant** of them

Moral responsibility of the **programmer** for **THERAC-25**

1. The programmer made, or at least allowed, the software errors that directly caused radiation overdose

2. As software expert, he ought to know that complex software could have bugs unlikely to be detected by testing. He should have notified management of this fact

3. Programmer knew machine potentially lethal and understood possible consequences of software failure

## Malware

- **Worm**—makes copies of itself and propagates through network to infect other computers
- **Virus**—similar to worm, but resides in another program. Program must execute for virus to propagate
- **Spyware**—program secretly installed for purpose of collecting information about computer’s user(s)
- **Trojan Horse**—software masquerades as innocent and perhaps useful, but actual malicious
- **Rootkit**—program that embeds into OS and acquires special privileges. Potential to override authority of OS, gaining access to passwords and all files

## Summary

- We all **trust** computing systems in our daily lives
    - With our health, safety, banking, security, …
- **Failure** can affect us all and cause pain / death
    - Safety-critical systems
- Failure can be **minimized**
    - Good software engineering / testing
    - Professional and ethical training
- As professionals, we may bear moral responsibility

