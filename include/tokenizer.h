#ifndef TOKENIZER_H
#define TOKENIZER_H

int extract_tokens
(
    char *buffer,
    char **icao,
    char **time,
    char **wind,
    char **visibility,
    char **clouds,
    char **temp_dew,
    char **pressure 
);

#endif