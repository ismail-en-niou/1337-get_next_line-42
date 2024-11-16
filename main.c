#include "get_next_line.h"

int main(void)
{
    int fd;
    char *line;

    // Open a file for reading
    fd = open("only_nl.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }

    // Read the file line by line
    while ((line = get_next_line(fd)) != NULL)
    {
        // Print the line to the console
        printf("%s", line);
        free(line);  // Don't forget to free the line after printing
    }

    // Close the file
    close(fd);

    return (0);
}