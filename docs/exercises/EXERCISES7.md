# Exercises sheet 7

**There will be no written corrections. Exercises will be discussed during the recorded live Q&A. Come and prepare questions.**

1. Explain what preemptable and non-preemptable mean.
2. What are the three metrics to consider when designing a scheduling policy?
3. Explain FCFS, SJF, SRTF and Round Robin scheduling algorithms.
4. Why SRTF would not be appropriate in a modern system?
5. Explain the CSF scheduling policy.
6. Explain the MLFQ.
7. Why do you think Linux use a red black tree structure to identify the next task to run?
8. We use a MLFQ algorithm with 3 level of priority with Q3=\{T4\}, Q2=\{T1,T2\} Q1=\{T7\}. What thread should be picked next?
9. We use a CSF algorithm. We have three threads such that: T1\{weight=1, aruntime=6\}, T2\{weight=10, aruntime=16\}, T3\{weight=8, aruntime=9\}. Which thread should be picked next?
10. In your opinion, in order to handle multi core scheduling should we use a single queue shared across multiple cores or implement a queue per-core?
11. Could you imagine a better load balancing than the one proposed in OS161? (remain at an abstract level, you do not need to implement it)
