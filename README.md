*This project has been created as part of the 42 curriculum by narginaa.*

# Philosophers

## Description

The **Philosophers** project is a concurrency exercise in C that simulates the classic Dining Philosophers problem.
The goal is to learn how to create threads, manage shared resources with mutexes, and ensure proper synchronization in a multithreaded environment.
Philosophers eat, think, and sleep while trying to avoid starving by properly acquiring and releasing forks.

## Instructions

### Compilation

To compile the project, run:
```Bash
make
```
### Usage

Run the program with the required arguments:
```Bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```
Example:
```Bash
./philo 5 800 200 200
```
- `number_of_philosophers`: Total philosophers/forks.  
- `time_to_die` (ms): Maximum time a philosopher can go without eating before dying.  
- `time_to_eat` (ms): Time it takes to eat (requires holding two forks).  
- `time_to_sleep` (ms): Time spent sleeping.  
- `[number_of_times_each_philosopher_must_eat]` (optional): Stops the simulation once all philosophers eat this many times.

## Rules & Mechanics

- Philosophers sit around a round table with one fork between each pair.  
- Philosophers **cannot eat** without acquiring both left and right forks.  
- They alternate between **eating**, **sleeping**, and **thinking**.  
- The simulation stops when **a philosopher dies** or when all philosophers have eaten the required number of times (if specified).  

### Logging

Each state change must be printed in the format:
timestamp_in_ms X has taken a fork
timestamp_in_ms X is eating
timestamp_in_ms X is sleeping
timestamp_in_ms X is thinking
timestamp_in_ms X died

- `timestamp_in_ms`: Current timestamp in milliseconds since the simulation started.  
- `X`: Philosopher number.  
- Death messages must appear **within 10 ms** of actual death.  

## Controls & Interaction

- This program has no interactive input once running; it only prints philosopher states to the terminal.  
- The mandatory part uses threads and mutexes.  
- The bonus part uses processes and semaphores, where each philosopher is a separate process.  

## Technical Implementation

- **Threads & Mutexes**: Each philosopher is represented as a thread; forks are protected by mutexes.  
- **Time Management**: `gettimeofday()` and `usleep()` are used to handle precise timing for eating, sleeping, and death checks.  
- **Monitoring**: A dedicated monitor tracks the last meal of each philosopher and prints death messages immediately.  
- **Process Bonus**: The bonus part replaces threads with processes and forks are represented by semaphores.  

## Resources

- [42 Curriculum Subject PDF](https://www.42.fr/) – Official project instructions and requirements. 
- [DINING-PHILOSOPHERS PROBLEM: SIMPLIFIED](https://www.youtube.com/watch?v=VSkvwzqo-Pk) - Short video that delves on the subject's problem.
- [pthread Documentation](https://man7.org/linux/man-pages/man7/pthreads.7.html) – Reference for threads and mutexes.  
- [Threads, Mutexes and Concurrent Programming in C](https://www.codequoi.com/en/threads-mutexes-and-concurrent-programming-in-c/#concurrent-programming) – More documentation on threads and mutexes.  
- AI Assistance: Used ChatGPT for clarifying concurrency pitfalls and testing strategies. All code and logic were implemented manually and fully understood.  

## Testing Examples
5 philosophers, die in 800ms, eat 200ms, sleep 200ms
```Bash
./philo 5 800 200 200
```
4 philosophers, with optional meal limit
```Bash
./philo 4 410 200 200 3
```
