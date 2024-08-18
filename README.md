# SPI Library for PIC Microcontrollers

## Overview

This library provides functions for using SPI (Serial Peripheral Interface) with PIC microcontrollers. It uses bit-banging to simulate SPI communication and is designed to be flexible, allowing the user to define the SPI pins in their main application code.

## Features

- **Flexible Pin Definitions**: Allows users to define SCK, SDI, and CS pins in their main code.
- **Simple SPI Communication**: Provides functions for initializing SPI, sending data, and generating clock pulses.
- **Port Data Transmission**: Includes a function to send data to a specific port via SPI.