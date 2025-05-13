/*
** EPITECH PROJECT, 2025
** B-MUL-100-REN-1-1-myradar-enzo.iffis
** File description:
** print_helper
*/

#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include <unistd.h>
#include "stdlib.h"

void print_helper(char const *filepath)
{
    struct stat stats;
    int fd = open(filepath, O_RDONLY);
    char *buffer;
    size_t bytes_read = 0;

    if (fd == -1)
        return;
    if (stat(filepath, &stats) == -1){
        close(fd);
        return;
    }
    buffer = malloc(sizeof(char) * stats.st_size + 1);
    if (!buffer){
        close(fd);
        return;
    }
    bytes_read = read(fd, buffer, stats.st_size);
    buffer[bytes_read] = '\0';
    my_printf("%s\n", buffer);
    free(buffer);
}
