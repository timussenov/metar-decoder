#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../include/tokenizer.h"

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
    // Command-line input validation
    int ci = correct_input(argc, argv);                   
    if (ci == 1)
    {
        printf("Usage: %s \"METAR_STRING\"\n", argv[0]);
        return 1;
    }
    // Creating buffer
    char buffer[256];
    strncpy(buffer, argv[1], sizeof(buffer) - 1);
    buffer[255] = '\0';

    char *icao = NULL;
    char *time = NULL;
    char *wind = NULL;
    char *visibility = NULL;
    char *clouds = NULL;
    char *temp_dew = NULL;
    char *pressure = NULL;

    // Call tokenizer
    extract_tokens(
        buffer, 
        &icao, 
        &time, 
        &wind, 
        &visibility, 
        &clouds, 
        &temp_dew, 
        &pressure
    );
    // Tests tokenization 
    printf("ICAO: %s\n", icao);
    printf("Time: %s\n", time);
    printf("Wind: %s\n", wind);
    printf("Visibility: %s\n", visibility);
    printf("Clouds %s\n", clouds);
    printf("Dew: %s\n", temp_dew);
    printf("Pressure : %s\n", pressure);

    // Validating return values
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
// Validation functions; To separate from main file
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