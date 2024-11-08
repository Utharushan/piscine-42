/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuthayak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:26:11 by tuthayak          #+#    #+#             */
/*   Updated: 2024/07/15 14:26:38 by tuthayak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	is_in_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (is_in_charset(str[i + 1], charset)
			&& !is_in_charset(str[i], charset))
			words++;
		i++;
	}
	return (words);
}

void	write_word(char *dest, char *src, char *charset)
{
	int	i;

	i = 0;
	while (is_in_charset(src[i], charset) == 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void	write_split(char **split, char *str, char *charset)
{
	int	i;
	int	len_word;
	int	word;

	word = 0;
	i = 0;
	while (str[i])
	{
		if (is_in_charset(str[i], charset))
			i++;
		else
		{
			len_word = 0;
			while (!is_in_charset(str[i + len_word], charset))
				len_word++;
			split[word] = (char *)malloc(sizeof(char) * (len_word + 1));
			write_word(split[word], str + i, charset);
			i += len_word;
			word++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		words;

	words = count_words(str, charset);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	res[words] = 0;
	write_split(res, str, charset);
	return (res);
}
/*
#include <stdio.h>

int	main(int ac, char **av)
{
	char **res;
	int	i = 0;

	if (ac == 3)
	{
		res = ft_split(av[1], av[2]);
		while (res[i])
		{
			printf("%s\n", res[i]);
			i++;
		}
	}
}
*/