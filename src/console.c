#include "../libs/console.h"

char* parseColor(Color color)
{
    char* res = (char *) malloc(7 * sizeof(char));
    switch (color)
    {
    case Default:
        strcpy(res, "\033[0m");
        break;
    case Black:
        strcpy(res, "\033[30m");
        break;
    case Green:
        strcpy(res, ESC);
        strcpy(res, "\033[32m");
        break;
    case Red:
        strcpy(res, ESC);
        strcpy(res, "\033[31m");
        break;
    default:
        break;
    }
    return res;
    free(res);
}

int printfc(const char* format, Color color, ...)
{
    va_list args;
    char buffer[BUFSIZ];

    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);
    return printf("%s%s%s",parseColor(color), buffer, parseColor(Default));
}