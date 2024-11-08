/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuthayak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:36:52 by tuthayak          #+#    #+#             */
/*   Updated: 2024/07/14 15:36:53 by tuthayak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*crop_space(char *str)
{
	char	*end;

	while (*str == ' ')
		str++;
	if (*str == 0)
		return (str);
	end = str + ft_strlen(str) - 1;
	while (end > str && (*end == ' ' || *end == '\n'))
		end--;
	end[1] = '\0';
	return (str);
}

char	*sub_read_line(char *line, char *buffer, int len)
{
	char	*temp;
	int		i;

	temp = (char *)malloc(len + 2);
	if (!temp)
	{
		free(line);
		return (NULL);
	}
	if (line)
	{
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
	return (temp);
}

char	*read_line(int fd)
{
	char	buffer[1];
	char	*line;
	int		len;
	int		n;
	char	*temp;
	int		i;

	line = NULL;
	len = 0;
	n = read(fd, buffer, 1);
	while (n > 0)
	{
		temp = (char *)malloc(len + 2);
		if (!temp)
		{
			free(line);
			return (NULL);
		}
		if (line)
		{
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
		n = read(fd, buffer, 1);
	}
	return (line);
}
