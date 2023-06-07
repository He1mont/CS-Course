#!/usr/bin/env python3

# We can use the import statement to include other python
# code or modules within our programs. There is a large
# collection of existing functionality in the standard library.
# Here we import the maths module from the standard library
# (https://docs.python.org/3/library/math.html) 
# which allows use to perform common mathematical operations

from math import sqrt

# Sometimes, we will only want to import a specific piece
# of functionality from a module. We can specify which we want
# by using the "from" keyword, as below. 
# This line should be read as "from the module os, import the
# function "getcwd" into the current namespace.

from os import getcwd
# cwd: currently working directory


# We use "#" to write comments. This will be ignored by Python.

# There are no brackets to define structure as there is in C. 
# This is completely replaced by indentation.

# We declare a function using the "def" keyword, followed by the
# function name (square) and (). Inside the () we may add parameters
# (x). Multiple parameters can be specified by using "," e.g. (x,y,z)

def square(x):
    # Simply return the number (parameter) timed by itself.
    return x * x

# We can define some parameters as being optional, 
# by specifying a default value, 
# as we've done here with parameter b.
# This can be overridden by the caller e.g. (sayHi("Jack", "Jill")
def sayHi(a, b="Bob"):
    print("Hello", a, "and hello", b)
    
# This is how we define our main entry point into the program
if __name__ == "__main__":
    
    # We can declare variables without specify a type. 
    # Python is dynamically typed, meaning a type will be deduced, by the Python runtime
    
    a = 0  # Integer
    b = 1.3 # Decimal Number
    c = "Hello!" # String
    d = True # Boolean
    e = None # NoneType: indicating the absence of a value.
    f = float('1.3') # Convert string to float
    print(type(f)) # type() returns a variable's type
    
    # We can output, to the console, using "print"
    print("hello world")
    # Print can accept many values, of many types.
    print(a, b, c, d, e)
    
    # If conditional,
    if a > 0:
        print("Number is positive")
    elif a < 0:
        print("Number is negative")
    else:
        print("Number is 0")
        
    # List
    # Here we define a list of names
    names = ["Alex", "Bob", "Charlie", "Dan"]
    
    # python will perform i++ automatically
    for name in names:
        print(name)
        
    # Print the entire list:
    print(names)
    # Print the second element of the list:
    print(names[1])
    # Add a new name to the list:
    names.append("Evan")
    # There are built-in methods to help us manage lists
    # Sort the list:
    names.sort()
    # Print the new list:
    print(names)
    
    # Tuple
    point = (12.34, 56.78)
    print(point)
    print(point[0])
    
    # Dictionary

    # {key:value, key1:value1, .... }
    population = {"UK": 66796807, "China": 1427647786}
    # Print out China's population
    print(population["China"])
    # Add a new 
    population["Malaysia"] = 31530000
    print(population)
    
    # We can loop using "for". Here we say, for each element
    # in our list ([1,2,3,4,5]), represent each single element
    # with the variable named i. We then pass "i" to the function
    # we defined above (square) and print the value returned from 
    # that function
    for i in [1,2,3,4,5]:
        print(square(i))
        
    sayHi("Alex")
    sayHi("Jack", "Jill")
    
    # Sometimes, we will only want to import a specific piece
    # of functionality from a module. We can specify which we want
    # by using the "from" keyword, as below. 
    # This line should be read as "from the module os, import the
    # function "getcwd" into the current namespace.
    
    # We can use the a method provided by the math library
    #(imported at the top of this file)
    print(sqrt(12345))
    
    # We explicitly imported getcwd from the os module, therefore
    # we do not need to prepends "os." before it.
    print(getcwd())