# SPI Library for PIC Microcontrollers

## Overview

This library provides functions for using SPI (Serial Peripheral Interface) with PIC microcontrollers. It uses bit-banging to simulate SPI communication and is designed to be flexible, allowing the user to define the SPI pins in their main application code.

## Features

- **Flexible Pin Definitions**: Allows users to define SCK, SDI, and CS pins in their main code.
- **Simple SPI Communication**: Provides functions for initializing SPI, sending data, and generating clock pulses.
- **Port Data Transmission**: Includes a function to send data to a specific port via SPI.

Example
Here is a simple example of how to use the SPI library:
#include "SPI_Lib.h"

sbit SCK_PIN at PORTB.B6;
sbit SDI_PIN at PORTB.B7;
sbit CS_PIN at PORTB.B5;

void main() {
    SPI_Initialize(&SCK_PIN, &SDI_PIN, &CS_PIN);

    while (1) {
        uint8_t portAValue = PORTA;  // Read value from PORTA
        SPI_WritePortData(&SCK_PIN, &SDI_PIN, &CS_PIN, 0x11, portAValue);  // Send address 0x11 and data
    }
}


Functions
void SPI_Initialize(sbit *sckPin, sbit *sdiPin, sbit *csPin);
Initializes the SPI interface by configuring the provided SCK, SDI, and CS pins as outputs.

Parameters:

sckPin: Pointer to the SCK pin definition.
sdiPin: Pointer to the SDI pin definition.
csPin: Pointer to the CS pin definition.
void SPI_Clock_Pulse(sbit *sckPin);
Generates a clock pulse on the SCK line.

Parameters:

sckPin: Pointer to the SCK pin definition.
void SPI_Write(sbit *sckPin, sbit *sdiPin, uint8_t spiData);
Writes a byte of data via SPI (bit-banging method).

Parameters:

sckPin: Pointer to the SCK pin definition.
sdiPin: Pointer to the SDI pin definition.
spiData: The byte of data to be sent.
void SPI_WritePortData(sbit *sckPin, sbit *sdiPin, sbit *csPin, uint8_t address, uint8_t value);
Sends data to a specified port via SPI. The function first sends the address, followed by the data.

Parameters:

sckPin: Pointer to the SCK pin definition.
sdiPin: Pointer to the SDI pin definition.
csPin: Pointer to the CS pin definition.
address: The address to be sent.
value: The value to be sent.