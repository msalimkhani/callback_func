#include <stdio.h>
#include "../libs/color.h"
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

#define ESC "\033"

int printfc(const char* format, Color color, ...);