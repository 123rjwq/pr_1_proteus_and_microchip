/*
 * pr_2.cpp
 *
 * Created: 07.02.2024 13:54:30
 * Author : 2707-21
 */ 

#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>

// ������� ��� ���������� PORTC � ���������
int port_c(int i)
{
	PORTC = (1<<i);
	_delay_ms(200);
	return (i);
}
// ������� ��� ���������� PORTD � ���������
int port_d(int i)
{
	PORTD = (1<<i);
	_delay_ms(200);
	return (i);
}
// ������� ��� ���������� PORTB � ���������
int port_b(int i)
{
	PORTB = (1<<i);
	_delay_ms(200);
	return (i);
}

int main(void)
{
	//DDRB = 0b00000010;
	DDRD= 0b11111111;
	DDRC= 0b11111111;
	DDRB= 0b11111010;
	PORTB|= (1<<PB0)|(1<<PB2);	
	
    /* Replace with your application code */
    while (1) 
    {
		if(!(PINB&(1<<PB2))) // ������ ������ ������ - ������� 
		{
			if(!(PINB&(1<<PB0))) // ������ ������ ������ - �� �������� �����
			{
				for (int i = 8; i  >= 0; i--)
				{
					DDRD=0b11111111;
					port_d(i);
					DDRD=0b00000000;
				}
				for (int i = 6; i  >= 0; i--)
				{
					DDRC=0b11111111;
					port_c(i);
					DDRC=0b00000000;
				}
				
				for (int i = 1; i  >= 1; i--)
				{
					DDRB=0b11111111;
					port_b(i);
					DDRB=0b00000000;
				}
			}
			else if((PINB&(1<<PB0)))// ������ �� ������ ������ - �� �������� ����
			{
				for (int i = 0; i < 6; i++)
				{
					DDRC=0b11111111;
					port_c(i);
					DDRC=0b00000000;
				}
				for (int i = 0; i < 9; i++)
				{
					DDRD=0b11111111;
					port_d(i);
					DDRD=0b00000000;
				}
				for (int i = 1; i  >= 1; i--)
				{
					DDRB=0b11111111;
					port_b(i);
					DDRB=0b00000000;
				}
			}
		}
		else if((PINB&(1<<PB2)))// ������ ������ �� ������ - �����������
		{
			if(!(PINB&(1<<PB0))) // ������ ������ ������ - �� ������������ �����
			{
				for (int i = 8; i  >= 0; i--)
				{
					DDRD=0b11111111;
					port_d(i);
					DDRD=0b00000000;
				}
			}
			else if((PINB&(1<<PB0))) // ������ �� ������ ������ - �� ������������ ����
			{
				for (int i = 0; i < 9; i++)
				{
					DDRD=0b11111111;
					port_d(i);
					DDRD=0b00000000;
				}
			}
		}
    }
}

