# Exercises sheet 7

**Ask questions on Teams if you get stuck!**

1. Explain what preemptable and non-preemptable mean.


2. What are the three metrics to consider when designing a scheduling policy?


3. Explain FCFS, SJF, SRTF and Round Robin scheduling algorithms.


4. Why SRTF would not be appropriate in a modern system?


5. Explain the CSF scheduling policy.


6. Explain the MLFQ.


7. Why do you think Linux use a red black tree structure to identify the next task to run?


8. We use a MLFQ algorithm with 3 level of priority with Q3=\{T4\}, Q2=\{T1,T2\} Q1=\{T7\}. What thread should be picked next?


9. We use a CFS algorithm. We have three threads such that: T1\{weight=1, aruntime=6\}, T2\{weight=10, aruntime=16\}, T3\{weight=8, aruntime=9\}. Which thread should be picked next?


10. In your opinion, in order to handle multi core scheduling should we use a single queue shared across multiple cores or implement a queue per-core?


11. Could you imagine a better load balancing than the one proposed in OS161? (remain at an abstract level, you do not need to implement it)


## Answers
    **Answer 1:** a preemptable resource is a resource that can be taken away from a process with no ill effect (e.g. memory), non-preemptable one is a resource that cannot be taken (i.e. printer).

    **Answer 2:** throughput, latency and fairness.

    **Answer 3:** Fist-come-first-served batch scheduling where job are executed in the order they arrive. Shortest job first: batch scheduling where the shortest job is picked to execute next. Short remaining: batch scheduling where the job with the shortest time remaining is picked to execute next (a job currently executing can be pre-empted to execute a new job that would finish faster). Round Robin is a time sharing scheduling algorithm where jobs are queued. Each job is given a quantum of time to execute, at the end of this quantum the executing job is pre-empted and the next job on the queue is picked.

    **Answer 4:** it is not adapted for interactive programs.

    **Answer 5:** the completely fair scheduler is used by Linux. Within a time period each thread is given a portion of time to execute proportional to its wait. The algorithm guarantee that every thread will make some progress during said time period.

    **Answer 6:** the Multi-level Feedback Queue algorithm use n different priority queues. The next job to execute is picked from the non-empty queue with the highest priority. When a job is pre-empted it is added to the queue "bellow" the one it was picked from. Thread that block on I/O are added to the high priority queue when they wake up. The quantum is smaller the higher the priority. The goal of MLFQ (used in Windows and Mac) is to favor interactive threads to give end-user a good experience.

    **Answer 7:** O(log) complexity to identify the next thread to execute.

    **Answer 8:** T4.

    **Answer 9:** T3
    
    **Answer 10:** one queue per core in order to reduce contention and benefit from CPU affinity.
 
    **Answer 11:** you could for example consider CPU affinity when moving a thread across core (e.g. using some priority metrics when deciding which thread should move).
