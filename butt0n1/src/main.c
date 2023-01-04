/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */
// Michael Daranto - YD3BRB - 04 Jan 2023
// Button with interupt

#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

#define SW0_NODE DT_ALIAS(sw0)

static const struct gpio_dt_spec sw00 = GPIO_DT_SPEC_GET(SW0_NODE, gpios);
static struct gpio_callback sw00_cb_data;

void sw00_pressed(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
{
	printk("Button pressed!(with bouncing lol) \n" );
}

void main(void)
{
	int i=0;
	gpio_pin_configure_dt(&sw00, GPIO_INPUT);
	gpio_pin_interrupt_configure_dt(&sw00, GPIO_INT_EDGE_TO_ACTIVE);
	gpio_init_callback(&sw00_cb_data, sw00_pressed, BIT(sw00.pin));
	gpio_add_callback(sw00.port, &sw00_cb_data);
	while (1) {

		k_msleep(1000);
		printk("Helloo world!!! %s,%d\n", CONFIG_BOARD,i++);
	}
}
