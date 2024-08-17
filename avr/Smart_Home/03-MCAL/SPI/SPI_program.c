#include "../../00-LIB/LSTD_types.h"
#include "../../00-LIB/LBIT_math.h"

#include "SPI_private.h"
#include "SPI_config.h"
#include "SPI_interface.h"

#if (SPI_MODE == SPI_MODE_SELECT_MASTER)
void SPI_voidInit_Master(ClockDivision copy_ClockDivisionType) {
    /*
     * Data Order
     */
    #if (SPI_DATA_ORDER == SPI_DATA_ORDER_MSB_TRANSMITTED_FIRST)
        CLR_BIT(SPI->SPCR, DORD);
    #elif (SPI_DATA_ORDER == SPI_DATA_ORDER_LSB_TRANSMITTED_FIRST)
        SET_BIT(SPI->SPCR, DORD);
    #else
        #error "wrong configuration for SPI_DATA_ORDER"
    #endif

    #if (SPI_CLOCK_POLARITY == SPI_CLOCK_POLARITY_IDEAL_LOW)
        CLR_BIT(SPI->SPCR, CPOL);
    #elif (SPI_CLOCK_POLARITY == SPI_CLOCK_POLARITY_IDEAL_HIGH)
        SET_BIT(SPI->SPCR, CPOL);
    #else
        #error "wrong configuration for SPI_CLOCK_POLARITY"
    #endif

    #if (SPI_CLOCK_PHASE == SPI_CLOCK_PHASE_SAMPLE_LEADING)
        CLR_BIT(SPI->SPCR, CPHA);
    #elif (SPI_CLOCK_PHASE == SPI_CLOCK_PHASE_SAMPLE_TRAILING)
        SET_BIT(SPI->SPCR, CPHA);
    #else
        #error "wrong configuration for SPI_CLOCK_PHASE"
    #endif

    // Set master mode
    SET_BIT(SPI->SPCR, MSTR);

    // Set clock division
    switch (copy_ClockDivisionType) {
        case fosc_div_2:
            CLR_BIT(SPI->SPCR, SPR0);
            CLR_BIT(SPI->SPCR, SPR1);
            SET_BIT(SPI->SPCR, SPI2X);
            break;
        case fosc_div_4:
            CLR_BIT(SPI->SPCR, SPR0);
            CLR_BIT(SPI->SPCR, SPR1);
            CLR_BIT(SPI->SPCR, SPI2X);
            break;
        case fosc_div_8:
            SET_BIT(SPI->SPCR, SPR0);
            CLR_BIT(SPI->SPCR, SPR1);
            SET_BIT(SPI->SPCR, SPI2X);
            break;
        case fosc_div_16:
            SET_BIT(SPI->SPCR, SPR0);
            CLR_BIT(SPI->SPCR, SPR1);
            CLR_BIT(SPI->SPCR, SPI2X);
            break;
        case fosc_div_32:
            CLR_BIT(SPI->SPCR, SPR0);
            SET_BIT(SPI->SPCR, SPR1);
            SET_BIT(SPI->SPCR, SPI2X);
            break;
        case fosc_div_64:
            CLR_BIT(SPI->SPCR, SPR0);
            SET_BIT(SPI->SPCR, SPR1);
            CLR_BIT(SPI->SPCR, SPI2X);
            break;
        case fosc_div_128:
            SET_BIT(SPI->SPCR, SPR0);
            SET_BIT(SPI->SPCR, SPR1);
            CLR_BIT(SPI->SPCR, SPI2X);
            break;
        default:
            // Handle invalid ClockDivision
            break;
    }

    /*
     * ENABLE SPI
     */
    SET_BIT(SPI->SPCR, SPE);
}
#elif (SPI_MODE == SPI_MODE_SELECT_SLAVE)
void SPI_voidInit_Slave(void) {
    /*
     * Data Order
     */
    #if (SPI_DATA_ORDER == SPI_DATA_ORDER_MSB_TRANSMITTED_FIRST)
        CLR_BIT(SPI->SPCR, DORD);
    #elif (SPI_DATA_ORDER == SPI_DATA_ORDER_LSB_TRANSMITTED_FIRST)
        SET_BIT(SPI->SPCR, DORD);
    #else
        #error "wrong configuration for SPI_DATA_ORDER"
    #endif

    #if (SPI_CLOCK_POLARITY == SPI_CLOCK_POLARITY_IDEAL_LOW)
        CLR_BIT(SPI->SPCR, CPOL);
    #elif (SPI_CLOCK_POLARITY == SPI_CLOCK_POLARITY_IDEAL_HIGH)
        SET_BIT(SPI->SPCR, CPOL);
    #else
        #error "wrong configuration for SPI_CLOCK_POLARITY"
    #endif

    #if (SPI_CLOCK_PHASE == SPI_CLOCK_PHASE_SAMPLE_LEADING)
        CLR_BIT(SPI->SPCR, CPHA);
    #elif (SPI_CLOCK_PHASE == SPI_CLOCK_PHASE_SAMPLE_TRAILING)
        SET_BIT(SPI->SPCR, CPHA);
    #else
        #error "wrong configuration for SPI_CLOCK_PHASE"
    #endif

    // Set slave mode
    CLR_BIT(SPI->SPCR, MSTR);

    /*
     * ENABLE SPI
     */
    SET_BIT(SPI->SPCR, SPE);
}
#else
#error "Invalid SPI mode configuration"
#endif

u8 SPI_u8Transcieve(u8 Copy_u8Value) {

    // Send the data
    SPI->SPDR = Copy_u8Value;

    // Wait for the reception to complete
    while (GET_BIT(SPI->SPSR,SPIF)==0);

    // Return the received data
    return SPI->SPDR;
}
