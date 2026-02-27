#include <string.h>
#include "../include/tokenizer.h"

int extract_tokens(char *buffer, char **icao, char **time, char **wind, 
                   char **visibility, char **clouds, char **temp_dew, char **pressure) 
{
    *icao       = strtok(buffer, " ");
    *time       = strtok(NULL, " ");
    *wind       = strtok(NULL, " ");
    *visibility = strtok(NULL, " ");
    *clouds     = strtok(NULL, " ");
    *temp_dew   = strtok(NULL, " ");
    *pressure   = strtok(NULL, " ");

    return 0; 
}