#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int     fd;
	char    *line;

	if (argc != 2)
	{
		printf("Error argument.\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);

	while(get_next_line(fd, &line))
	{
		printf("%s\n", line);
		free(line);
	}

}