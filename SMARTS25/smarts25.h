#ifndef SMARTS25_H
#define SMARTS25_H

#include <conio.h>
#include <stdio.h>
#include <dos.h>
#include <values.h>
#include <iostream.h>

#include "task25.h"
#include "event25.h"
#include "parellism25.h"

extern unsigned getTimerClocks();
// external functions for 'externalFunctions' function
void far interrupt timerInterruptHandler(...);
void scheduler();
void myTaskEnd();
// 'short term' scheduler algorithms
int roundRobin();
// main scheduler object
extern Parallelism SMARTS;

#endif // SMARTS25_H