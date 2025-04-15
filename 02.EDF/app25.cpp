#include "smarts25.h"

// user Functions
void a()
{
	SMARTS.contextSwitchOff();
	cout << "\n *************   A Start    *********************";
	SMARTS.contextSwitchOn();
	for (int j=0; j <500; j++)
	{
		for (long i=0; i <600000; i++);
		SMARTS.contextSwitchOff();
		cout << "A";
		SMARTS.contextSwitchOn();
	}
	SMARTS.contextSwitchOff();
	cout << "\n *************   A Finish   *********************";
	SMARTS.contextSwitchOn();
}

void b()
{
	SMARTS.contextSwitchOff();
	cout << "\n *************   B Start    *********************";
	SMARTS.contextSwitchOn();
	for (int j=0; j <500; j++)
	{
		for (long i=0; i < 600000; i++);
		SMARTS.contextSwitchOff();
		cout << "B";
		SMARTS.contextSwitchOn();
	}
	SMARTS.contextSwitchOff();
	cout << "\n *************   B Finish   *********************";
	SMARTS.contextSwitchOn();
}

void c()
{
	SMARTS.contextSwitchOff();
	cout << "\n *************   C Start    *********************";
	SMARTS.contextSwitchOn();
	for (int j=0; j <500; j++)
	{
		for (long i=0; i < 600000; i++);
		SMARTS.contextSwitchOff();
		cout << "C";
		SMARTS.contextSwitchOn();
	}
	SMARTS.contextSwitchOff();
	cout << "\n *************   C Finish   *********************";
	SMARTS.contextSwitchOn();
}

void main()
{
	clrscr();
	SMARTS.externalFunctions(timerInterruptHandler, scheduler, myTaskEnd, edf);
	SMARTS.declareTask(a,'A', 5, 3);
	SMARTS.declareTask(b,'B', 7, 4);
	SMARTS.declareTask(c,'C', 10, 5);
	SMARTS.runTheTasks();
}



