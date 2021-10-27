#include "printf.h"
#include "mm.h"
#include "sched.h"
#include "entry.h"

int copy_process(unsigned long fn, unsigned long arg)
{
	preempt_disable();
	struct task_struct *p;

	p = (struct task_struct *) get_free_page();
	if (!p)
		return 1;
	p->priority = current->priority;
	p->state = TASK_RUNNING;
	p->counter = p->priority;
	p->preempt_count = 1; //disable preemtion until schedule_tail

	p->cpu_context.x19 = fn;
	p->cpu_context.x20 = arg;
	p->cpu_context.pc = (unsigned long)ret_from_fork;
	p->cpu_context.sp = (unsigned long)p + THREAD_SIZE;
	int pid = nr_tasks++;
	task[pid] = p;	
	
	printf("\n\r  New task[%d] schedule \r\n", pid);
	printf("\nThe next task is:  0x%08x.\r\n", p);
	printf("cpu_context.x19 = 0x%08x. (fn)\r\n", p->cpu_context.x19);
	printf("cpu_context.x20 = 0x%08x. (arg)\r\n", p->cpu_context.x20);
	printf("cpu_context.sp  = 0x%08x. (sp)\r\n", p->cpu_context.sp);
	printf("cpu_context.pc  = 0x%08x. (ret_from_fork)\r\n", p->cpu_context.pc);
	
	
	preempt_enable();
	return 0;
}
