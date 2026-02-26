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

// Validation function prototypes
int correct_input(int argc, char *argv[]);
int icao_validation(char *airport);
int time_validation(char *date);
int wind_validation(char *wind_data);


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
    if(tv == 2)
    {
        printf("'Z' letter is abscent in time format\n");
        return 1;
    }
    if (tv == 3)
    {
        printf("Incomplite time format\n");
        return 1;
    }
    int wv = wind_validation(wind);
    if (wv == 1)
    {
        printf("Wind data are incomplete\n");
        return 1;
    }
    else if (wv == 2)
    {
        printf("First 5 characters in wind part must be digits\n");
        return 1;
    }
    else if (wv == 3)
    {
        printf("Windspeed unit is not mentioned\n");
        return 1;
    }
    printf("METAR has been succesfully validated\n");
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
    for (int i = 0; i < 4; i++)
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
    for (int i = 0; i < 6; i++)
    {
        if(!isdigit(date[i]))
        {
            return 1;
        }
    }
    if (toupper(date[6]) != 'Z')
    {
        return 2;
    }
    if (strlen(date) != 7)
    {
        return 3;
    }
    return 0;
}
int wind_validation(char *wind_data)
{
    if (strlen(wind_data) < 7)
    {
        return 1;
    }
    for (int i = 0; i < 5; i++)
    {
        if (!isdigit(wind_data[i]))
        {
            return 2;
        }
    }
    if (strcmp(&wind_data[5], "KT") != 0 && strcmp(&wind_data[5], "MPS") != 0)
    {
        return 3;
    }
    return 0;
}