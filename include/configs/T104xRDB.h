/*
+ * Copyright 2014 Freescale Semiconductor, Inc.
+ *
+ * SPDX-License-Identifier:     GPL-2.0+
+ */

#ifndef __CONFIG_H
#define __CONFIG_H

/*
 * T104x RDB board configuration file
 */
#define CONFIG_T104xRDB
#define CONFIG_PHYS_64BIT
#define CONFIG_DISPLAY_BOARDINFO
#define CONFIG_FSL_CLK

#define CONFIG_E500			/* BOOKE e500 family */
#include <asm/config_mpc85xx.h>

#ifdef CONFIG_RAMBOOT_PBL
#define CONFIG_SYS_FSL_PBL_PBI $(SRCTREE)/board/freescale/t104xrdb/t104x_pbi.cfg
#ifdef CONFIG_T1040RDB
#define CONFIG_SYS_FSL_PBL_RCW $(SRCTREE)/board/freescale/t104xrdb/t1040_rcw.cfg
#endif
#ifdef CONFIG_T1042RDB_PI
#define CONFIG_SYS_FSL_PBL_RCW $(SRCTREE)/board/freescale/t104xrdb/t1042_pi_rcw.cfg
#endif
#ifdef CONFIG_T1042RDB
#define CONFIG_SYS_FSL_PBL_RCW $(SRCTREE)/board/freescale/t104xrdb/t1042_rcw.cfg
#endif
#ifdef CONFIG_T1040D4RDB
#define CONFIG_SYS_FSL_PBL_RCW \
$(SRCTREE)/board/freescale/t104xrdb/t1040d4_rcw.cfg
#endif
#ifdef CONFIG_T1042D4RDB
#define CONFIG_SYS_FSL_PBL_RCW \
$(SRCTREE)/board/freescale/t104xrdb/t1042d4_rcw.cfg
#endif

#define CONFIG_SPL_MPC8XXX_INIT_DDR_SUPPORT
#define CONFIG_SPL_ENV_SUPPORT
#define CONFIG_SPL_SERIAL_SUPPORT
#define CONFIG_SPL_FLUSH_IMAGE
#define CONFIG_SPL_TARGET		"u-boot-with-spl.bin"
#define CONFIG_SPL_LIBGENERIC_SUPPORT
#define CONFIG_SPL_LIBCOMMON_SUPPORT
#define CONFIG_SPL_I2C_SUPPORT
#define CONFIG_SPL_DRIVERS_MISC_SUPPORT
#define CONFIG_FSL_LAW                 /* Use common FSL init code */
#define CONFIG_SYS_TEXT_BASE		0x30001000
#define CONFIG_SPL_TEXT_BASE		0xFFFD8000
#define CONFIG_SPL_PAD_TO		0x40000
#define CONFIG_SPL_MAX_SIZE		0x28000
#ifdef CONFIG_SPL_BUILD
#define CONFIG_SPL_SKIP_RELOCATE
#define CONFIG_SPL_COMMON_INIT_DDR
#define CONFIG_SYS_CCSR_DO_NOT_RELOCATE
#define CONFIG_SYS_NO_FLASH
#endif
#define RESET_VECTOR_OFFSET		0x27FFC
#define BOOT_PAGE_OFFSET		0x27000

#ifdef CONFIG_NAND
#define CONFIG_SPL_NAND_SUPPORT
#define CONFIG_SYS_NAND_U_BOOT_SIZE	(768 << 10)
#define CONFIG_SYS_NAND_U_BOOT_DST	0x30000000
#define CONFIG_SYS_NAND_U_BOOT_START	0x30000000
#define CONFIG_SYS_NAND_U_BOOT_OFFS	(256 << 10)
#define CONFIG_SYS_LDSCRIPT	"arch/powerpc/cpu/mpc85xx/u-boot-nand.lds"
#define CONFIG_SPL_NAND_BOOT
#endif

#ifdef CONFIG_SPIFLASH
#define	CONFIG_RESET_VECTOR_ADDRESS		0x30000FFC
#define CONFIG_SPL_SPI_SUPPORT
#define CONFIG_SPL_SPI_FLASH_SUPPORT
#define CONFIG_SPL_SPI_FLASH_MINIMAL
#define CONFIG_SYS_SPI_FLASH_U_BOOT_SIZE	(768 << 10)
#define CONFIG_SYS_SPI_FLASH_U_BOOT_DST		(0x30000000)
#define CONFIG_SYS_SPI_FLASH_U_BOOT_START	(0x30000000)
#define CONFIG_SYS_SPI_FLASH_U_BOOT_OFFS	(256 << 10)
#define CONFIG_SYS_LDSCRIPT	"arch/powerpc/cpu/mpc85xx/u-boot.lds"
#ifndef CONFIG_SPL_BUILD
#define	CONFIG_SYS_MPC85XX_NO_RESETVEC
#endif
#define CONFIG_SPL_SPI_BOOT
#endif

#ifdef CONFIG_SDCARD
#define	CONFIG_RESET_VECTOR_ADDRESS		0x30000FFC
#define CONFIG_SPL_MMC_SUPPORT
#define CONFIG_SPL_MMC_MINIMAL
#define CONFIG_SYS_MMC_U_BOOT_SIZE	(768 << 10)
#define CONFIG_SYS_MMC_U_BOOT_DST	(0x30000000)
#define CONFIG_SYS_MMC_U_BOOT_START	(0x30000000)
#define CONFIG_SYS_MMC_U_BOOT_OFFS	(260 << 10)
#define CONFIG_SYS_LDSCRIPT	"arch/powerpc/cpu/mpc85xx/u-boot.lds"
#ifndef CONFIG_SPL_BUILD
#define	CONFIG_SYS_MPC85XX_NO_RESETVEC
#endif
#define CONFIG_SPL_MMC_BOOT
#endif

#endif

/* High Level Configuration Options */
#define CONFIG_BOOKE
#define CONFIG_E500MC			/* BOOKE e500mc family */
#define CONFIG_SYS_BOOK3E_HV		/* Category E.HV supported */
#define CONFIG_MP			/* support multiple processors */

/* support deep sleep */
#define CONFIG_DEEP_SLEEP
#if defined(CONFIG_DEEP_SLEEP)
#define CONFIG_BOARD_EARLY_INIT_F
#define CONFIG_SILENT_CONSOLE
#endif

#ifndef CONFIG_SYS_TEXT_BASE
#define CONFIG_SYS_TEXT_BASE	0xeff40000
#endif

#ifndef CONFIG_RESET_VECTOR_ADDRESS
#define CONFIG_RESET_VECTOR_ADDRESS	0xeffffffc
#endif

#define CONFIG_SYS_FSL_CPC		/* Corenet Platform Cache */
#define CONFIG_SYS_NUM_CPC		CONFIG_NUM_DDR_CONTROLLERS
#define CONFIG_FSL_IFC			/* Enable IFC Support */
#define CONFIG_FSL_CAAM			/* Enable SEC/CAAM */
#define CONFIG_PCI			/* Enable PCI/PCIE */
#define CONFIG_PCI_INDIRECT_BRIDGE
#define CONFIG_PCIE1			/* PCIE controler 1 */
#define CONFIG_PCIE2			/* PCIE controler 2 */
#define CONFIG_PCIE3			/* PCIE controler 3 */
#define CONFIG_PCIE4			/* PCIE controler 4 */

#define CONFIG_FSL_PCI_INIT		/* Use common FSL init code */
#define CONFIG_SYS_PCI_64BIT		/* enable 64-bit PCI resources */

#define CONFIG_FSL_LAW			/* Use common FSL init code */

#define CONFIG_ENV_OVERWRITE

#ifndef CONFIG_SYS_NO_FLASH
#define CONFIG_FLASH_CFI_DRIVER
#define CONFIG_SYS_FLASH_CFI
#define CONFIG_SYS_FLASH_USE_BUFFER_WRITE
#endif

#if defined(CONFIG_SPIFLASH)
#define CONFIG_SYS_EXTRA_ENV_RELOC
#define CONFIG_ENV_IS_IN_SPI_FLASH
#define CONFIG_ENV_SIZE                 0x2000          /* 8KB */
#define CONFIG_ENV_OFFSET               0x100000        /* 1MB */
#define CONFIG_ENV_SECT_SIZE            0x10000
#elif defined(CONFIG_SDCARD)
#define CONFIG_SYS_EXTRA_ENV_RELOC
#define CONFIG_ENV_IS_IN_MMC
#define CONFIG_SYS_MMC_ENV_DEV          0
#define CONFIG_ENV_SIZE			0x2000
#define CONFIG_ENV_OFFSET		(512 * 0x800)
#elif defined(CONFIG_NAND)
#define CONFIG_SYS_EXTRA_ENV_RELOC
#define CONFIG_ENV_IS_IN_NAND
#define CONFIG_ENV_SIZE			0x2000
#define CONFIG_ENV_OFFSET		(3 * CONFIG_SYS_NAND_BLOCK_SIZE)
#else
#define CONFIG_ENV_IS_IN_FLASH
#define CONFIG_ENV_ADDR		(CONFIG_SYS_MONITOR_BASE - CONFIG_ENV_SECT_SIZE)
#define CONFIG_ENV_SIZE		0x2000
#define CONFIG_ENV_SECT_SIZE	0x20000 /* 128K (one sector) */
#endif

#define CONFIG_SYS_CLK_FREQ	100000000
#define CONFIG_DDR_CLK_FREQ	66666666

/*
 * These can be toggled for performance analysis, otherwise use default.
 */
#define CONFIG_SYS_CACHE_STASHING
#define CONFIG_BACKSIDE_L2_CACHE
#define CONFIG_SYS_INIT_L2CSR0		L2CSR0_L2E
#define CONFIG_BTB			/* toggle branch predition */
#define CONFIG_DDR_ECC
#ifdef CONFIG_DDR_ECC
#define CONFIG_ECC_INIT_VIA_DDRCONTROLLER
#define CONFIG_MEM_INIT_VALUE		0xdeadbeef
#endif

#define CONFIG_ENABLE_36BIT_PHYS

#define CONFIG_ADDR_MAP
#define CONFIG_SYS_NUM_ADDR_MAP		64	/* number of TLB1 entries */

#define CONFIG_SYS_MEMTEST_START	0x00200000	/* memtest works on */
#define CONFIG_SYS_MEMTEST_END		0x00400000
#define CONFIG_SYS_ALT_MEMTEST
#define CONFIG_PANIC_HANG	/* do not reset board on panic */

/*
 *  Config the L3 Cache as L3 SRAM
 */
#define CONFIG_SYS_INIT_L3_ADDR		0xFFFC0000
#define CONFIG_SYS_L3_SIZE		256 << 10
#define CONFIG_SPL_GD_ADDR		(CONFIG_SYS_INIT_L3_ADDR + 32 * 1024)
#ifdef CONFIG_RAMBOOT_PBL
#define CONFIG_ENV_ADDR			(CONFIG_SPL_GD_ADDR + 4 * 1024)
#endif
#define CONFIG_SPL_RELOC_MALLOC_ADDR	(CONFIG_SPL_GD_ADDR + 12 * 1024)
#define CONFIG_SPL_RELOC_MALLOC_SIZE	(30 << 10)
#define CONFIG_SPL_RELOC_STACK		(CONFIG_SPL_GD_ADDR + 64 * 1024)
#define CONFIG_SPL_RELOC_STACK_SIZE	(22 << 10)

#define CONFIG_SYS_DCSRBAR		0xf0000000
#define CONFIG_SYS_DCSRBAR_PHYS		0xf00000000ull

/*
 * DDR Setup
 */
#define CONFIG_VERY_BIG_RAM
#define CONFIG_SYS_DDR_SDRAM_BASE	0x00000000
#define CONFIG_SYS_SDRAM_BASE		CONFIG_SYS_DDR_SDRAM_BASE

/* CONFIG_NUM_DDR_CONTROLLERS is defined in include/asm/config_mpc85xx.h */
#define CONFIG_DIMM_SLOTS_PER_CTLR	1
#define CONFIG_CHIP_SELECTS_PER_CTRL	(2 * CONFIG_DIMM_SLOTS_PER_CTLR)

#define CONFIG_DDR_SPD
#ifndef CONFIG_SYS_FSL_DDR4
#define CONFIG_SYS_FSL_DDR3
#endif

#define CONFIG_SYS_SPD_BUS_NUM	0
#define SPD_EEPROM_ADDRESS	0x51

#define CONFIG_SYS_SDRAM_SIZE	4096	/* for fixed parameter use */

/*
 * IFC Definitions
 */
#define CONFIG_SYS_FLASH_BASE	0xe8000000
#define CONFIG_SYS_FLASH_BASE_PHYS	(0xf00000000ull | CONFIG_SYS_FLASH_BASE)

#define CONFIG_SYS_NOR_CSPR_EXT	(0xf)
#define CONFIG_SYS_NOR_CSPR	(CSPR_PHYS_ADDR(CONFIG_SYS_FLASH_BASE) | \
				CSPR_PORT_SIZE_16 | \
				CSPR_MSEL_NOR | \
				CSPR_V)
#define CONFIG_SYS_NOR_AMASK	IFC_AMASK(128*1024*1024)

/*
 * TDM Definition
 */
#define T1040_TDM_QUIRK_CCSR_BASE	0xfe000000

/* NOR Flash Timing Params */
#define CONFIG_SYS_NOR_CSOR	CSOR_NAND_TRHZ_80
#define CONFIG_SYS_NOR_FTIM0	(FTIM0_NOR_TACSE(0x4) | \
				FTIM0_NOR_TEADC(0x5) | \
				FTIM0_NOR_TEAHC(0x5))
#define CONFIG_SYS_NOR_FTIM1	(FTIM1_NOR_TACO(0x35) | \
				FTIM1_NOR_TRAD_NOR(0x1A) |\
				FTIM1_NOR_TSEQRAD_NOR(0x13))
#define CONFIG_SYS_NOR_FTIM2	(FTIM2_NOR_TCS(0x4) | \
				FTIM2_NOR_TCH(0x4) | \
				FTIM2_NOR_TWPH(0x0E) | \
				FTIM2_NOR_TWP(0x1c))
#define CONFIG_SYS_NOR_FTIM3	0x0

#define CONFIG_SYS_FLASH_QUIET_TEST
#define CONFIG_FLASH_SHOW_PROGRESS	45 /* count down from 45/5: 9..1 */

#define CONFIG_SYS_MAX_FLASH_BANKS	2	/* number of banks */
#define CONFIG_SYS_MAX_FLASH_SECT	1024	/* sectors per device */
#define CONFIG_SYS_FLASH_ERASE_TOUT	60000	/* Flash Erase Timeout (ms) */
#define CONFIG_SYS_FLASH_WRITE_TOUT	500	/* Flash Write Timeout (ms) */

#define CONFIG_SYS_FLASH_EMPTY_INFO
#define CONFIG_SYS_FLASH_BANKS_LIST	{CONFIG_SYS_FLASH_BASE_PHYS}

/* CPLD on IFC */
#define CPLD_LBMAP_MASK			0x3F
#define CPLD_BANK_SEL_MASK		0x07
#define CPLD_BANK_OVERRIDE		0x40
#define CPLD_LBMAP_ALTBANK		0x44 /* BANK OR | BANK 4 */
#define CPLD_LBMAP_DFLTBANK		0x40 /* BANK OR | BANK0 */
#define CPLD_LBMAP_RESET		0xFF
#define CPLD_LBMAP_SHIFT		0x03

#if defined(CONFIG_T1042RDB_PI)
#define CPLD_DIU_SEL_DFP		0x80
#elif defined(CONFIG_T1042D4RDB)
#define CPLD_DIU_SEL_DFP		0xc0
#endif

#if defined(CONFIG_T1040D4RDB)
#define CPLD_INT_MASK_ALL		0xFF
#define CPLD_INT_MASK_THERM		0x80
#define CPLD_INT_MASK_DVI_DFP		0x40
#define CPLD_INT_MASK_QSGMII1		0x20
#define CPLD_INT_MASK_QSGMII2		0x10
#define CPLD_INT_MASK_SGMI1		0x08
#define CPLD_INT_MASK_SGMI2		0x04
#define CPLD_INT_MASK_TDMR1		0x02
#define CPLD_INT_MASK_TDMR2		0x01
#endif

#define CONFIG_SYS_CPLD_BASE	0xffdf0000
#define CONFIG_SYS_CPLD_BASE_PHYS	(0xf00000000ull | CONFIG_SYS_CPLD_BASE)
#define CONFIG_SYS_CSPR2_EXT	(0xf)
#define CONFIG_SYS_CSPR2	(CSPR_PHYS_ADDR(CONFIG_SYS_CPLD_BASE_PHYS) \
				| CSPR_PORT_SIZE_8 \
				| CSPR_MSEL_GPCM \
				| CSPR_V)
#define CONFIG_SYS_AMASK2	IFC_AMASK(64*1024)
#define CONFIG_SYS_CSOR2	0x0
/* CPLD Timing parameters for IFC CS2 */
#define CONFIG_SYS_CS2_FTIM0		(FTIM0_GPCM_TACSE(0x0e) | \
					FTIM0_GPCM_TEADC(0x0e) | \
					FTIM0_GPCM_TEAHC(0x0e))
#define CONFIG_SYS_CS2_FTIM1		(FTIM1_GPCM_TACO(0x0e) | \
					FTIM1_GPCM_TRAD(0x1f))
#define CONFIG_SYS_CS2_FTIM2		(FTIM2_GPCM_TCS(0x0e) | \
					FTIM2_GPCM_TCH(0x8) | \
					FTIM2_GPCM_TWP(0x1f))
#define CONFIG_SYS_CS2_FTIM3		0x0

/* NAND Flash on IFC */
#define CONFIG_NAND_FSL_IFC
#define CONFIG_SYS_NAND_BASE		0xff800000
#define CONFIG_SYS_NAND_BASE_PHYS	(0xf00000000ull | CONFIG_SYS_NAND_BASE)

#define CONFIG_SYS_NAND_CSPR_EXT	(0xf)
#define CONFIG_SYS_NAND_CSPR	(CSPR_PHYS_ADDR(CONFIG_SYS_NAND_BASE_PHYS) \
				| CSPR_PORT_SIZE_8 /* Port Size = 8 bit */ \
				| CSPR_MSEL_NAND	/* MSEL = NAND */ \
				| CSPR_V)
#define CONFIG_SYS_NAND_AMASK	IFC_AMASK(64*1024)

#define CONFIG_SYS_NAND_CSOR    (CSOR_NAND_ECC_ENC_EN   /* ECC on encode */ \
				| CSOR_NAND_ECC_DEC_EN  /* ECC on decode */ \
				| CSOR_NAND_ECC_MODE_4  /* 4-bit ECC */ \
				| CSOR_NAND_RAL_3	/* RAL = 3Byes */ \
				| CSOR_NAND_PGS_4K	/* Page Size = 4K */ \
				| CSOR_NAND_SPRZ_224/* Spare size = 224 */ \
				| CSOR_NAND_PB(64))	/*Pages Per Block = 64*/

#define CONFIG_SYS_NAND_ONFI_DETECTION

/* ONFI NAND Flash mode0 Timing Params */
#define CONFIG_SYS_NAND_FTIM0		(FTIM0_NAND_TCCST(0x07) | \
					FTIM0_NAND_TWP(0x18)   | \
					FTIM0_NAND_TWCHT(0x07) | \
					FTIM0_NAND_TWH(0x0a))
#define CONFIG_SYS_NAND_FTIM1		(FTIM1_NAND_TADLE(0x32) | \
					FTIM1_NAND_TWBE(0x39)  | \
					FTIM1_NAND_TRR(0x0e)   | \
					FTIM1_NAND_TRP(0x18))
#define CONFIG_SYS_NAND_FTIM2		(FTIM2_NAND_TRAD(0x0f) | \
					FTIM2_NAND_TREH(0x0a) | \
					FTIM2_NAND_TWHRE(0x1e))
#define CONFIG_SYS_NAND_FTIM3		0x0

#define CONFIG_SYS_NAND_DDR_LAW		11
#define CONFIG_SYS_NAND_BASE_LIST	{ CONFIG_SYS_NAND_BASE }
#define CONFIG_SYS_MAX_NAND_DEVICE	1
#define CONFIG_CMD_NAND

#define CONFIG_SYS_NAND_BLOCK_SIZE	(512 * 1024)

#if defined(CONFIG_NAND)
#define CONFIG_SYS_CSPR0_EXT		CONFIG_SYS_NAND_CSPR_EXT
#define CONFIG_SYS_CSPR0		CONFIG_SYS_NAND_CSPR
#define CONFIG_SYS_AMASK0		CONFIG_SYS_NAND_AMASK
#define CONFIG_SYS_CSOR0		CONFIG_SYS_NAND_CSOR
#define CONFIG_SYS_CS0_FTIM0		CONFIG_SYS_NAND_FTIM0
#define CONFIG_SYS_CS0_FTIM1		CONFIG_SYS_NAND_FTIM1
#define CONFIG_SYS_CS0_FTIM2		CONFIG_SYS_NAND_FTIM2
#define CONFIG_SYS_CS0_FTIM3		CONFIG_SYS_NAND_FTIM3
#define CONFIG_SYS_CSPR1_EXT		CONFIG_SYS_NOR_CSPR_EXT
#define CONFIG_SYS_CSPR1		CONFIG_SYS_NOR_CSPR
#define CONFIG_SYS_AMASK1		CONFIG_SYS_NOR_AMASK
#define CONFIG_SYS_CSOR1		CONFIG_SYS_NOR_CSOR
#define CONFIG_SYS_CS1_FTIM0		CONFIG_SYS_NOR_FTIM0
#define CONFIG_SYS_CS1_FTIM1		CONFIG_SYS_NOR_FTIM1
#define CONFIG_SYS_CS1_FTIM2		CONFIG_SYS_NOR_FTIM2
#define CONFIG_SYS_CS1_FTIM3		CONFIG_SYS_NOR_FTIM3
#else
#define CONFIG_SYS_CSPR0_EXT		CONFIG_SYS_NOR_CSPR_EXT
#define CONFIG_SYS_CSPR0		CONFIG_SYS_NOR_CSPR
#define CONFIG_SYS_AMASK0		CONFIG_SYS_NOR_AMASK
#define CONFIG_SYS_CSOR0		CONFIG_SYS_NOR_CSOR
#define CONFIG_SYS_CS0_FTIM0		CONFIG_SYS_NOR_FTIM0
#define CONFIG_SYS_CS0_FTIM1		CONFIG_SYS_NOR_FTIM1
#define CONFIG_SYS_CS0_FTIM2		CONFIG_SYS_NOR_FTIM2
#define CONFIG_SYS_CS0_FTIM3		CONFIG_SYS_NOR_FTIM3
#define CONFIG_SYS_CSPR1_EXT		CONFIG_SYS_NAND_CSPR_EXT
#define CONFIG_SYS_CSPR1		CONFIG_SYS_NAND_CSPR
#define CONFIG_SYS_AMASK1		CONFIG_SYS_NAND_AMASK
#define CONFIG_SYS_CSOR1		CONFIG_SYS_NAND_CSOR
#define CONFIG_SYS_CS1_FTIM0		CONFIG_SYS_NAND_FTIM0
#define CONFIG_SYS_CS1_FTIM1		CONFIG_SYS_NAND_FTIM1
#define CONFIG_SYS_CS1_FTIM2		CONFIG_SYS_NAND_FTIM2
#define CONFIG_SYS_CS1_FTIM3		CONFIG_SYS_NAND_FTIM3
#endif

#ifdef CONFIG_SPL_BUILD
#define CONFIG_SYS_MONITOR_BASE	CONFIG_SPL_TEXT_BASE
#else
#define CONFIG_SYS_MONITOR_BASE	CONFIG_SYS_TEXT_BASE	/* start of monitor */
#endif

#if defined(CONFIG_RAMBOOT_PBL)
#define CONFIG_SYS_RAMBOOT
#endif

#ifdef CONFIG_SYS_FSL_ERRATUM_A008044
#if defined(CONFIG_NAND)
#define CONFIG_A008044_WORKAROUND
#endif
#endif

#define CONFIG_BOARD_EARLY_INIT_R
#define CONFIG_MISC_INIT_R

#define CONFIG_HWCONFIG

/* define to use L1 as initial stack */
#define CONFIG_L1_INIT_RAM
#define CONFIG_SYS_INIT_RAM_LOCK
#define CONFIG_SYS_INIT_RAM_ADDR	0xfdd00000	/* Initial L1 address */
#define CONFIG_SYS_INIT_RAM_ADDR_PHYS_HIGH	0xf
#define CONFIG_SYS_INIT_RAM_ADDR_PHYS_LOW	0xfe03c000
/* The assembler doesn't like typecast */
#define CONFIG_SYS_INIT_RAM_ADDR_PHYS \
	((CONFIG_SYS_INIT_RAM_ADDR_PHYS_HIGH * 1ull << 32) | \
	  CONFIG_SYS_INIT_RAM_ADDR_PHYS_LOW)
#define CONFIG_SYS_INIT_RAM_SIZE		0x00004000

#define CONFIG_SYS_GBL_DATA_OFFSET	(CONFIG_SYS_INIT_RAM_SIZE - \
					GENERATED_GBL_DATA_SIZE)
#define CONFIG_SYS_INIT_SP_OFFSET	CONFIG_SYS_GBL_DATA_OFFSET

#define CONFIG_SYS_MONITOR_LEN		(768 * 1024)
#define CONFIG_SYS_MALLOC_LEN		(4 * 1024 * 1024)

/* Serial Port - controlled on board with jumper J8
 * open - index 2
 * shorted - index 1
 */
#define CONFIG_CONS_INDEX	1
#define CONFIG_SYS_NS16550
#define CONFIG_SYS_NS16550_SERIAL
#define CONFIG_SYS_NS16550_REG_SIZE	1
#define CONFIG_SYS_NS16550_CLK		(get_bus_freq(0)/2)

#define CONFIG_SYS_BAUDRATE_TABLE	\
	{300, 600, 1200, 2400, 4800, 9600, 19200, 38400, 57600, 115200}

#define CONFIG_SYS_NS16550_COM1	(CONFIG_SYS_CCSRBAR+0x11C500)
#define CONFIG_SYS_NS16550_COM2	(CONFIG_SYS_CCSRBAR+0x11C600)
#define CONFIG_SYS_NS16550_COM3	(CONFIG_SYS_CCSRBAR+0x11D500)
#define CONFIG_SYS_NS16550_COM4	(CONFIG_SYS_CCSRBAR+0x11D600)
#ifndef CONFIG_SPL_BUILD
#define CONFIG_SYS_CONSOLE_IS_IN_ENV	/* determine from environment */
#endif

/* Use the HUSH parser */
#define CONFIG_SYS_HUSH_PARSER
#define CONFIG_SYS_PROMPT_HUSH_PS2 "> "

#if defined(CONFIG_T1042RDB_PI) || defined(CONFIG_T1042D4RDB)
/* Video */
#define CONFIG_FSL_DIU_FB

#ifdef CONFIG_FSL_DIU_FB
#define CONFIG_FSL_DIU_CH7301
#define CONFIG_SYS_DIU_ADDR	(CONFIG_SYS_CCSRBAR + 0x180000)
#define CONFIG_VIDEO
#define CONFIG_CMD_BMP
#define CONFIG_CFB_CONSOLE
#define CONFIG_CFB_CONSOLE_ANSI
#define CONFIG_VIDEO_SW_CURSOR
#define CONFIG_VGA_AS_SINGLE_DEVICE
#define CONFIG_VIDEO_LOGO
#define CONFIG_VIDEO_BMP_LOGO
#endif
#endif

/* pass open firmware flat tree */
#define CONFIG_OF_LIBFDT
#define CONFIG_OF_BOARD_SETUP
#define CONFIG_OF_STDOUT_VIA_ALIAS

/* new uImage format support */
#define CONFIG_FIT
#define CONFIG_FIT_VERBOSE	/* enable fit_format_{error,warning}() */

/* I2C */
#define CONFIG_SYS_I2C
#define CONFIG_SYS_I2C_FSL		/* Use FSL common I2C driver */
#define CONFIG_SYS_FSL_I2C_SPEED	400000	/* I2C speed in Hz */
#define CONFIG_SYS_FSL_I2C2_SPEED	400000
#define CONFIG_SYS_FSL_I2C3_SPEED	400000
#define CONFIG_SYS_FSL_I2C4_SPEED	400000
#define CONFIG_SYS_FSL_I2C_SLAVE	0x7F
#define CONFIG_SYS_FSL_I2C2_SLAVE	0x7F
#define CONFIG_SYS_FSL_I2C3_SLAVE	0x7F
#define CONFIG_SYS_FSL_I2C4_SLAVE	0x7F
#define CONFIG_SYS_FSL_I2C_OFFSET	0x118000
#define CONFIG_SYS_FSL_I2C2_OFFSET	0x118100
#define CONFIG_SYS_FSL_I2C3_OFFSET	0x119000
#define CONFIG_SYS_FSL_I2C4_OFFSET	0x119100

/* I2C bus multiplexer */
#define I2C_MUX_PCA_ADDR                0x70
#if defined(CONFIG_T104xRDB) || defined(CONFIG_T104XD4RDB)
#define I2C_MUX_CH_DEFAULT      0x8
#endif

#if defined(CONFIG_T1042RDB_PI) || defined(CONFIG_T104XD4RDB)
/* LDI/DVI Encoder for display */
#define CONFIG_SYS_I2C_LDI_ADDR		0x38
#define CONFIG_SYS_I2C_DVI_ADDR		0x75

/*
 * RTC configuration
 */
#define RTC
#define CONFIG_RTC_DS1337               1
#define CONFIG_SYS_I2C_RTC_ADDR         0x68

/*DVI encoder*/
#define CONFIG_HDMI_ENCODER_I2C_ADDR  0x75
#endif

/*
 * eSPI - Enhanced SPI
 */
#define CONFIG_FSL_ESPI
#define CONFIG_SPI_FLASH_STMICRO
#define CONFIG_SPI_FLASH_BAR
#define CONFIG_CMD_SF
#define CONFIG_SF_DEFAULT_SPEED         10000000
#define CONFIG_SF_DEFAULT_MODE          0
#define CONFIG_ENV_SPI_BUS              0
#define CONFIG_ENV_SPI_CS               0
#define CONFIG_ENV_SPI_MAX_HZ           10000000
#define CONFIG_ENV_SPI_MODE             0

/*
 * General PCI
 * Memory space is mapped 1-1, but I/O space must start from 0.
 */

#ifdef CONFIG_PCI
/* controller 1, direct to uli, tgtid 3, Base address 20000 */
#ifdef CONFIG_PCIE1
#define	CONFIG_SYS_PCIE1_MEM_VIRT	0x80000000
#define	CONFIG_SYS_PCIE1_MEM_BUS	0xe0000000
#define	CONFIG_SYS_PCIE1_MEM_PHYS	0xc00000000ull
#define CONFIG_SYS_PCIE1_MEM_SIZE	0x10000000	/* 256M */
#define CONFIG_SYS_PCIE1_IO_VIRT	0xf8000000
#define CONFIG_SYS_PCIE1_IO_BUS		0x00000000
#define CONFIG_SYS_PCIE1_IO_PHYS	0xff8000000ull
#define CONFIG_SYS_PCIE1_IO_SIZE	0x00010000	/* 64k */
#endif

/* controller 2, Slot 2, tgtid 2, Base address 201000 */
#ifdef CONFIG_PCIE2
#define CONFIG_SYS_PCIE2_MEM_VIRT	0x90000000
#define CONFIG_SYS_PCIE2_MEM_BUS	0xe0000000
#define CONFIG_SYS_PCIE2_MEM_PHYS	0xc10000000ull
#define CONFIG_SYS_PCIE2_MEM_SIZE	0x10000000	/* 256M */
#define CONFIG_SYS_PCIE2_IO_VIRT	0xf8010000
#define CONFIG_SYS_PCIE2_IO_BUS		0x00000000
#define CONFIG_SYS_PCIE2_IO_PHYS	0xff8010000ull
#define CONFIG_SYS_PCIE2_IO_SIZE	0x00010000	/* 64k */
#endif

/* controller 3, Slot 1, tgtid 1, Base address 202000 */
#ifdef CONFIG_PCIE3
#define CONFIG_SYS_PCIE3_MEM_VIRT	0xa0000000
#define CONFIG_SYS_PCIE3_MEM_BUS	0xe0000000
#define CONFIG_SYS_PCIE3_MEM_PHYS	0xc20000000ull
#define CONFIG_SYS_PCIE3_MEM_SIZE	0x10000000	/* 256M */
#define CONFIG_SYS_PCIE3_IO_VIRT	0xf8020000
#define CONFIG_SYS_PCIE3_IO_BUS		0x00000000
#define CONFIG_SYS_PCIE3_IO_PHYS	0xff8020000ull
#define CONFIG_SYS_PCIE3_IO_SIZE	0x00010000	/* 64k */
#endif

/* controller 4, Base address 203000 */
#ifdef CONFIG_PCIE4
#define CONFIG_SYS_PCIE4_MEM_VIRT	0xb0000000
#define CONFIG_SYS_PCIE4_MEM_BUS	0xe0000000
#define CONFIG_SYS_PCIE4_MEM_PHYS	0xc30000000ull
#define CONFIG_SYS_PCIE4_MEM_SIZE	0x10000000	/* 256M */
#define CONFIG_SYS_PCIE4_IO_VIRT	0xf8030000
#define CONFIG_SYS_PCIE4_IO_BUS		0x00000000
#define CONFIG_SYS_PCIE4_IO_PHYS	0xff8030000ull
#define CONFIG_SYS_PCIE4_IO_SIZE	0x00010000	/* 64k */
#endif

#define CONFIG_PCI_PNP			/* do pci plug-and-play */

#define CONFIG_PCI_SCAN_SHOW		/* show pci devices on startup */
#define CONFIG_DOS_PARTITION
#endif	/* CONFIG_PCI */

/* SATA */
#define CONFIG_FSL_SATA_V2
#ifdef CONFIG_FSL_SATA_V2
#define CONFIG_LIBATA
#define CONFIG_FSL_SATA

#define CONFIG_SYS_SATA_MAX_DEVICE	1
#define CONFIG_SATA1
#define CONFIG_SYS_SATA1		CONFIG_SYS_MPC85xx_SATA1_ADDR
#define CONFIG_SYS_SATA1_FLAGS		FLAGS_DMA

#define CONFIG_LBA48
#define CONFIG_CMD_SATA
#define CONFIG_DOS_PARTITION
#define CONFIG_CMD_EXT2
#endif

/*
* USB
*/
#define CONFIG_HAS_FSL_DR_USB

#ifdef CONFIG_HAS_FSL_DR_USB
#define CONFIG_USB_EHCI

#ifdef CONFIG_USB_EHCI
#define CONFIG_CMD_USB
#define CONFIG_USB_STORAGE
#define CONFIG_USB_EHCI_FSL
#define CONFIG_EHCI_HCD_INIT_AFTER_RESET
#define CONFIG_CMD_EXT2
#endif
#endif

#define CONFIG_MMC

#ifdef CONFIG_MMC
#define CONFIG_FSL_ESDHC
#define CONFIG_SYS_FSL_ESDHC_ADDR       CONFIG_SYS_MPC85xx_ESDHC_ADDR
#define CONFIG_CMD_MMC
#define CONFIG_GENERIC_MMC
#define CONFIG_CMD_EXT2
#define CONFIG_CMD_FAT
#define CONFIG_DOS_PARTITION
#endif

/* Qman/Bman */
#ifndef CONFIG_NOBQFMAN
#define CONFIG_SYS_DPAA_QBMAN		/* Support Q/Bman */
#define CONFIG_SYS_BMAN_NUM_PORTALS	10
#define CONFIG_SYS_BMAN_MEM_BASE	0xf4000000
#define CONFIG_SYS_BMAN_MEM_PHYS	0xff4000000ull
#define CONFIG_SYS_BMAN_MEM_SIZE	0x02000000
#define CONFIG_SYS_BMAN_SP_CENA_SIZE    0x4000
#define CONFIG_SYS_BMAN_SP_CINH_SIZE    0x1000
#define CONFIG_SYS_BMAN_CENA_BASE       CONFIG_SYS_BMAN_MEM_BASE
#define CONFIG_SYS_BMAN_CENA_SIZE       (CONFIG_SYS_BMAN_MEM_SIZE >> 1)
#define CONFIG_SYS_BMAN_CINH_BASE       (CONFIG_SYS_BMAN_MEM_BASE + \
					CONFIG_SYS_BMAN_CENA_SIZE)
#define CONFIG_SYS_BMAN_CINH_SIZE       (CONFIG_SYS_BMAN_MEM_SIZE >> 1)
#define CONFIG_SYS_BMAN_SWP_ISDR_REG	0xE08
#define CONFIG_SYS_QMAN_NUM_PORTALS	10
#define CONFIG_SYS_QMAN_MEM_BASE	0xf6000000
#define CONFIG_SYS_QMAN_MEM_PHYS	0xff6000000ull
#define CONFIG_SYS_QMAN_MEM_SIZE	0x02000000
#define CONFIG_SYS_QMAN_SP_CENA_SIZE    0x4000
#define CONFIG_SYS_QMAN_SP_CINH_SIZE    0x1000
#define CONFIG_SYS_QMAN_CENA_BASE       CONFIG_SYS_QMAN_MEM_BASE
#define CONFIG_SYS_QMAN_CENA_SIZE       (CONFIG_SYS_QMAN_MEM_SIZE >> 1)
#define CONFIG_SYS_QMAN_CINH_BASE       (CONFIG_SYS_QMAN_MEM_BASE + \
					CONFIG_SYS_QMAN_CENA_SIZE)
#define CONFIG_SYS_QMAN_CINH_SIZE       (CONFIG_SYS_QMAN_MEM_SIZE >> 1)
#define CONFIG_SYS_QMAN_SWP_ISDR_REG	0xE08

#define CONFIG_SYS_DPAA_FMAN
#define CONFIG_SYS_DPAA_PME

#if defined(CONFIG_T104xRDB) || defined(CONFIG_T104XD4RDB)
#define CONFIG_QE
#define CONFIG_U_QE
#endif

/* Default address of microcode for the Linux Fman driver */
#if defined(CONFIG_SPIFLASH)
/*
 * env is stored at 0x100000, sector size is 0x10000, ucode is stored after
 * env, so we got 0x110000.
 */
#define CONFIG_SYS_QE_FW_IN_SPIFLASH
#define CONFIG_SYS_FMAN_FW_ADDR	0x110000
#elif defined(CONFIG_SDCARD)
/*
 * PBL SD boot image should stored at 0x1000(8 blocks), the size of the image is
 * about 1MB (2048 blocks), Env is stored after the image, and the env size is
 * 0x2000 (16 blocks), 8 + 2048 + 16 = 2072, enlarge it to 2080.
 */
#define CONFIG_SYS_QE_FMAN_FW_IN_MMC
#define CONFIG_SYS_FMAN_FW_ADDR	(512 * 0x820)
#elif defined(CONFIG_NAND)
#define CONFIG_SYS_QE_FMAN_FW_IN_NAND
#define CONFIG_SYS_FMAN_FW_ADDR	(5 * CONFIG_SYS_NAND_BLOCK_SIZE)
#else
#define CONFIG_SYS_QE_FMAN_FW_IN_NOR
#define CONFIG_SYS_FMAN_FW_ADDR		0xEFF00000
#endif

#if defined(CONFIG_T104xRDB) || defined(CONFIG_T104XD4RDB)
#if defined(CONFIG_SPIFLASH)
#define CONFIG_SYS_QE_FW_ADDR		0x130000
#elif defined(CONFIG_SDCARD)
#define CONFIG_SYS_QE_FW_ADDR		(512 * 0x920)
#elif defined(CONFIG_NAND)
#define CONFIG_SYS_QE_FW_ADDR		(7 * CONFIG_SYS_NAND_BLOCK_SIZE)
#else
#define CONFIG_SYS_QE_FW_ADDR		0xEFF10000
#endif
#endif


#define CONFIG_SYS_QE_FMAN_FW_LENGTH	0x10000
#define CONFIG_SYS_FDT_PAD		(0x3000 + CONFIG_SYS_QE_FMAN_FW_LENGTH)
#endif /* CONFIG_NOBQFMAN */

#ifdef CONFIG_SYS_DPAA_FMAN
#define CONFIG_FMAN_ENET
#define CONFIG_PHY_VITESSE
#define CONFIG_PHY_REALTEK
#endif

#ifdef CONFIG_FMAN_ENET
#if defined(CONFIG_T1040RDB) || defined(CONFIG_T1042RDB)
#define CONFIG_SYS_SGMII1_PHY_ADDR             0x03
#elif defined(CONFIG_T1040D4RDB) || defined(CONFIG_T1042D4RDB)
#define CONFIG_SYS_SGMII1_PHY_ADDR             0x02
#define CONFIG_SYS_SGMII2_PHY_ADDR             0x03
#define CONFIG_SYS_SGMII3_PHY_ADDR             0x01
#endif

#ifdef CONFIG_T104XD4RDB
#define CONFIG_SYS_RGMII1_PHY_ADDR             0x04
#define CONFIG_SYS_RGMII2_PHY_ADDR             0x05
#else
#define CONFIG_SYS_RGMII1_PHY_ADDR             0x01
#define CONFIG_SYS_RGMII2_PHY_ADDR             0x02
#endif

/* Enable VSC9953 L2 Switch driver on T1040 SoC */
#if defined(CONFIG_T1040RDB) || defined(CONFIG_T1040D4RDB)
#define CONFIG_VSC9953
#define CONFIG_CMD_ETHSW
#ifdef CONFIG_T1040RDB
#define CONFIG_SYS_FM1_QSGMII11_PHY_ADDR	0x04
#define CONFIG_SYS_FM1_QSGMII21_PHY_ADDR	0x08
#else
#define CONFIG_SYS_FM1_QSGMII11_PHY_ADDR	0x08
#define CONFIG_SYS_FM1_QSGMII21_PHY_ADDR	0x0c
#endif
#endif

#define CONFIG_MII		/* MII PHY management */
#define CONFIG_ETHPRIME		"FM1@DTSEC4"
#define CONFIG_PHY_GIGE		/* Include GbE speed/duplex detection */
#endif

/*
 * Environment
 */
#define CONFIG_LOADS_ECHO		/* echo on for serial download */
#define CONFIG_SYS_LOADS_BAUD_CHANGE	/* allow baudrate change */

/*
 * Command line configuration.
 */
#ifdef CONFIG_T1042RDB_PI
#define CONFIG_CMD_DATE
#endif
#define CONFIG_CMD_DHCP
#define CONFIG_CMD_ERRATA
#define CONFIG_CMD_GREPENV
#define CONFIG_CMD_IRQ
#define CONFIG_CMD_I2C
#define CONFIG_CMD_MII
#define CONFIG_CMD_PING
#define CONFIG_CMD_REGINFO

#ifdef CONFIG_PCI
#define CONFIG_CMD_PCI
#endif

/* Hash command with SHA acceleration supported in hardware */
#ifdef CONFIG_FSL_CAAM
#define CONFIG_CMD_HASH
#define CONFIG_SHA_HW_ACCEL
#endif

/*
 * Miscellaneous configurable options
 */
#define CONFIG_SYS_LONGHELP			/* undef to save memory	*/
#define CONFIG_CMDLINE_EDITING			/* Command-line editing */
#define CONFIG_AUTO_COMPLETE			/* add autocompletion support */
#define CONFIG_SYS_LOAD_ADDR	0x2000000	/* default load address */
#ifdef CONFIG_CMD_KGDB
#define CONFIG_SYS_CBSIZE	1024		/* Console I/O Buffer Size */
#else
#define CONFIG_SYS_CBSIZE	256		/* Console I/O Buffer Size */
#endif
#define CONFIG_SYS_PBSIZE (CONFIG_SYS_CBSIZE+sizeof(CONFIG_SYS_PROMPT)+16)
#define CONFIG_SYS_MAXARGS	16		/* max number of command args */
#define CONFIG_SYS_BARGSIZE	CONFIG_SYS_CBSIZE/* Boot Argument Buffer Size */

/*
 * For booting Linux, the board info and command line data
 * have to be in the first 64 MB of memory, since this is
 * the maximum mapped by the Linux kernel during initialization.
 */
#define CONFIG_SYS_BOOTMAPSZ	(64 << 20)	/* Initial map for Linux*/
#define CONFIG_SYS_BOOTM_LEN	(64 << 20)	/* Increase max gunzip size */

#ifdef CONFIG_CMD_KGDB
#define CONFIG_KGDB_BAUDRATE	230400	/* speed to run kgdb serial port */
#endif

/*
 * Dynamic MTD Partition support with mtdparts
 */
#ifndef CONFIG_SYS_NO_FLASH
#define CONFIG_MTD_DEVICE
#define CONFIG_MTD_PARTITIONS
#define CONFIG_CMD_MTDPARTS
#define CONFIG_FLASH_CFI_MTD
#define MTDIDS_DEFAULT "nor0=fe8000000.nor,nand0=fff800000.flash," \
			"spi0=spife110000.0"
#define MTDPARTS_DEFAULT	"mtdparts=fe8000000.nor:1m(uboot),5m(kernel)," \
				"128k(dtb),96m(fs),-(user);"\
				"fff800000.flash:2m(uboot),9m(kernel),"\
				"128k(dtb),96m(fs),-(user);spife110000.0:" \
				"2m(uboot),9m(kernel),128k(dtb),-(user)"
#endif

/*
 * Environment Configuration
 */
#define CONFIG_ROOTPATH		"/opt/nfsroot"
#define CONFIG_BOOTFILE		"uImage"
#define CONFIG_UBOOTPATH	"u-boot.bin"	/* U-Boot image on TFTP server*/

/* default location for tftp and bootm */
#define CONFIG_LOADADDR		1000000

#define CONFIG_BOOTDELAY	10	/*-1 disables auto-boot*/

#define CONFIG_BAUDRATE	115200

#define __USB_PHY_TYPE	utmi
#define RAMDISKFILE	"t104xrdb/ramdisk.uboot"

#ifdef CONFIG_T1040RDB
#define FDTFILE		"t1040rdb/t1040rdb.dtb"
#elif defined(CONFIG_T1042RDB_PI)
#define FDTFILE		"t1042rdb_pi/t1042rdb_pi.dtb"
#elif defined(CONFIG_T1042RDB)
#define FDTFILE		"t1042rdb/t1042rdb.dtb"
#elif defined(CONFIG_T1040D4RDB)
#define FDTFILE		"t1042rdb/t1040d4rdb.dtb"
#elif defined(CONFIG_T1042D4RDB)
#define FDTFILE		"t1042rdb/t1042d4rdb.dtb"
#endif

#ifdef CONFIG_FSL_DIU_FB
#define DIU_ENVIRONMENT "video-mode=fslfb:1024x768-32@60,monitor=dvi"
#else
#define DIU_ENVIRONMENT
#endif

#define	CONFIG_EXTRA_ENV_SETTINGS				\
	"hwconfig=fsl_ddr:bank_intlv=cs0_cs1;"			\
	"usb1:dr_mode=host,phy_type=" __stringify(__USB_PHY_TYPE) ";"\
	"usb2:dr_mode=host,phy_type=" __stringify(__USB_PHY_TYPE) "\0"\
	"netdev=eth0\0"						\
	"video-mode=" __stringify(DIU_ENVIRONMENT) "\0"		\
	"uboot=" __stringify(CONFIG_UBOOTPATH) "\0"		\
	"ubootaddr=" __stringify(CONFIG_SYS_TEXT_BASE) "\0"	\
	"tftpflash=tftpboot $loadaddr $uboot && "		\
	"protect off $ubootaddr +$filesize && "			\
	"erase $ubootaddr +$filesize && "			\
	"cp.b $loadaddr $ubootaddr $filesize && "		\
	"protect on $ubootaddr +$filesize && "			\
	"cmp.b $loadaddr $ubootaddr $filesize\0"		\
	"consoledev=ttyS0\0"					\
	"ramdiskaddr=2000000\0"					\
	"ramdiskfile=" __stringify(RAMDISKFILE) "\0"		\
	"fdtaddr=c00000\0"					\
	"fdtfile=" __stringify(FDTFILE) "\0"			\
	"bdev=sda3\0"

#define CONFIG_LINUX                       \
	"setenv bootargs root=/dev/ram rw "            \
	"console=$consoledev,$baudrate $othbootargs;"  \
	"setenv ramdiskaddr 0x02000000;"               \
	"setenv fdtaddr 0x00c00000;"		       \
	"setenv loadaddr 0x1000000;"		       \
	"bootm $loadaddr $ramdiskaddr $fdtaddr"

#define CONFIG_HDBOOT					\
	"setenv bootargs root=/dev/$bdev rw "		\
	"console=$consoledev,$baudrate $othbootargs;"	\
	"tftp $loadaddr $bootfile;"			\
	"tftp $fdtaddr $fdtfile;"			\
	"bootm $loadaddr - $fdtaddr"

#define CONFIG_NFSBOOTCOMMAND			\
	"setenv bootargs root=/dev/nfs rw "	\
	"nfsroot=$serverip:$rootpath "		\
	"ip=$ipaddr:$serverip:$gatewayip:$netmask:$hostname:$netdev:off " \
	"console=$consoledev,$baudrate $othbootargs;"	\
	"tftp $loadaddr $bootfile;"		\
	"tftp $fdtaddr $fdtfile;"		\
	"bootm $loadaddr - $fdtaddr"

#define CONFIG_RAMBOOTCOMMAND				\
	"setenv bootargs root=/dev/ram rw "		\
	"console=$consoledev,$baudrate $othbootargs;"	\
	"tftp $ramdiskaddr $ramdiskfile;"		\
	"tftp $loadaddr $bootfile;"			\
	"tftp $fdtaddr $fdtfile;"			\
	"bootm $loadaddr $ramdiskaddr $fdtaddr"

#define CONFIG_BOOTCOMMAND		CONFIG_LINUX

#ifdef CONFIG_SECURE_BOOT
#include <asm/fsl_secure_boot.h>
#define CONFIG_CMD_BLOB
#endif

#endif	/* __CONFIG_H */
