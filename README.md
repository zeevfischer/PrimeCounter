# Thread Safe Prime Counter

### Background for this task </br>
You have an endless data stream that should be processed fast. For example, security camera data is where an 
intrusion should be detected.</br>
In this assignment, we will use a random number generator that simulates the endless stream, the task is to count the number of prime numbers in this stream.</br>

File explanation:</br>
**generator.c:**    
This file will creat random numbers that simulates the endless stream, we will be piping the out put from this program to the next file.   

**primeCounter.c**    
This is the inithal code given this will get the endless stream from compiling and runing generator.c and for every number check if is a prime number and sum the amount of primes.   

**MyPrimeCounter.c**    
This is my code that is the solution of the assiment given:   
isPrime function: the original function given.      
is_prime function: is my new function for checking prime numbers.     
Threads function: to manage the threads.    
main function: to run it all.   
**Note: when running this code you need to change in it the prime function you want to run !!**

**Makefile**
runing ``` make all ``` will creat the following files we can run:   
randomGenerator: this is the runable file connected to generator.c ``` ./randomGenerator <seed> <num_of_numbers> ```      
primeCounter: this is the runable file connected to primeCounter.c ``` ./randomGenerator <seed> <num_of_numbers> | ./primesCounter ```   
MyPrimeCounter: this is the runable file connected to MyPrimeCounter.c ``` ./randomGenerator <seed> <num_of_numbers> | ./MyPrimeCounter ```   

## This repository involves
a) The best solution code. </br>
and in the README: </br>
b) Screenshot with 10M numbers checked by the provided primeCounter.c + time </br>
c) Screenshot with 10M numbers checked by our solution + time </br>
d) proof of RAM usage below 2MB </br>

## How to run
1. ``` make all ```
2. ``` ./randomGenerator <seed> <num_of_numbers> | ./primeCounter ```

For example:
1. ``` make all ```
2. ``` ./randomGenerator 10 10000 | ./primeCounter ```

To see the time:
1. ``` make all ```
2. ``` time ./randomGenerator 10 10000 | ./primeCounter ```

To see the usage of RAM:
1. ``` make all ```
2. ``` valgrind --tool=massif --massif-out-file=massif.out ./randomGenerator 10 10000 | ./primeCounter  ```
3. ``` ms_print massif.out ```
 

## Time improvement:
Base code:
![image](https://github.com/annapinchuk/thread_safe_prime_counter/assets/78349342/400ad7d4-295d-4b78-b362-8dd170faf42e)

Better isPrime function:
![image](https://github.com/annapinchuk/thread_safe_prime_counter/assets/78349342/90164e16-bca2-4856-999b-78e6b5bdcb04)

Usage of better isPrime function and threads:
![image](https://github.com/annapinchuk/thread_safe_prime_counter/assets/78349342/7469aae7-d38b-42b8-96ae-4923b8b236a1)

## RAM space:
As we can see in the image the memory usage is 7.5 KB.
![image](https://github.com/annapinchuk/thread_safe_prime_counter/assets/78349342/761e8cc7-b80c-489a-92a7-ac95ee0cd186)
