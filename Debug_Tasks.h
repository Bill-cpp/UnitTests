#ifndef DEBUG_TASKS_H
#define DEBUG_TASKS_H

#ifdef DEBUG_TASKS_FLAG
#include "TaskPolicy.h"
#include <iostream>
#include <chrono>
#include <ctime>

#define DEBUG_TASKS(x) x
#else
#define DEBUG_TASKS(x)
#endif

#endif
