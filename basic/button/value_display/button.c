#include "button.h"
#include "bcm2835.h"

#define BTN_PIN		RPI_V2_GPIO_P1_11

int button_init(void)
{
	if(!bcm2835_init())
		return 0;
	bcm2835_gpio_fsel(BTN_PIN, BCM2835_GPIO_FSEL_INPT);
	// with a pullup
	bcm2835_gpio_set_pud(BTN_PIN, BCM2835_GPIO_PUD_DOWN);
	// And a rising detect enable
	bcm2835_gpio_ren(BTN_PIN);
	return 1;
}

int button_value(void)
{
	return bcm2835_gpio_lev(BTN_PIN);
}

void button_end(void)
{
	bcm2835_close();
}
