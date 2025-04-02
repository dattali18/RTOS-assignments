/********************************************************************/
/* A Small Real Time System for the Real-Time laboratory                 */
/* built by: A.Teitelbaum on an idea of H.G.Mendelbaum                  */
/* Jerusalem College of Technology, 5759-64 (1999)                            */
/* SchedAlgo64.CPP, short-term scheduler algorithms                */
/****************************************************************/


#include "smarts77.h"

int roundRobin( )
// Round Robin short-term algorithm 
{
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


int edf()
{
	int nextTask = -1;
	unsigned int earliestDeadline = MAXINT:

	for(int i = 0; i < SMARTS.getTotalTasks(); ++i)
	{
		// get all the task that are in the ready state
		if(SMARTS.getStatus(i) == READY)
		{
			// get the task with the earliest deadline
			if(SMARTS.getDeadline(i) < earliestDeadline)
			{
				earliestDeadline = SMARTS.getDeadline(i);
				nextTask = i;
			}
		}
	}

	return (nextTask == -1) ? SMARTS.getTotalTasks() : nextTask;
}

