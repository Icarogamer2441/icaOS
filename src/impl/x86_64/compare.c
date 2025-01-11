#include "compare.h"

bool compare_str(char* str1, char* str2) {
    while (*str1 && *str2) {
        if (*str1 != *str2) {
            return false;
        }
        str1++;
        str2++;
    }
    return *str1 == '\0' && *str2 == '\0';
}
