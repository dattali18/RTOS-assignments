#ifndef TASK25_H
#define TASK25_H

#include "event25.h"

///////////////////////////////////////////////////////////////
// Enum
///////////////////////////////////////////////////////////////

enum taskStatus
{
    READY,
    NOT_ACTIVE,
    SUSPENDED,
    SLEEP,
    UNDEFINED
};

///////////////////////////////////////////////////////////////
// Task class
///////////////////////////////////////////////////////////////

class Task
{
public:
    char name;                   // task name
    unsigned stack[MaxStack];    // the stack
    unsigned stackSeg, stackPtr; // the stack pointer
    int currentPriority;         // the priority of the task
    int priority;                // the original priority
    taskStatus status;           // the status of the task
    Event *expectedEvent;        // the event that this task is waiting for
    int sleepCount;              // the sleep remainder time
    Task();
    void declare(void far *code, void far *taskEnd, char name);
    void sleepDecr();
    void incrPriority();
    void setOriginalPriority();
};

#endif // TASK25_H