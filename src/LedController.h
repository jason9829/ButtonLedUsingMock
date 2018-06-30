#ifndef _LEDCONTROLLER_H
#define _LEDCONTROLLER_H

#include "Led.h"
#include "Button.h"

typedef struct LedButtonInfo LedButtonInfo;
struct LedButtonInfo{
  LedState FakeLedState;
  LedState CurrentLedState;
  ButtonState previousButtonState;
  ButtonState TwoButtonStateBefore;
};

void turnOnLedIfButtonIsPressed(void);
//void turnOffLedIfButtonIsPressed(void);
void doTapTurnOnTapTurnOffLed(LedButtonInfo *Info);

#endif // _LEDCONTROLLER_H
