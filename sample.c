#include "SPI_Lib.h"

sbit SCK_PIN at PORTB.B6;
sbit SDI_PIN at PORTB.B7;
sbit CS_PIN at PORTB.B5;

void main() {
    // Initialize SPI with defined pins
    SPI_Initialize(&SCK_PIN, &SDI_PIN, &CS_PIN);

    while (1) {
        uint8_t portAValue = PORTA;  // Read value from PORTA
        SPI_WritePortData(&SCK_PIN, &SDI_PIN, &CS_PIN, 0x11, portAValue);  // Send address 0x11 and data
    }
}
