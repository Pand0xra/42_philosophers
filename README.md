# Philosophers (42 School Project)

![Language](https://img.shields.io/badge/language-C-blue)
![Threads](https://img.shields.io/badge/threads-pthread-orange)
![Mutex](https://img.shields.io/badge/synchronization-mutex-red)
![Status](https://img.shields.io/badge/status-completed-brightgreen)
![Github code size in bytes](https://img.shields.io/github/languages/code-size/Pand0xra/42_so_long?color=6272a4)
![Main Language](https://img.shields.io/github/languages/top/Pand0xra/42_so_long?color=6272a4)
![License](https://img.shields.io/github/license/Pand0xra/42_so_long?color=6272a4)

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

## Mistakes / Lessons Learned
### Deadlock Prevention
#### 1. Resource Hierarchy (Dijkstra’s approach)
Initially, all philosophers attempted to lock forks in the same order (by left first), which caused a circular dependency
where every philosopher could hold one fork indefinitely.

Solutions:
A global ordering was enforced on fork acquisition.
Each philosopher always locks the lower-indexed fork first, preventing ciruclar wait conditions.

```c
if (philo->left_fork < philo->right_fork)
	{
		pthread_mutex_lock(philo->left_fork);
		ft_print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		ft_print_status(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		ft_print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		ft_print_status(philo, "has taken a fork");
	}
```
#### 2. Staggered Start (Contention Reduction)
To reduce contention and prevent all philosophers from attempting to grab their forks simultaneously,
even-numbered philosophers are slightly delayed at startup.
```c
if (philo->id % 2 == 0)
		ft_usleep(philo->data->time_to_eat / 2);
```
> [!NOTE]
> This improves scheduling distribution but does not replace proper deadlock prevention.

### Data Races
Shared variables such as:
- `last_meal_time`
- `meals_eaten`
- simulation state
required mutex protection to avoid inconsistent reads/writes between philosopher and monitor threads.
> [!NOTE]
> Without a dedicated print mutex, philosopher messages became interleaved.
> All console output is protected by a mutex for clarity and correctness.

### Timing Accuracy
Using `usleep()` directly caused inaccurate sleeping times and delayed philosopher death detection.

Solution:
- implemented a custom sleep function with frequent wake-ups and checks

### Single Philosopher Edge Case
A single philosopher can only take one fork and must eventually die after `time_to_die`.
Special handling was required to avoid undefined behavior and invalid fork access.

## Resources

- 42 Curriculum Subject PDF – internal curriculum
- [DINING-PHILOSOPHERS PROBLEM: SIMPLIFIED](https://www.youtube.com/watch?v=VSkvwzqo-Pk) - simplified explanation
- [pthread Documentation](https://man7.org/linux/man-pages/man7/pthreads.7.html) – Reference for threads and mutexes.  
- [Threads, Mutexes and Concurrent Programming in C](https://www.codequoi.com/en/threads-mutexes-and-concurrent-programming-in-c/#concurrent-programming) – Code example and concurrency explanations 
- External references and debugging tools were used to validate concurrency behavior and edge cases.

## Testing Examples
5 philosophers, die in 800ms, eat 200ms, sleep 200ms
```Bash
./philo 5 800 200 200
```
4 philosophers, with optional meal limit
```Bash
./philo 4 410 200 200 3
```
## Debugging & Testing

### Compile with debug symbols
```bash
make re CFLAGS="-Wall -Wextra -Werror -g3"
```

---

### Compile with AddressSanitizer (memory errors)
Detects:
- invalid memory access
- use-after-free
- buffer overflows
- double free

```bash
make re CFLAGS="-Wall -Wextra -Werror -g3 -fsanitize=address"
```

---

### Compile with ThreadSanitizer (data races)
Detects:
- data races
- synchronization issues
- thread misuse

```bash
make re CFLAGS="-Wall -Wextra -Werror -g3 -fsanitize=thread"
```

---

### Use Helgrind (thread error detection)
Checks:
- data races
- mutex misuse
- lock ordering issues
- possible deadlocks

```bash
valgrind --tool=helgrind --max-threads=300 ./philo 200 800 200 200
```
> Built by Pand0xra as part of the 42 curriculum.
