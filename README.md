# Thread Safe Prime Counter

### Background for this task </br>
You have an endless data stream that should be processed fast. For example, security camera data where an 
intrusion should be detected.</br>
In this assignment, we will use a random number generator that simulates the endless stream. The task is to count the number of prime numbers in this stream.</br>

File explanation:</br>
**generator.c:**</br>
This file will create random numbers that simulate the endless stream. We will be piping the output from this program to the next file.</br>

**primeCounter.c:**</br>
This is the initial code given. This will get the endless stream from compiling and running generator.c and for every number, check if it is a prime number and sum the amount of primes.</br>

**MyPrimeCounter.c:**</br>
This is my code that is the solution to the assignment given:</br>
isPrime function: the original function given.</br>
is_prime function: is my new function for checking prime numbers.</br>
Threads function: to manage the threads.</br>
main function: to run it all.</br>
**Note: when running this code you need to change in it the prime function you want to run !!**</br>

**Makefile:**</br>
Running ``` make all ``` will create the following files we can run:</br>
randomGenerator: this is the runnable file connected to generator.c ``` ./randomGenerator <seed> <num_of_numbers> ```</br>
primeCounter: this is the runnable file connected to primeCounter.c ``` ./randomGenerator <seed> <num_of_numbers> | ./primeCounter ```</br>
MyPrimeCounter: this is the runnable file connected to MyPrimeCounter.c ``` ./randomGenerator <seed> <num_of_numbers> | ./MyPrimeCounter ```</br>

## This repository involves</br>
a) The best solution code. </br>
and in the README: </br>

## Time improvement:
Screenshot with 10M numbers checked by the provided primeCounter.c + time </br>   
![image](https://github.com/zeevfischer/PrimeCounter/blob/main/img/all%20original.png)</br>

Screenshot with 10M numbers checked by MyPrimeCounter.c with the original prime function + threads + time. This is around 4 times better. </br>  
![image](https://github.com/zeevfischer/PrimeCounter/blob/main/img/original%20prime%20add%20threads.png)</br>

Screenshot with 10M numbers checked by our solution's better prime function and threads + time. This is around 10 times better. </br>   
![image](https://github.com/zeevfischer/PrimeCounter/blob/main/img/original%20prime%20add%20threads.png)</br>

## RAM space:</br>
In each image, you can see that the "Maximum resident set size (kbytes)" does not exceed 2000 kbytes = 2 MB</br>

## How to run</br>
**Note: the code MyPrimeCounter is set to run the optimal prime function but if you want you can change to the original**</br>
1. download this repository and open it in a linux based environment.
2. in the terminal run ``` make all ```</br>
3. for the original code run: ``` ./randomGenerator 10 10000000 | time -v ./primeCounter ```</br>
4. for the optimizedcode run: ``` ./randomGenerator 10 10000000 | time -v ./MyPrimeCounter ```</br>
