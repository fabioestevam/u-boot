// SPDX-License-Identifier: GPL-2.0+
/*
 * (C)Copyright 2016 Rockchip Electronics Co., Ltd
 * Authors: Andy Yan <andy.yan@rock-chips.com>
 */

#include <init.h>
#include <syscon.h>
#include <asm/global_data.h>
#include <asm/arch-rockchip/clock.h>
#include <asm/arch-rockchip/grf_rv1103.h>
#include <asm/arch-rockchip/hardware.h>
#include <asm/gpio.h>

DECLARE_GLOBAL_DATA_PTR;

int board_early_init_f(void)
{
	return 0;
}

#define MODEM_ENABLE_GPIO 111

int rk_board_late_init(void)
{
	return 0;
}

int dram_init(void)
{
	gd->ram_size = 0x10000000;

	return 0;
}

int dram_init_banksize(void)
{
	gd->bd->bi_dram[0].start = 0x00000000;
	gd->bd->bi_dram[0].size = 0x10000000;

	return 0;
}

