#include "smarts25.h"

#define BIG_N 10000

// user Functions
void a()
{
	SMARTS.contextSwitchOff();
	cout << "\n *************   A Start    *********************";
	SMARTS.contextSwitchOn();
	for (int j = 0; j < 500; j++)
	{
		for (long i = 0; i < BIG_N; i++);
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
	for (int j = 0; j < 500; j++)
	{
		for (long i = 0; i < BIG_N; i++);
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
	for (int j = 0; j < 500; j++)
	{
		for (long i = 0; i < BIG_N; i++);
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
	SMARTS.declareTask(a,'A', 5, 1000);
	SMARTS.declareTask(b,'B', 7, 1000);
	SMARTS.declareTask(c,'C', 10, 1000);
	SMARTS.runTheTasks();
	// get input from user to stop the program
	cout << "\n Press any key to stop the program";
	char c;
	cin >> c;
}



