/*
 * Timer_conf.h
 *
 *  Created on: Feb 28, 2023
 *      Author: Mohammed Ramadan
 */

#ifndef MCAL_TIMER_TIMER_CONF_H_
#define MCAL_TIMER_TIMER_CONF_H_
/*************************************************************************************************/
/**                         Config of TIM1                                                      **/
/*************************************************************************************************/

   /*
    * Select the Direction :
    *** Options :
        *  UP_COUNTER
        *  DOWN_COUNTER
    **/
    #define TIM1_DIRECTION UP_COUNTER

    /* Set the clock division
     * *** Options :
        *  tCK_INT_x_1
        *  tCK_INT_x_2
        *  tCK_INT_x_4
     **/
    #define TIM1_DIVISION  tCK_INT_x_1

   /* Set the Prescaler value
    * *** Options :
        *  1
        *  ....
        *  65535
    **/
   #define TIM1_PRESCALLER  8

   /* Set the preload value
    * *** Options :
        *  1
        *  ....
        *  65535
    */
   #define TIM1_PRELOAD_VALUE 0x0f

   /* Specifies the repetition counter value. Each time the RCR downcounter
      reaches zero, an update event is generated and counting restarts
      from the RCR value (N).
      This means in PWM mode that (N+1) corresponds to:
        - the number of PWM periods in edge-aligned mode
        - the number of half PWM period in center-aligned mode
      This parameter must be a number between Min_Data = 0x00 and Max_Data = 0xFF.
   */
   #define REPETATION_COUNTER  0x0f

/*************************************************************************************************/
/**                         Config of TIM2                                                      **/
/*************************************************************************************************/

   /*
    * Select the Direction :
    *** Options :
        *  UP_COUNTER
        *  DOWN_COUNTER
    **/
    #define TIM2_DIRECTION UP_COUNTER

    /* Set the clock division
     * *** Options :
        *  tCK_INT_x_1
        *  tCK_INT_x_2
        *  tCK_INT_x_4
     **/
    #define TIM2_DIVISION  tCK_INT_x_1

   /* Set the Prescaler value
    * *** Options :
        *  1
        *  ....
        *  65535
    **/
   #define TIM2_PRESCALLER  8

   /* Set the preload value
    * *** Options :
        *  1
        *  ....
        *  65535
    */
   #define TIM2_PRELOAD_VALUE 0x0f
/*************************************************************************************************/
/**                         Config of TIM3                                                      **/
/*************************************************************************************************/

   /*
    * Select the Direction :
    *** Options :
        *  UP_COUNTER
        *  DOWN_COUNTER
    **/
    #define TIM3_DIRECTION UP_COUNTER

    /* Set the clock division
     * *** Options :
        *  tCK_INT_x_1
        *  tCK_INT_x_2
        *  tCK_INT_x_4
     **/
    #define TIM3_DIVISION  tCK_INT_x_1

   /* Set the Prescaler value
    * *** Options :
        *  1
        *  ....
        *  65535
    **/
   #define TIM3_PRESCALLER  8

   /* Set the preload value
    * *** Options :
        *  1
        *  ....
        *  65535
    */
   #define TIM3_PRELOAD_VALUE 0x0f
/*************************************************************************************************/
/**                         Config of TIM4                                                      **/
/*************************************************************************************************/

   /*
    * Select the Direction :
    *** Options :
        *  UP_COUNTER
        *  DOWN_COUNTER
    **/
    #define TIM4_DIRECTION UP_COUNTER

    /* Set the clock division
     * *** Options :
        *  tCK_INT_x_1
        *  tCK_INT_x_2
        *  tCK_INT_x_4
     **/
    #define TIM4_DIVISION  tCK_INT_x_1

   /* Set the Prescaler value
    * *** Options :
        *  1
        *  ....
        *  65535
    **/
   #define TIM4_PRESCALLER  8

   /* Set the preload value
    * *** Options :
        *  1
        *  ....
        *  65535
    */
   #define TIM4_PRELOAD_VALUE 0x0f

/*************************************************************************************************/
/**                         Config of TIM5                                                      **/
/*************************************************************************************************/

   /*
    * Select the Direction :
    *** Options :
        *  UP_COUNTER
        *  DOWN_COUNTER
    **/
    #define TIM5_DIRECTION UP_COUNTER

    /* Set the clock division
     * *** Options :
        *  tCK_INT_x_1
        *  tCK_INT_x_2
        *  tCK_INT_x_4
     **/
    #define TIM5_DIVISION  tCK_INT_x_1

   /* Set the Prescaler value
    * *** Options :
        *  1
        *  ....
        *  65535
    **/
   #define TIM5_PRESCALLER  8

   /* Set the preload value
    * *** Options :
        *  1
        *  ....
        *  65535
    */
   #define TIM5_PRELOAD_VALUE 0x0f

#endif /* MCAL_TIMER_TIMER_CONF_H_ */
