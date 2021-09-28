#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	int		fd;
	char	*j;
	int		t;

	t = 13;
	fd = open("42.txt", O_RDONLY);
	if (fd == -1)
		printf("error");
	j = get_next_line(fd);
	//printf ("%s", j);
	while (j)
	{
		printf ("%s", j);
		free(j);
		j = get_next_line(fd);
		t--;
	}
	free(j);
	close(fd);
}
