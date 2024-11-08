#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*cpy;

	i = 0;
	cpy = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!cpy)
		return (NULL);
	while (src[i])
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char *crop_space(char *str)
{
	char	*end;

	while (*str == ' ')
		str++;
	if (*str == 0)
		return (str);
	end = str + ft_strlen(str) - 1;
	while (end > str && *end == ' ')
		end--;
	end[1] = '\0';
	return (str);
}

char *read_line(int fd)
{
	char	buffer[1];
	char	*line;
	int	len;
	int	n;

	line = NULL;
	len = 0;
	while ((n = read(fd, buffer, 1)) > 0)
	{
		char	*temp;
		temp = (char *)malloc(len + 2);
		if (!temp)
		{
			free(line);
			return (NULL);
		}
		if (line)
		{
			int	i;

			i = 0;
			while (i < len)
			{
				temp[i] = line[i];
				i++;
			}
			free(line);
		}
		temp[len++] = buffer[0];
		temp[len] = '\0';
		line = temp;
		if (buffer[0] == '\n')
			break ;
	}
	return (line);
}
