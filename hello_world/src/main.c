/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */
// Michael Daranto - YD3BRB - 04 Jan 2023
// Hello World!

#include <zephyr/kernel.h>

void main(void)
{
	while(1){

	printk("Hello World! %s\n", CONFIG_BOARD);
	k_msleep(500);

	}
}
