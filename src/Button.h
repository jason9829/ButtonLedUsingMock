#ifndef _BUTTON_H
#define _BUTTON_H

typedef enum{
  BUTTON_NOT_PRESS = 0,
  BUTTON_PRESS     = 1,
} ButtonState;

/*
  Return non-zero if button is pressed; Otherwise, return 0
*/
int getButtonState(void);
int getTapState(void);
#endif // _BUTTON_H
