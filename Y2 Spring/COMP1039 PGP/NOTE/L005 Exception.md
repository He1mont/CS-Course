## L005: Exception Handling

##### 1. Exceptions

-   Compile-time error:
    -   syntax errors, e.g. `int n =  "Integer";`
    -   detected by the **java compiler**
    -   cannot be executed
-   Run-time error: exceptions only happens at run time
    -   index out or range, ... (most programming logic problems)
    -   detected by the **JVM**
    -   can be executed
    -   can be handled **by a block of code called exception handler**



##### 2. Exception Hierarchy

-   All runtime errors are classes derived from a class called **Throwable**, i.e. `java.lang.Throwable`
-   Two direct subclass of Throwable
    -   Error: system errors beyond control
    -   Exception: errors that result from program activity
        -   RuntimeException: caused by programming errors



##### 3. Checked vs Unchecked Exception

-   Unchecked Exceptions:
    -   RuntimeException, Error and their subclasses
    -   Reflect programming logic errors that are not recoverable
    -   Java does not force you to catch
-   Checked Exceptions
    -   All other exceptions are known as checked exceptions
    -   I/O exception: related to hardware
    -   File Not found
-   Unchecked Exceptions are denoted in blue frame

<img src="assets/Screenshot 2023-03-30 at 17.22.59.png" alt="Screenshot 2023-03-30 at 17.22.59" style="zoom:40%;" />



-   Unchecked Exceptions

    | Exception              | Meaning                                            |
    | ---------------------- | -------------------------------------------------- |
    | ArithmeticException    | Arithmetic errors                                  |
    | NullPointerException   | Invalid use of a null reference                    |
    | NumberFormatException  | Invalid conversion of a string to a numeric format |
    | ClassCastException     | Invalid Cast                                       |
    | ArrayIndexOutOfBounds  | Array index is out-of-bounds                       |
    | IndexOutOfBounds       | Some type of index is out of bounds                |
    | StringIndexOutOfBounds | Attempt to index outside the bounds of a string    |
    | ...                    | ...                                                |



##### 4. Exception Handling

-   `try`: used to monitor exceptions
-   `catch`: used to catch the exceptions and define how to handle it
-   `throw`: used to manually throw an exception
-   `throws`: used in the method signature to declare an exception which might be thrown by executing this method

-   `finally`: to declare any code that must be executed upon exiting from a try block



##### 5. Try and Catch

```java
try{
    // block of code to monitor
    
} catch (ExceptionType1 exOb){
    // handler for exception 1
    
} catch (ExceptionType2 exOb){
    // handler for exception 2
    
}
```



##### 6. Throw an Exception

-   use **throw** keyword to throw an exception manually

```java
try{
	System.out.println("Before");
    throw new ArithmeticException();
} catch(ArithmeticException exc){
    System.out.println("Exception caught");
}
```



##### 7. Finally

-   we may want to execute some code no matter there is an exception or not

```java
try{
    System.out.println("Before");
    throw new ArithmeticException(); 
    // no exception detected, but we manually throw one exception	
}
catch(ArithmeticException exc){
    System.out.println("Exception caught");
    return;
}
finally{
  	System.out.println("Finally");
}
System.out.println("After");
```



##### 8. Throws

-   if a method generates an exception that does not need to be handled, then it must declare that exception
-   `except-list` : a list of exceptions the method might throw outside of itself

```java
public static char propmt(String str) throws java.io.IOException{
    System.out.println(str + ": ");
    return (char) System.in.read();
    // a method to read the next byte from the input
}
public static void main(String[] args){
    char ch = 'X';
    try{
        ch = prompt("Enter a letter");
    } catch(java.io.IOException exc){
        System.out.println("I/O exception occurred.");
    }
    System.out.println("You pressed " + ch);
}
```



##### 9. Throws vs Exception Handling

-   when to use **throws**
    -   all checked exceptions must be thrown
    -   if you want the exception to be processed by its caller
-   when to use **try-catch** block
    -   to deal with unexpected error conditions
    -   if you want to handle the exception in the method where it occurs























