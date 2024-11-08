/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuthayak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:26:25 by tuthayak          #+#    #+#             */
/*   Updated: 2024/07/09 09:26:27 by tuthayak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_longueur(char **strs, int size, char *sep)
{
	int	longueur;
	int	i;

	i = 0;
	longueur = 0;
	while (i < size)
	{
		longueur += ft_strlen(strs[i]);
		i++;
	}
	longueur += (size - 1) * ft_strlen(sep) + 1;
	return (longueur);
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

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		j;

	if (size == 0)
	{
		str = malloc(sizeof(char));
		*str = 0;
		return (str);
	}
	str = malloc(sizeof(char) * (ft_longueur(strs, size, sep)));
	if (!str)
		return (NULL);
	*str = 0;
	j = 0;
	while (j < size - 1)
	{
		ft_strcat(str, strs[j]);
		ft_strcat(str, sep);
		j++;
	}
	ft_strcat(str, strs[j]);
	return (str);
}
/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	printf("%s", ft_strjoin(argc, argv, "---"));
}
*/