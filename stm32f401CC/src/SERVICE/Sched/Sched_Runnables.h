#ifndef SCHED_RUNNABLES_H
#define SCHED_RUNNABLES_H

#include "../../LIB/STD_TYPES.h"
 
 #define MAX_RUNNABLES 5

 typedef enum {
  switches,
     RUNNABLE1,
       RUNNABLE2,
       TrafficLight,
       SWITCH_APP
 }RunnableID_t;
 typedef void (*RunnableCB_t)(void);
 typedef struct {

    RunnableID_t name;
    uint32_t periodicity_ms;
      RunnableCB_t CB;

 }Runnables_t;

 #endif




    


