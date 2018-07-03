#include "LedController.h"
#include "Led.h"
#include "Button.h"

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
void doTapTurnOnTapTurnOffLed(LedButtonInfo *Info){

    //int CurrentLedState = Info->CurrentLedState;
    //int previousButtonState = Info->previousButtonStat  e;
    //int TwoButtonStateBefore = Info->TwoButtonStateBefore;
    int currentButtonState = getButtonState();
    int currentCycleState = getcyclesState();


    // TURN ON (RELEASED - PRESS - RELEASED),1
        if(Info->CurrentLedState == LED_OFF  && Info->OnOrOff== TURN_ON){       // check LED state
        //if(Info->previousButtonState == BUTTON_NOT_PRESS || Info->TwoButtonStateBefore == BUTTON_NOT_PRESS){  // check previouos button

              if(currentButtonState == BUTTON_NOT_PRESS && currentCycleState == FIRST_CYCLE){     // first button
                Info->tempStateForStatement = SET;
              }
              if (currentButtonState == BUTTON_PRESS && Info->tempStateForStatement == SET && currentCycleState == SECOND_CYCLE){
                Info->previousButtonState = BUTTON_PRESS;
                Info->CurrentLedState = LED_ON;
                turnLed(LED_ON);
              }

            }
			// TURN ON (PRESS - PRESS - PRESS),4
          else if (Info->CurrentLedState == LED_ON && Info->OnOrOff== TURN_ON){
            if(currentButtonState == BUTTON_PRESS && currentCycleState == FIRST_CYCLE){
              Info->tempStateForStatement = SET;


            }
            if(currentButtonState == BUTTON_PRESS && Info->tempStateForStatement == SET && currentCycleState == SECOND_CYCLE){
              Info->tempStateForStatement = TOGGLE;

            }
              if(currentButtonState == BUTTON_PRESS && Info->tempStateForStatement == TOGGLE && currentCycleState == THIRD_CYCLE){
                Info->previousButtonState = BUTTON_PRESS;
                Info->CurrentLedState = LED_ON;
                turnLed(LED_ON);
              }
          }

        // TURN OFF (RELEASED - PRESS - RELEASED),2
          else if (Info->CurrentLedState == LED_ON && Info->OnOrOff== TURN_OFF){
        //if(Info->previousButtonState == BUTTON_PRESS || Info->TwoButtonStateBefore == BUTTON_NOT_PRESS){


              if(currentButtonState == BUTTON_NOT_PRESS && Info->tempStateForStatement ==TOGGLE && currentCycleState == FIRST_CYCLE){
              Info->tempStateForStatement  = RESET;
              }

              if (currentButtonState == BUTTON_PRESS && Info->tempStateForStatement  == RESET && currentCycleState == SECOND_CYCLE ){
                Info->previousButtonState = BUTTON_PRESS;
                Info->tempStateForStatement  = TOGGLE;


              }
              if(Info->previousButtonState == BUTTON_PRESS && currentButtonState == BUTTON_NOT_PRESS && Info->tempStateForStatement  == TOGGLE && currentCycleState == THIRD_CYCLE){
                Info->previousButtonState = BUTTON_NOT_PRESS;
                Info->CurrentLedState = LED_OFF;
                turnLed(LED_OFF);
            }
          }
		    // TURN OFF  (RELEASED - RELEASED - RELEASED),3
            else if (Info->CurrentLedState == LED_OFF && Info->OnOrOff== TURN_OFF){
              if(currentButtonState == BUTTON_NOT_PRESS && Info->tempStateForStatement == RESET && currentCycleState == FIRST_CYCLE){
                Info->tempStateForStatement  = SET;
                Info->CurrentLedState = LED_OFF;

              }
              if(currentButtonState == BUTTON_NOT_PRESS && Info->tempStateForStatement == SET && currentCycleState == SECOND_CYCLE){
                Info->tempStateForStatement  = TOGGLE;
                Info->CurrentLedState = LED_OFF;

              }
              if(currentButtonState == BUTTON_NOT_PRESS && Info->tempStateForStatement == TOGGLE && currentCycleState == THIRD_CYCLE){
                Info->previousButtonState = BUTTON_NOT_PRESS;
                Info->CurrentLedState = LED_OFF;
                turnLed(LED_OFF);
              }
          }
  }

/*void doTapTapLedController(void){
  LedState CurrentLedState
  while(1){

  }
}*/
