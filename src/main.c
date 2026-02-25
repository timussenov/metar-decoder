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
int icao_validation(char *airport);
int time_validation(char *date);

int main(int argc, char *argv[])
{
    int ci = correct_input(argc, argv);                   
    if (ci == 1)
    {
        printf("Usage: %s \"METAR_STRING\"\n", argv[0]);
        return 1;
    }
    char buffer [256];
    strncpy(buffer, argv[1], sizeof(buffer));
    buffer[255] = '\0';
    char *icao = strtok(buffer, " ");
    char *time = strtok(NULL, " ");
    char *wind = strtok(NULL, " ");
    char *visibility = strtok(NULL, " ");
    char *clouds = strtok(NULL, " ");
    char *temp_dew = strtok(NULL, " ");
    char *pressure = strtok(NULL, " ");
    if (!icao || !time)
    {
        printf("Invalid METAR structure\n");
        return 1;
    }

    if (icao_validation(icao) == 1)
    {
        printf("Invalid ICAO format \n");
        return 1;
    }

    int tv = time_validation(time);
    if (tv == 1)
    {
        printf("Invalid time format \n");
        return 1;
    }

    else if (tv == 2)
    {
        printf("Z letter is absent in time string\n");
        return 1;
    }

    return 0;
}

int correct_input(int argc, char *argv[])
{
    if (argc != 2)
    {
        return 1;
    }
    return 0;
}

int icao_validation(char *airport)
{
     if (strlen(airport) != 4) 
    {    
        return 1;
    }    
    for (int i = 0,n = 4; i < n; i++)
    {
        if (!isalpha(airport[i]))
        {
            return 1;
        }
    }
    return 0;
}

int time_validation(char *date)
{
    if (strlen(date) != 7)
    {
        return 1;
    }
    
    int n = 6;
    for (int i = 0; i < n; i++)
    {
        if(!isdigit(date[i]))
        {
            return 1;
        }
    }
    if (toupper(date[n]) != 'Z')
    {
        return 2;
    }
    return 0;
}