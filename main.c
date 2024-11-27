#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "labpzrl.h"

char num_to_ascii(int num, int key)
{
	num = num - key;
	return (char)num;
}

int is_flag_correct(char flag[2])
{
	if (strcmp(flag, "-k") == 0)
	{
		return 1;
	}
	else
	{
		printf("Недопустимый флаг.\n");
		exit(1);
	}
}

int main(int argc, char* argv[])
{
	if (argc < 4 || argc > 1024)
	{
		printf("Неверный формат ввода.\n");
		exit(1);
	}
	int sz = 2;
	int* answers = (int*) malloc(sz * sizeof(int));
	int size = 0;
	int flag = 1;

	for (int i = 1; i < argc; i += 3)
	{
		if (argv[i][0] == '-' && is_flag_correct(argv[i]) == 1)
		{
			flag = 0;
			break;
		}
		else
		{
			char oper;
			int num_a;
			int num_b;
			oper = argv[i + 1][0];
			num_a = atoi(argv[i]);
			num_b = atoi(argv[i + 2]);

			// printf("%d %c %d\n", num_a, oper, num_b);

			if (size >= sz)
			{
				sz++;
				answers = (int*) realloc(answers, sz * sizeof(int));
			}
			answers[size++] = operation(num_a, oper, num_b);
		}
	}

	int key;
	key = atoi(argv[argc - 1]);

	char res_str[size];

	for (int i = 0; i < size; i++)
	{
		res_str[i] = num_to_ascii(answers[i], key);
	}

	print_int_mass(answers, size);
	printf("Результирующая строка: ");
	print_char_mass(res_str, size);

	free(answers);

	return 0;
}
