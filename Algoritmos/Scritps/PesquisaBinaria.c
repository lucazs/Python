#include <stdio.h>
#include <stdlib.h>

/*Macro para converter strings em long...*/
#define str_to_long(s) strtol((s), NULL, 10)


/*Funções.....*/
void ordenar_vetor(int argc, char **argv)
{
    long val;

    for(int i = 0; i < argc; i++)
    {
        if (i == 0)
        {
            val = str_to_long(argv[i]);
        }
        else
        {
            if(val < str_to_long(argv[i]))
            {
                argv[i] = argv[i + 1];
                val = argv[i];
            }
        }
    }
}

int main(int argc, char **argv)
{
    /*Remover argc[0] */
    argc--;
    /*Pular para o proximo byte...*/
    argv++;

    for(int i = 0; i < argc; i++)
    {
        printf("Valores: %s ", argv[i]);
    }

    return EXIT_SUCCESS;
}
