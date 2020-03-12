/* ***************************************************************** */
/* File name:        mgc.c                                           */
/* File description: Multipurpose clk generator hardware abstraction */
/*                   layer. Enables the clock configuration          */
/*                                                                   */
/*                   Modes of Operation                              */
/*                   FLL Engaged Internal (FEI)    = DEFAULT         */
/*                   FLL Engaged External (FEE)                      */
/*                   FLL Bypassed Internal (FBI)                     */
/*                   FLL Bypassed External (FBE)                     */
/*                   PLL Engaged External (PEE)                      */
/*                   PLL Bypassed External (PBE)                     */
/*                   Bypassed Low Power Internal (BLPI)              */
/*                   Bypassed Low Power External (BLPE)              */
/*                   Stop                                            */
/*                                                                   */
/*                   For clock definitions, check the chapter        */
/*                   5.4 Clock definitions from                      */
/*                   KL25 Sub-Family Reference Manual                */
/*                                                                   */
/* Author name:      dloubach                                        */
/* Creation date:    21out2015                                       */
/* Revision date:    21mar2016                                       */
/* ***************************************************************** */

#include "mcg.h"

/* systems include */
#include "fsl_smc_hal.h"
#include "fsl_port_hal.h"
#include "fsl_clock_manager.h"

/* EXTAL0 PTA18 */
#define EXTAL0_PORT                  PORTA
#define EXTAL0_PIN                   18U
#define EXTAL0_PINMUX                kPortPinDisabled

/* XTAL0 PTA19 */
#define XTAL0_PORT                   PORTA
#define XTAL0_PIN                    19U
#define XTAL0_PINMUX                 kPortPinDisabled

/* OSC0 configuration */
#define OSC0_INSTANCE                0U
#define OSC0_XTAL_FREQ               8000000U /* 08 MHz*/
#define OSC0_SC2P_ENABLE_CONFIG      false
#define OSC0_SC4P_ENABLE_CONFIG      false
#define OSC0_SC8P_ENABLE_CONFIG      false
#define OSC0_SC16P_ENABLE_CONFIG     false
#define MCG_HGO0                     kOscGainLow
#define MCG_RANGE0                   kOscRangeVeryHigh
#define MCG_EREFS0                   kOscSrcOsc

/* RTC external clock configuration. */
#define RTC_XTAL_FREQ                0U
#define RTC_SC2P_ENABLE_CONFIG       false
#define RTC_SC4P_ENABLE_CONFIG       false
#define RTC_SC8P_ENABLE_CONFIG       false
#define RTC_SC16P_ENABLE_CONFIG      false
#define RTC_OSC_ENABLE_CONFIG        false
#define RTC_CLK_OUTPUT_ENABLE_CONFIG false

/* RTC_CLKIN PTC1 */
#define RTC_CLKIN_PORT               PORTC
#define RTC_CLKIN_PIN                1U
#define RTC_CLKIN_PINMUX             kPortMuxAsGpio


#define CLOCK_VLPR                   1U /* very low power run mode */
#define CLOCK_RUN                    2U /* run mode */

#ifndef CLOCK_INIT_CONFIG
#define CLOCK_INIT_CONFIG CLOCK_RUN
#endif


/* Configuration for enter VLPR mode, Core clock = 4MHz */
const clock_manager_user_config_t g_defaultClockConfigVlpr =
{
    .mcgConfig =
    {
        .mcg_mode           = kMcgModeBLPI,       // Work in BLPI mode
        .irclkEnable        = true,               // MCGIRCLK enable
        .irclkEnableInStop  = false,              // MCGIRCLK disable in STOP mode
        .ircs               = kMcgIrcFast,        // Select IRC4M
        .fcrdiv             = 0U,                 // FCRDIV is 0

        .frdiv   = 0U,
        .drs     = kMcgDcoRangeSelLow,            // Low frequency range
        .dmx32   = kMcgDmx32Default,              // DCO has a default range of 25%

        .pll0EnableInFllMode = false,             // PLL0 disable
        .pll0EnableInStop  = false,               // PLL0 disalbe in STOP mode
        .prdiv0            = 0U,
        .vdiv0             = 0U,
    },
    .simConfig =
    {
        .pllFllSel = kClockPllFllSelFll,          // PLLFLLSEL select FLL
        .er32kSrc  = kClockEr32kSrcLpo,           // ERCLK32K selection, use LPO
        .outdiv1   = 0U,
        .outdiv4   = 4U,
    },
    .oscerConfig =
    {
        .enable       = true,                     // OSCERCLK enable
        .enableInStop = false,                    // OSCERCLK disable in STOP mode
    }
};

/* Configuration for enter RUN mode, Core clock = 40 MHz */
/*
 * 24.5.1.1 Initializing the MCG
 * KL25 Sub-Family Reference Manual, Rev. 3, September 2012
 *
 * Refer also to
 * Table 24-18. MCG modes of operation
 *
 * On L-series devices the MCGFLLCLK frequency is limited to 48 MHz max
 * The DCO is limited to the two lowest range settings (MCG_C4[DRST_DRS] must be set to either 0b00 or 0b01).
 *
 * FEE (FLL engaged external)
 * fext / FLL_R must be in the range of 31.25 kHz to 39.0625 kHz
 * FLL_R is the reference divider selected by the C1[FRDIV] bits
 * F is the FLL factor selected by C4[DRST_DRS] and C4[DMX32] bits
 *
 * (fext / FLL_R) * F = (8 MHz / 256 ) * 1280 = 40 MHz
 *
 * */
const clock_manager_user_config_t g_defaultClockConfigRun =
{
    /* ----------- multipurpose clock generator configurations -------------- */
    .mcgConfig =
    {
        .mcg_mode           = kMcgModeFEE,       // Work in FEE mode

        /* ------------------ MCGIRCCLK settings ---------------------- */
        .irclkEnable        = true,              // MCGIRCLK enable
        .irclkEnableInStop  = false,             // MCGIRCLK disable in STOP mode
        .ircs               = kMcgIrcSlow,       // Select IRC 32kHz
        .fcrdiv             = 0U,                // FCRDIV is 0

        /* -------------------- MCG FLL settings ---------------------- */
        .frdiv   = 0b011,                        // Divide Factor is 256 (EXT OSC 8 MHz / 256 = 31.250 kHz)
                                                 // The resulting frequency must be in the range 31.25 kHz to 39.0625 kHz
        .drs     = kMcgDcoRangeSelMid,           // frequency range
        .dmx32   = kMcgDmx32Default,             // DCO has a default range of 25%

        /* -------------------- MCG PLL settings ---------------------- */
        .pll0EnableInFllMode = false,            // PLL0 disable
        .pll0EnableInStop  = false,              // PLL0 disabLe in STOP mode
        .prdiv0            = 0x0U,
        .vdiv0             = 0x0U,
    },
    /* ----------- system integration module configurations    -------------- */
    .simConfig =
    {
        .pllFllSel = kClockPllFllSelFll,         // PLLFLLSEL select PLL
        .er32kSrc  = kClockEr32kSrcLpo,          // ERCLK32K selection, use LPO
        .outdiv1   = 0U,                         // core/system clock, as well as the bus/flash clocks.
        .outdiv4   = 1U,                         // bus and flash clock and is in addition to the System clock divide ratio
    },
    /* ----------- system oscillator output configurations     -------------- */
    .oscerConfig =
    {
        .enable       = true,                    // OSCERCLK enable
        .enableInStop = false,                   // OSCERCLK disable in STOP mode
    }
};


/* ************************************************ */
/* Method name:        mcg_initOsc0                 */
/* Method description: Oscillator configuration     */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void mcg_initOsc0(void)
{
    /* OSC0 configuration */
    osc_user_config_t osc0Config =
    {
        .freq                = OSC0_XTAL_FREQ,
        .hgo                 = MCG_HGO0,
        .range               = MCG_RANGE0,
        .erefs               = MCG_EREFS0,
        .enableCapacitor2p   = OSC0_SC2P_ENABLE_CONFIG,
        .enableCapacitor4p   = OSC0_SC4P_ENABLE_CONFIG,
        .enableCapacitor8p   = OSC0_SC8P_ENABLE_CONFIG,
        .enableCapacitor16p  = OSC0_SC16P_ENABLE_CONFIG,
    };

    /* oscillator initialization */
    CLOCK_SYS_OscInit(OSC0_INSTANCE, &osc0Config);
}



/* ************************************************ */
/* Method name:        mcg_initRtcOsc               */
/* Method description: Function to initialize RTC   */
/*                     external clock base on       */
/*                     board configuration          */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void mcg_initRtcOsc(void)
{

#if RTC_XTAL_FREQ
    // If RTC_CLKIN is connected, need to set pin mux. Another way for
    // RTC clock is set RTC_OSC_ENABLE_CONFIG to use OSC0, please check
    // reference manual for details
    PORT_HAL_SetMuxMode(RTC_CLKIN_PORT, RTC_CLKIN_PIN, RTC_CLKIN_PINMUX);
#endif

#if ((OSC0_XTAL_FREQ != 32768U) && (RTC_OSC_ENABLE_CONFIG))
#error Set RTC_OSC_ENABLE_CONFIG will override OSC0 configuration and OSC0 must be 32k.
#endif

    rtc_osc_user_config_t rtcOscConfig =
    {
        .freq                = RTC_XTAL_FREQ,
        .enableCapacitor2p   = RTC_SC2P_ENABLE_CONFIG,
        .enableCapacitor4p   = RTC_SC4P_ENABLE_CONFIG,
        .enableCapacitor8p   = RTC_SC8P_ENABLE_CONFIG,
        .enableCapacitor16p  = RTC_SC16P_ENABLE_CONFIG,
        .enableOsc           = RTC_OSC_ENABLE_CONFIG,
        .enableClockOutput   = RTC_CLK_OUTPUT_ENABLE_CONFIG,
    };

    /* OSC RTC initialization */
    CLOCK_SYS_RtcOscInit(0U, &rtcOscConfig);
}



/* ************************************************ */
/* Method name:        mcg_initSystemClock          */
/* Method description: System clock configuration   */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void mcg_initSystemClock(void)
{
    /* Set system clock configuration. */
    #if (CLOCK_INIT_CONFIG == CLOCK_VLPR)
        CLOCK_SYS_SetConfiguration(&g_defaultClockConfigVlpr);
    #else
        CLOCK_SYS_SetConfiguration(&g_defaultClockConfigRun);
    #endif
}



/* ************************************************ */
/* Method name:        mcg_clockInit                */
/* Method description: main board clk configuration */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void mcg_clockInit(void)
{
    /* enable clock for PORTs */
    CLOCK_SYS_EnablePortClock(PORTA_IDX);
    CLOCK_SYS_EnablePortClock(PORTC_IDX);
    CLOCK_SYS_EnablePortClock(PORTE_IDX);

    /* set allowed power mode to allow all */
    SMC_HAL_SetProtection(SMC, kAllowPowerModeAll);

    /* configure OSC0 pin mux */
    PORT_HAL_SetMuxMode(EXTAL0_PORT, EXTAL0_PIN, EXTAL0_PINMUX);
    PORT_HAL_SetMuxMode(XTAL0_PORT, XTAL0_PIN, XTAL0_PINMUX);

    /* setup OSC0 */
    mcg_initOsc0();

    /* setup OSC RTC */
    mcg_initRtcOsc();

    /* setup system clock */
    mcg_initSystemClock();
}
