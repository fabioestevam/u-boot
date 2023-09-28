/* SPDX-License-Identifier: GPL-2.0+ */

#ifndef __CONFIGS_IMX28WINKHUB_H__
#define __CONFIGS_IMX28WINKHUB_H__

/* Memory configuration */
#define PHYS_SDRAM_1			0x40000000	/* Base address */
#define PHYS_SDRAM_1_SIZE		0x04000000	/* 64 MB of RAM */
#define CFG_SYS_SDRAM_BASE		PHYS_SDRAM_1

/* Extra Environment */
#define CFG_EXTRA_ENV_SETTINGS \
	"ubifs_file=filesystem.ubifs\0" \
	"update_nand_full_filename=u-boot.nand\0" \
	"update_nand_firmware_filename=u-boot.sb\0"	\
	"update_nand_firmware_maxsz=0x100000\0"	\
	"update_nand_stride=0x40\0"	/* MX28 datasheet ch. 12.12 */ \
	"update_nand_count=0x4\0"	/* MX28 datasheet ch. 12.12 */ \
	"update_nand_get_fcb_size="	/* Get size of FCB blocks */ \
		"nand device 0 ; " \
		"nand info ; " \
		"setexpr fcb_sz ${update_nand_stride} * ${update_nand_count};" \
		"setexpr update_nand_fcb ${fcb_sz} * ${nand_writesize}\0" \
	"update_nand_firmware_full=" /* Update FCB, DBBT and FW */ \
		"if ubifsload ${loadaddr} ${update_nand_full_filename} ; then " \
		"run update_nand_get_fcb_size ; " \
		"nand scrub -y 0x0 ${filesize} ; " \
		"nand write.raw ${loadaddr} 0x0 ${fcb_sz} ; " \
		"setexpr update_off ${loadaddr} + ${update_nand_fcb} ; " \
		"setexpr update_sz ${filesize} - ${update_nand_fcb} ; " \
		"nand write ${update_off} ${update_nand_fcb} ${update_sz} ; " \
		"else echo \'Mount the UBI partition using something like: " \
		"mtdparts default && ubi part database && ubifsmount ubi0:database\';" \
		"fi\0" \
	"update_nand_firmware="		/* Update only firmware */ \
		"if ubifsload ${loadaddr} ${update_nand_full_filename} ; then " \
		"run update_nand_get_fcb_size ; " \
		"setexpr fcb_sz ${update_nand_fcb} * 2 ; " /* FCB + DBBT */ \
		"setexpr fw_sz ${update_nand_firmware_maxsz} * 2 ; " \
		"setexpr fw_off ${fcb_sz} + ${update_nand_firmware_maxsz};" \
		"nand erase ${fcb_sz} ${fw_sz} ; " \
		"nand write ${loadaddr} ${fcb_sz} ${filesize} ; " \
		"nand write ${loadaddr} ${fw_off} ${filesize} ; " \
		"else echo \"Mount the UBI partition using something like: " \
		"mtdparts default && ubi part database && ubifsmount ubi0:database\";" \
		"fi\0" \
	"fdt_file=imx28-wink-hub1.dtb\0" \
	"fdt_addr=0x41000000\0" \

/* The rest of the configuration is shared */
#include <configs/mxs.h>

#endif /* __CONFIGS_IMX28WINKHUB_H__ */
