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
    size_t t = 0;
    size_t passLen = strlen(password);
    size_t seed = 0;
    for (size_t i = 0; i < passLen; i++)
    {
        seed += password[i];
    }
    for (size_t i = 0; i < passLen; i++) {
        if (t == bufferLen) t = 0;
        buffer[t] = (char)(buffer[t] * password[i] * passLen);
        t++;
    }
    int randOp = 1;
    for (size_t i = 0; i < bufferLen; i++)
    {
        int temp = buffer[i] * (l % 3 + 1) + passLen*seed;
        switch (randOp)
        {
        case 1:
            temp << l;
            break;
        case 2:
            temp = temp * l;
            break;
        case 3:
            temp ^= l;
            break;
        }
        temp = temp % hashLogSize;
        randOp++;
        if (randOp > 3) randOp = 1;
        buffer[i] = hashLog[temp];
    }
    return buffer;
}
