# Test Cases

## Test Case 1: Urgency vs Value

Input:
- Essay: 2 days, 100 points, 5 hours, 20% progress
- Quiz: 1 day, 20 points, 1 hour, 0% progress
- Project: 5 days, 200 points, 10 hours, 50% progress

Expected: Project > Essay > Quiz  
Actual: Project > Essay > Quiz  
Result: PASS

---

## Test Case 2: Progress and Value

Input:
- Research Paper: 4 days, 250 points, 12 hours, 80% progress
- Homework: 2 days, 20 points, 1 hour, 0% progress
- Presentation: 6 days, 100 points, 4 hours, 50% progress

Expected: Research Paper > Presentation > Homework  
Actual: Research Paper > Presentation > Homework  
Result: PASS

---

## Test Case 3: Near Deadline

Input:
- Lab: 1 day, 50 points, 2 hours, 90% progress
- Essay: 5 days, 100 points, 8 hours, 20% progress
- Quiz: 2 days, 25 points, 1 hour, 0% progress

Expected: Lab > Essay > Quiz  
Actual: Lab > Essay > Quiz  
Result: PASS
