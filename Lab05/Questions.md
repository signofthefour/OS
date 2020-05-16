**QUESTION1**: What resources are used when a thread is created? How do they differ from those
used when a process is created?
*answer:*
- Creating either a user or kernel thread involves allocating a small data structure to hold register set, stack, and priority.
- Creating a process requires allocating a big data struct called process control block (PCB). PCB consists a memeory map, list of open files, and environment variables. The most time-consuming activity is allocating and managing memory map.

**QUESTION2**: Is it possible to have concurrency but not parallelism? Explain.
*answer:*
- Yes
- Concurrency means where two process or thread start working together in an overlaped time period, however it does not mean running parallelism.
> Multi-task switch on a single-cored processor
- Parallelism is where two or more different tasks start their execution at the same time. It means that the two tasks or threads start working simultaneously. 
> Multi-processor system

Therefor, It is possible to have concurrency but not parallelism.

