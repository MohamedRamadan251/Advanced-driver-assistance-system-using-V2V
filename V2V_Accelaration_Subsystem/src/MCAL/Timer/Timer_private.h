/*
 * Timer_private.h
 *
 *  Created on: Feb 28, 2023
 *      Author: Mohammed Ramadan
 */

#ifndef MCAL_TIMER_TIMER_PRIVATE_H_
#define MCAL_TIMER_TIMER_PRIVATE_H_

/****************************************************************/
/**          (Advanced-control timer)TIMER1 register           **/
/****************************************************************/
/****************************************************************/
/**              TIM1 control register1 bits(CR1)              **/
/****************************************************************/
/*  Counter enable                 */
#define TIM1_CR1_CEN_BIT   0
/*  Update disable                 */
#define TIM1_CR1_UDIS_BIT  1
/*  Update request source          */
#define TIM1_CR1_URS_BIT   2
/*  One pulse mode                 */
#define TIM1_CR1_OPM_BIT   3
/*  Direction                      */
#define TIM1_CR1_DIR_BIT   4
/*  Center-aligned mode selection  */
#define TIM1_CR1_CMS_BIT0  5
#define TIM1_CR1_CMS_BIT1  6
/*  Auto-reload preload enable     */
#define TIM1_CR1_ARPE_BIT  7
/*  Clock division                 */
#define TIM1_CR1_CKD_BIT0  8
#define TIM1_CR1_CKD_BIT1  9

/****************************************************************/
/**              TIM1 control register2 bits(CR2)              **/
/****************************************************************/
/*  Capture/compare preloaded control         */
#define TIM1_CR2_CCPC_BIT    0
/*  Capture/compare control update selection  */
#define TIM1_CR2_CCUS_BIT    2
/*  Capture/compare DMA selection             */
#define TIM1_CR2_CCDS_BIT    3
/*  Master mode selection                     */
#define TIM1_CR2_MMS_BIT0    4
#define TIM1_CR2_MMS_BIT1    5
#define TIM1_CR2_MMS_BIT2    6
/*  TI1 selection                             */
#define TIM1_CR2_TI1S_BIT    7
/*  Output Idle state 1 (OC1N output)         */
#define TIM1_CR2_OIS1_BIT    8
/*  Output Idle state 1 (OC1N output)         */
#define TIM1_CR2_OIS1N_BIT   9
/*  Output Idle state 2 (OC2 output)          */
#define TIM1_CR2_OIS2_BIT    10
/*  Output Idle state 2 (OC2N output)         */
#define TIM1_CR2_OIS2N_BIT   11
/*  Output Idle state 3 (OC3 output)          */
#define TIM1_CR2_OIS3_BIT    12
/*  Output Idle state 3 (OC3N output)         */
#define TIM1_CR2_OIS3N_BIT   13
/*  Output Idle state 4 (OC4 output)          */
#define TIM1_CR2_OIS4_BIT    14

/****************************************************************/
/**       TIM1 slave mode control register(SMCR)               **/
/****************************************************************/
/*  Slave mode selection        */
#define TIM1_SMCR_SMS_BIT0    0
#define TIM1_SMCR_SMS_BIT1    1
#define TIM1_SMCR_SMS_BIT2    2
/*  Trigger selection           */
#define TIM1_SMCR_TS_BIT0     4
#define TIM1_SMCR_TS_BIT1     5
#define TIM1_SMCR_TS_BIT2     6
/*  Master/slave mode           */
#define TIM1_SMCR_MSM_BIT     7
/*  External trigger filter     */
#define TIM1_SMCR_ETF_BIT0    8
#define TIM1_SMCR_ETF_BIT1    9
#define TIM1_SMCR_ETF_BIT2    10
#define TIM1_SMCR_ETF_BIT3    11
/*  External trigger prescaler  */
#define TIM1_SMCR_ETPS_BIT0   12
#define TIM1_SMCR_ETPS_BIT1   13
/*  External clock enable       */
#define TIM1_SMCR_ECE_BIT     14
/*  External trigger polarity   */
#define TIM1_SMCR_ETP_BIT     15

/****************************************************************/
/**       TIM1 DMA/interrupt enable register(DIER)               **/
/****************************************************************/
/*  Update interrupt enable               */
#define TIM1_DIER_UIE_BIT        0
/*  Capture/Compare 1 interrupt enable    */
#define TIM1_DIER_CC1IE_BIT      1
/*  Capture/Compare 2 interrupt enable    */
#define TIM1_DIER_CC2IE_BIT      2
/*  Capture/Compare 3 interrupt enable    */
#define TIM1_DIER_CC3IE_BIT      3
/*  Capture/Compare 4 interrupt enable    */
#define TIM1_DIER_CC4IE_BIT      4
/*  COM interrupt enable                  */
#define TIM1_DIER_COMIE_BIT      5
/*  Trigger interrupt enable              */
#define TIM1_DIER_TIE_BIT        6
/*  Break interrupt enable                */
#define TIM1_DIER_BIE_BIT        7
/*  Update DMA request enable             */
#define TIM1_DIER_UDE_BIT        8
/*  Capture/Compare 1 DMA request enable  */
#define TIM1_DIER_CC1DE_BIT      9
/*  Capture/Compare 2 DMA request enable  */
#define TIM1_DIER_CC2DE_BIT      10
/*  Capture/Compare 3 DMA request enable  */
#define TIM1_DIER_CC3DE_BIT      11
/*  Capture/Compare 4 DMA request enable  */
#define TIM1_DIER_CC4DE_BIT      12
/*  COM DMA request enable                */
#define TIM1_DIER_COMDE_BIT      13
/*  Trigger DMA request enable            */
#define TIM1_DIER_TDE_BIT        14

/****************************************************************/
/**              TIM1 status register (SR)                     **/
/****************************************************************/
/*  Update interrupt flag               */
#define TIM1_SR_UIF_BIT       0
/*  Capture/Compare 1 interrupt flag    */
#define TIM1_SR_CC1IF_BIT     1
/*  Capture/Compare 2 interrupt flag    */
#define TIM1_SR_CC2IF_BIT     2
/*  Capture/Compare 3 interrupt flag    */
#define TIM1_SR_CC3IF_BIT     3
/*  Capture/Compare 4 interrupt flag    */
#define TIM1_SR_CC4IF_BIT     4
/*  COM interrupt flag                  */
#define TIM1_SR_COMIF_BIT     5
/*  Trigger interrupt flag              */
#define TIM1_SR_TIF_BIT       6
/*  Break interrupt flag                */
#define TIM1_SR_BIF_BIT       7
/*  Capture/Compare 1 overcapture flag  */
#define TIM1_SR_CC1OF_BIT     9
/*  Capture/Compare 2 overcapture flag  */
#define TIM1_SR_CC2OF_BIT     10
/*  Capture/Compare 3 overcapture flag  */
#define TIM1_SR_CC3OF_BIT     11
/*  Capture/Compare 4 overcapture flag  */
#define TIM1_SR_CC4OF_BIT     12

/****************************************************************/
/**        TIM1 event generation register (EGR)                **/
/****************************************************************/
/*  Update generation                          */
#define TIM1_EGR_UG_BIT      0
/*  Capture/Compare 1 generation               */
#define TIM1_EGR_CC1G_BIT    1
/*  Capture/Compare 2 generation               */
#define TIM1_EGR_CC2G_BIT    2
/*  Capture/Compare 3 generation               */
#define TIM1_EGR_CC3G_BIT    3
/*  Capture/Compare 4 generation               */
#define TIM1_EGR_CC4G_BIT    4
/*  Capture/Compare control update generation  */
#define TIM1_EGR_COMG_BIT    5
/*  Trigger generation                         */
#define TIM1_EGR_TG_BIT      6
/*  Break generation                           */
#define TIM1_EGR_BG_BIT      7

/****************************************************************/
/**     TIM1 capture/compare mode register 1 (CCMR1)           **/
/****************************************************************/
/*****************Output compare mode****************************/
/*  Capture/Compare 1 selection      */
#define TIM1_CCMR1_CC1S_BIT0      0
#define TIM1_CCMR1_CC1S_BIT1      1
/*  Output Compare 1 fast enable     */
#define TIM1_CCMR1_OC1FE_BIT      2
/*  Output Compare 1 preload enable  */
#define TIM1_CCMR1_OC1PE_BIT      3
/*  Output Compare 1 mode            */
#define TIM1_CCMR1_OC1M_BIT0      4
#define TIM1_CCMR1_OC1M_BIT1      5
#define TIM1_CCMR1_OC1M_BIT2      6
/*  Output Compare 1 clear enable    */
#define TIM1_CCMR1_OC1CE_BIT      7
/*  Capture/Compare 2 selection      */
#define TIM1_CCMR1_CC2S_BIT0      8
#define TIM1_CCMR1_CC2S_BIT1      9
/*  Output Compare 2 fast enable     */
#define TIM1_CCMR1_OC2FE_BIT      10
/*  Output Compare 2 preload enable  */
#define TIM1_CCMR1_OC2PE_BIT      11
/*  Output Compare 2 mode            */
#define TIM1_CCMR1_OC2M_BIT0      12
#define TIM1_CCMR1_OC2M_BIT1      13
#define TIM1_CCMR1_OC2M_BIT2      14
/*  Output Compare 2 clear enable    */
#define TIM1_CCMR1_OC2CE_BIT      15
/*****************Output compare mode****************************/
/*  Input capture 1 prescaler        */
#define TIM1_CCMR1_IC1PSC_BIT0    2
#define TIM1_CCMR1_IC1PSC_BIT1    3
/*  Input capture 1 filter           */
#define TIM1_CCMR1_IC1F_BIT0      4
#define TIM1_CCMR1_IC1F_BIT1      5
#define TIM1_CCMR1_IC1F_BIT2      6
#define TIM1_CCMR1_IC1F_BIT3      7
/*  Input capture 2 prescaler        */
#define TIM1_CCMR1_IC2PSC_BIT0    10
#define TIM1_CCMR1_IC2PSC_BIT1    11
/*  Input capture 2 filter           */
#define TIM1_CCMR1_IC2F_BIT0      12
#define TIM1_CCMR1_IC2F_BIT1      13
#define TIM1_CCMR1_IC2F_BIT2      14
#define TIM1_CCMR1_IC2F_BIT3      15

/****************************************************************/
/**     TIM1 capture/compare mode register 2 (CCMR2)           **/
/****************************************************************/
/*****************Output compare mode****************************/
/*  Capture/Compare 3 selection      */
#define TIM1_CCMR2_CC3S_BIT0      0
#define TIM1_CCMR2_CC3S_BIT1      1
/*  Output Compare 3 fast enable     */
#define TIM1_CCMR2_OC3FE_BIT      2
/*  Output Compare 3 preload enable  */
#define TIM1_CCMR2_OC3PE_BIT      3
/*  Output Compare 3 mode            */
#define TIM1_CCMR2_OC3M_BIT0      4
#define TIM1_CCMR2_OC3M_BIT1      5
#define TIM1_CCMR2_OC3M_BIT2      6
/*  Output Compare 3 clear enable    */
#define TIM1_CCMR1_OC3CE_BIT      7
/*  Capture/Compare 4 selection      */
#define TIM1_CCMR2_CC4S_BIT0      8
#define TIM1_CCMR2_CC4S_BIT1      9
/*  Output Compare 4 fast enable     */
#define TIM1_CCMR2_OC4FE_BIT      10
/*  Output Compare 4 preload enable  */
#define TIM1_CCMR2_OC4PE_BIT      11
/*  Output Compare 4 mode            */
#define TIM1_CCMR2_OC4M_BIT0      12
#define TIM1_CCMR2_OC4M_BIT1      13
#define TIM1_CCMR2_OC4M_BIT2      14
/*  Output Compare 4 clear enable    */
#define TIM1_CCMR2_OC2CE_BIT      15
/*****************Input compare mode****************************/
/*  Input capture 3 prescaler        */
#define TIM1_CCMR2_IC3PSC_BIT0    2
#define TIM1_CCMR2_IC3PSC_BIT1    3
/*  Input capture 3 filter           */
#define TIM1_CCMR2_IC3F_BIT0      4
#define TIM1_CCMR2_IC3F_BIT1      5
#define TIM1_CCMR2_IC3F_BIT2      6
#define TIM1_CCMR2_IC3F_BIT3      7
/*  Input capture 4 prescaler        */
#define TIM1_CCMR2_IC4PSC_BIT0    10
#define TIM1_CCMR2_IC4PSC_BIT1    11
/*  Input capture 4 filter           */
#define TIM1_CCMR2_IC4F_BIT0      12
#define TIM1_CCMR2_IC4F_BIT1      13
#define TIM1_CCMR2_IC4F_BIT2      14
#define TIM1_CCMR2_IC4F_BIT3      15

/****************************************************************/
/**     TIM1 capture/compare enable register (CCER)            **/
/****************************************************************/
/*  Capture/Compare 1 output enable                  */
#define TIM1_CCER_CC1E_BIT     0
/*  Capture/Compare 1 output polarity                */
#define TIM1_CCER_CC1P_BIT     1
/*  Capture/Compare 1 complementary output enable    */
#define TIM1_CCER_CC1NE_BIT    2
/*  Capture/Compare 1 complementary output polarity  */
#define TIM1_CCER_CC1NP_BIT    3
/*  Capture/Compare 2 output enable                  */
#define TIM1_CCER_CC2E_BIT     4
/*  Capture/Compare 2 output polarity                */
#define TIM1_CCER_CC2P_BIT     5
/*  Capture/Compare 2 complementary output enable    */
#define TIM1_CCER_CC2NE_BIT    6
/*  Capture/Compare 2 complementary output polarity  */
#define TIM1_CCER_CC2NP_BIT    7
/*  Capture/Compare 3 output enable                  */
#define TIM1_CCER_CC3E_BIT     8
/*  Capture/Compare 3 output polarity                */
#define TIM1_CCER_CC3P_BIT     9
/*  Capture/Compare 3 complementary output enable    */
#define TIM1_CCER_CC3NE_BIT    10
/*  Capture/Compare 3 complementary output polarity  */
#define TIM1_CCER_CC3NP_BIT    11
/*  Capture/Compare 4 output enable                  */
#define TIM1_CCER_CC4E_BIT     12
/*  Capture/Compare 4 output polarity                */
#define TIM1_CCER_CC4P_BIT     13

/****************************************************************/
/**        TIM1 break and dead-time register (BDTR)            **/
/****************************************************************/
/*  Dead-time generator setup          */
#define TIM1_BDTR_DTG_BIT0   0
#define TIM1_BDTR_DTG_BIT5   5
#define TIM1_BDTR_DTG_BIT6   6
#define TIM1_BDTR_DTG_BIT7   7
/*  Lock configuration                 */
#define TIM1_BDTR_LOCK_BIT0  8
#define TIM1_BDTR_LOCK_BIT1  9
/*  Off-state selection for Idle mode  */
#define TIM1_BDTR_OSSI_BIT   10
/*  Off-state selection for Run mode   */
#define TIM1_BDTR_OSSR_BIT   11
/*  Break enable                       */
#define TIM1_BDTR_BKE_BIT    12
/*  Break polarity                     */
#define TIM1_BDTR_BKP_BIT    13
/*  Automatic output enable            */
#define TIM1_BDTR_AOE_BIT    14
/*  Main output enable                 */
#define TIM1_BDTR_MOE_BIT    15

/****************************************************************/
/**            TIM1 DMA control register (DCR)                 **/
/****************************************************************/
/*  DMA base address            */
#define TIM1_DCR_DBA_BIT0     0
#define TIM1_DCR_DBA_BIT1     1
#define TIM1_DCR_DBA_BIT2     2
#define TIM1_DCR_DBA_BIT3     3
#define TIM1_DCR_DBA_BIT4     4
/*  DMA burst length            */
#define TIM1_DCR_DBL_BIT0     8
#define TIM1_DCR_DBL_BIT1     9
#define TIM1_DCR_DBL_BIT2     10
#define TIM1_DCR_DBL_BIT3     11
#define TIM1_DCR_DBL_BIT4     12

/****************************************************************/
/**     (General-purpose timers)TIMER2 to TIMER5 register      **/
/****************************************************************/
/****************************************************************/
/**     TIMER2 to TIMER5 control register1 bits(CR1)           **/
/****************************************************************/
/*  Counter enable                 */
#define TIM2_TO_TIM5_CR1_CEN_BIT   0
/*  Update disable                 */
#define TIM2_TO_TIM5_CR1_UDIS_BIT  1
/*  Update request source          */
#define TIM2_TO_TIM5_CR1_URS_BIT   2
/*  One pulse mode                 */
#define TIM2_TO_TIM5_CR1_OPM_BIT   3
/*  Direction                      */
#define TIM2_TO_TIM5_CR1_DIR_BIT   4
/*  Center-aligned mode selection  */
#define TIM2_TO_TIM5_CR1_CMS_BIT0  5
#define TIM2_TO_TIM5_CR1_CMS_BIT1  6
/*  Auto-reload preload enable     */
#define TIM2_TO_TIM5_CR1_ARPE_BIT  7
/*  Clock division                 */
#define TIM2_TO_TIM5_CR1_CKD_BIT0  8
#define TIM2_TO_TIM5_CR1_CKD_BIT1  9

/****************************************************************/
/**        TIMER2 to TIMER5 control register2 bits(CR2)        **/
/****************************************************************/
/*  TI1 selection                         */
#define TIM2_TO_TIM5_CR2_CCDS_BIT     3
/*  Master mode selection                 */
#define TIM2_TO_TIM5_CR2_MMS_BIT0     4
#define TIM2_TO_TIM5_CR2_MMS_BIT1     5
#define TIM2_TO_TIM5_CR2_MMS_BIT2     6
/*  Capture/compare DMA selection         */
#define TIM2_TO_TIM5_CR2_TI1S_BIT     7

/****************************************************************/
/**       TIMER2 to TIMER5 slave mode control register(SMCR)   **/
/****************************************************************/
/*  Slave mode selection        */
#define TIM2_TO_TIM5_SMCR_SMS_BIT0    0
#define TIM2_TO_TIM5_SMCR_SMS_BIT1    1
#define TIM2_TO_TIM5_SMCR_SMS_BIT2    2
/*  Trigger selection           */
#define TIM2_TO_TIM5_SMCR_TS_BIT0     4
#define TIM2_TO_TIM5_SMCR_TS_BIT1     5
#define TIM2_TO_TIM5_SMCR_TS_BIT2     6
/*  Master/slave mode           */
#define TIM2_TO_TIM5_SMCR_MSM_BIT     7
/*  External trigger filter     */
#define TIM2_TO_TIM5_SMCR_ETF_BIT0    8
#define TIM2_TO_TIM5_SMCR_ETF_BIT1    9
#define TIM2_TO_TIM5_SMCR_ETF_BIT2    10
#define TIM2_TO_TIM5_SMCR_ETF_BIT3    11
/*  External trigger prescaler  */
#define TIM2_TO_TIM5_SMCR_ETPS_BIT0   12
#define TIM2_TO_TIM5_SMCR_ETPS_BIT1   13
/*  External clock enable       */
#define TIM2_TO_TIM5_SMCR_ECE_BIT     14
/*  External trigger polarity   */
#define TIM2_TO_TIM5_SMCR_ETP_BIT     15

/****************************************************************/
/**    TIMER2 to TIMER5 DMA/interrupt enable register(DIER)    **/
/****************************************************************/
/*  Update interrupt enable               */
#define TIM2_TO_TIM5_DIER_UIE_BIT        0
/*  Capture/Compare 1 interrupt enable    */
#define TIM2_TO_TIM5_DIER_CC1IE_BIT      1
/*  Capture/Compare 2 interrupt enable    */
#define TIM2_TO_TIM5_DIER_CC2IE_BIT      2
/*  Capture/Compare 3 interrupt enable    */
#define TIM2_TO_TIM5_DIER_CC3IE_BIT      3
/*  Capture/Compare 4 interrupt enable    */
#define TIM2_TO_TIM5_DIER_CC4IE_BIT      4
/*  COM interrupt enable                  */
#define TIM2_TO_TIM5_DIER_COMIE_BIT      5
/*  Trigger interrupt enable              */
#define TIM2_TO_TIM5_DIER_TIE_BIT        6
/*  Update DMA request enable             */
#define TIM2_TO_TIM5_DIER_UDE_BIT        8
/*  Capture/Compare 1 DMA request enable  */
#define TIM2_TO_TIM5_DIER_CC1DE_BIT      9
/*  Capture/Compare 2 DMA request enable  */
#define TIM2_TO_TIM5_DIER_CC2DE_BIT      10
/*  Capture/Compare 3 DMA request enable  */
#define TIM2_TO_TIM5_DIER_CC3DE_BIT      11
/*  Capture/Compare 4 DMA request enable  */
#define TIM2_TO_TIM5_DIER_CC4DE_BIT      12
/*  Trigger DMA request enable            */
#define TIM2_TO_TIM5_DIER_TDE_BIT        14


/****************************************************************/
/**              TIMER2 TO TIIMER5 status register (SR)             **/
/****************************************************************/
/*  Update interrupt flag               */
#define TIM2_TO_TIM5_SR_UIF_BIT       0
/*  Capture/Compare 1 interrupt flag    */
#define TIM2_TO_TIM5_SR_CC1IF_BIT     1
/*  Capture/Compare 2 interrupt flag    */
#define TIM2_TO_TIM5_SR_CC2IF_BIT     2
/*  Capture/Compare 3 interrupt flag    */
#define TIM2_TO_TIM5_SR_CC3IF_BIT     3
/*  Capture/Compare 4 interrupt flag    */
#define TIM2_TO_TIM5_SR_CC4IF_BIT     4
/*  Trigger interrupt flag              */
#define TIM2_TO_TIM5_SR_TIF_BIT       6
/*  Capture/Compare 1 overcapture flag  */
#define TIM2_TO_TIM5_SR_CC1OF_BIT     9
/*  Capture/Compare 2 overcapture flag  */
#define TIM2_TO_TIM5_SR_CC2OF_BIT     10
/*  Capture/Compare 3 overcapture flag  */
#define TIM2_TO_TIM5_CC3OF_BIT        11
/*  Capture/Compare 4 overcapture flag  */
#define TIM2_TO_TIM5_SR_CC4OF_BIT     12

/****************************************************************/
/**     TIMER2 TO TIIMER5 event generation register (EGR)      **/
/****************************************************************/
/*  Update generation                          */
#define TIM2_TO_TIM5_EGR_UG_BIT      0
/*  Capture/Compare 1 generation               */
#define TIM2_TO_TIM5_EGR_CC1G_BIT    1
/*  Capture/Compare 2 generation               */
#define TIM2_TO_TIM5_EGR_CC2G_BIT    2
/*  Capture/Compare 3 generation               */
#define TIM2_TO_TIM5_EGR_CC3G_BIT    3
/*  Capture/Compare 4 generation               */
#define TIM2_TO_TIM5_EGR_CC4G_BIT    4
/*  Trigger generation                         */
#define TIM2_TO_TIM5_EGR_TG_BIT      6

/****************************************************************/
/** TIMER2 TO TIIMER5 capture/compare mode register 1 (CCMR1)  **/
/****************************************************************/
/*****************Output compare mode****************************/
/*  Capture/Compare 1 selection      */
#define TIM2_TO_TIM5_CCMR1_CC1S_BIT0      0
#define TIM2_TO_TIM5_CCMR1_CC1S_BIT1      1
/*  Output Compare 1 fast enable     */
#define TIM2_TO_TIM5_CCMR1_OC1FE_BIT      2
/*  Output Compare 1 preload enable  */
#define TIM2_TO_TIM5_CCMR1_OC1PE_BIT      3
/*  Output Compare 1 mode            */
#define TIM2_TO_TIM5_CCMR1_OC1M_BIT0      4
#define TIM2_TO_TIM5_CCMR1_OC1M_BIT1      5
#define TIM2_TO_TIM5_CCMR1_OC1M_BIT2      6
/*  Output Compare 1 clear enable    */
#define TIM2_TO_TIM5_CCMR1_OC1CE_BIT      7
/*  Capture/Compare 2 selection      */
#define TIM2_TO_TIM5_CCMR1_CC2S_BIT0      8
#define TIM2_TO_TIM5_CCMR1_CC2S_BIT1      9
/*  Output Compare 2 fast enable     */
#define TIM2_TO_TIM5_CCMR1_OC2FE_BIT      10
/*  Output Compare 2 preload enable  */
#define TIM2_TO_TIM5_CCMR1_OC2PE_BIT      11
/*  Output Compare 2 mode            */
#define TIM2_TO_TIM5_CCMR1_OC2M_BIT0      12
#define TIM2_TO_TIM5_CCMR1_OC2M_BIT1      13
#define TIM2_TO_TIM5_CCMR1_OC2M_BIT2      14
/*  Output Compare 2 clear enable    */
#define TIM2_TO_TIM5_CCMR1_OC2CE_BIT      15
/*****************Output compare mode****************************/
/*  Input capture 1 prescaler        */
#define TIM2_TO_TIM5_CCMR1_IC1PSC_BIT0    2
#define TIM2_TO_TIM5_CCMR1_IC1PSC_BIT1    3
/*  Input capture 1 filter           */
#define TIM2_TO_TIM5_CCMR1_IC1F_BIT0      4
#define TIM2_TO_TIM5_CCMR1_IC1F_BIT1      5
#define TIM2_TO_TIM5_CCMR1_IC1F_BIT2      6
#define TIM2_TO_TIM5_CCMR1_IC1F_BIT3      7
/*  Input capture 2 prescaler        */
#define TIM2_TO_TIM5_CCMR1_IC2PSC_BIT0    10
#define TIM2_TO_TIM5_CCMR1_IC2PSC_BIT1    11
/*  Input capture 2 filter           */
#define TIM2_TO_TIM5_CCMR1_IC2F_BIT0      12
#define TIM2_TO_TIM5_CCMR1_IC2F_BIT1      13
#define TIM2_TO_TIM5_CCMR1_IC2F_BIT2      14
#define TIM2_TO_TIM5_CCMR1_IC2F_BIT3      15

/****************************************************************/
/**  TIMER2 TO TIIMER5 capture/compare mode register 2 (CCMR2) **/
/****************************************************************/
/*****************Output compare mode****************************/
/*  Capture/Compare 3 selection      */
#define TIM2_TO_TIM5_CCMR2_CC3S_BIT0      0
#define TIM2_TO_TIM5_CCMR2_CC3S_BIT1      1
/*  Output Compare 3 fast enable     */
#define TIM2_TO_TIM5_CCMR2_OC3FE_BIT      2
/*  Output Compare 3 preload enable  */
#define TIM2_TO_TIM5_CCMR2_OC3PE_BIT      3
/*  Output Compare 3 mode            */
#define TIM2_TO_TIM5_CCMR2_OC3M_BIT0      4
#define TIM2_TO_TIM5_CCMR2_OC3M_BIT1      5
#define TIM2_TO_TIM5_CCMR2_OC3M_BIT2      6
/*  Output Compare 3 clear enable    */
#define TIM2_TO_TIM5_CCMR1_OC3CE_BIT      7
/*  Capture/Compare 4 selection      */
#define TIM2_TO_TIM5_CCMR2_CC4S_BIT0      8
#define TIM2_TO_TIM5_CCMR2_CC4S_BIT1      9
/*  Output Compare 4 fast enable     */
#define TIM2_TO_TIM5_CCMR2_OC4FE_BIT      10
/*  Output Compare 4 preload enable  */
#define TIM2_TO_TIM5_CCMR2_OC4PE_BIT      11
/*  Output Compare 4 mode            */
#define TIM2_TO_TIM5_CCMR2_OC4M_BIT0      12
#define TIM2_TO_TIM5_CCMR2_OC4M_BIT1      13
#define TIM2_TO_TIM5_CCMR2_OC4M_BIT2      14
/*  Output Compare 4 clear enable    */
#define TIM2_TO_TIM5_CCMR2_OC2CE_BIT      15
/*****************Output compare mode****************************/
/*  Input capture 3 prescaler        */
#define TIM2_TO_TIM5_CCMR2_IC3PSC_BIT0    2
#define TIM2_TO_TIM5_CCMR2_IC3PSC_BIT1    3
/*  Input capture 3 filter           */
#define TIM2_TO_TIM5_CCMR2_IC3F_BIT0      4
#define TIM2_TO_TIM5_CCMR2_IC3F_BIT1      5
#define TIM2_TO_TIM5_CCMR2_IC3F_BIT2      6
#define TIM2_TO_TIM5_CCMR2_IC3F_BIT3      7
/*  Input capture 4 prescaler        */
#define TIM2_TO_TIM5_CCMR2_IC4PSC_BIT0    10
#define TIM2_TO_TIM5_CCMR2_IC4PSC_BIT1    11
/*  Input capture 4 filter           */
#define TIM2_TO_TIM5_CCMR2_IC4F_BIT0      12
#define TIM2_TO_TIM5_CCMR2_IC4F_BIT1      13
#define TIM2_TO_TIM5_CCMR2_IC4F_BIT2      14
#define TIM2_TO_TIM5_CCMR2_IC4F_BIT3      15

/****************************************************************/
/**  TIMER2 TO TIIMER5 capture/compare enable register (CCER)  **/
/****************************************************************/
/*  Capture/Compare 1 output enable                  */
#define TIM2_TO_TIM5_CCER_CC1E_BIT     0
/*  Capture/Compare 1 output polarity                */
#define TIM2_TO_TIM5_CCER_CC1P_BIT     1
/*  Capture/Compare 1 complementary output polarity  */
#define TIM2_TO_TIM5_CCER_CC1NP_BIT    3
/*  Capture/Compare 2 output enable                  */
#define TIM2_TO_TIM5_CCER_CC2E_BIT     4
/*  Capture/Compare 2 output polarity                */
#define TIM2_TO_TIM5_CCER_CC2P_BIT     5
/*  Capture/Compare 2 complementary output polarity  */
#define TIM2_TO_TIM5_CCER_CC2NP_BIT    7
/*  Capture/Compare 3 output enable                  */
#define TIM2_TO_TIM5_CCER_CC3E_BIT     8
/*  Capture/Compare 3 output polarity                */
#define TIM2_TO_TIM5_CCER_CC3P_BIT     9
/*  Capture/Compare 3 complementary output polarity  */
#define TIM2_TO_TIM5_CCER_CC3NP_BIT    11
/*  Capture/Compare 4 output enable                  */
#define TIM2_TO_TIM5_CCER_CC4E_BIT     12
/*  Capture/Compare 4 output polarity                */
#define TIM2_TO_TIM5_CCER_CC4P_BIT     13
/*  Capture/Compare 4 output polarity                */
#define TIM2_TO_TIM5_CCER_CC4NP_BIT    15

/****************************************************************/
/**       TIMER2 TO TIIMER5 DMA control register (DCR)         **/
/****************************************************************/
/*  DMA base address            */
#define TIM2_TO_TIM5_DCR_DBA_BIT0     0
#define TIM2_TO_TIM5_DCR_DBA_BIT1     1
#define TIM2_TO_TIM5_DCR_DBA_BIT2     2
#define TIM2_TO_TIM5_DCR_DBA_BIT3     3
#define TIM2_TO_TIM5_DCR_DBA_BIT4     4
/*  DMA burst length            */
#define TIM2_TO_TIM5_DCR_DBL_BIT0     8
#define TIM2_TO_TIM5_DCR_DBL_BIT1     9
#define TIM2_TO_TIM5_DCR_DBL_BIT2     10
#define TIM2_TO_TIM5_DCR_DBL_BIT3     11
#define TIM2_TO_TIM5_DCR_DBL_BIT4     12

/****************************************************************/
/**               TIMER2 option register (OR)                  **/
/****************************************************************/
/*  Internal trigger 1 remap          */
#define TIM2_OR_ITR1_RMP_BIT0     10
#define TIM2_OR_ITR1_RMP_BIT1     11

/****************************************************************/
/**               TIMER5 option register (OR)                  **/
/****************************************************************/
/*  Internal trigger 4 remap          */
#define TIM5_OR_ITR4_RMP_BIT0     6
#define TIM5_OR_ITR4_RMP_BIT1     7

/****************************************************************/
/**          (General-purpose timer)TIMER9 register           **/
/****************************************************************/
/****************************************************************/
/**              TIM9 control register1 bits(CR1)              **/
/****************************************************************/
/*  Counter enable                 */
#define TIM9_CR1_CEN_BIT   0
/*  Update disable                 */
#define TIM9_CR1_UDIS_BIT  1
/*  Update request source          */
#define TIM9_CR1_URS_BIT   2
/*  One pulse mode                 */
#define TIM9_CR1_OPM_BIT   3
/*  Auto-reload preload enable     */
#define TIM9_CR1_ARPE_BIT  7
/*  Clock division                 */
#define TIM9_CR1_CKD_BIT0  8
#define TIM9_CR1_CKD_BIT1  9

/****************************************************************/
/**       TIM9 slave mode control register(SMCR)               **/
/****************************************************************/
/*  Slave mode selection        */
#define TIM9_SMCR_SMS_BIT0    0
#define TIM9_SMCR_SMS_BIT1    1
#define TIM9_SMCR_SMS_BIT2    2
/*  Trigger selection           */
#define TIM9_SMCR_TS_BIT0     4
#define TIM9_SMCR_TS_BIT1     5
#define TIM9_SMCR_TS_BIT2     6
/*  Master/slave mode           */
#define TIM9_SMCR_MSM_BIT     7

/****************************************************************/
/**       TIM9 DMA/interrupt enable register(DIER)               **/
/****************************************************************/
/*  Update interrupt enable               */
#define TIM9_DIER_UIE_BIT        0
/*  Capture/Compare 1 interrupt enable    */
#define TIM9_DIER_CC1IE_BIT      1
/*  Capture/Compare 2 interrupt enable    */
#define TIM9_DIER_CC2IE_BIT      2
/*  Trigger interrupt enable              */
#define TIM9_DIER_TIE_BIT        6

/****************************************************************/
/**              TIM9 status register (SR)                     **/
/****************************************************************/
/*  Update interrupt flag               */
#define TIM9_SR_UIF_BIT       0
/*  Capture/Compare 1 interrupt flag    */
#define TIM9_SR_CC1IF_BIT     1
/*  Capture/Compare 2 interrupt flag    */
#define TIM9_SR_CC2IF_BIT     2
/*  Trigger interrupt flag              */
#define TIM9_SR_TIF_BIT       6
/*  Capture/Compare 1 overcapture flag  */
#define TIM9_SR_CC1OF_BIT     9
/*  Capture/Compare 2 overcapture flag  */
#define TIM9_SR_CC2OF_BIT     10

/****************************************************************/
/**        TIM9 event generation register (EGR)                **/
/****************************************************************/
/*  Update generation                          */
#define TIM9_EGR_UG_BIT      0
/*  Capture/Compare 1 generation               */
#define TIM9_EGR_CC1G_BIT    1
/*  Capture/Compare 2 generation               */
#define TIM9_EGR_CC2G_BIT    2
/*  Trigger generation                         */
#define TIM9_EGR_TG_BIT      6

/****************************************************************/
/**     TIM9 capture/compare mode register 1 (CCMR1)           **/
/****************************************************************/
/*****************Output compare mode****************************/
/*  Capture/Compare 1 selection      */
#define TIM9_CCMR1_CC1S_BIT0      0
#define TIM9_CCMR1_CC1S_BIT1      1
/*  Output Compare 1 fast enable     */
#define TIM9_CCMR1_OC1FE_BIT      2
/*  Output Compare 1 preload enable  */
#define TIM9_CCMR1_OC1PE_BIT      3
/*  Output Compare 1 mode            */
#define TIM9_CCMR1_OC1M_BIT0      4
#define TIM9_CCMR1_OC1M_BIT1      5
#define TIM9_CCMR1_OC1M_BIT2      6
/*  Capture/Compare 2 selection      */
#define TIM9_CCMR1_CC2S_BIT0      8
#define TIM9_CCMR1_CC2S_BIT1      9
/*  Output Compare 2 fast enable     */
#define TIM9_CCMR1_OC2FE_BIT      10
/*  Output Compare 2 preload enable  */
#define TIM9_CCMR1_OC2PE_BIT      11
/*  Output Compare 2 mode            */
#define TIM9_CCMR1_OC2M_BIT0      12
#define TIM9_CCMR1_OC2M_BIT1      13
#define TIM9_CCMR1_OC2M_BIT2      14
/*****************Output compare mode****************************/
/*  Input capture 1 prescaler        */
#define TIM9_CCMR1_IC1PSC_BIT0    2
#define TIM9_CCMR1_IC1PSC_BIT1    3
/*  Input capture 1 filter           */
#define TIM9_CCMR1_IC1F_BIT0      4
#define TIM9_CCMR1_IC1F_BIT1      5
#define TIM9_CCMR1_IC1F_BIT2      6
#define TIM9_CCMR1_IC1F_BIT3      7
/*  Input capture 2 prescaler        */
#define TIM9_CCMR1_IC2PSC_BIT0    10
#define TIM9_CCMR1_IC2PSC_BIT1    11
/*  Input capture 2 filter           */
#define TIM9_CCMR1_IC2F_BIT0      12
#define TIM9_CCMR1_IC2F_BIT1      13
#define TIM9_CCMR1_IC2F_BIT2      14
#define TIM9_CCMR1_IC2F_BIT3      15

/****************************************************************/
/**     TIM9 capture/compare enable register (CCER)            **/
/****************************************************************/
/*  Capture/Compare 1 output enable                  */
#define TIM9_CCER_CC1E_BIT     0
/*  Capture/Compare 1 output polarity                */
#define TIM9_CCER_CC1P_BIT     1
/*  Capture/Compare 1 complementary output polarity  */
#define TIM9_CCER_CC1NP_BIT    3
/*  Capture/Compare 2 output enable                  */
#define TIM9_CCER_CC2E_BIT     4
/*  Capture/Compare 2 output polarity                */
#define TIM9_CCER_CC2P_BIT     5
/*  Capture/Compare 2 complementary output polarity  */
#define TIM9_CCER_CC2NP_BIT    7

/****************************************************************/
/**          (General-purpose timer)TIM10 To TIM11 register           **/
/****************************************************************/
/****************************************************************/
/**              TIM10 To TIM11 control register1 bits(CR1)              **/
/****************************************************************/
/*  Counter enable                 */
#define TIM10_To_TIM11_CR1_CEN_BIT   0
/*  Update disable                 */
#define TIM10_To_TIM11_CR1_UDIS_BIT  1
/*  Update request source          */
#define TIM10_To_TIM11_CR1_URS_BIT   2
/*  One pulse mode                 */
#define TIM10_To_TIM11_CR1_OPM_BIT   3
/*  Auto-reload preload enable     */
#define TIM10_To_TIM11_CR1_ARPE_BIT  7
/*  Clock division                 */
#define TIM10_To_TIM11_CR1_CKD_BIT0  8
#define TIM10_To_TIM11_CR1_CKD_BIT1  9

/****************************************************************/
/**    TIM10 To TIM11 DMA/interrupt enable register(DIER)      **/
/****************************************************************/
/*  Update interrupt enable               */
#define TIM10_To_TIM11_DIER_UIE_BIT        0
/*  Capture/Compare 1 interrupt enable    */
#define TIM10_To_TIM11_DIER_CC1IE_BIT      1

/****************************************************************/
/**       TIM10 To TIM11 status register (SR)                  **/
/****************************************************************/
/*  Update interrupt flag               */
#define TIM10_To_TIM11_SR_UIF_BIT       0
/*  Capture/Compare 1 interrupt flag    */
#define TIM10_To_TIM11_SR_CC1IF_BIT     1
/*  Capture/Compare 1 overcapture flag  */
#define TIM10_To_TIM11_SR_CC1OF_BIT     9

/****************************************************************/
/**    TIM10 To TIM11 event generation register (EGR)          **/
/****************************************************************/
/*  Update generation                          */
#define TIM10_To_TIM11_EGR_UG_BIT      0
/*  Capture/Compare 1 generation               */
#define TIM10_To_TIM11_EGR_CC1G_BIT    1

/****************************************************************/
/**  TIM10 To TIM11 capture/compare mode register 1 (CCMR1)    **/
/****************************************************************/
/*****************Output compare mode****************************/
/*  Capture/Compare 1 selection      */
#define TIM10_To_TIM11_CCMR1_CC1S_BIT0      0
#define TIM10_To_TIM11_CCMR1_CC1S_BIT1      1
/*  Output Compare 1 fast enable     */
#define TIM10_To_TIM11_CCMR1_OC1FE_BIT      2
/*  Output Compare 1 preload enable  */
#define TIM10_To_TIM11_CCMR1_OC1PE_BIT      3
/*  Output Compare 1 mode            */
#define TIM10_To_TIM11_CCMR1_OC1M_BIT0      4
#define TIM10_To_TIM11_CCMR1_OC1M_BIT1      5
#define TIM10_To_TIM11_CCMR1_OC1M_BIT2      6
/*****************Output compare mode****************************/
/*  Input capture 1 prescaler        */
#define TIM10_To_TIM11_CCMR1_IC1PSC_BIT0    2
#define TIM10_To_TIM11_CCMR1_IC1PSC_BIT1    3
/*  Input capture 1 filter           */
#define TIM10_To_TIM11_CCMR1_IC1F_BIT0      4
#define TIM10_To_TIM11_CCMR1_IC1F_BIT1      5
#define TIM10_To_TIM11_CCMR1_IC1F_BIT2      6
#define TIM10_To_TIM11_CCMR1_IC1F_BIT3      7

/****************************************************************/
/** TIM10 To TIM11 capture/compare enable register (CCER)      **/
/****************************************************************/
/*  Capture/Compare 1 output enable                  */
#define TIM10_To_TIM11_CCER_CC1E_BIT     0
/*  Capture/Compare 1 output polarity                */
#define TIM10_To_TIM11_CCER_CC1P_BIT     1
/*  Capture/Compare 1 complementary output polarity  */
#define TIM10_To_TIM11_CCER_CC1NP_BIT    3

/**********************************************************************************************/

/* define directions of Timer counting */
#define UP_COUNTER    1
#define DOWN_COUNTER  2

/* define timer division */
#define tCK_INT_x_1  1
#define tCK_INT_x_2  2
#define tCK_INT_x_4  3

/* define maximum prescaller */
#define MAX_TIM_PRESCALLER 65535

/* define maximum repatation counter */
#define MAX_TIM_REPETATION_COUNTER 0xff

/* define maximum preload value */
#define MAX_TIM_PRELOAD_VALUE 0xff

/* PWM mode 1 - In upcounting, channel 1 is active as long as TIMx_CNT<TIMx_CCR1
   else inactive. In downcounting, channel 1 is inactive (OC1REF=‘0’) as long as
   TIMx_CNT>TIMx_CCR1 else active (OC1REF=’1’).*/
#define TIM_PWM_MODE1 0b110

#endif /* MCAL_TIMER_TIMER_PRIVATE_H_ */
