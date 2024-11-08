/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuthayak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 16:40:33 by tuthayak          #+#    #+#             */
/*   Updated: 2024/07/14 16:40:34 by tuthayak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int			ft_strlen(char *str);

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_puterror(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

char	*ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
			i++;
	return (s1[i] - s2[i]);
}

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	size_dest;
	unsigned int	i;

	i = 0;
	size_dest = ft_strlen(dest);
	while (src[i] != '\0')
	{
			dest[size_dest + i] = src[i];
			i++;
	}
	dest[size_dest + i] = '\0';
	return (dest);
}
