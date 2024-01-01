
#include <stm32f1xx_hal.h>
#include <tusb.h>

void AppMain() {
    tusb_init();
}

void AppLoop() {
    static int i = 0;
    HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
    HAL_Delay(i++);
    if (i > 500000000) i = 0;
}

extern PCD_HandleTypeDef hpcd_USB_FS;

void USB_HP_CAN1_TX_IRQHandler(void) {
    HAL_PCD_IRQHandler(&hpcd_USB_FS);
}

void USB_LP_CAN1_RX0_IRQHandler(void) {
    HAL_PCD_IRQHandler(&hpcd_USB_FS);
}
