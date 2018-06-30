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
    //int previousButtonState = Info->previousButtonState;
    //int TwoButtonStateBefore = Info->TwoButtonStateBefore;
    int currentButtonState = getButtonState();


    // Turn On
      if(Info->CurrentLedState == LED_OFF && Info->previousButtonState == BUTTON_NOT_PRESS && Info->TwoButtonStateBefore == BUTTON_NOT_PRESS){       // check LED state
      //if(Info->previousButtonState == BUTTON_NOT_PRESS || Info->TwoButtonStateBefore == BUTTON_NOT_PRESS){  // check previouos button

            if(currentButtonState == BUTTON_NOT_PRESS){     // first button
              Info->TwoButtonStateBefore = BUTTON_NOT_PRESS;
            }
            if (currentButtonState == BUTTON_PRESS){
              Info->previousButtonState = BUTTON_PRESS;
              Info->CurrentLedState = LED_ON;
              turnLed(LED_ON);
            }

          }


      // Turn Off
      else if (Info->CurrentLedState && LED_ON || Info->previousButtonState == BUTTON_PRESS || Info->TwoButtonStateBefore == BUTTON_NOT_PRESS){
      //if(Info->previousButtonState == BUTTON_PRESS || Info->TwoButtonStateBefore == BUTTON_NOT_PRESS){


            if(currentButtonState == BUTTON_NOT_PRESS && Info->TwoButtonStateBefore == BUTTON_NOT_PRESS){
              Info->TwoButtonStateBefore = BUTTON_NOT_PRESS;
              Info->FakeLedState = LED_OFF;
            }

            if (currentButtonState == BUTTON_PRESS ){
              Info->previousButtonState = BUTTON_PRESS;
              Info->TwoButtonStateBefore = BUTTON_PRESS;


            }
            if(Info->previousButtonState == BUTTON_PRESS && currentButtonState == BUTTON_NOT_PRESS && Info->TwoButtonStateBefore == BUTTON_PRESS){
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
