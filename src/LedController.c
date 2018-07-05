#include "unity.h"
#include "LedController.h"
#include "Led.h"
#include "Button.h"
#include "unity.h"

/*void turnOnLedIfButtonIsPressed(void){
  if(getButtonState() != 0){
      turnLed(LED_OFF);
  }
}

void turnOffLedIfButtonIsPressed(void){
  if(getButtonState() == 0){
      turnLed(LED_ON);
  }
}
*/

// combine both

void turnOnLedIfButtonIsPressed(void){
    int button_state = getButtonState();
  if(button_state != 0){
      turnLed(LED_ON);
    }
  else if(button_state == 0){
      turnLed(LED_OFF);
    }
  }

/*void checkButtonAndDoLedForever(void){
  while(1){
      turnOnLedIfButtonIsPressed()
          }
}*/

//*******************Specification of the LED*********************
//1. To turn on
//  Release -> Press -> [ON]
//2. To turn off
//  Release -> Press -> Release -> [OFF]
//3. Remain Led state
//   Release -> Release -> Release -> [ON/OFF]

// use switch so cant break after running operation in if / else statement
void doTapTurnOnTapTurnOffLed(LedButtonInfo *Info){

    int currentButtonState = getButtonState();

    switch(Info->Cycles){
      case FIRST_CYCLE:
        // TURN ON (RELEASED - PRESS - RELEASED),1
        if (Info->CurrentLedState == LED_OFF  && Info->OnOrOff== TURN_ON && currentButtonState == BUTTON_RELEASED){
          Info->previousButtonState = BUTTON_RELEASED;
          Info->Cycles = SECOND_CYCLE;
          break;
        }
        // TURN OFF (RELEASED - PRESS - RELEASED),2
        else if (Info->CurrentLedState == LED_ON && Info->OnOrOff== TURN_OFF && currentButtonState == BUTTON_RELEASED){
          Info->previousButtonState = BUTTON_RELEASED;
          Info->Cycles = SECOND_CYCLE;
          break;
        }
         // STAY ON (RELEASED - RELEASED - RELEASED),3
        else if (Info->CurrentLedState == LED_ON && Info->OnOrOff== STAY_ON && currentButtonState == BUTTON_RELEASED){
          Info->previousButtonState = BUTTON_RELEASED;
          Info->Cycles = SECOND_CYCLE;
          break;
        }
        // STAY OFF (RELEASED - RELEASED - RELEASED),4
        else if (Info->CurrentLedState == LED_OFF && Info->OnOrOff== TURN_OFF && currentButtonState == BUTTON_RELEASED){
          Info->previousButtonState = BUTTON_RELEASED;
          Info->Cycles = SECOND_CYCLE;
          break;
        }
        // STAY ON (PRESS - PRESS - PRESS),5
        else if (Info->CurrentLedState == LED_ON  && Info->OnOrOff== STAY_ON && currentButtonState == BUTTON_PRESSED){
          Info->previousButtonState = BUTTON_PRESSED;
          Info->Cycles = SECOND_CYCLE;
          break;
        }
        // STAY OFF (PRESS - PRESS - PRESS),6
        else if (Info->CurrentLedState == LED_OFF  && Info->OnOrOff== STAY_OFF && currentButtonState == BUTTON_PRESSED){
          Info->previousButtonState = BUTTON_PRESSED;
          Info->Cycles = SECOND_CYCLE;
          break;
        }

      case SECOND_CYCLE:
        // TURN ON (RELEASED - PRESS - RELEASED),1
        if (currentButtonState == BUTTON_PRESSED  && Info->Cycles == SECOND_CYCLE && Info->OnOrOff== TURN_ON){
          Info->previousButtonState = BUTTON_PRESSED;
          Info->Cycles = THIRD_CYCLE;
          turnLed(LED_ON);
          break;
        }
        // TURN OFF (RELEASED - PRESS - RELEASED),2
        if (currentButtonState == BUTTON_PRESSED && Info->Cycles == SECOND_CYCLE && Info->OnOrOff== TURN_OFF){
          Info->previousButtonState = BUTTON_PRESSED;
          Info->Cycles = THIRD_CYCLE;
          break;
        }
         // STAY ON (RELEASED - RELEASED - RELEASED),3
        if (currentButtonState == BUTTON_RELEASED  && Info->Cycles == SECOND_CYCLE && Info->OnOrOff== STAY_ON){
          Info->previousButtonState = BUTTON_RELEASED;
          Info->Cycles = THIRD_CYCLE;
          break;
        }
        // STAY OFF (RELEASED - RELEASED - RELEASED),4
        if (currentButtonState == BUTTON_RELEASED  && Info->Cycles == SECOND_CYCLE && Info->OnOrOff== TURN_OFF){
          Info->previousButtonState = BUTTON_RELEASED;
          Info->Cycles = THIRD_CYCLE;
          break;
        }
        // STAY ON (PRESS - PRESS - PRESS),5
        if (currentButtonState == BUTTON_PRESSED  && Info->Cycles == SECOND_CYCLE && Info->OnOrOff== STAY_ON){
          Info->previousButtonState = BUTTON_PRESSED;
          Info->Cycles = THIRD_CYCLE;
          break;
        }
        // STAY OFF (PRESS - PRESS - PRESS),6
        if (currentButtonState == BUTTON_PRESSED  && Info->Cycles == SECOND_CYCLE && Info->OnOrOff== STAY_OFF){
          Info->previousButtonState = BUTTON_PRESSED;
          Info->Cycles = THIRD_CYCLE;
          break;
        }

      case THIRD_CYCLE:
        // TURN ON (RELEASED - PRESS - RELEASED),1
        if (Info->CurrentLedState == LED_OFF  && currentButtonState == BUTTON_RELEASED && Info->OnOrOff== TURN_ON){
          Info->CurrentLedState = LED_ON;
          Info->previousButtonState = BUTTON_RELEASED;
          Info->Cycles = FIRST_CYCLE;
          break;
        }
        // TURN OFF (RELEASED - PRESS - RELEASED),2
        if (Info->CurrentLedState == LED_ON && currentButtonState == BUTTON_RELEASED && Info->OnOrOff== TURN_OFF){
          Info->previousButtonState = BUTTON_RELEASED;
          Info->CurrentLedState = LED_OFF;
          Info->Cycles= FIRST_CYCLE;
          turnLed(LED_OFF);
          break;
        }
         // STAY ON (RELEASED - RELEASED - RELEASED),3
        if (Info->CurrentLedState == LED_ON && currentButtonState == BUTTON_RELEASED && Info->OnOrOff== STAY_ON){
          Info->previousButtonState = BUTTON_RELEASED;
          Info->CurrentLedState = LED_ON;
          Info->Cycles= FIRST_CYCLE;
          turnLed(LED_ON);
          break;
        }
        // STAY OFF (RELEASED - RELEASED - RELEASED),4
        if (Info->CurrentLedState == LED_OFF && currentButtonState == BUTTON_RELEASED && Info->OnOrOff== TURN_OFF){
          Info->previousButtonState = BUTTON_RELEASED;
          Info->CurrentLedState = LED_OFF;
          Info->Cycles= FIRST_CYCLE;
          turnLed(LED_OFF);
          break;
        }
        // STAY ON (PRESS - PRESS - PRESS),5
        if (currentButtonState == BUTTON_PRESSED && Info->Cycles == THIRD_CYCLE && Info->OnOrOff== STAY_ON){
          Info->previousButtonState = BUTTON_PRESSED;
          Info->CurrentLedState = LED_ON;
          Info->Cycles= FIRST_CYCLE;
          turnLed(LED_ON);
          break;
        }
        // STAY OFF (PRESS - PRESS - PRESS),6
        if (currentButtonState == BUTTON_PRESSED  && Info->Cycles == THIRD_CYCLE && Info->OnOrOff== STAY_OFF){
          Info->previousButtonState = BUTTON_PRESSED;
          Info->CurrentLedState = LED_OFF;
          Info->Cycles= FIRST_CYCLE;
          turnLed(LED_OFF);
          break;
        }
      default:
      TEST_FAIL_MESSAGE("Invalid Cycle");
  }
}
/*void doTapTapLedController(void){
  LedState CurrentLedState
  while(1){

  }
}*/
