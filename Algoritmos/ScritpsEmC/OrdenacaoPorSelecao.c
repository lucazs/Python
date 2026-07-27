#include <stdlib.h>
#include <stdio.h>

/* Macro para converter strings em long...*/
#define str_to_long(s) strtol((s), NULL, 10)

/*Função para encontrar menor argumento e seu indice*/
long find_min(char **argv, int count, int *index)
{
    long min = str_to_long(argv[0]);
    int min_index = 0;
    long val;

    for(int i = 1; i < count; i++)
    {
        val = str_to_long(argv[i]);
        if(val < min)
        {
            min = val;
            min_index = i;
        }
    }

    *index = min_index;
    return min;
}

/*Função para remover argumento encontrado...*/
void array_lshift(char **argv, int count, int index)
{
    for(int i = index; i < count - 1; i++)
    {
        argv[i] = argv[i + 1];
    }
}

int main(int argc, char **argv)
{
    /*Remover argv[0] (invocação do programa)*/
    argc--;
    argv++;

    int index;
    int count = argc;

    for (int i = 0; i < count; i++)
    {
        printf("%ld ", find_min(argv, argc, &index));
        array_lshift(argv, argc, index);
        argc--;
    }
    putchar('\n');

    return EXIT_SUCCESS;
}
