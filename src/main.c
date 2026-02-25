#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    char station_id[5];
    int temperature;
    int dew_point;
    //TODO
}MetarData;

int correct_input(int argc, char *argv[]);
int icao_valid(char *s);
int time_valid(char *t);


int main(int argc, char *argv[])
{
    if (correct_input(argc, argv) == 1)
    {
        printf("Usage: %s \"METAR_STRING\"\n", argv[0]);
        return 1;
    }
    printf("Received METAR %s\n", argv[1]);
    if (icao_valid(argv[1]) == 1)
    {
        printf("Incorrect ICAO format \n");
        return 1;
    }
    if (time_valid(argv[1]) == 1)
    {
        printf("Incorrect time format \n");
        return 1;
    }
    else if (time_valid(argv[1]) == 2)
    {
        printf("Time format should end with 'Z' \n");
        return 1;
    }
}

int correct_input(int argc, char *argv[])
{
    if (argc != 2)
    {
        return 1;
    }
    return 0;
}

int icao_valid(char *s)
{
    for (int i = 0, n = 4; i < n; i++) 
    {
        if (!isalpha(s[i]))
        {
            return 1;
        }
    } 
    return 0;
}

int time_valid(char *t)
{
    int n = 11;
    for (int i = 5; i < n; i++)
    {
        if (!isdigit(t[i]))
        {
            return 1;
        }

    }
    if (toupper(t[n]) != 'Z')
    {
        return 2;
    }
    return 0;
}