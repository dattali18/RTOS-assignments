# Exercise 1: Execution of Cyclic Processes

**Course:** Real-time and Reactive Systems (153203)
**Lecturer:** Dr. Arie Teitelbaum, Y. Levian

**Objective:** Implement and compare algorithms for managing the execution of cyclic processes.

**Description:**

The algorithm manages cyclic processes. Each process needs to be executed for a specified number of cycles, according to its defined cycle time.  Each process aims to complete its activity once per cycle.

**Example:**

| Process | Cycle Time | Cycles |
|---|---|---|
| A | 5 | 3 |
| B | 7 | 4 |
| C | 10 | 5 |

* Process A completes its activity every 5 time units.
* Process B completes its activity every 7 time units.
* Process C completes its activity every 10 time units.

**Algorithm for Managing Process State:**

* Decrease the cycle time counter for all processes.
* If a new cycle time has arrived, restore the process data and put the process to work. 
* If an error occurs (process is still running from the previous cycle), display an appropriate message and exit the program.

**Algorithms for Selecting the Next Task:**

The algorithm must determine which process replaces the currently running process. 

* Note: There may be idle time slots.

**Algorithms to Implement:**

1.  **EDF (Earliest Deadline First):**
    * The process with the least time remaining until the end of its cycle gets priority.
    * Choose the process with the most urgent deadline.
    * If no task needs to run but there are tasks with remaining work, allow the background loop to run.
2.  **RoundRobin:** (Given)

**Implementation Details:**

* Add necessary fields to the `Task` class.
* Adapt the `declareTask` function to handle cycle time and the number of execution cycles.
* Implement a `reDeclare` function to restore task data for reuse (similar to the scheduler's restoration process).
* Write functions to implement the EDF and RoundRobin algorithms.
* Run the application with both algorithms and test various scenarios, including successful and unsuccessful executions.

**Submission:**

* Submit the exercise in the eighth week of the semester. 
