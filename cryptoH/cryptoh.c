#include "cryptoh.h"
#include <string.h>
#include <stdlib.h>

char* hash(char* data, char* password, size_t bufferLen)
{
    size_t l = strlen(data);
    char *buffer = (char* )malloc(bufferLen + 1);
    if (buffer == NULL)
    {
        return NULL;
    }
    buffer[bufferLen] = '\0';
    if (bufferLen > l)
    {
        for (size_t i = 0; i < l - 1; i++)
        {
            buffer[i] = data[i];
        }
        size_t t = 0;
        for (size_t i = l - 1; i < bufferLen; i++)
        {
            buffer[i] = data[t];
            t++;
            if (t == l)
            {
                t = 0;
            }
        }
    }
    else if (bufferLen < l) {
        for (size_t i = 0; i < bufferLen; i++)
        {
            buffer[i] = data[i];
        }
        size_t t = 0;
        for (size_t i = 0; i < l; i++)
        {
            buffer[t] = data[i];
            if (t == bufferLen) {
                t = 0;
            }
            t++;
        }
    }
    else {
        for (size_t i = 0; i < bufferLen; i++)
        {
            buffer[i] = data[i];
        }
    }
    for (size_t i = 0; i < bufferLen; i++)
    {

    }
    return buffer;
}
