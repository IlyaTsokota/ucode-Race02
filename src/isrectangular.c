#include "header.h"

bool isrectangular(char *str, int count_row, int size_first_row) {
    if (count_row <= 1) {
        return true;
    }
    int size_current_row = 0;
    while (*str) {
        if (*str == '\n') {
            if (size_first_row != size_current_row) {
                return true;
            } else {
               
                size_current_row = 0;
            }
        } else {
            size_current_row++;
        }
        str++;
    }
    return false;
}
