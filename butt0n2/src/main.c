/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */
// Michael Darant0 - YD3BRB - 04 Jan 2023
// Button Pooling

#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

#define SW0_NODE DT_ALIAS(sw0)

static const struct gpio_dt_spec sw00 = GPIO_DT_SPEC_GET(SW0_NODE, gpios);

void main(void)
{
	int i=0;
	gpio_pin_configure_dt(&sw00, GPIO_INPUT);
	while (1) {

		int c = gpio_pin_get_dt(&sw00);
		if (c !=0){
			printk("Who pressed the button? :) %s, %d\n", CONFIG_BOARD,i++);
		}
	}
}
