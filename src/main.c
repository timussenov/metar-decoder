#include <stdio.h>

int main(int argc, char *argv[])
{
    if (correct_input(argc, argv) == 1)
    {
        printf("Usage: %s \"METAR_STRING\"\n", argv[0]);
        return 1;
    }
    printf("Received METAR %s\n", argv[1]);
}

int correct_input(int argc, char *argv[])
{
    if (argc != 2)
    {
        return 1;
    }
    return 0;
}