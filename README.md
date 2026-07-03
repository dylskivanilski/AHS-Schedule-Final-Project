# Adaptive Homework Scheduler (AHS)

## CS460 Final Project

### Description

The Adaptive Homework Scheduler (AHS) recommends which assignment a student should complete next. Instead of relying only on assignment deadlines, it calculates a priority score using four factors:

- Days remaining until the deadline
- Assignment point value
- Estimated completion time
- Current completion progress

Assignments are ranked from highest to lowest priority, allowing students to better manage their workload.

### Features

- Calculates a priority score for each assignment
- Sorts assignments by priority
- Displays the recommended order
- Demonstrates time complexity of O(n log n)

### Building

```bash
g++ main.cpp -o scheduler
```

### Running

```bash
./scheduler
```

(or `scheduler.exe` on Windows)

### Author

Dylan Jacob Nery Fermo

CS460 Algorithms
