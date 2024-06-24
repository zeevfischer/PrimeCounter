# Compiler
CC = gcc
CXX = g++

# Compiler flags
CFLAGS = -std=c11 -O2
CXXFLAGS = -std=c++11 -O2 -pthread

# Target executables
TARGETS = randomGenerator primeCounter liav anna MyPrimeCounter

.PHONY: all clean

# Default target
all: $(TARGETS)

# Rule to build the random number generator
randomGenerator: generator.c
#	$(CC) $(CFLAGS) -o $@ $<
	$(CC) -o randomGenerator generator.c

# Rule to build the prime counter in C
primeCounter: primeCounter.c
#	$(CC) $(CFLAGS) -o $@ $<
	$(CC) -o primeCounter primeCounter.c

MyPrimeCounter: MyPrimeCounter.c
	$(CC) -o MyPrimeCounter MyPrimeCounter.c

# Clean rule to remove generated files
clean:
	-rm -f $(TARGETS)
