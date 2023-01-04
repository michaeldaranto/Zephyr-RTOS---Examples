/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */
// Michael Daranto - YD3BRB - 04 Jan 2023
// Simple Blink

#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

#define LED0_NODE	DT_ALIAS(led0)
#define PIN		DT_GPIO_PIN(LED0_NODE, gpios)
#define FLAGS		DT_GPIO_FLAGS(LED0_NODE, gpios)

void main(void)
{

	const struct device *dev;
	dev = DEVICE_DT_GET(DT_NODELABEL(gpiod));
	gpio_pin_configure(dev, PIN, GPIO_OUTPUT_ACTIVE | FLAGS);

	while (1) {
		gpio_pin_toggle(dev, PIN);
		k_msleep(1000);
	}
}
