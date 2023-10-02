#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "MCAL/GPIO/GPIO_init.h"
#include "MCAL/SPI/SPI_init.h"
#include "MCAL/UART/UART_interface.h"
#include "MCAL/SYSTIC/SYSTIC_init.h"

#include "HAL/PWM_DCmotor/PWM_DCmotor_init.h"
#include "HAL/TFT/TFT_init.h"
#include "HAL/LED/LED_int.h"
#include "HAL/Ultrasonic/Ultrasonic_init.h"

#include "car_image.h"

#define Go              0
#define Back            1
#define Right           2
#define Left            3
#define Forward_Right   4
#define Forward_Left    5
#define Backward_Right  6
#define Backward_Left   7

#define Speed1          1
#define Speed2          2
#define Speed3          3

#define SO_SHORT_DISTANCE  10.0
#define UN_SAFE_DISTANCE   20.0


void APP_voidGoTasks () ;
void APP_voidBackTasks () ;
void APP_voidBackward_RightTasks () ;
void APP_voidBackward_LEFTTasks () ;
void APP_voidRight_LeftTasks () ;
void APP_voidForward_RightTasks () ;
void APP_voidForward_LeftTasks () ;

/*declaration 4motors*/
extern DCmotor_Type M1 ;
extern DCmotor_Type M2 ;
extern DCmotor_Type M3 ;
extern DCmotor_Type M4 ;

/*declaratioin init and clock for UART*/
extern USART_InitType         MUART_Init ;
extern USART_ClockInitTypeDef MUART_clock ;

/*declaration my speed and direction tacken from NRF*/
typedef struct
{
	u8 Direction:3 ;
	u8 Speed    :3 ;
	u8 Flag     :2 ;
}My_Data;

/*declaration distance between my car and nearing car */
typedef struct
{
	u8 Distance_GO ;
	u8 Distance_Back ;
	u8 Distance_Left ;
	u8 Distance_Right ;
}Near_Distance;

My_Data       G_xMy_Data       = {0,0,0};
Near_Distance G_xNear_Distance = {0,0,0,0};

u8 G_u8DataFromRPI        = 0 ; // using UART6  (Rx)
u8 G_u8DataToRPI          = 0 ; // using UART6  (Tx)
u8 G_u8DataFromBluetooth  = 0 ; // using UART1  (Rx)
void RpiData (void)
{
	/*Recived data from UART*/
	G_u8DataFromRPI = MUART_u8ReadDataRegister(UART6);
}

void BluetoothData (void)
{
	/*Recived data from UART*/
	G_u8DataFromBluetooth = MUART_u8ReadDataRegister(UART1);
}

u8 G_u8DataAfterProccing = 0 ;
u8 ProcessingFun (void)
{
	/*Mapping data from bluetooth*/
	switch (G_u8DataFromBluetooth)
	{
	case 'F':
		G_xMy_Data.Direction = Go ;
		break;
	case 'I':
		G_xMy_Data.Direction = Forward_Right ;
		break;
	case 'R':
		G_xMy_Data.Direction = Right ;
		break;
	case 'J':
		G_xMy_Data.Direction = Backward_Right ;
		break;
	case 'b':
		G_xMy_Data.Direction = Back ;
		break;
	case 'U':
	case 'u':
		G_xMy_Data.Direction = Backward_Left ;
		break;
	case 'L':
		G_xMy_Data.Direction = Left ;
		break;
	case 'G':
		G_xMy_Data.Direction = Forward_Left ;
		break;
	case '1':
	case '2':
	case '3':
		G_xMy_Data.Speed = Speed1 ;
		break;
	case '4':
	case '5':
	case '6':
		G_xMy_Data.Speed = Speed2 ;
		break;
	case '7':
	case '8':
	case '9':
	case 'q':
		G_xMy_Data.Speed = Speed3 ;
		break;
	}

	G_xNear_Distance.Distance_GO    = 15.0 ;
	G_xNear_Distance.Distance_Right = 15.0 ;
	G_xNear_Distance.Distance_Left  = 15.0 ;
	G_xNear_Distance.Distance_Back  = 15.0 ;

	G_u8DataAfterProccing = ((G_u8DataAfterProccing & (0xF8)) | G_xMy_Data.Direction) ;
	G_u8DataAfterProccing = ((G_u8DataAfterProccing & (0xC7)) | (G_xMy_Data.Speed << 3)) ;

	if (G_u8DataFromBluetooth == 'F')
	{
		/*send data to RPI to open back camera*/
		G_u8DataToRPI = Go ;
		MUART_voidTransmitByte(UART6 , G_u8DataToRPI) ;
		MSTK_voidSetBusyWait(1000) ;
		APP_voidGoTasks() ;
	}
	else if (G_u8DataFromBluetooth == 'b')
	{
		/*send data to RPI to open back camera*/
		G_u8DataToRPI = Back ;
		MUART_voidTransmitByte(UART6 , G_u8DataToRPI) ;
		MSTK_voidSetBusyWait(1000) ;
		APP_voidBackTasks () ;
	}
	else if (G_u8DataFromBluetooth == 'J')
	{
		/*send data to RPI to open back camera*/
		G_u8DataToRPI = Backward_Right ;
		MUART_voidTransmitByte(UART6 , G_u8DataToRPI) ;
		MSTK_voidSetBusyWait(1000) ;
		APP_voidBackward_RightTasks () ;
	}
	else if (G_u8DataFromBluetooth == 'U')
	{
		/*send data to RPI to open back camera*/
		G_u8DataToRPI = Backward_Left ;
		MUART_voidTransmitByte(UART6 , G_u8DataToRPI) ;
		MSTK_voidSetBusyWait(1000) ;
		APP_voidBackward_LEFTTasks () ;
	}
	else if (G_u8DataFromBluetooth == 'L' ||
			G_u8DataFromBluetooth == 'R')
	{
		APP_voidRight_LeftTasks () ;
	}
	else if (G_xMy_Data.Direction == Forward_Right)
	{
		/*send data to RPI*/
		G_u8DataToRPI = G_xMy_Data.Direction ;
		MUART_voidTransmitByte(UART6 , G_u8DataToRPI) ;
		MSTK_voidSetBusyWait(1000) ;
		APP_voidForward_RightTasks() ;
	}
	else if (G_xMy_Data.Direction == Forward_Left)
	{
		/*send data to RPI*/
		G_u8DataToRPI = G_xMy_Data.Direction ;
		MUART_voidTransmitByte(UART6 , G_u8DataToRPI) ;
		MSTK_voidSetBusyWait(1000) ;
		APP_voidForward_LeftTasks() ;
	}
	return G_u8DataAfterProccing ;
}

void main (void)
{
	u8  L_u8Speed ;
	u8  L_u8Direction ;
	u8  L_u8Flag ;

	MSTK_voidInit() ;

	MUART_voidInit(&MUART_Init , &MUART_clock , UART6) ;
	MUART6_voidSetCallBack(RpiData) ;
	MUART_RxIntSetStatus (UART6 , ENABLE) ;
	MUART_voidEnable (UART6) ;

	MUART_voidInit(&MUART_Init , &MUART_clock , UART1) ;
	MUART1_voidSetCallBack(BluetoothData) ;
	MUART_RxIntSetStatus (UART1 , ENABLE) ;
	MUART_voidEnable (UART1) ;

	/*initialize 4motors*/
	HDC_init (M1) ;
	HDC_init (M2) ;
	HDC_init (M3) ;
	HDC_init (M4) ;

	/*initialization LEDs*/
	HLED_voidLedInitial(LED1_ID) ; /* Green */
	HLED_voidLedInitial(LED2_ID) ; /*  Red  */
	HLED_voidLedInitial(LED3_ID) ; /* Yellow*/

	//	/*initialize Ultrasonic*/
	//	HUltrasonic_voidInit(&Ultrasonic1_Conf);
	//	HUltrasonic_voidInit(&Ultrasonic2_Conf);
	//	HUltrasonic_voidInit(&Ultrasonic3_Conf);
	//	HUltrasonic_voidInit(&Ultrasonic4_Conf);

	/*initialization TFT*/
	HTFT_voidInit(SPI2_Type) ;

	HTFT_voidDisplayImage(SPI2_Type , car , sizeof (car) / sizeof (car [0])) ;
	HTFT_voidDisplayString(SPI2_Type , 1 , 3 , (u8*)"Direction =inittial" , YELLOW) ;
	HTFT_voidDisplayString(SPI2_Type , 1 , 4 , (u8*)"Speed     =stop    " , YELLOW) ;
	while (1)
	{
		ProcessingFun () ;
		/*
		              ------------------------
		              | 2bit | 3bits | 3bits |
		              ------------------------
		 */
		/*Encoding recived data and take Direction (second 3bits)*/
		L_u8Direction = G_u8DataAfterProccing & 0x07 ;
		/*Encoding recived data and take Speed (first 4bits)*/
		L_u8Speed = (G_u8DataAfterProccing >> 3) & 0x07 ;
		/*Encoding recived data and take Flag (last bit)*/
		L_u8Flag = G_u8DataAfterProccing >> 6 ;
		if (G_u8DataFromBluetooth == 'S' || G_u8DataFromBluetooth == 'W' || G_u8DataFromBluetooth == 'w')

		{
			HDC_Stop(M1) ;
			HDC_Stop(M2) ;
			HDC_Stop(M3) ;
			HDC_Stop(M4) ;
			HLED_voidLedOn(LED2_ID) ;
			HLED_voidLedOff(LED1_ID) ;
			HLED_voidLedOff(LED3_ID) ;
			HTFT_voidDisplayString(SPI2_Type , 12 , 4 , (u8*)"Zero  " , YELLOW) ;
		}
		else
		{
			/*
			 * first speed  = 1 + 0x09 = 0x0B
			 * second speed = 2 + 0x09 = 0x0C
			 * third speed  = 3 + 0x09 = 0x0D
			 */
			L_u8Speed = (G_xMy_Data.Speed) + 0x9;

			if (G_u8DataFromBluetooth == 'F')  //Forward direction
			{
				HDC_ClockWise(M1 , L_u8Speed) ;
				HDC_ClockWise(M2 , L_u8Speed) ;
				HDC_ClockWise(M3 , L_u8Speed) ;
				HDC_ClockWise(M4 , L_u8Speed) ;
				HTFT_voidDisplayString(SPI2_Type , 12 , 3 , (u8*)"Forward " , YELLOW) ;
			}
			else if (G_u8DataFromBluetooth == 'b')  //Backward direction
			{
				HDC_CounterClockWise(M1 , L_u8Speed) ;
				HDC_CounterClockWise(M2 , L_u8Speed) ;
				HDC_CounterClockWise(M3 , L_u8Speed) ;
				HDC_CounterClockWise(M4 , L_u8Speed) ;
				HTFT_voidDisplayString(SPI2_Type , 12 , 3 , (u8*)"Back    " , YELLOW) ;
			}
			else if (G_u8DataFromBluetooth == 'R')  //Right direction
			{
				HDC_Stop(M1) ;
				HDC_Stop(M3) ;
				HDC_ClockWise(M2 , L_u8Speed) ;
				HDC_ClockWise(M4 , L_u8Speed) ;
				HTFT_voidDisplayString(SPI2_Type , 12 , 3 , (u8*)"Right   " , YELLOW) ;
			}
			else if (G_u8DataFromBluetooth == 'L')  //Left direction
			{
				HDC_ClockWise(M1 , L_u8Speed) ;
				HDC_ClockWise(M3 , L_u8Speed) ;
				HDC_Stop(M2) ;
				HDC_Stop(M4) ;
				HTFT_voidDisplayString(SPI2_Type , 12 , 3 , (u8*)"Left    " , YELLOW) ;
			}
			else if (G_u8DataFromBluetooth == 'I')  //forward right
			{
				HDC_ClockWise(M1 , 0xa) ;
				HDC_ClockWise(M3 , 0xa) ;
				HDC_ClockWise(M2 , 0xc) ;
				HDC_ClockWise(M4 , 0xc) ;
				HTFT_voidDisplayString(SPI2_Type , 12 , 3 , (u8*)"F_Right " , YELLOW) ;
			}
			else if (G_u8DataFromBluetooth == 'G')  //forward left
			{
				HDC_ClockWise(M1 , 0xa) ;
				HDC_ClockWise(M3 , 0xa) ;
				HDC_ClockWise(M2 , 0xc) ;
				HDC_ClockWise(M4 , 0xc) ;
				HTFT_voidDisplayString(SPI2_Type , 12 , 3 , (u8*)"F_Left  " , YELLOW) ;
			}
			else if (G_u8DataFromBluetooth == 'J')  //backward right
			{
				HDC_CounterClockWise(M1 , 0xa) ;
				HDC_CounterClockWise(M3 , 0xa) ;
				HDC_CounterClockWise(M2 , 0xc) ;
				HDC_CounterClockWise(M4 , 0xc) ;
				HTFT_voidDisplayString(SPI2_Type , 12 , 3 , (u8*)"B_right  " , YELLOW) ;
			}
			else if (G_u8DataFromBluetooth == 'U')  //backward left
			{
				HDC_CounterClockWise(M1 , 0xa) ;
				HDC_CounterClockWise(M3 , 0xa) ;
				HDC_CounterClockWise(M2 , 0xc) ;
				HDC_CounterClockWise(M4 , 0xc) ;
				HTFT_voidDisplayString(SPI2_Type , 12 , 3 , (u8*)"B_Left  " , YELLOW) ;
			}
			if (L_u8Speed == 0xA)
			{
				HLED_voidLedOn(LED3_ID) ;
				HLED_voidLedOff(LED2_ID) ;
				HLED_voidLedOff(LED1_ID) ;
				HTFT_voidDisplayString(SPI2_Type , 12 , 4 , (u8*)"First " , YELLOW) ;
			}
			else if (L_u8Speed == 0xB)
			{
				HLED_voidLedOn(LED3_ID) ;
				HLED_voidLedOff(LED2_ID) ;
				HLED_voidLedOff(LED1_ID) ;
				HTFT_voidDisplayString(SPI2_Type , 12 , 4 , (u8*)"Second" , YELLOW) ;
			}
			else if (L_u8Speed == 0xC)
			{
				HLED_voidLedOn(LED1_ID) ;
				HLED_voidLedOff(LED2_ID) ;
				HLED_voidLedOff(LED3_ID) ;
				HTFT_voidDisplayString(SPI2_Type , 12 , 4 , (u8*)"Third " , YELLOW) ;
			}

			if (L_u8Flag == 0)
			{
				HTFT_voidDisplayString(SPI2_Type , 1 , 5 , (u8*)"Safed Case       " , GREEN) ;
			}
			else if (L_u8Flag == 1)
			{
				HTFT_voidDisplayString(SPI2_Type , 1 , 5 , (u8*)"Un Safed Distance" , RED) ;
			}
			else if (L_u8Flag == 2)
			{
				if (L_u8Direction == 4 || L_u8Direction == 5)
				{
					HTFT_voidDisplayString(SPI2_Type , 1 , 5 , (u8*)"Ignore Order     " , RED) ;
				}
				else if (L_u8Direction == 0)
				{
					HTFT_voidDisplayString(SPI2_Type , 1 , 5 , (u8*)"Limit Speed      " , RED) ;
				}
			}
			else if (L_u8Flag == 3)
			{
				L_u8Speed = 0 ;
				HDC_Stop(M1) ;
				HDC_Stop(M2) ;
				HDC_Stop(M3) ;
				HDC_Stop(M4) ;
				HTFT_voidDisplayString(SPI2_Type , 1 , 5 , (u8*)"Stop Car             " , RED) ;
			}
			if (L_u8Speed == 0)
			{
				L_u8Speed = 0 ;
				HDC_Stop(M1) ;
				HDC_Stop(M2) ;
				HDC_Stop(M3) ;
				HDC_Stop(M4) ;
				HLED_voidLedOn(LED2_ID) ;
				HLED_voidLedOff(LED1_ID) ;
				HLED_voidLedOff(LED3_ID) ;
				HTFT_voidDisplayString(SPI2_Type , 12 , 4 , (u8*)"Zero  " , YELLOW) ;
			}
		}
	}
}

void APP_voidGoTasks ()
{
	if (G_xNear_Distance.Distance_GO  <= SO_SHORT_DISTANCE) // stop car
	{
		/*flag = 3*/
		SET_BIT(G_u8DataAfterProccing , 6) ;
		SET_BIT(G_u8DataAfterProccing , 7) ;
		/*stop car + alarm*/
		G_u8DataAfterProccing = G_u8DataAfterProccing & 0xC7 ;
	}
	else if (G_xNear_Distance.Distance_GO <= UN_SAFE_DISTANCE) //Un Safed Distance
	{
		if (G_u8DataFromRPI != 0)
		{
			if (G_xMy_Data.Speed <= G_u8DataFromRPI)
			{
				/*flag = 0*/
				CLR_BIT(G_u8DataAfterProccing , 6) ;
				CLR_BIT(G_u8DataAfterProccing , 7) ;
				/*send direction and speed without any change*/
				G_u8DataAfterProccing = ((G_u8DataAfterProccing & 0xF8) | G_xMy_Data.Direction) ;
				G_u8DataAfterProccing = ((G_u8DataAfterProccing & 0xC7) | (G_xMy_Data.Speed << 3)) ;
			}
			else
			{
				/*flag = 2*/
				CLR_BIT(G_u8DataAfterProccing , 6) ;
				SET_BIT(G_u8DataAfterProccing , 7) ;
				/*send direction and speed without any change*/
				G_u8DataAfterProccing = ((G_u8DataAfterProccing & 0xF8) | G_xMy_Data.Direction) ;
				G_u8DataAfterProccing = ((G_u8DataAfterProccing & 0xC7) | (G_u8DataFromRPI << 3)) ;
			}
		}
		else
		{
			/*flag = 1*/
			SET_BIT(G_u8DataAfterProccing , 6) ;
			CLR_BIT(G_u8DataAfterProccing , 7) ;
			/*send direction and speed without any change*/
			G_u8DataAfterProccing = ((G_u8DataAfterProccing & 0xF8) | G_xMy_Data.Direction) ;
			G_u8DataAfterProccing = ((G_u8DataAfterProccing & 0xC7) | (G_xMy_Data.Speed << 3)) ;
		}
	}
	else //sefed case
	{
		/*flag = 0*/
		CLR_BIT(G_u8DataAfterProccing , 6) ;
		CLR_BIT(G_u8DataAfterProccing , 7) ;
		/*send direction and speed without any change*/
		G_u8DataAfterProccing = ((G_u8DataAfterProccing & 0xF8) | G_xMy_Data.Direction) ;
		G_u8DataAfterProccing = ((G_u8DataAfterProccing & 0xC7) | (G_xMy_Data.Speed << 3)) ;
	}
}
/*************************************************/
void APP_voidBackTasks ()
{
	if (G_xNear_Distance.Distance_Back <= SO_SHORT_DISTANCE)//stop car
	{
		/*flag = 3*/
		SET_BIT(G_u8DataAfterProccing , 6) ;
		SET_BIT(G_u8DataAfterProccing , 7) ;
		/*stop car + alarm*/
		G_u8DataAfterProccing = G_u8DataAfterProccing & 0xC7 ;
	}
	else if (G_xNear_Distance.Distance_Back <= UN_SAFE_DISTANCE) //Un Safed Distance
	{
		/*flag = 1*/
		SET_BIT(G_u8DataAfterProccing , 6) ;
		CLR_BIT(G_u8DataAfterProccing , 7) ;
		/*send direction and speed without any change + alarm*/
		G_u8DataAfterProccing = ((G_u8DataAfterProccing & 0xF8) | Back) ;
		G_u8DataAfterProccing = ((G_u8DataAfterProccing & 0xC7) | (G_xMy_Data.Speed << 3)) ;
	}
	else //sefed case
	{
		/*flag = 0*/
		CLR_BIT(G_u8DataAfterProccing , 6) ;
		CLR_BIT(G_u8DataAfterProccing , 7) ;
		/*send direction and speed without any change*/
		G_u8DataAfterProccing = ((G_u8DataAfterProccing & 0xF8) | Back) ;
		G_u8DataAfterProccing = ((G_u8DataAfterProccing & 0xC7) | (G_xMy_Data.Speed << 3)) ;
	}
}
/*************************************************/
void APP_voidBackward_RightTasks ()
{
	if (G_xNear_Distance.Distance_Left <= SO_SHORT_DISTANCE)//stop car
	{
		/*flag = 3*/
		SET_BIT(G_u8DataAfterProccing , 6) ;
		SET_BIT(G_u8DataAfterProccing , 7) ;
		/*stop car + alarm*/
		G_u8DataAfterProccing = G_u8DataAfterProccing & 0xC7 ;
	}
	else if (G_xNear_Distance.Distance_Left <= UN_SAFE_DISTANCE) //Un Safed Distance
	{
		/*flag = 1*/
		SET_BIT(G_u8DataAfterProccing , 6) ;
		CLR_BIT(G_u8DataAfterProccing , 7) ;
		/*send direction and speed without any change + alarm*/
		G_u8DataAfterProccing = ((G_u8DataAfterProccing & 0xF8) | Backward_Right) ;
		G_u8DataAfterProccing = ((G_u8DataAfterProccing & 0xC7) | (G_xMy_Data.Speed << 3)) ;
	}
	else //sefed case
	{
		/*flag = 0*/
		CLR_BIT(G_u8DataAfterProccing , 6) ;
		CLR_BIT(G_u8DataAfterProccing , 7) ;
		/*send direction and speed without any change*/
		G_u8DataAfterProccing = ((G_u8DataAfterProccing & 0xF8) | Backward_Right) ;
		G_u8DataAfterProccing = ((G_u8DataAfterProccing & 0xC7) | (G_xMy_Data.Speed << 3)) ;
	}
}
/*************************************************/
void APP_voidBackward_LEFTTasks ()
{
	if (G_xNear_Distance.Distance_Right <= SO_SHORT_DISTANCE)//stop car
	{
		/*flag = 3*/
		SET_BIT(G_u8DataAfterProccing , 6) ;
		SET_BIT(G_u8DataAfterProccing , 7) ;
		/*stop car + alarm*/
		G_u8DataAfterProccing = G_u8DataAfterProccing & 0xC7 ;
	}
	else if (G_xNear_Distance.Distance_Right <= UN_SAFE_DISTANCE) //Un Safed Distance
	{
		/*flag = 1*/
		SET_BIT(G_u8DataAfterProccing , 6) ;
		CLR_BIT(G_u8DataAfterProccing , 7) ;
		/*send direction and speed without any change + alarm*/
		G_u8DataAfterProccing = ((G_u8DataAfterProccing & 0xF8) | Backward_Left) ;
		G_u8DataAfterProccing = ((G_u8DataAfterProccing & 0xC7) | (G_xMy_Data.Speed << 3)) ;
	}
	else //sefed case
	{
		/*flag = 0*/
		CLR_BIT(G_u8DataAfterProccing , 6) ;
		CLR_BIT(G_u8DataAfterProccing , 7) ;
		/*send direction and speed without any change*/
		G_u8DataAfterProccing = ((G_u8DataAfterProccing & 0xF8) | Backward_Left) ;
		G_u8DataAfterProccing = ((G_u8DataAfterProccing & 0xC7) | (G_xMy_Data.Speed << 3)) ;
	}
}
/*************************************************/
void APP_voidRight_LeftTasks ()
{
	/*flag = 0*/
	CLR_BIT(G_u8DataAfterProccing , 6) ;
	CLR_BIT(G_u8DataAfterProccing , 7) ;
	/*send direction and speed without any change*/
	G_u8DataAfterProccing = ((G_u8DataAfterProccing & 0xF8) | G_xMy_Data.Direction) ;
	G_u8DataAfterProccing = ((G_u8DataAfterProccing & 0xC7) | (G_xMy_Data.Speed << 3)) ;
}
/*************************************************/
void APP_voidForward_RightTasks ()
{
	if (G_xNear_Distance.Distance_Right <= SO_SHORT_DISTANCE)//stop car
	{
		/*flag = 3*/
		SET_BIT(G_u8DataAfterProccing , 6) ;
		SET_BIT(G_u8DataAfterProccing , 7) ;
		/*stop car + alarm*/
		G_u8DataAfterProccing = G_u8DataAfterProccing & 0xC7 ;
	}
	else if (G_xNear_Distance.Distance_Right <= UN_SAFE_DISTANCE) //Un Safed Distance
	{
		/*flag = 1*/
		SET_BIT(G_u8DataAfterProccing , 6) ;
		CLR_BIT(G_u8DataAfterProccing , 7) ;
		/*send direction and speed without any change + alarm*/
		G_u8DataAfterProccing = ((G_u8DataAfterProccing & 0xF8) | G_xMy_Data.Direction) ;
		G_u8DataAfterProccing = ((G_u8DataAfterProccing & 0xC7) | (G_xMy_Data.Speed << 3)) ;
	}
	else //sefed case
	{
		/*flag = 0*/
		CLR_BIT(G_u8DataAfterProccing , 6) ;
		CLR_BIT(G_u8DataAfterProccing , 7) ;
		/*send direction and speed without any change*/
		G_u8DataAfterProccing = ((G_u8DataAfterProccing & 0xF8) | G_xMy_Data.Direction) ;
		G_u8DataAfterProccing = ((G_u8DataAfterProccing & 0xC7) | (G_xMy_Data.Speed << 3)) ;
	}
}
/*************************************************/
void APP_voidForward_LeftTasks ()
{
	if (G_xNear_Distance.Distance_Left <= SO_SHORT_DISTANCE)//stop car
	{
		/*flag = 3*/
		SET_BIT(G_u8DataAfterProccing , 6) ;
		SET_BIT(G_u8DataAfterProccing , 7) ;
		/*stop car + alarm*/
		G_u8DataAfterProccing = G_u8DataAfterProccing & 0xC7 ;
	}
	else if (G_xNear_Distance.Distance_Left <= UN_SAFE_DISTANCE) //Un Safed Distance
	{
		/*flag = 1*/
		SET_BIT(G_u8DataAfterProccing , 6) ;
		CLR_BIT(G_u8DataAfterProccing , 7) ;
		/*send direction and speed without any change + alarm*/
		G_u8DataAfterProccing = ((G_u8DataAfterProccing & 0xF8) | G_xMy_Data.Direction) ;
		G_u8DataAfterProccing = ((G_u8DataAfterProccing & 0xC7) | (G_xMy_Data.Speed << 3)) ;
	}
	else //sefed case
	{
		/*flag = 0*/
		CLR_BIT(G_u8DataAfterProccing , 6) ;
		CLR_BIT(G_u8DataAfterProccing , 7) ;
		/*send direction and speed without any change*/
		G_u8DataAfterProccing = ((G_u8DataAfterProccing & 0xF8) | G_xMy_Data.Direction) ;
		G_u8DataAfterProccing = ((G_u8DataAfterProccing & 0xC7) | (G_xMy_Data.Speed << 3)) ;
	}
}
