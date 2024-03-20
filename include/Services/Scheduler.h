#ifndef Scheduler_H_
#define Scheduler_H_

/********************************************************************************************************/
/************************************************Includes************************************************/
/********************************************************************************************************/

#include "StdTypes.h"

/********************************************************************************************************/
/************************************************Defines*************************************************/
/********************************************************************************************************/



/********************************************************************************************************/
/************************************************Types***************************************************/
/********************************************************************************************************/

typedef void(*Sched_CallBackPtr_t)(void);

typedef struct{
    u32 periodicityMS;
    u32 firstDelayMS;
    Sched_CallBackPtr_t callBack;
}Sched_runnable_t;

/********************************************************************************************************/
/************************************************APIs****************************************************/
/********************************************************************************************************/

void Sched_init(void);
void Sched_start(void);


#endif // Scheduler_H_