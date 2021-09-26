#pragma once
#include <avr/io.h>

namespace AVR_Utility
{
    class USART
    {
    private:
        USART() = delete;
    public:
        static void init(const uint8_t &stop_bits, const uint8_t &data_bits = 8);
        static void set_speed(const uint16_t &speed);

        template<typename T>
        static void transmit(T data)
        {
            if(!(UCSR0B & (1 << TXEN0)))
            return; // если бит TX не включен, выходим
            while(!(UCSR0A & (1 << UDRE0))); //Ждем, пока буфер будет свободен
            UDR0 = data;
        }
        template<typename T>
        static void transmit(T data[])
        {
            if(!(UCSR0B & (1 << TXEN0)))
                return; // если бит TX не включен, выходим
            while(*data != '\0')
            {
                while(!(UCSR0A & (1 << UDRE0))); //Ждем, пока буфер будет свободен
                UDR0 = *data;
                data++;
            }
        }
        static const uint8_t receive();
    };
};