// SPDX-License-Identifier: GPL-2.0+

#include <common.h>
#include <init.h>
#include <net.h>
#include <asm/global_data.h>
#include <asm/gpio.h>
#include <asm/io.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/iomux-mx28.h>
#include <asm/arch/clock.h>
#include <asm/arch/sys_proto.h>
#include <errno.h>

DECLARE_GLOBAL_DATA_PTR;

/*
 * Functions
 */
int board_early_init_f(void)
{
	/* IO0 clock at 480MHz */
	mxs_set_ioclk(MXC_IOCLK0, 480000);
	/* IO1 clock at 480MHz */
	mxs_set_ioclk(MXC_IOCLK1, 480000);

	return 0;
}

int dram_init(void)
{
	return mxs_dram_init();
}

int board_init(void)
{
	/* Adress of boot parameters */
	gd->bd->bi_boot_params = PHYS_SDRAM_1 + 0x100;

	/* Set the Wifi control pins to default values */
	gpio_direction_output(MX28_PAD_LCD_D23__GPIO_1_23, 1);
	gpio_direction_output(MX28_PAD_LCD_D13__GPIO_1_13, 1);
	gpio_direction_output(MX28_PAD_LCD_D18__GPIO_1_18, 1);
	gpio_direction_output(MX28_PAD_SSP0_DETECT__GPIO_2_9, 0);

	return 0;
}
