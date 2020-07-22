/* ready.c - ready */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sched.h>

/*------------------------------------------------------------------------
 * ready  --  make a process eligible for CPU service
 *------------------------------------------------------------------------
 */
int ready(int pid, int resch)
{
	register struct	pentry	*pptr;

	if (isbadpid(pid))
		return(SYSERR);
	pptr = &proctab[pid];
	pptr->pstate = PRREADY;
	if(scheduler == LINUXSCHED) {
 	kprintf("Linux Scheduler---Before entering Ready Queue : Current Proc. : %d  Process Entered  %d , Priority %d\n",currpid, pid, pptr->pprio);
		insert(pid,rdyhead,pptr->pprio);
	}
	else{

	// Trying to see which processes are being added to 
	// ready queue
 	kprintf("---Before entering Ready Queue : Current Proc. : %d  Process Entered  %d , Priority %d\n",currpid, pid, pptr->pprio);

		insert(pid,rdyhead,pptr->pprio);
	}
	if (resch)
		resched();
	return(OK);
}
