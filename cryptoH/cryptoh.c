#include "cryptoh.h"
#include <string.h>

char* hash(char* data, char* password, unsigned int bufferLen)
{
    unsigned int l = strlen(hash);
    char *buffer = (char* )malloc(bufferLen + 1);
    if (buffer == nullptr)
    {
        return nullptr;
    }
    buffer[bufferLen] = '\0';
    if (bufferLen > l)
    {
        for (unsigned int i = 0; i < l - 1; i++)
        {
            buffer[i] = data[i];
        }
        int t = 0;
        for (unsigned int i = l - 1; i < bufferLen; i++)
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
        for (unsigned int i = 0; i < bufferLen; i++)
        {
            buffer[i] = data[i];
        }
        int t = 0;
        for (unsigned int i = 0; i < l; i++)
        {
            buffer[t] = data[i];
            if (t == bufferLen) {
                t == 0;
            }
            t++;
        }
    }
    else {
        for (int i = 0; i < bufferLen; i++)
        {
            buffer[i] = data[i];
        }
    }
    return buffer;
}
