#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "labpzrl.h"

void print_int_mass(int mass[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("Ответ №%d: %d\n", i + 1, mass[i]);
	}
}

void print_char_mass(char mass[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%c", mass[i]);
	}
	printf("\n");
}

int is_decimal(char* str)
{
	if (!str || !*str) 
	{
		return 0;
	}
	if (*str == '-' || *str == '+')
	{
		str++;
	}
	while (*str)
	{
		if (!isdigit((unsigned char) *str))
		{
			return 0;
		}
		str++;
	}
	return 1;
}

int operation(int a, char n, int b)
{
	switch (n)
	{
		case '+':
			return a + b;
			break;
		case '-':
			return a - b;
			break;
		case '*':
			return a * b;
			break;
		case '%':
			if (b != 0)
			{
				return a % b;
				break;
			}
			else
			{
				printf("Делить на ноль нельзя.\n");
				exit(1);
			}
		default:
			printf("Недопустимый символ операции.\n");
			exit(1);
	}
}