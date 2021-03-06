#include <stdint.h>
#include "bsp/bsp.h"

/**
 * @brief Delay por software
 *
 * @param nCount Numero de ciclos del delay
 */
void Delay(volatile uint32_t nCount);

/**
 * @brief Se encarga de prender un led y apagarlo luego de un tiempo
 *
 * @param led    Numero de led a pulsar
 * @param tiempo Numero de ciclos del delay entre prendido y apagado
 */
void pulsoLed(uint8_t led, uint32_t tiempo);

/**
 * @brief Aplicacion principal
 */
int main(void) {
	bsp_init();
	int brillo = 0;
	int flag = 0;
	while (1) {
		bsp_delayMs(10);

		led_setBright(0, brillo);
		led_setBright(1, brillo);
		led_setBright(2, brillo);
		led_setBright(3, brillo);

		if (brillo >= 100)
			flag = 1;
		if (brillo <= 0)
			flag = 0;
		if (flag)
			brillo++;
		else
			brillo--;
	}
}

void pulsoLed(uint8_t led, uint32_t tiempo) {
	led_on(led);
	Delay(tiempo);
	led_off(led);
}

void Delay(volatile uint32_t nCount) {
	while (nCount--) {
	}
}

void APP_ISR_sw(void) {

}

void APP_ISR_1ms(void) {
	static uint16_t count_1ms = 1000;
	count_1ms--;
	if (!count_1ms) {
		led_toggle(0);
		count_1ms = 1000;
	}
}
