Similar to l153, we can solve this problem by finding the "pivot" which is the minimum value in this array and call subproblem binSearch(0,pivot-1,target) and binSearch(pivot,n-1,target).

Tripped by boundary cases really hard.