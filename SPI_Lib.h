#ifndef _SPI_LIB_H_
#define _SPI_LIB_H_

#include <stdint.h>
#include "built_in.h"  // Assuming the built-in functions like Delay_us are declared here

// Function Prototypes
void SPI_Initialize(sbit *sckPin, sbit *sdiPin, sbit *csPin);
void SPI_Clock_Pulse(sbit *sckPin);
void SPI_Write(sbit *sckPin, sbit *sdiPin, uint8_t spiData);
void SPI_WritePortData(sbit *sckPin, sbit *sdiPin, sbit *csPin, uint8_t address, uint8_t value);

// Function Definitions

/**
 * @brief Initializes the SPI interface by setting up the necessary pins.
 * 
 * @param sckPin Pointer to the SCK pin definition.
 * @param sdiPin Pointer to the SDI pin definition.
 * @param csPin Pointer to the CS pin definition.
 */
void SPI_Initialize(sbit *sckPin, sbit *sdiPin, sbit *csPin) {
    *sckPin = 0;  // Set SCK pin as output
    *sdiPin = 0;  // Set SDI pin as output
    *csPin = 0;   // Set CS pin as output
}

/**
 * @brief Generates a clock pulse on the SCK line.
 * 
 * @param sckPin Pointer to the SCK pin definition.
 */
void SPI_Clock_Pulse(sbit *sckPin) {
    *sckPin = 1;  // Set SCK high
    Delay_us(1);  // Short delay
    *sckPin = 0;  // Set SCK low
    Delay_us(1);  // Short delay
}

/**
 * @brief Writes a byte of data via SPI (bit-banging method).
 * 
 * @param sckPin Pointer to the SCK pin definition.
 * @param sdiPin Pointer to the SDI pin definition.
 * @param spiData The byte of data to be sent.
 */
void SPI_Write(sbit *sckPin, sbit *sdiPin, uint8_t spiData) {
    uint8_t i;
    for (i = 0; i < 8; i++) {
        // Write data bit by bit
        if (spiData & 0x80)
            *sdiPin = 1;  // Set SDI high if MSB is 1
        else
            *sdiPin = 0;  // Set SDI low if MSB is 0

        SPI_Clock_Pulse(sckPin);  // Generate clock pulse
        spiData <<= 1;  // Shift data left by 1
    }
}

/**
 * @brief Sends data to a specified port via SPI.
 * 
 * @param sckPin Pointer to the SCK pin definition.
 * @param sdiPin Pointer to the SDI pin definition.
 * @param csPin Pointer to the CS pin definition.
 * @param address The address to be sent.
 * @param value The value to be sent.
 */
void SPI_WritePortData(sbit *sckPin, sbit *sdiPin, sbit *csPin, uint8_t address, uint8_t value) {
    *csPin = 0;  // Activate chip select (low)
    SPI_Write(sckPin, sdiPin, address);  // Send the address first
    SPI_Write(sckPin, sdiPin, value);    // Send the data
    *csPin = 1;  // Deactivate chip select (high)
}

#endif // _SPI_LIB_H_
