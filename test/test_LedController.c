#include "unity.h"
#include "LedController.h"
#include "mock_Button.h"    // mock_ tell ceedling to mock
#include "mock_Led.h"       // mock_ will be removed when compile

void setUp(void){}
void tearDown(void){}

/*void test_turnOnLedIfButtonIsPressed_given_button_is_pressed_expect_led_is_turned_on(void){

    getButtonState_ExpectAndReturn(BUTTON_PRESS);      // button_state not zero means turn on
    turnLed_Expect(LED_ON);                           // turn Led to ON
    turnOnLedIfButtonIsPressed();                     // verify
}

void test_turnOnLedIfButtonIsPressed_given_button_is_not_pressed_expect_led_is_turned_off(void){

    getButtonState_ExpectAndReturn(BUTTON_NOT_PRESS);
    turnLed_Expect(LED_OFF);
    turnOnLedIfButtonIsPressed();
}
*/
  // TURN ON (RELEASED - PRESS - RELEASED),1
void test_doTapTurnOnTapTurnOffLed_given_led_is_off_button_is_pressed_and_released_expect_led_is_turned_on(void){

    LedButtonInfo Info = {LED_OFF, BUTTON_NOT_PRESS,SET,TURN_ON};

    getButtonState_ExpectAndReturn(BUTTON_NOT_PRESS);
    getcyclesState_ExpectAndReturn(FIRST_CYCLE);
    doTapTurnOnTapTurnOffLed(&Info);

    getButtonState_ExpectAndReturn(BUTTON_PRESS);
    getcyclesState_ExpectAndReturn(SECOND_CYCLE);
    turnLed_Expect(LED_ON);
    doTapTurnOnTapTurnOffLed(&Info);

    getButtonState_ExpectAndReturn(BUTTON_NOT_PRESS);
    getcyclesState_ExpectAndReturn(THIRD_CYCLE);
    doTapTurnOnTapTurnOffLed(&Info);


    TEST_ASSERT_EQUAL(LED_ON, Info.CurrentLedState);
}
// TURN OFF (RELEASED - PRESS - RELEASED),2
void test_doTapTurnOnTapTurnOffLed_given_led_is_on_button_is_pressed_and_released_expect_led_is_turned_off(void){
//                      currentLed , previousbut ,2 statesbeforebut
  LedButtonInfo Info = {LED_ON, BUTTON_PRESS,TOGGLE,TURN_OFF};

  getButtonState_ExpectAndReturn(BUTTON_NOT_PRESS);
  getcyclesState_ExpectAndReturn(FIRST_CYCLE);
  doTapTurnOnTapTurnOffLed(&Info);

  getButtonState_ExpectAndReturn(BUTTON_PRESS);
  getcyclesState_ExpectAndReturn(SECOND_CYCLE);
  doTapTurnOnTapTurnOffLed(&Info);

  getButtonState_ExpectAndReturn(BUTTON_NOT_PRESS);
  getcyclesState_ExpectAndReturn(THIRD_CYCLE);
  turnLed_Expect(LED_OFF);
  doTapTurnOnTapTurnOffLed(&Info);


  TEST_ASSERT_EQUAL(LED_OFF, Info.CurrentLedState);
}
// STAY ON (RELEASED - RELEASED - RELEASED),3
void test_doTapTurnOnTapTurnOffLed_given_led_is_on_button_is_released_and_released_expect_led_is_turned_on(void){

    LedButtonInfo Info = {LED_ON, BUTTON_NOT_PRESS,RESET,STAY_ON};

    getButtonState_ExpectAndReturn(BUTTON_NOT_PRESS);
    getcyclesState_ExpectAndReturn(FIRST_CYCLE);
    doTapTurnOnTapTurnOffLed(&Info);

    getButtonState_ExpectAndReturn(BUTTON_NOT_PRESS);
    getcyclesState_ExpectAndReturn(SECOND_CYCLE);
    doTapTurnOnTapTurnOffLed(&Info);

    getButtonState_ExpectAndReturn(BUTTON_NOT_PRESS);
    getcyclesState_ExpectAndReturn(THIRD_CYCLE);
    turnLed_Expect(LED_ON);
    doTapTurnOnTapTurnOffLed(&Info);


    TEST_ASSERT_EQUAL(LED_ON, Info.CurrentLedState);
}

// STAY OFF (RELEASED - RELEASED - RELEASED),4
void test_doTapTurnOnTapTurnOffLed_given_led_is_off_button_is_released_and_released_expect_led_is_turned_off(void){

    LedButtonInfo Info = {LED_OFF, BUTTON_NOT_PRESS,RESET,TURN_OFF};

    getButtonState_ExpectAndReturn(BUTTON_NOT_PRESS);
    getcyclesState_ExpectAndReturn(FIRST_CYCLE);
    doTapTurnOnTapTurnOffLed(&Info);

    getButtonState_ExpectAndReturn(BUTTON_NOT_PRESS);
    getcyclesState_ExpectAndReturn(SECOND_CYCLE);
    doTapTurnOnTapTurnOffLed(&Info);

    getButtonState_ExpectAndReturn(BUTTON_NOT_PRESS);
    getcyclesState_ExpectAndReturn(THIRD_CYCLE);
    turnLed_Expect(LED_OFF);
    doTapTurnOnTapTurnOffLed(&Info);


    TEST_ASSERT_EQUAL(LED_OFF, Info.CurrentLedState);
}

// STAY ON (PRESS - PRESS -PRESS),5
void test_doTapTurnOnTapTurnOffLed_given_led_is_on_button_is_pressed_and_pressed_expect_led_is_turned_on(void){

  LedButtonInfo Info = {LED_ON, BUTTON_PRESS,TOGGLE,TURN_ON};

  getButtonState_ExpectAndReturn(BUTTON_PRESS);
  getcyclesState_ExpectAndReturn(FIRST_CYCLE);
  doTapTurnOnTapTurnOffLed(&Info);

  getButtonState_ExpectAndReturn(BUTTON_PRESS);
  getcyclesState_ExpectAndReturn(SECOND_CYCLE);

  doTapTurnOnTapTurnOffLed(&Info);
  getButtonState_ExpectAndReturn(BUTTON_PRESS);
  getcyclesState_ExpectAndReturn(THIRD_CYCLE);
  turnLed_Expect(LED_ON);
  doTapTurnOnTapTurnOffLed(&Info);


  TEST_ASSERT_EQUAL(LED_ON, Info.CurrentLedState);
}

// STAY OFF (PRESS - PRESS -PRESS),6
void test_doTapTurnOnTapTurnOffLed_given_led_is_off_button_is_pressed_and_pressed_expect_led_is_turned_off(void){

  LedButtonInfo Info = {LED_OFF, BUTTON_PRESS,SET,STAY_OFF};

  getButtonState_ExpectAndReturn(BUTTON_PRESS);
  getcyclesState_ExpectAndReturn(FIRST_CYCLE);
  doTapTurnOnTapTurnOffLed(&Info);

  getButtonState_ExpectAndReturn(BUTTON_PRESS);
  getcyclesState_ExpectAndReturn(SECOND_CYCLE);

  doTapTurnOnTapTurnOffLed(&Info);
  getButtonState_ExpectAndReturn(BUTTON_PRESS);
  getcyclesState_ExpectAndReturn(THIRD_CYCLE);
  turnLed_Expect(LED_OFF);
  doTapTurnOnTapTurnOffLed(&Info);


  TEST_ASSERT_EQUAL(LED_OFF, Info.CurrentLedState);
}
