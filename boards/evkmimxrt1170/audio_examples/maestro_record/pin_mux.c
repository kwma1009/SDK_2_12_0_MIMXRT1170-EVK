/*
 * Copyright 2020-2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v10.0
processor: MIMXRT1176xxxxx
package_id: MIMXRT1176DVMAA
mcu_data: ksdk2_0
processor_version: 10.0.0
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "fsl_gpio.h"
#include "pin_mux.h"

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 *
 * END ****************************************************************************************************************/
void BOARD_InitBootPins(void) {
    BOARD_InitPins();
}

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', coreID: cm7, enableClock: 'true'}
- pin_list:
  - {pin_num: M15, peripheral: LPUART1, signal: RXD, pin_signal: GPIO_AD_25, software_input_on: Enable, pull_up_down_config: Pull_Down, pull_keeper_select: Pull,
    open_drain: Disable, drive_strength: High, slew_rate: Slow}
  - {pin_num: L13, peripheral: LPUART1, signal: TXD, pin_signal: GPIO_AD_24, software_input_on: Disable, pull_up_down_config: Pull_Down, pull_keeper_select: Pull,
    open_drain: Disable, drive_strength: High, slew_rate: Slow}
  - {pin_num: U8, peripheral: MIC, signal: CLK, pin_signal: GPIO_LPSR_08, software_input_on: Disable, pull_up_down_config: Pull_Down, pull_keeper_select: Keeper,
    open_drain: Disable, drive_strength: High, slew_rate: Fast}
  - {pin_num: P5, peripheral: MIC, signal: 'mic_bitstream, 00', pin_signal: GPIO_LPSR_09, software_input_on: Disable, pull_up_down_config: Pull_Down, pull_keeper_select: Keeper,
    open_drain: Disable, drive_strength: High, slew_rate: Fast}
  - {pin_num: N15, peripheral: SAI1, signal: sai_mclk, pin_signal: GPIO_AD_17, software_input_on: Enable, pull_up_down_config: Pull_Down, pull_keeper_select: Pull,
    open_drain: Disable, drive_strength: High, slew_rate: Slow}
  - {pin_num: K14, peripheral: SAI1, signal: sai_tx_data00, pin_signal: GPIO_AD_21, software_input_on: Enable, pull_up_down_config: Pull_Down, pull_keeper_select: Pull,
    open_drain: Disable, drive_strength: High, slew_rate: Slow}
  - {pin_num: K12, peripheral: SAI1, signal: sai_tx_bclk, pin_signal: GPIO_AD_22, software_input_on: Enable, pull_up_down_config: Pull_Down, pull_keeper_select: Pull,
    open_drain: Disable, drive_strength: High, slew_rate: Slow}
  - {pin_num: J12, peripheral: SAI1, signal: sai_tx_sync, pin_signal: GPIO_AD_23, software_input_on: Enable, pull_up_down_config: Pull_Down, pull_keeper_select: Pull,
    open_drain: Disable, drive_strength: High, slew_rate: Slow}
  - {pin_num: N8, peripheral: LPI2C5, signal: SCL, pin_signal: GPIO_LPSR_05, software_input_on: Enable, pull_up_down_config: Pull_Down, pull_keeper_select: Keeper,
    open_drain: Disable, drive_strength: High, slew_rate: Slow}
  - {pin_num: N7, peripheral: LPI2C5, signal: SDA, pin_signal: GPIO_LPSR_04, software_input_on: Enable, pull_up_down_config: Pull_Down, pull_keeper_select: Keeper,
    open_drain: Disable, drive_strength: High, slew_rate: Slow}
  - {pin_num: A16, peripheral: USDHC1, signal: 'usdhc_data, 3', pin_signal: GPIO_SD_B1_05, software_input_on: Enable, pull_down_pull_up_config: Pull_Up}
  - {pin_num: B15, peripheral: USDHC1, signal: 'usdhc_data, 2', pin_signal: GPIO_SD_B1_04, software_input_on: Enable, pull_down_pull_up_config: Pull_Up}
  - {pin_num: B17, peripheral: USDHC1, signal: 'usdhc_data, 1', pin_signal: GPIO_SD_B1_03, software_input_on: Enable, pull_down_pull_up_config: Pull_Up}
  - {pin_num: C15, peripheral: USDHC1, signal: 'usdhc_data, 0', pin_signal: GPIO_SD_B1_02, software_input_on: Enable, pull_down_pull_up_config: Pull_Up}
  - {pin_num: B16, peripheral: USDHC1, signal: usdhc_cmd, pin_signal: GPIO_SD_B1_00, software_input_on: Enable, pull_down_pull_up_config: Pull_Up}
  - {pin_num: D15, peripheral: USDHC1, signal: usdhc_clk, pin_signal: GPIO_SD_B1_01, software_input_on: Enable, pull_down_pull_up_config: No_Pull}
  - {pin_num: J16, peripheral: USDHC1, signal: usdhc_vselect, pin_signal: GPIO_AD_34}
  - {pin_num: G17, peripheral: GPIO10, signal: 'gpio_io, 02', pin_signal: GPIO_AD_35}
  - {pin_num: K16, peripheral: CM7_GPIO3, signal: 'gpio_mux_io_cm7, 31', pin_signal: GPIO_AD_32}
  - {pin_num: T8, peripheral: GPIO13, signal: 'gpio_io, 00', pin_signal: WAKEUP, direction: INPUT, gpio_interrupt: kGPIO_IntFallingEdge}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins, assigned for the Cortex-M7F core.
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitPins(void) {
  CLOCK_EnableClock(kCLOCK_Iomuxc);           /* LPCG on: LPCG is ON. */
  CLOCK_EnableClock(kCLOCK_Iomuxc_Lpsr);      /* LPCG on: LPCG is ON. */

  /* GPIO configuration on WAKEUP_DIG (pin T8) */
  gpio_pin_config_t gpio13_pinT8_config = {
      .direction = kGPIO_DigitalInput,
      .outputLogic = 0U,
      .interruptMode = kGPIO_IntFallingEdge
  };
  /* Initialize GPIO functionality on WAKEUP_DIG (pin T8) */
  GPIO_PinInit(GPIO13, 0U, &gpio13_pinT8_config);
  /* Enable GPIO pin interrupt on WAKEUP_DIG (pin T8) */
  GPIO_PortEnableInterrupts(GPIO13, 1U << 0U);

  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_17_SAI1_MCLK,            /* GPIO_AD_17 is configured as SAI1_MCLK */
      1U);                                    /* Software Input On Field: Force input path of pad GPIO_AD_17 */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_21_SAI1_TX_DATA00,       /* GPIO_AD_21 is configured as SAI1_TX_DATA00 */
      1U);                                    /* Software Input On Field: Force input path of pad GPIO_AD_21 */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_22_SAI1_TX_BCLK,         /* GPIO_AD_22 is configured as SAI1_TX_BCLK */
      1U);                                    /* Software Input On Field: Force input path of pad GPIO_AD_22 */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_23_SAI1_TX_SYNC,         /* GPIO_AD_23 is configured as SAI1_TX_SYNC */
      1U);                                    /* Software Input On Field: Force input path of pad GPIO_AD_23 */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_24_LPUART1_TXD,          /* GPIO_AD_24 is configured as LPUART1_TXD */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_25_LPUART1_RXD,          /* GPIO_AD_25 is configured as LPUART1_RXD */
      1U);                                    /* Software Input On Field: Force input path of pad GPIO_AD_25 */
  IOMUXC_GPR->GPR0 = ((IOMUXC_GPR->GPR0 &
    (~(IOMUXC_GPR_GPR0_SAI1_MCLK_DIR_MASK)))  /* Mask bits to zero which are setting */
      | IOMUXC_GPR_GPR0_SAI1_MCLK_DIR(0x01U)  /* SAI1_MCLK signal direction control: 0x01U */
    );
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_LPSR_04_LPI2C5_SDA,         /* GPIO_LPSR_04 is configured as LPI2C5_SDA */
      1U);                                    /* Software Input On Field: Force input path of pad GPIO_LPSR_04 */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_LPSR_05_LPI2C5_SCL,         /* GPIO_LPSR_05 is configured as LPI2C5_SCL */
      1U);                                    /* Software Input On Field: Force input path of pad GPIO_LPSR_05 */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_32_GPIO_MUX3_IO31,       /* GPIO_AD_32 is configured as GPIO_MUX3_IO31 */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_34_USDHC1_VSELECT,       /* GPIO_AD_34 is configured as USDHC1_VSELECT */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_35_GPIO10_IO02,          /* GPIO_AD_35 is configured as GPIO10_IO02 */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_SD_B1_00_USDHC1_CMD,        /* GPIO_SD_B1_00 is configured as USDHC1_CMD */
      1U);                                    /* Software Input On Field: Force input path of pad GPIO_SD_B1_00 */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_SD_B1_01_USDHC1_CLK,        /* GPIO_SD_B1_01 is configured as USDHC1_CLK */
      1U);                                    /* Software Input On Field: Force input path of pad GPIO_SD_B1_01 */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_SD_B1_02_USDHC1_DATA0,      /* GPIO_SD_B1_02 is configured as USDHC1_DATA0 */
      1U);                                    /* Software Input On Field: Force input path of pad GPIO_SD_B1_02 */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_SD_B1_03_USDHC1_DATA1,      /* GPIO_SD_B1_03 is configured as USDHC1_DATA1 */
      1U);                                    /* Software Input On Field: Force input path of pad GPIO_SD_B1_03 */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_SD_B1_04_USDHC1_DATA2,      /* GPIO_SD_B1_04 is configured as USDHC1_DATA2 */
      1U);                                    /* Software Input On Field: Force input path of pad GPIO_SD_B1_04 */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_SD_B1_05_USDHC1_DATA3,      /* GPIO_SD_B1_05 is configured as USDHC1_DATA3 */
      1U);                                    /* Software Input On Field: Force input path of pad GPIO_SD_B1_05 */

  IOMUXC_SetPinMux(
      IOMUXC_GPIO_LPSR_08_MIC_CLK,            /* GPIO_LPSR_08 is configured as MIC_CLK */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_LPSR_09_MIC_BITSTREAM0,     /* GPIO_LPSR_09 is configured as MIC_BITSTREAM0 */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_WAKEUP_DIG_GPIO13_IO00,          /* WAKEUP_DIG is configured as GPIO13_IO00 */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */

  IOMUXC_GPR->GPR43 = ((IOMUXC_GPR->GPR43 &
    (~(IOMUXC_GPR_GPR43_GPIO_MUX3_GPIO_SEL_HIGH_MASK))) /* Mask bits to zero which are setting */
      | IOMUXC_GPR_GPR43_GPIO_MUX3_GPIO_SEL_HIGH(0x8000U) /* GPIO3 and CM7_GPIO3 share same IO MUX function, GPIO_MUX3 selects one GPIO function: 0x8000U */
    );
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_AD_17_SAI1_MCLK,            /* GPIO_AD_17 PAD functional properties : */
      0x06U);                                 /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: high drive strength
                                                 Pull / Keep Select Field: Pull Enable
                                                 Pull Up / Down Config. Field: Weak pull down
                                                 Open Drain Field: Disabled
                                                 Domain write protection: Both cores are allowed
                                                 Domain write protection lock: Neither of DWP bits is locked */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_AD_21_SAI1_TX_DATA00,       /* GPIO_AD_21 PAD functional properties : */
      0x06U);                                 /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: high drive strength
                                                 Pull / Keep Select Field: Pull Enable
                                                 Pull Up / Down Config. Field: Weak pull down
                                                 Open Drain Field: Disabled
                                                 Domain write protection: Both cores are allowed
                                                 Domain write protection lock: Neither of DWP bits is locked */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_AD_22_SAI1_TX_BCLK,         /* GPIO_AD_22 PAD functional properties : */
      0x06U);                                 /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: high drive strength
                                                 Pull / Keep Select Field: Pull Enable
                                                 Pull Up / Down Config. Field: Weak pull down
                                                 Open Drain Field: Disabled
                                                 Domain write protection: Both cores are allowed
                                                 Domain write protection lock: Neither of DWP bits is locked */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_AD_23_SAI1_TX_SYNC,         /* GPIO_AD_23 PAD functional properties : */
      0x06U);                                 /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: high drive strength
                                                 Pull / Keep Select Field: Pull Enable
                                                 Pull Up / Down Config. Field: Weak pull down
                                                 Open Drain Field: Disabled
                                                 Domain write protection: Both cores are allowed
                                                 Domain write protection lock: Neither of DWP bits is locked */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_AD_24_LPUART1_TXD,          /* GPIO_AD_24 PAD functional properties : */
      0x06U);                                 /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: high drive strength
                                                 Pull / Keep Select Field: Pull Enable
                                                 Pull Up / Down Config. Field: Weak pull down
                                                 Open Drain Field: Disabled
                                                 Domain write protection: Both cores are allowed
                                                 Domain write protection lock: Neither of DWP bits is locked */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_AD_25_LPUART1_RXD,          /* GPIO_AD_25 PAD functional properties : */
      0x06U);                                 /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: high drive strength
                                                 Pull / Keep Select Field: Pull Enable
                                                 Pull Up / Down Config. Field: Weak pull down
                                                 Open Drain Field: Disabled
                                                 Domain write protection: Both cores are allowed
                                                 Domain write protection lock: Neither of DWP bits is locked */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_LPSR_04_LPI2C5_SDA,         /* GPIO_LPSR_04 PAD functional properties : */
      0x02U);                                 /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: high driver
                                                 Pull / Keep Select Field: Pull Disable
                                                 Pull Up / Down Config. Field: Weak pull down
                                                 Open Drain LPSR Field: Disabled
                                                 Domain write protection: Both cores are allowed
                                                 Domain write protection lock: Neither of DWP bits is locked */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_LPSR_05_LPI2C5_SCL,         /* GPIO_LPSR_05 PAD functional properties : */
      0x02U);                                 /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: high driver
                                                 Pull / Keep Select Field: Pull Disable
                                                 Pull Up / Down Config. Field: Weak pull down
                                                 Open Drain LPSR Field: Disabled
                                                 Domain write protection: Both cores are allowed
                                                 Domain write protection lock: Neither of DWP bits is locked */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_SD_B1_00_USDHC1_CMD,        /* GPIO_SD_B1_00 PAD functional properties : */
      0x04U);                                 /* PDRV Field: high drive strength
                                                 Pull Down Pull Up Field: Internal pullup resistor enabled
                                                 Open Drain Field: Disabled
                                                 Domain write protection: Both cores are allowed
                                                 Domain write protection lock: Neither of DWP bits is locked */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_SD_B1_01_USDHC1_CLK,        /* GPIO_SD_B1_01 PAD functional properties : */
      0x0CU);                                 /* PDRV Field: high drive strength
                                                 Pull Down Pull Up Field: No Pull
                                                 Open Drain Field: Disabled
                                                 Domain write protection: Both cores are allowed
                                                 Domain write protection lock: Neither of DWP bits is locked */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_SD_B1_02_USDHC1_DATA0,      /* GPIO_SD_B1_02 PAD functional properties : */
      0x04U);                                 /* PDRV Field: high drive strength
                                                 Pull Down Pull Up Field: Internal pullup resistor enabled
                                                 Open Drain Field: Disabled
                                                 Domain write protection: Both cores are allowed
                                                 Domain write protection lock: Neither of DWP bits is locked */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_SD_B1_03_USDHC1_DATA1,      /* GPIO_SD_B1_03 PAD functional properties : */
      0x04U);                                 /* PDRV Field: high drive strength
                                                 Pull Down Pull Up Field: Internal pullup resistor enabled
                                                 Open Drain Field: Disabled
                                                 Domain write protection: Both cores are allowed
                                                 Domain write protection lock: Neither of DWP bits is locked */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_SD_B1_04_USDHC1_DATA2,      /* GPIO_SD_B1_04 PAD functional properties : */
      0x04U);                                 /* PDRV Field: high drive strength
                                                 Pull Down Pull Up Field: Internal pullup resistor enabled
                                                 Open Drain Field: Disabled
                                                 Domain write protection: Both cores are allowed
                                                 Domain write protection lock: Neither of DWP bits is locked */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_SD_B1_05_USDHC1_DATA3,      /* GPIO_SD_B1_05 PAD functional properties : */
      0x04U);                                 /* PDRV Field: high drive strength
                                                 Pull Down Pull Up Field: Internal pullup resistor enabled
                                                 Open Drain Field: Disabled
                                                 Domain write protection: Both cores are allowed
                                                 Domain write protection lock: Neither of DWP bits is locked */

  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_LPSR_08_MIC_CLK,            /* GPIO_LPSR_08 PAD functional properties : */
      0x03U);                                 /* Slew Rate Field: Fast Slew Rate
                                                 Drive Strength Field: high driver
                                                 Pull / Keep Select Field: Pull Disable
                                                 Pull Up / Down Config. Field: Weak pull down
                                                 Open Drain LPSR Field: Disabled
                                                 Domain write protection: Both cores are allowed
                                                 Domain write protection lock: Neither of DWP bits is locked */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_LPSR_09_MIC_BITSTREAM0,     /* GPIO_LPSR_09 PAD functional properties : */
      0x03U);                                 /* Slew Rate Field: Fast Slew Rate
                                                 Drive Strength Field: high driver
                                                 Pull / Keep Select Field: Pull Disable
                                                 Pull Up / Down Config. Field: Weak pull down
                                                 Open Drain LPSR Field: Disabled
                                                 Domain write protection: Both cores are allowed
                                                 Domain write protection lock: Neither of DWP bits is locked */
}

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/