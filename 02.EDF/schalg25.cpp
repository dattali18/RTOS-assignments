#include "smarts25.h"

int roundRobin()
{
	// Round Robin short-term algorithm 
	int count;
	int nextTask = (SMARTS.getCurrentTask()+1)%SMARTS.getTotalTasks( );
	for (count=0;
	     SMARTS.getStatus(nextTask)!=READY && count<SMARTS.getTotalTasks( );
	     count++)
	     nextTask=++nextTask%SMARTS.getTotalTasks( );
	if (count == SMARTS.getTotalTasks( ))	// no found READY task to run
		nextTask = SMARTS.getTotalTasks( );
	return nextTask;
}


/// **** Addition to the original code ****

// edf - earliest deadline first
int edf() 
{
	int next_task = SMARTS.getTotalTasks();
	unsigned int earliest_deadline = MAXINT;

	for (int i = 0; i < SMARTS.getTotalTasks(); i++)
	{
		if (SMARTS.getStatus(i) == READY)
		{
			unsigned int deadline = SMARTS.getTaskDeadline(i);
			if (deadline < earliest_deadline)
			{
				earliest_deadline = deadline;
				next_task = i;
			}
		}
	}

	return next_task;
}
/// **** End of Addition ****