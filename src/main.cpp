#include <avr/io.h>
#include <util/delay.h>
#include "AVR_USART.hpp"
#include <string.h>
using namespace AVR_Utility;

int main()
{
	USART::init(2, 8);
	USART::set_speed(1);
	_delay_ms(1000);


	while(true)
	{
		USART::transmit("Hello, world!\n");
		USART::transmit('t');
		USART::transmit(164);//A4 in HEX
		USART::transmit("123\n");
	}
	return 0;
}