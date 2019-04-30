/**
  ******************************************************************************
  * @file    Project/STM32F4xx_StdPeriph_Templates/main.c 
  * @author  MCD Application Team
  * @version V1.5.0
  * @date    06-March-2015
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2015 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx_it.h"
/** @addtogroup Template_Project
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static __IO uint32_t uwTimingDelay;
RCC_ClocksTypeDef RCC_Clocks;
s16 current_M3508[4];
chassis_t chassis = { 0 };
moto_measure_t moto_chassis[4] = { 0 } ;
//#define AUTOP_SIZE 17   //sizeof(tReceXToneTData)
extern char temp_buf[14];
extern char RECIVE_start;
extern u16 get1,get2,get3,get4,get5,get6,get7,get8;
tReceTXoneData ReceData = {0};
extern pid_t pid_spd[4];
extern u16 ppm_rx[10];
//extern uint16_t count;
//extern	float l1_1,l1_2,l2_1,l2_2,r1_1,r1_2,r2_1,r2_2;


u8 SV1_State = 0;
u8 SV2_State = 0;
u8 SV3_State = 0;
u8 SV4_State = 0;
u8 SV5_State = 0;

//volatile float Gyno;


int main(void)
{ 
		SysTick_Configuration();
		TIM3_Int_Init(5000-1,2100-1);  //84M  84M/psc = 10Khz  10Khz * 50 = 5ms
		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  
    LED_KEY_Init();
//		Init_CAN1();
//		SV_Init();
	  TIM5_PWM_Init(10000-1,168-1);
	  TIM2_PWM_Init(10000-1,168-1);
	  TIM4_PWM_Init(10000-1,168-1);
	  TIM8_PWM_Init(10000-1,336-1);
	  UART6_Init(115200);
		while (1)
		{
//			BALANCE();
			get1=ReceData.temp1_1;
			get2=ReceData.temp2_1;
			get3=ReceData.temp3_1;
			get4=ReceData.temp4_1;
			get5=ReceData.temp5_1;
			get6=ReceData.temp6_1;
			get7=ReceData.temp7_1;
			get8=ReceData.temp8_1;	
if((get4>0)&&(get4<150))
{
	LED_OFF;
	GAITF();
}
else if((get3>250)&&(get3<=409))
{
	LED_OFF;
	GAITL();
}
else if((get3>0)&&(get3<150))
{
	LED_OFF;
	GAITR();
}
else if((get4>250)&&(get4<=409))
{
	LED_OFF;
	GAITB();
}
else if((get1>250)&&(get1<=409))
{
	 LED_OFF;
	 LEFT();
}

else if((get1>0)&&(get1<150))
{
	LED_OFF;
	RIGHT();
}

else
{
	LED_ON;
	STANDUP();
}
}
}

