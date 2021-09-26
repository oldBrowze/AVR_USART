#include "AVR_USART.hpp"

namespace AVR_Utility
{
    void USART::init(const uint8_t &stop_bits, const uint8_t &data_bits)
    {
        UCSR0B |= (1 << RXEN0) | (1 << TXEN0);

        if(data_bits >= 5 && data_bits <= 8)
            UCSR0C |= ((data_bits - 5) << UCSZ00);
        if(stop_bits >= 1 && stop_bits <= 2)
            UCSR0C |= ((stop_bits - 1) << USBS0);

    }
    void USART::set_speed(const uint16_t &speed)
    {
        UBRR0H = (speed >> 8);
        UBRR0L = speed;
    }
    /*
    void transmit(char &data)
    {
        if(!(UCSR0B & (1 << TXEN0)))
            return; // если бит TX не включен, выходим
        while(!(UCSR0A & (1 << UDRE0))); //Ждем, пока буфер будет свободен
        UDR0 = data;
    }
    
    void transmit(const char *data)
    {
        if(!(UCSR0B & (1 << TXEN0)))
            return; // если бит TX не включен, выходим
        while(*data != '\0')
        {
            while(!(UCSR0A & (1 << UDRE0))); //Ждем, пока буфер будет свободен
            UDR0 = *data;
            data++;
        }
    }*/
    const uint8_t USART::receive()
    {
        if(!(UCSR0A & (1 << RXEN0)))
            return 0; // если бит RX не включен, выходим
        while(!(UCSR0A & (1 << RXC0))); //Ждем, пока буфер будет свободен
        return UDR0;
    }
};