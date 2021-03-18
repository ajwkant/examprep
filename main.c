#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
	int		r;
	char	*line;

	line = NULL;
	while ((r = get_next_line(&line)) > 0)
	{
		printf("d: %d, %s\n", r, line);
		free(line);
	}
	printf("d: %d, %s\n", r, line);
	free(line);
}