#ifndef _BUTTON_H
#define _BUTTON_H

/*
  Return non-zero if button is pressed; Otherwise, return 0
*/
typedef enum{
  BUTTON_NOT_PRESS = 0,
  BUTTON_PRESS     = 1,
} ButtonState;

/*
  tempState is use to differentiate/ break if else statement so
  it wont run into same if else
  NO specific meanig for SET, RESET, TOGGLE
*/
typedef enum{
  SET    = 0,
  RESET  = 1,
  TOGGLE = 2,

}tempState;

/*
  To diffentiate the if else statement for turn ON led or OFF
*/
typedef enum{
  TURN_OFF = 0 ,
  TURN_ON  = 1 ,
  STAY_OFF =2,
  STAY_ON =3,
}Operation;

typedef enum{
  FIRST_CYCLE  = 1,
  SECOND_CYCLE = 2,
  THIRD_CYCLE  = 3,
} cyclesState;

int getButtonState(void);
int getcyclesState(void);
#endif // _BUTTON_H
