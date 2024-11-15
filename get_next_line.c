#include "get_next_line.h"



char *get_next_line(int fd)
{
	char	*line;
	char	*tank;
	static 	char *rest;
	char *test;

	line =ft_strdup("");
	if (rest){
		test = ft_strjoin(line,rest);
		free(rest);
	}
	while (1)
	{
		read(fd,tank,BUFFER);
		printf("%s",tank);
		if (ft_test_new(tank) == -1)
		{
			line = ft_strjoin(line , tank);
		}else 
		{
			break;
		}
	}
	return line ;
}