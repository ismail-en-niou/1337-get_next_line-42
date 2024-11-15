#include <stdio.h>
#include "get_next_line.h"
int main()
{
    char *line ;

    int fd = open("test.txt",O_RDWR | O_CREAT , 0777);

    line = get_next_line(fd);
    printf("%s",line);
    close(fd);
}