#!/bin/bash

echo "Compiling ./wd..."
gcc -ansi -pedantic-errors -Wall -Wextra -g wd.c wd_main.c -o wd ../../system_programming/scheduler/scheduler.c ../../system_programming/task/task.c ../../system_programming/uid/uid.c ../../ds/priorityq/priorityq_sll.c ../../ds/sortedlist/sortedlist.c ../../ds/doublelist/doublelist.c -I../../system_programming/include -I../../ds/include -D_POSIX_C_SOURCE -pthread
echo "Compiling ./app..."
gcc -ansi -pedantic-errors -Wall -Wextra -g wd_api_func.c wd.c app_wd.c -o app ../../system_programming/scheduler/scheduler.c ../../system_programming/task/task.c ../../system_programming/uid/uid.c ../../ds/priorityq/priorityq_sll.c ../../ds/sortedlist/sortedlist.c ../../ds/doublelist/doublelist.c -I../../system_programming/include -I../../ds/include -D_POSIX_C_SOURCE -pthread
