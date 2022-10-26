This is a code to find the beginning node in a circular linked list

Approach:
Step 1:
We use the Floyd's Cycle Detection Alogirthm to detect the presence of a loop such that
We create two pointers:
	slow: moves 1 step at a time
	fast: moves 2 steps at a time
Case 1: If fast reaaches NULL
	Conclusion: No loop is present
Case 2: If fast and slow meet, a loop is present

Once the loop is detected, we proceed to find the beginning of the loop
Step 2:
If a loop is detected a point is reached where slow and fast both point to the same node

Step 3: 
slow pointer is taken back to the node where head points 

Step 4:
slow and fast made to move with equal steps now

The node at which both pointers meet is the required node i.e. the beginning node of the circular linked list.