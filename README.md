# Philosophers 🧘‍♂️🍝

**Philosophers** is a classic project in system programming curricula. The goal is to simulate the **dining philosophers problem**, an exercise designed to explore concepts of concurrency, synchronization, and thread management.

## Introduction 🚀

The dining philosophers problem involves several philosophers sitting around a circular table. Each philosopher alternates between thinking and eating. To eat, a philosopher needs two forks (one on their left and one on their right). However, a fork can only be used by one philosopher at a time, creating potential synchronization challenges.

This project introduces key concepts such as:
- **Threads** and concurrent execution.
- **Mutexes** for synchronization.
- Preventing issues like **deadlocks**.

## Features ✨

- Simulation of philosophers and their states (thinking, eating, sleeping).
- Efficient management of shared resources (forks).
- Use of **mutexes** to prevent access conflicts.
- Mechanisms to prevent **deadlocks** and ensure smooth execution.

## Code Structure 🧩

### Main Files

- **`main.c`** : Entry point of the program, initializes structures and starts the simulation.
- **`init.c`** : Contains functions to initialize philosophers, forks, and other necessary structures.
- **`monitor_check.c`** : Monitors the philosophers' states and detects starvation or termination.
- **`routine.c`** : Defines the philosophers' core actions (thinking, eating, sleeping) and their associated logic.
- **`utils/`** : Includes auxiliary functions for string manipulation, time management, etc.

### Header File

- **`philo.h`** : Declares functions, structures (like `philosopher`, `info `, etc.), and constants used throughout the project.

## Compilation and Installation ⚙️

To compile the project, use the provided `Makefile`. Available commands include:

- **Compile the project**:
  ```bash
  make
  ```
- **Clean object files**:
  ```bash
  make fclean
  ```
- **Recompile from scratch**:
 ```bash
 make re
 ```
## Usage 🖥️
After compilation, the project produces an executable that can be run as follows:
```bash
./philosophers [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat (optional)]
```
**Example**:
```bash
./philosophers 5 800 200 200
 ```
In this example:
- 5 philosophers are seated at the table.
- Each philosopher will die if they do not eat within 800ms.
- Eating takes 200ms, and sleeping also takes 200ms.

**Output**:
- The simulation outputs real-time actions of the philosophers (thinking, eating, sleeping) and indicates when a philosopher dies.

## Key Concepts 🧠
- ***Threads***: Each philosopher is represented by an independent thread.
- ***Mutexes***: Used to synchronize access to forks and prevent conflicts.
- ***Deadlock Prevention***: Mechanisms are implemented to ensure the program doesn’t freeze if all philosophers try to pick up forks simultaneously.

## Testing 🧪
To test various scenarios, modify the command-line parameters. Here are some interesting scenarios:
- ***Starvation Test***: Simulate a philosopher unable to access a fork for an extended period.
- ***Stress Test***: Increase the number of philosophers to observe how the program handles higher concurrency.





  
  
