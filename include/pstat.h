#ifndef _PSTAT_H_
#define _PSTAT_H_
#include "param.h"
struct pstat {
	int inuse[NPROC]; // 1 if this slot of the process table is in use, 0 otherwise
	int pid[NPROC]; // PID of each process
	int tickets[NPROC]; // tickets held
	int ticks[NPROC]; // number of times each process has been scheduled
	int stride[NPROC]; // STRIDE_BIG / tickets
	int pass[NPROC]; // stride progress
	int size[NPROC]; // size of each process's memory, in bytes
};
#endif // _PSTAT_H_
