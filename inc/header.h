#ifndef HEADER_H
#define HEADER_H

//standard libs
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/errno.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdbool.h>

//work with console output
#include "print.h"
//my functions for counting rows and columns
#include "count.h"
//work with file
#include "file_man.h"
//work with string
#include "string_man.h"
//functions which return true / false
#include "boolean_is.h"

//fail
void ismap_error(const char *filename);
void isempty_or_missing_file(const char *filename);
void start_fail(int count_args, const char *filename);
void isout_of_range(int x1, int x2, int y1, int y2, int column, int row);

int mx_atoi(const char *str);
char **create_char_matrix(char *res, int *row, int *column);
int **create_int_matrix(char *res, int *row, int *column);
int max_way(int **grid, int x1, int y1, int count_row, int count_column, char **final);
bool ispath(int **grid, int x1, int y1, int x2, int y2, int row, int column, int *length, int *pathX, int *pathY);

void working(char const *argv[]);

#endif
