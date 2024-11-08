/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuthayak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:33:04 by tuthayak          #+#    #+#             */
/*   Updated: 2024/07/15 11:33:05 by tuthayak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int		ft_strlen(char *str);
char	*ft_strcat(char *dest, char *src);
char	*ft_putnbr_base(int nbr, char *base);
char	*ft_strcpy(char *dest, char *src);

int	contains_error(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = i + 1;
	if (ft_strlen(&base[0]) <= 1)
		return (1);
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] < 32 || base[i] > 126)
			return (1);
		while (base[j])
		{
			if (base[j] == base[i])
				return (1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

int	char_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	sub_ft_atoi(char *str, char *base, int i, int count_sign_moins)
{
	int	atoi;
	int	pos;

	atoi = 0;
	if (count_sign_moins % 2 == 0)
		count_sign_moins = 1;
	else
		count_sign_moins = -1;
	while (char_in_base(str[i], base) != -1)
	{
		pos = char_in_base(str[i], base);
		atoi = atoi * ft_strlen(&base[0]) + pos;
		i++;
	}
	return (count_sign_moins * atoi);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	count_sign_moins;
	int	count_sign;

	i = 0;
	count_sign_moins = 0;
	count_sign = 0;
	while (char_in_base(str[i], base) == -1)
	{
		if (str[i] == '\0' || (96 < str[i] && str[i] < 123)
			|| (64 < str[i] && str[i] < 91)
			|| (str[i] != '-' && str[i] != '+' && count_sign != 0))
			return (0);
		else if (str[i] == '-')
		{
			count_sign_moins += 1;
			count_sign += 1;
		}
		else if (str[i] == '+')
			count_sign += 1;
		i++;
	}
	return (sub_ft_atoi(str, base, i, count_sign_moins));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		dec;
	char	*res;

	if (contains_error(base_from) || contains_error(base_to))
		return (NULL);
	dec = ft_atoi_base(nbr, base_from);
	if (dec == 0)
	{
		res = malloc(sizeof(char) * 2);
		res[0] = base_to[0];
		res[1] = 0;
		return (res);
	}
	res = ft_putnbr_base(dec, base_to);
	return (res);
}
/*
#include <stdio.h>

int	main(int ac, char **av)
{
	char	*str;

	if (ac == 4)
	{
		str = ft_convert_base(av[1], av[2], av[3]);
		printf("%s", str);
		free(str);
	}
}
*/