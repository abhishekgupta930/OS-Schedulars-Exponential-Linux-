
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sched.h>

int get_next_process4expscheduler(double *random) {

  int iterator = q[rdytail].qprev;
  int next = iterator;
  while (iterator != rdyhead && q[iterator].qkey > *random) {

    // next=iterator;
    iterator = q[iterator].qprev;
    next = iterator;
  }
  if (iterator < NPROC)
    return next;
  else
    return EMPTY;
}

void getMaxGoodnessProcess(int *next, int *max_goodness) {
  *next = 0;
  *max_goodness = 0;
  int proc = 0;
  int count = 0;

  for (proc = q[rdyhead].qnext; proc != rdytail; proc = q[proc].qnext) {
    // kprintf("PRINT in getMaxGoodnessProcesss in for looop Calling Process(%d)
    // ...| Process ID %d , GoodNess Value %d,count  %d\n",currpid,
    // proc,proctab[proc].goodness,count);
    count++;
    if (proctab[proc].goodness > *max_goodness) {
      *next = proc;
      *max_goodness = proctab[proc].goodness;
    }
  }
}

void updateGoodness_Value() {
  int process_id;
  struct pentry *tmp_process;

  // kprintf("PRINT In updateGoodness_Value\n");

  if (NPROC > 0) {
    while (process_id < NPROC) {
      tmp_process = &proctab[process_id];
      if (tmp_process->pstate != PRFREE) {
        tmp_process->goodness = tmp_process->pprio + tmp_process->counter;
        tmp_process->counter = tmp_process->pprio + (tmp_process->counter) / 2;
      }
      process_id++;
    }
  }
}
void updateGoodness() {
  int process_id = 1;
  struct pentry *tmp_process;

  // kprintf("\nIn updateGoodness() Process ID : %d  curr Goodness %d state =
  // %d:",currpid,proctab[currpid].goodness,proctab[currpid].pstate);
  // kprintf("PRINT In updateGoodness_Value\n");

  while (process_id < NPROC)

  {
    tmp_process = &proctab[process_id];
    if (proctab[process_id].pstate != PRFREE)
      // kprintf("\n Process ID : %d Updates Goodness value %d : ",process_id,
      // tmp_process->goodness);
      if (proctab[process_id].pstate != PRFREE && tmp_process->goodness != 0) {
        tmp_process->goodness = tmp_process->pprio + tmp_process->counter;
        // kprintf("\nProcess ID : %d Updates Goodness value : %d",process_id,
        // tmp_process->goodness);
      }
    process_id++;
  }
}

