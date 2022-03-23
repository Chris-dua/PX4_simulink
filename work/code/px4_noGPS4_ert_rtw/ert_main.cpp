//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ert_main.cpp
//
// Code generated for Simulink model 'px4_noGPS4'.
//
// Model version                  : 5.150
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Wed Mar 23 21:49:27 2022
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include <stdio.h>
#include <stdlib.h>
#include "px4_noGPS4.h"
#include "px4_noGPS4_private.h"
#include "rtwtypes.h"
#include "limits.h"
#include "rt_nonfinite.h"
#include "MW_PX4_TaskControl.h"
#include "nuttxinitialize.h"
#define UNUSED(x)                      x = x
#define NAMELEN                        16

// Function prototype declaration
void exitFcn(int sig);
void *terminateTask(void *arg);
void *baseRateTask(void *arg);
void *subrateTask(void *arg);
volatile boolean_T stopRequested = false;
volatile boolean_T runModel = true;
sem_t stopSem;
sem_t baserateTaskSem;
sem_t subrateTaskSem[1];
int taskId[1];
pthread_t schedulerThread;
pthread_t baseRateThread;
pthread_t backgroundThread;
void *threadJoinStatus;
int terminatingmodel = 0;
pthread_t subRateThread[1];
int subratePriority[1];
void *subrateTask(void *arg)
{
  int tid = *((int *) arg);
  int subRateId;
  subRateId = tid + 1;
  while (runModel) {
    sem_wait(&subrateTaskSem[tid]);
    if (terminatingmodel)
      break;

#ifdef MW_RTOS_DEBUG

    printf(" -subrate task %d semaphore received\n", subRateId);

#endif

    px4_noGPS4_step(subRateId);

    // Get model outputs here
  }

  pthread_exit((void *)0);
  return NULL;
}

void *baseRateTask(void *arg)
{
  runModel = (rtmGetErrorStatus(px4_noGPS4_M) == (NULL)) && !rtmGetStopRequested
    (px4_noGPS4_M);
  while (runModel) {
    sem_wait(&baserateTaskSem);

#ifdef MW_RTOS_DEBUG

    printf("*base rate task semaphore received\n");
    fflush(stdout);

#endif

    if (rtmStepTask(px4_noGPS4_M, 1)
        ) {
      sem_post(&subrateTaskSem[0]);
    }

    // External mode
    {
      boolean_T rtmStopReq = false;
      rtExtModePauseIfNeeded(px4_noGPS4_M->extModeInfo, 2, &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(px4_noGPS4_M, true);
      }

      if (rtmGetStopRequested(px4_noGPS4_M) == true) {
        rtmSetErrorStatus(px4_noGPS4_M, "Simulation finished");
        break;
      }
    }

    px4_noGPS4_step(0);

    // Get model outputs here
    rtExtModeCheckEndTrigger();
    stopRequested = !((rtmGetErrorStatus(px4_noGPS4_M) == (NULL)) &&
                      !rtmGetStopRequested(px4_noGPS4_M));
    runModel = !stopRequested;
  }

  terminateTask(arg);
  pthread_exit((void *)0);
  return NULL;
}

void exitFcn(int sig)
{
  UNUSED(sig);
  rtmSetErrorStatus(px4_noGPS4_M, "stopping the model");
  runModel = 0;
}

void *terminateTask(void *arg)
{
  UNUSED(arg);
  terminatingmodel = 1;

  {
    int i;

    // Signal all periodic tasks to complete
    for (i=0; i<1; i++) {
      CHECK_STATUS(sem_post(&subrateTaskSem[i]), 0, "sem_post");
      CHECK_STATUS(sem_destroy(&subrateTaskSem[i]), 0, "sem_destroy");
    }

    // Wait for all periodic tasks to complete
    for (i=0; i<1; i++) {
      CHECK_STATUS(pthread_join(subRateThread[i], &threadJoinStatus), 0,
                   "pthread_join");
    }

    runModel = 0;

    // Wait for background task to complete
    CHECK_STATUS(pthread_join(backgroundThread, &threadJoinStatus), 0,
                 "pthread_join");
  }

  MW_PX4_Terminate();

  // Terminate model
  px4_noGPS4_terminate();
  rtExtModeShutdown(2);
  sem_post(&stopSem);
  return NULL;
}

void *backgroundTask(void *arg)
{
  while (runModel) {
    // External mode
    {
      boolean_T rtmStopReq = false;
      rtExtModeOneStep(px4_noGPS4_M->extModeInfo, 2, &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(px4_noGPS4_M, true);
      }
    }
  }

  return NULL;
}

int px4_simulink_app_task_main (int argc, char *argv[])
{
  subratePriority[0] = 249;
  px4_simulink_app_control_MAVLink();
  rtmSetErrorStatus(px4_noGPS4_M, 0);
  rtExtModeParseArgs(argc, (const char_T **)argv, NULL);

  // Initialize model
  px4_noGPS4_initialize();

  // External mode
  rtSetTFinalForExtMode(&rtmGetTFinal(px4_noGPS4_M));
  rtExtModeCheckInit(2);

  {
    boolean_T rtmStopReq = false;
    rtExtModeWaitForStartPkt(px4_noGPS4_M->extModeInfo, 2, &rtmStopReq);
    if (rtmStopReq) {
      rtmSetStopRequested(px4_noGPS4_M, true);
    }
  }

  rtERTExtModeStartMsg();

  // Call RTOS Initialization function
  nuttxRTOSInit(0.005, 1);

  // Wait for stop semaphore
  sem_wait(&stopSem);

#if (MW_NUMBER_TIMER_DRIVEN_TASKS > 0)

  {
    int i;
    for (i=0; i < MW_NUMBER_TIMER_DRIVEN_TASKS; i++) {
      CHECK_STATUS(sem_destroy(&timerTaskSem[i]), 0, "sem_destroy");
    }
  }

#endif

  return 0;
}

//
// File trailer for generated code.
//
// [EOF]
//
