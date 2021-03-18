#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*add_to_line(char *linebuilt, char *buffer)
{
	int len;
	char *newline;

	len = ft_strlen(linebuilt);
	newline = malloc(len + 2);
	if (!newline)
		return (NULL);
	newline[len] = buffer[0];
	newline[len + 1] = '\0';
	while (len)
	{
		newline[len - 1] = linebuilt[len - 1];
		len--;
	}
	free(linebuilt);
	return (newline);
}

int		get_next_line(char **line)
{
	char	buffer[1];
	int		bytes;

	if (!line)
		return (-1);
	*line = NULL;
	bytes = 1;
	while (bytes)
	{
		bytes = read(0, buffer, 1);
		if (bytes == 1)
			*line = add_to_line(*line, buffer);
		if (!*line)
			return (-1);
		if (!buffer[0] || buffer[0] == '\n')
			break ;
	}
	return (bytes);
}
