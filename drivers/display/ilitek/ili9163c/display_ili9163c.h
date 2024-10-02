/*
 * Copyright (c) 2024, CATIE
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_DRIVERS_SENSOR_ILI9163C_ILI9163C_H_
#define ZEPHYR_DRIVERS_SENSOR_ILI9163C_ILI9163C_H_

#include <zephyr/device.h>

/* Commands/registers. */
#define ILI9163_GAMSET   0x26
#define ILI9163_FRMCTR1  0xB1
#define ILI9163_PGAMCTRL 0xE0
#define ILI9163_NGAMCTRL 0xE1
#define ILI9163_PWCTRL1  0xC0
#define ILI9163_PWCTRL2  0xC1
#define ILI9163_VMCTRL1  0xC5
#define ILI9163_VMCTRL2  0xC7
#define ILI9163_GAMADJ   0xF2
#define ILI9163_DISPINV  0xB4
#define ILI9163_MADCTL   0x36

/* Commands/registers length. */
#define ILI9163_GAMSET_LEN   1U
#define ILI9163_FRMCTR1_LEN  2U
#define ILI9163_PGAMCTRL_LEN 15U
#define ILI9163_NGAMCTRL_LEN 15U
#define ILI9163_PWCTRL1_LEN  2U
#define ILI9163_PWCTRL2_LEN  1U
#define ILI9163_VMCTRL1_LEN  2U
#define ILI9163_VMCTRL2_LEN  1U
#define ILI9163_GAMADJ_LEN   1U
#define ILI9163_DISPINV_LEN  1U
#define ILI9163_MADCTL_LEN   1U

/** X resolution (pixels). */
#define ILI9163_X_RES 160U
/** Y resolution (pixels). */
#define ILI9163_Y_RES 128U

/** ILI9163 registers to be initialized. */
struct ili9163_regs {
	uint8_t gamset[ILI9163_GAMSET_LEN];
	uint8_t frmctr1[ILI9163_FRMCTR1_LEN];
	uint8_t pgamctrl[ILI9163_PGAMCTRL_LEN];
	uint8_t ngamctrl[ILI9163_NGAMCTRL_LEN];
	uint8_t pwctrl1[ILI9163_PWCTRL1_LEN];
	uint8_t pwctrl2[ILI9163_PWCTRL2_LEN];
	uint8_t vmctrl1[ILI9163_VMCTRL1_LEN];
	uint8_t vmctrl2[ILI9163_VMCTRL2_LEN];
	uint8_t gamadj[ILI9163_GAMADJ_LEN];
	uint8_t dispinv[ILI9163_DISPINV_LEN];
	uint8_t madctl[ILI9163_MADCTL_LEN];
};

/* Initializer macro for ILI9163 registers. */
#define ILI9163_REGS_INIT(n)                                                                       \
	static const struct ili9163_regs ili9xxx_regs_##n = {                                      \
		.gamset = DT_PROP(DT_INST(n, ilitek_ili9163), gamset),                             \
		.frmctr1 = DT_PROP(DT_INST(n, ilitek_ili9163), frmctr1),                           \
		.pgamctrl = DT_PROP(DT_INST(n, ilitek_ili9163), pgamctrl),                         \
		.ngamctrl = DT_PROP(DT_INST(n, ilitek_ili9163), ngamctrl),                         \
		.pwctrl1 = DT_PROP(DT_INST(n, ilitek_ili9163), pwctrl1),                           \
		.pwctrl2 = DT_PROP(DT_INST(n, ilitek_ili9163), pwctrl2),                           \
		.vmctrl1 = DT_PROP(DT_INST(n, ilitek_ili9163), vmctrl1),                           \
		.vmctrl2 = DT_PROP(DT_INST(n, ilitek_ili9163), vmctrl2),                           \
		.gamadj = DT_PROP(DT_INST(n, ilitek_ili9163), gamadj),                             \
		.dispinv = DT_PROP(DT_INST(n, ilitek_ili9163), dispinv),                           \
		.madctl = DT_PROP(DT_INST(n, ilitek_ili9163), madctl),                             \
	}

int ili9163_regs_init(const struct device *dev);

#endif /* ZEPHYR_DRIVERS_SENSOR_ILI9163C_ILI9163C_H_ */
