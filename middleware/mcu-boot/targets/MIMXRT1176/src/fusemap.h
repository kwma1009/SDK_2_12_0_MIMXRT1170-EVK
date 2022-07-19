/*
 * Copyright 2018 NXP
 *
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __FUSEMAP_H__
#define __FUSEMAP_H__

#include "fsl_device_registers.h"

////////////////////////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////////////////////////

#define FUSE_BANK0_OFFSET 0x800
#define HW_FUSE_REG_ADDR(n) (OCOTP_BASE + FUSE_BANK0_OFFSET + ((n)*0x10))
#define HW_OCOTP_REG_RD(n) (*(volatile uint32_t *)HW_FUSE_REG_ADDR(n))

/* ======================== Boot Configuration ================================= */
/* BOOT DEVICE */
#define FUSE_BOOT_DEVICE_SHIFT ((uint8_t)4)
#define FUSE_BOOT_DEVICE_MASK ((uint32_t)(0xf << FUSE_BOOT_DEVICE_SHIFT))
#define FUSE_BOOT_DEVICE_VALUE ((SRC->SBMR1 & FUSE_BOOT_DEVICE_MASK) >> FUSE_BOOT_DEVICE_SHIFT)

/* SPEED_LIMIT */
#define FUSE_SPEED_LIMIT_SHIFT (2)
#define FUSE_SPEED_LIMIT_MASK (1u << FUSE_SPEED_LIMIT_SHIFT)
#define FUSE_SPEED_LIMIT_VALUE ((HW_OCOTP_REG_RD(0x07) & FUSE_SPEED_LIMIT_MASK) >> FUSE_SPEED_LIMIT_SHIFT)

/* ====================== FlexSPI NAND Boot ================================= */
/* Safe Frequency */
#define FUSE_SAFE_FREQ_SHIFT ((uint8_t)5)
#define FUSE_SAFE_FREQ_MASK (1u << FUSE_SAFE_FREQ_SHIFT)
#define FUSE_SAFE_FREQ_VALUE ((SRC->SBMR1 & FUSE_SAFE_FREQ_MASK) >> FUSE_SAFE_FREQ_SHIFT)

/* COL_Address_width */
#define FUSE_COL_ADDRESS_WIDTH_SHIFT ((uint8_t)4)
#define FUSE_COL_ADDRESS_WIDTH_MASK (1u << FUSE_COL_ADDRESS_WIDTH_SHIFT)
#define FUSE_COL_ADDRESS_WIDTH_VALUE ((SRC->SBMR1 & FUSE_COL_ADDRESS_WIDTH_MASK) >> FUSE_COL_ADDRESS_WIDTH_SHIFT)

/* Boot_Search_Stride */
#define FUSE_BOOT_SEARCH_STRIDE_SHIFT ((uint8_t)0)
#define FUSE_BOOT_SEARCH_STRIDE_MASK (3u << FUSE_BOOT_SEARCH_STRIDE_SHIFT)
#define FUSE_BOOT_SEARCH_STRIDE_VALUE ((SRC->SBMR1 & FUSE_BOOT_SEARCH_STRIDE_MASK) >> FUSE_BOOT_SEARCH_STRIDE_SHIFT)

/* Boot_Search_Count */
#define FUSE_BOOT_SEARCH_COUNT_SHIFT ((uint8_t)8)
#define FUSE_BOOT_SEARCH_COUNT_MASK (1u << FUSE_BOOT_SEARCH_COUNT_SHIFT)
#define FUSE_BOOT_SEARCH_COUNT_VALUE ((SRC->SBMR1 & FUSE_BOOT_SEARCH_COUNT_MASK) >> FUSE_BOOT_SEARCH_COUNT_SHIFT)

/* CS_Interval */
#define FUSE_CS_INTERVAL_SHIFT ((uint8_t)9)
#define FUSE_CS_INTERVAL_MASK (0x3u << FUSE_CS_INTERVAL_SHIFT)
#define FUSE_CS_INTERVAL_VALUE ((SRC->SBMR1 & FUSE_CS_INTERVAL_MASK) >> FUSE_CS_INTERVAL_SHIFT)

/* SPI NAND Boot - override Busy Offset */
#define FUSE_SPI_NAND_BOOT_BUSY_BIT_OFFSET_OVERRIDE_SHIFT ((uint8_t)7)
#define FUSE_SPI_NAND_BOOT_BUSY_BIT_OFFSET_OVERRIDE_MASK (1u << FUSE_SPI_NAND_BOOT_BUSY_BIT_OFFSET_OVERRIDE_SHIFT)
#define FUSE_SPI_NAND_BOOT_BUSY_BIT_OFFSET_OVERRIDE_VALUE                          \
    ((HW_OCOTP_REG_RD(0x48) & FUSE_SPI_NAND_BOOT_BUSY_BIT_OFFSET_OVERRIDE_MASK) >> \
     FUSE_SPI_NAND_BOOT_BUSY_BIT_OFFSET_OVERRIDE_SHIFT)

/* Bypass_ECC_Read */
#define FUSE_BYPASS_ECC_READ_SHIFT ((uint8_t)14)
#define FUSE_BYPASS_ECC_READ_MASK (1u << FUSE_BYPASS_ECC_READ_SHIFT)
#define FUSE_BYPASS_ECC_READ_VALUE ((HW_OCOTP_REG_RD(0x48) & FUSE_BYPASS_ECC_READ_MASK) >> FUSE_BYPASS_ECC_READ_SHIFT)

/* Bypass_Read_Status */
#define FUSE_BYPASS_READ_STATUS_SHIFT ((uint8_t)15)
#define FUSE_BYPASS_READ_STATUS_MASK (1u << FUSE_BYPASS_READ_STATUS_SHIFT)
#define FUSE_BYPASS_READ_STATUS_VALUE \
    ((HW_OCOTP_REG_RD(0x48) & FUSE_BYPASS_READ_STATUS_MASK) >> FUSE_BYPASS_READ_STATUS_SHIFT)

/* SPI NAND BOOT - page read cmd */
#define FUSE_SPI_NAND_BOOT_PAGE_RD_CMD_SHIFT ((uint8_t)16)
#define FUSE_SPI_NAND_BOOT_PAGE_RD_CMD_MASK (0xffu << FUSE_SPI_NAND_BOOT_PAGE_RD_CMD_SHIFT)
#define FUSE_SPI_NAND_BOOT_PAGE_RD_CMD_VALUE \
    ((HW_OCOTP_REG_RD(0x48) & FUSE_SPI_NAND_BOOT_PAGE_RD_CMD_MASK) >> FUSE_SPI_NAND_BOOT_PAGE_RD_CMD_SHIFT)

/* SPI NAND BOOT - cache read cmd */
#define FUSE_SPI_NAND_BOOT_CACHE_RD_CMD_SHIFT ((uint8_t)24)
#define FUSE_SPI_NAND_BOOT_CACHE_RD_CMD_MASK (0xFFu << FUSE_SPI_NAND_BOOT_CACHE_RD_CMD_SHIFT)
#define FUSE_SPI_NAND_BOOT_CACHE_RD_CMD_VALUE \
    ((HW_OCOTP_REG_RD(0x48) & FUSE_SPI_NAND_BOOT_CACHE_RD_CMD_MASK) >> FUSE_SPI_NAND_BOOT_CACHE_RD_CMD_SHIFT)

/* ======================== SEMC NAND Boot ================================= */
/* Boot_Search_Count */
#define FUSE_SEMC_NAND_SEARCH_COUNT_SHIFT ((uint8_t)0)
#define FUSE_SEMC_NAND_SEARCH_COUNT_MASK (1u << FUSE_SEMC_NAND_SEARCH_COUNT_SHIFT)
#define FUSE_SEMC_NAND_SEARCH_COUNT_VALUE \
    ((SRC->SBMR1 & FUSE_SEMC_NAND_SEARCH_COUNT_MASK) >> FUSE_SEMC_NAND_SEARCH_COUNT_SHIFT)

/* Boot_Search_Stride  */
#define FUSE_SEMC_NAND_SEARCH_STRIDE_SHIFT ((uint8_t)1)
#define FUSE_SEMC_NAND_SEARCH_STRIDE_MASK (0xFu << FUSE_SEMC_NAND_SEARCH_STRIDE_SHIFT)
#define FUSE_SEMC_NAND_SEARCH_STRIDE_VALUE \
    ((SRC->SBMR1 & FUSE_SEMC_NAND_SEARCH_STRIDE_MASK) >> FUSE_SEMC_NAND_SEARCH_STRIDE_SHIFT)

/* ONFI compliant */
#define FUSE_SEMC_NAND_ONFI_COMPLIANT_SHIFT ((uint8_t)8)
#define FUSE_SEMC_NAND_ONFI_COMPLIANT_MASK (1u << FUSE_SEMC_NAND_ONFI_COMPLIANT_SHIFT)
#define FUSE_SEMC_NAND_ONFI_COMPLIANT_VALUE \
    ((SRC->SBMR1 & FUSE_SEMC_NAND_ONFI_COMPLIANT_MASK) >> FUSE_SEMC_NAND_ONFI_COMPLIANT_SHIFT)

/* EDO mode */
#define FUSE_SEMC_NAND_EDO_MODE_SHIFT ((uint8_t)9)
#define FUSE_SEMC_NAND_EDO_MODE_MASK (1u << FUSE_SEMC_NAND_EDO_MODE_SHIFT)
#define FUSE_SEMC_NAND_EDO_MODE_VALUE ((SRC->SBMR1 & FUSE_SEMC_NAND_EDO_MODE_MASK) >> FUSE_SEMC_NAND_EDO_MODE_SHIFT)

/* Memory Access Command */
#define FUSE_SEMC_NAND_ACCESS_COMMAND_SHIFT ((uint8_t)10)
#define FUSE_SEMC_NAND_ACCESS_COMMAND_MASK (1u << FUSE_SEMC_NAND_ACCESS_COMMAND_SHIFT)
#define FUSE_SEMC_NAND_ACCESS_COMMAND_VALUE \
    ((SRC->SBMR1 & FUSE_SEMC_NAND_ACCESS_COMMAND_MASK) >> FUSE_SEMC_NAND_ACCESS_COMMAND_SHIFT)

/* I/O Port_width */
#define FUSE_SEMC_NAND_IO_PORT_WIDTH_SHIFT ((uint8_t)3)
#define FUSE_SEMC_NAND_IO_PORT_WIDTH_MASK (1u << FUSE_SEMC_NAND_IO_PORT_WIDTH_SHIFT)
#define FUSE_SEMC_NAND_IO_PORT_WIDTH_VALUE \
    ((HW_OCOTP_REG_RD(0x48) & FUSE_SEMC_NAND_IO_PORT_WIDTH_MASK) >> FUSE_SEMC_NAND_IO_PORT_WIDTH_SHIFT)

/* ECC Type */
#define FUSE_SEMC_NAND_ECC_TYPE_SHIFT ((uint8_t)4)
#define FUSE_SEMC_NAND_ECC_TYPE_MASK (1u << FUSE_SEMC_NAND_ECC_TYPE_SHIFT)
#define FUSE_SEMC_NAND_ECC_TYPE_VALUE \
    ((HW_OCOTP_REG_RD(0x48) & FUSE_SEMC_NAND_ECC_TYPE_MASK) >> FUSE_SEMC_NAND_ECC_TYPE_SHIFT)

/* RDY Polarity */
#define FUSE_SEMC_NAND_RDY_POLARITY_SHIFT ((uint8_t)5)
#define FUSE_SEMC_NAND_RDY_POLARITY_MASK (1u << FUSE_SEMC_NAND_RDY_POLARITY_SHIFT)
#define FUSE_SEMC_NAND_RDY_POLARITY_VALUE \
    ((HW_OCOTP_REG_RD(0x48) & FUSE_SEMC_NAND_RDY_POLARITY_MASK) >> FUSE_SEMC_NAND_RDY_POLARITY_SHIFT)

/* Ready Check type */
#define FUSE_SEMC_NAND_READY_CHECK_TYPE_SHIFT ((uint8_t)6)
#define FUSE_SEMC_NAND_READY_CHECK_TYPE_MASK (1u << FUSE_SEMC_NAND_READY_CHECK_TYPE_SHIFT)
#define FUSE_SEMC_NAND_READY_CHECK_TYPE_VALUE \
    ((HW_OCOTP_REG_RD(0x48) & FUSE_SEMC_NAND_READY_CHECK_TYPE_MASK) >> FUSE_SEMC_NAND_READY_CHECK_TYPE_SHIFT)

/* Clock Frequency */
#define FUSE_SEMC_NAND_CLK_FREQ_SHIFT ((uint8_t)7)
#define FUSE_SEMC_NAND_CLK_FREQ_MASK (1u << FUSE_SEMC_NAND_CLK_FREQ_SHIFT)
#define FUSE_SEMC_NAND_CLK_FREQ_VALUE \
    ((HW_OCOTP_REG_RD(0x48) & FUSE_SEMC_NAND_CLK_FREQ_MASK) >> FUSE_SEMC_NAND_CLK_FREQ_SHIFT)

/* Row Column address mode */
#define FUSE_SEMC_NAND_ROW_COL_ADDR_MODE_SHIFT ((uint8_t)8)
#define FUSE_SEMC_NAND_ROW_COL_ADDR_MODE_MASK (0x07u << FUSE_SEMC_NAND_ROW_COL_ADDR_MODE_SHIFT)
#define FUSE_SEMC_NAND_ROW_COL_ADDR_MODE_VALUE \
    ((HW_OCOTP_REG_RD(0x48) & FUSE_SEMC_NAND_ROW_COL_ADDR_MODE_MASK) >> FUSE_SEMC_NAND_ROW_COL_ADDR_MODE_SHIFT)

/* COL_Address_width */
#define FUSE_SEMC_NAND_COL_ADDRESS_WIDTH_SHIFT ((uint8_t)11)
#define FUSE_SEMC_NAND_COL_ADDRESS_WIDTH_MASK (0x7u << FUSE_SEMC_NAND_COL_ADDRESS_WIDTH_SHIFT)
#define FUSE_SEMC_NAND_COL_ADDRESS_WIDTH_VALUE \
    ((HW_OCOTP_REG_RD(0x48) & FUSE_SEMC_NAND_COL_ADDRESS_WIDTH_MASK) >> FUSE_SEMC_NAND_COL_ADDRESS_WIDTH_SHIFT)

/* Status Command Type */
#define FUSE_SEMC_NAND_STATUS_CMD_TYPE_SHIFT ((uint8_t)14)
#define FUSE_SEMC_NAND_STATUS_CMD_TYPE_MASK (1u << FUSE_SEMC_NAND_STATUS_CMD_TYPE_SHIFT)
#define FUSE_SEMC_NAND_STATUS_CMD_TYPE_VALUE \
    ((HW_OCOTP_REG_RD(0x48) & FUSE_SEMC_NAND_STATUS_CMD_TYPE_MASK) >> FUSE_SEMC_NAND_STATUS_CMD_TYPE_SHIFT)

/* Pages in block */
#define FUSE_SEMC_NAND_PAGES_IN_BLOCK_SHIFT ((uint8_t)16)
#define FUSE_SEMC_NAND_PAGES_IN_BLOCK_MASK (0x07 << FUSE_SEMC_NAND_PAGES_IN_BLOCK_SHIFT)
#define FUSE_SEMC_NAND_PAGES_IN_BLOCK_VALUE \
    ((HW_OCOTP_REG_RD(0x48) & FUSE_SEMC_NAND_PAGES_IN_BLOCK_MASK) >> FUSE_SEMC_NAND_PAGES_IN_BLOCK_SHIFT)

/* PCS selection */
#define FUSE_SEMC_NAND_PCS_SELECTION_SHIFT ((uint8_t)19)
#define FUSE_SEMC_NAND_PCS_SELECTION_MASK (0x07 << FUSE_SEMC_NAND_PCS_SELECTION_SHIFT)
#define FUSE_SEMC_NAND_PCS_SELECTION_VALUE \
    ((HW_OCOTP_REG_RD(0x48) & FUSE_SEMC_NAND_PCS_SELECTION_MASK) >> FUSE_SEMC_NAND_PCS_SELECTION_SHIFT)

/* Device ECC initial status */
#define FUSE_SEMC_NAND_DEVICE_ECC_STATUS_SHIFT ((uint8_t)24)
#define FUSE_SEMC_NAND_DEVICE_ECC_STATUS_MASK (1u << FUSE_SEMC_NAND_DEVICE_ECC_STATUS_SHIFT)
#define FUSE_SEMC_NAND_DEVICE_ECC_STATUS_VALUE \
    ((HW_OCOTP_REG_RD(0x48) & FUSE_SEMC_NAND_DEVICE_ECC_STATUS_MASK) >> FUSE_SEMC_NAND_DEVICE_ECC_STATUS_SHIFT)

/* ONFI Timing mode */
#define FUSE_SEMC_NAND_TIMING_MODE_SHIFT ((uint8_t)25)
#define FUSE_SEMC_NAND_TIMING_MODE_MASK (0x07u << FUSE_SEMC_NAND_TIMING_MODE_SHIFT)
#define FUSE_SEMC_NAND_TIMING_MODE_VALUE \
    ((HW_OCOTP_REG_RD(0x48) & FUSE_SEMC_NAND_TIMING_MODE_MASK) >> FUSE_SEMC_NAND_TIMING_MODE_SHIFT)


/* ========================== LP boot ======================================= */
#define FUSE_LPB_BOOT_SHIFT 4
#define FUSE_LPB_BOOT_MASK (0x03 << FUSE_LPB_BOOT_SHIFT)
#define FUSE_LPB_BOOT_VALUE ((HW_OCOTP_REG_RD(0x1a) & FUSE_LPB_BOOT_MASK) >> FUSE_LPB_BOOT_SHIFT)

#define FUSE_BOOT_FREQ_SHIFT 0x03
#define FUSE_BOOT_FREQ_MASK (1u << FUSE_BOOT_FREQ_SHIFT)
#define FUSE_BOOT_FREQ_VALUE ((HW_OCOTP_REG_RD(0x1a) & FUSE_BOOT_FREQ_MASK) >> FUSE_BOOT_FREQ_SHIFT)

#define FUSE_BOOT_OSC_REF_SHIFT 0x02
#define FUSE_BOOT_OSC_REF_MASK (1u << FUSE_BOOT_OSC_REF_SHIFT)
#define FUSE_BOOT_OSC_REF_VALUE ((HW_OCOTP_REG_RD(0x1a) & FUSE_BOOT_OSC_REF_MASK) >> FUSE_BOOT_OSC_REF_SHIFT)

/* ========================== Secure/Encrypt boot ======================================= */
/* FIELD_RETURN */
#define FUSE_FIELD_RETURN_SHIFT ((uint8_t)4)
#define FUSE_FIELD_RETURN_MASK (0xFu << FUSE_FIELD_RETURN_SHIFT)
#define FUSE_FIELD_RETURN_VALUE ((HW_OCOTP_REG_RD(0x0D) & FUSE_FIELD_RETURN_MASK) >> FUSE_FIELD_RETURN_SHIFT)

/* SEC Config[0] */
#define FUSE_SEC_CONFIG0_SHIFT ((uint8_t)1)
#define FUSE_SEC_CONFIG0_MASK (1u << FUSE_SEC_CONFIG0_SHIFT)
#define FUSE_SEC_CONFIG0_VALUE ((HW_OCOTP_REG_RD(0x0E) & FUSE_SEC_CONFIG0_MASK) >> FUSE_SEC_CONFIG0_SHIFT)
/* SEC_Config[1] */
#define FUSE_SEC_CONFIG1_SHIFT ((uint8_t)1)
#define FUSE_SEC_CONFIG1_MASK (1u << FUSE_SEC_CONFIG1_SHIFT)
#define FUSE_SEC_CONFIG1_VALUE ((HW_OCOTP_REG_RD(0x16) & FUSE_SEC_CONFIG1_MASK) >> FUSE_SEC_CONFIG1_SHIFT)
#define FUSE_SEC_CONFIG_VALUE (FUSE_SEC_CONFIG0_VALUE | (FUSE_SEC_CONFIG1_VALUE << 1))

/* ========================== MMC/SD boot(Common Part)======================================= */
/* SD/MMC instance 1 reset polarity */
#define FUSE_SD1_RST_ACTIVE_POLARITY_SHIFT ((uint8_t)2)
#define FUSE_SD1_RST_ACTIVE_POLARITY_MASK ((uint32_t)(0x1 << FUSE_SD1_RST_ACTIVE_POLARITY_SHIFT))
#define FUSE_SD1_RST_ACTIVE_POLARITY_VALUE \
    ((HW_OCOTP_REG_RD(0x17) & FUSE_SD1_RST_ACTIVE_POLARITY_MASK) >> FUSE_SD1_RST_ACTIVE_POLARITY_SHIFT)

/* SD/MMC instance 2 reset polarity */
#define FUSE_SD2_RST_ACTIVE_POLARITY_SHIFT ((uint8_t)1)
#define FUSE_SD2_RST_ACTIVE_POLARITY_MASK ((uint32_t)(0x1 << FUSE_SD2_RST_ACTIVE_POLARITY_SHIFT))
#define FUSE_SD2_RST_ACTIVE_POLARITY_VALUE \
    ((HW_OCOTP_REG_RD(0x17) & FUSE_SD2_RST_ACTIVE_POLARITY_MASK) >> FUSE_SD2_RST_ACTIVE_POLARITY_SHIFT)

/* ========================== Misc. Configuration ======================================= */
/* FLEXRAM PART */
#define FUSE_FLEXRAM_CFG_SHIFT ((uint8_t)16)
#define FUSE_FLEXRAM_CFG_MASK (0x3fu << FUSE_FLEXRAM_CFG_SHIFT)
#define FUSE_FLEXRAM_CFG_VALUE ((HW_OCOTP_REG_RD(0x47) & FUSE_FLEXRAM_CFG_MASK) >> FUSE_FLEXRAM_CFG_SHIFT)

#endif /* __FUSEMAP_H__*/
