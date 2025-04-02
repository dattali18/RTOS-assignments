def EDF(tasks):
    """
    Schedules tasks using the Earliest Deadline First (EDF) algorithm.

    Args:
        tasks: A list of dictionaries, where each dictionary represents a task
               and has the following keys:
               - 'name': The name of the task (string).
               - 'deadline': The deadline of the task (integer).
               - 'execution_time': The execution time of the task (integer).
               - 'arrival_time': The time at which the task arrives (integer).

    Returns:
        A list of strings representing the schedule of tasks, or None if the
        tasks are not schedulable.
    """

    # Sort tasks by arrival time
    tasks.sort(key=lambda task: task['arrival_time'])

    current_time = 0
    schedule = []
    ready_queue = []

    while tasks or ready_queue:
        # Add newly arrived tasks to the ready queue
        while tasks and tasks[0]['arrival_time'] <= current_time:
            ready_queue.append(tasks.pop(0))

        # Sort the ready queue by deadline
        ready_queue.sort(key=lambda task: task['deadline'])

        if not ready_queue:
            current_time += 1  # Idle time
            continue

        # Select the task with the earliest deadline
        current_task = ready_queue.pop(0)

        # Check if the task can meet its deadline
        if current_time + current_task['execution_time'] > current_task['deadline']:
            print("Tasks are not schedulable! Deadline missed.")
            return None

        # Execute the task
        schedule.append(f"{current_time}: {current_task['name']}")
        current_time += current_task['execution_time']

    return schedule


# Example usage:
tasks = [
    {'name': 'Task A', 'deadline': 5, 'execution_time': 2, 'arrival_time': 0},
    {'name': 'Task B', 'deadline': 7, 'execution_time': 3, 'arrival_time': 2},
    {'name': 'Task C', 'deadline': 10, 'execution_time': 2, 'arrival_time': 4},
]

schedule = EDF(tasks)

if schedule:
    print("Schedule:")
    for item in schedule:
        print(item)