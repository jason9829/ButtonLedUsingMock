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

void test_doTapTurnOnTapTurnOffLed_given_led_is_off_button_is_pressed_and_released_expect_led_is_turned_on(void){

    LedButtonInfo Info = {LED_OFF, BUTTON_NOT_PRESS,BUTTON_NOT_PRESS};

    getButtonState_ExpectAndReturn(BUTTON_NOT_PRESS);
    doTapTurnOnTapTurnOffLed(&Info);
    getButtonState_ExpectAndReturn(BUTTON_PRESS);
    turnLed_Expect(LED_ON);
    doTapTurnOnTapTurnOffLed(&Info);
    getButtonState_ExpectAndReturn(BUTTON_NOT_PRESS);
    doTapTurnOnTapTurnOffLed(&Info);


    TEST_ASSERT_EQUAL(LED_ON, Info.CurrentLedState);
}

void test_doTapTurnOnTapTurnOffLed_given_led_is_on_button_is_pressed_and_released_expect_led_is_turned_off(void){

  LedButtonInfo Info = {LED_ON, BUTTON_PRESS,BUTTON_NOT_PRESS};

  getButtonState_ExpectAndReturn(BUTTON_NOT_PRESS);
  doTapTurnOnTapTurnOffLed(&Info);
  getButtonState_ExpectAndReturn(BUTTON_PRESS);
  doTapTurnOnTapTurnOffLed(&Info);
  getButtonState_ExpectAndReturn(BUTTON_NOT_PRESS);
  turnLed_Expect(LED_OFF);
  doTapTurnOnTapTurnOffLed(&Info);


  TEST_ASSERT_EQUAL(LED_OFF, Info.CurrentLedState);
}


/*void test_doTapTurnOnTapTurnOffLed_given_led_is_off_button_is_pressed_and_released_expect_led_is_turned_off(void){

    LedButtonInfo Info = {LED_OFF,LED_OFF, BUTTON_NOT_PRESS,BUTTON_NOT_PRESS};

    getButtonState_ExpectAndReturn(BUTTON_NOT_PRESS);
    doTapTurnOnTapTurnOffLed(&Info);
    getButtonState_ExpectAndReturn(BUTTON_NOT_PRESS);
    turnLed_Expect(LED_ON);
    doTapTurnOnTapTurnOffLed(&Info);
    getButtonState_ExpectAndReturn(BUTTON_NOT_PRESS);
    doTapTurnOnTapTurnOffLed(&Info);


    TEST_ASSERT_EQUAL(LED_OFF, Info.CurrentLedState);
}

void test_doTapTurnOnTapTurnOffLed_given_led_is_on_button_is_pressed_and_released_expect_led_is_turned_on(void){

  LedButtonInfo Info = {LED_OFF,LED_ON, BUTTON_PRESS,BUTTON_PRESS};

  getButtonState_ExpectAndReturn(BUTTON_PRESS);
  doTapTurnOnTapTurnOffLed(&Info);
  getButtonState_ExpectAndReturn(BUTTON_PRESS);
  doTapTurnOnTapTurnOffLed(&Info);
  getButtonState_ExpectAndReturn(BUTTON_PRESS);
  turnLed_Expect(LED_OFF);
  doTapTurnOnTapTurnOffLed(&Info);


  TEST_ASSERT_EQUAL(LED_ON, Info.CurrentLedState);
}
*/
