/* Copyright (C) 2021 Bill Rubin
 * Contact: rubin@contractor.net
 *
 * This program is licensed under the MIT license, a copy of which
 * has been provided with this program. You can also find the MIT
 * license at https://OpenSource.org/licenses/MIT
 */

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
