/* 
 * Charge System Management Framework
 * Sccsid @(#)svc.h	1.2 (Charge) 29/06/14
 */

#ifndef SVC_H
#define SVC_H

#include "pidlist.h"

#define T_SIMPLE 1
#define T_FORKING 2
#define T_ONESHOT 3

struct Service
{
	int Type;
	char* PIDFile;

	char* ExecStartPre;
	char* ExecStart;
	char* ExecStartPost;
	char* ExecStopPost;
	
	int StartTimeout;
	int StopTimeout;
	
	int Restart;

	/* internal */
	int StateTimerOn;
	int TimedOut;
	int AuxStateTimerOn;
	int AuxTimedOut;
	int KillTimerOn;
	int KillTimedOut;
	int AuxKillTimerOn;
	int AuxKillTimedOut;

	int FirstRun;
	int State;
	int AuxState;
	int Want;
	int AuxWant;
	int MainPIDExited;
	int AuxMainPIDExited;
	int MainPIDExitWstat;

	int PIDFileRead;
	int MainPID;
	int PIDsPurged;
	int AuxMainPID;
	int AuxPIDsPurged;
	PIDList_t *PL;
	PIDList_t *AuxPL;
};

typedef struct Service Service;

#define S_INACTIVE 0
#define S_EXITED 1
#define S_START_PRE 2
#define S_START 3
#define S_START_POST 4
#define S_RUNNING 14/* v.s. online */
#define S_ONLINE 5
#define S_STOP 6
#define S_STOP_SIGTERM 7
#define S_STOP_SIGKILL 8
#define S_STOP_POST 9
#define S_FINAL_SIGTERM 10
#define S_FINAL_SIGKILL 11
#define S_FAILED 12
#define S_RESTART 13

#define S_NONE 999

#define TIMER_STATELIMIT 1
#define TIMER_AUX 2
#define TIMER_AUXKILL 4
#define TIMER_KILL 5

#define R_NO 0
#define R_ALWAYS 1
#define R_ON_SUCCESS 2
#define R_ON_FAILURE 3

#define AUX 1
#define MAIN 0

#endif
