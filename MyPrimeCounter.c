#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdatomic.h>
#include <limits.h>

// pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
// using atomic means i dont need to use mutex as you can see i started with it but commented it out !!
atomic_int counter = 0;

// intetnet function to check if a number is prime
bool is_prime(int n)
{
    if (n <= 1) {
        return false;
    }
    if (n <= 3) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}
// original Function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// Threads: function to handel the threads
void* Threads(void* arg)
{
    int Thread_counter = 0;
    int num;

    while (scanf("%d", &num) != EOF)
    {
        // Check if the number is prime
        if (is_prime(num))
        {
            Thread_counter++;
        }
    }

    // pthread_mutex_lock(&count_mutex);
    counter += Thread_counter;
    // pthread_mutex_unlock(&count_mutex);

    pthread_exit(NULL);
}

int main()
{
    int CPU_cores = sysconf(_SC_NPROCESSORS_ONLN);
    printf("%d CPUs \n" ,CPU_cores);

    int num_of_threads = CPU_cores / 2;
    printf("number of threads: %d\n" ,num_of_threads);

    pthread_t threads[num_of_threads];

    for (int i = 0; i < num_of_threads; ++i) {
        pthread_create(&threads[i], NULL, Threads, NULL);
    }

    // Join threads
    for (int i = 0; i < num_of_threads; ++i) {
        pthread_join(threads[i], NULL);
    }

    printf("%d total primes.\n", counter);
    return 0;
}
// #include <stdio.h>
// #include <stdbool.h>
// #include <pthread.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <stdatomic.h>
// #include <limits.h>
// #include <sys/mman.h>

// #define STACK_SIZE (128 * 1024) // Stack size set to 8 KB

// atomic_int counter = 0;

// // Function to check if a number is prime
// bool is_prime(int n)
// {
//     if (n <= 1) return false;
//     if (n <= 3) return true;
//     if (n % 2 == 0 || n % 3 == 0) return false;
//     for (int i = 5; i * i <= n; i += 6) {
//         if (n % i == 0 || n % (i + 2) == 0) return false;
//     }
//     return true;
// }

// // Thread function to handle the threads
// void* Threads(void* arg)
// {
//     int Thread_counter = 0;
//     int num;

//     char buffer[2048];
//     while (fgets(buffer, sizeof(buffer), stdin) != NULL)
//     {
//         num = atoi(buffer);
//         if (is_prime(num)) {
//             Thread_counter++;
//         }
//     }

//     counter += Thread_counter;

//     pthread_exit(NULL);
// }

// int main()
// {
//     int CPU_cores = sysconf(_SC_NPROCESSORS_ONLN);
//     CPU_cores = (CPU_cores / 2); // Using half the available cores to be conservative with memory
//     printf("%d CPUs\n", CPU_cores);
//     pthread_t threads[CPU_cores];

//     // Set thread attributes to reduce stack size
//     pthread_attr_t attr;
//     pthread_attr_init(&attr);
//     pthread_attr_setstacksize(&attr, STACK_SIZE);

//     for (int i = 0; i < CPU_cores; ++i) {
//         void *stack;
//         if (posix_memalign(&stack, sysconf(_SC_PAGESIZE), STACK_SIZE) != 0) {
//             perror("posix_memalign");
//             exit(EXIT_FAILURE);
//         }

//         pthread_attr_setstack(&attr, stack, STACK_SIZE);
//         pthread_create(&threads[i], &attr, Threads, NULL);
//     }

//     pthread_attr_destroy(&attr);

//     // Join threads
//     for (int i = 0; i < CPU_cores; ++i) {
//         pthread_join(threads[i], NULL);
//     }

//     printf("%d total primes.\n", counter);
//     return 0;
// }
