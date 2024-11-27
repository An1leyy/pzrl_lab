#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_int_mass(int mass[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Ответ №%d: %d \n", i + 1, mass[i]);
    }
}

void print_char_mass(char mass[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%c", mass[i]);
    }
}

char num_to_ascii(int num, int key)
{
    num = num - key;
    return (char) num;
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

int main()
{
    int sz = 2;
    int *answers = malloc(sz * sizeof(int));
    int flag = 1;
    int size = 0;
    while (flag == 1)
    {   
        char a_str[100];

        scanf("%s", a_str);

        if (strcmp(a_str, "-k") == 0)
        {
                flag = 0;
                break;
        }
        else
        {
            char oper;
            int num_a = atoi(a_str);
            int num_b;
            
            scanf(" %c %d", &oper, &num_b);

            if (size >= sz)
            {
                sz++;
                answers = (int *) realloc(answers, sz * sizeof(int));
            }
            answers[size] = operation(num_a, oper, num_b);
            size++;
        }
    }

    int key;
    scanf("%d", &key);

    char res_str[size];

    for (int i = 0; i < size; i++)
    {
        res_str[i] = num_to_ascii(answers[i], key);
    }


    print_int_mass(answers, size);
    printf("Результирующая строка: ");
    print_char_mass(res_str, size);

    free(answers);
}
