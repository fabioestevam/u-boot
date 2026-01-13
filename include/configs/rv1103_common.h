/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * (C) Copyright 2016 Rockchip Electronics Co., Ltd
 */
#ifndef __CONFIG_RV1103_COMMON_H
#define __CONFIG_RV1103_COMMON_H

#include "rockchip-common.h"
#include <config_distro_bootcmd.h>

#define CFG_IRAM_BASE			0x210f6000

#ifndef CONFIG_SYS_ARCH_TIMER
#define CFG_SYS_TIMER_RATE		(24 * 1000 * 1000)
#define CFG_SYS_TIMER_BASE		0x20500000
#define CFG_SYS_TIMER_COUNTER		(CFG_SYS_TIMER_BASE + 8)
#endif

#define CFG_SYS_SDRAM_BASE		0x00000000

#endif
